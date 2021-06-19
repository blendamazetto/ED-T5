#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"
#include "hashfile.h"
#include "item.h"

typedef struct hashfile{
    char nomeArq[80];
    int nbuckets;
    int numRecPerBucket;
    int tamRec;
    int tamCh;
}HashfileStruct;

typedef struct balde{
    int nItens;
    Item* itens;
    long int next;
}Balde;

int getKey(char *chave, int nbuckets) 
{
    int aux = 0, res;
    int tamanho = strlen(chave);
    for (int i = 0; i < tamanho; i++) 
    {
        aux += chave[i];
    }
    res = aux % nbuckets;
    return res;
}

Hashfile fcreateHF(char *nome,int nbuckets,int numRecPerBkt, int tamRec, int tamCh)
{
    HashfileStruct* hf = malloc(sizeof(HashfileStruct));
    FILE* file = fopen(nome,"wb");
    strcpy(hf->nomeArq,nome);
    hf->nbuckets = nbuckets;
    hf->numRecPerBucket = numRecPerBkt;
    hf->tamRec = tamRec;
    hf->tamCh = tamCh;
    fwrite(nome,sizeof(char),80,file);
    fwrite(&nbuckets,sizeof(int),1,file);
    fwrite(&numRecPerBkt,sizeof(int),1,file);
    fwrite(&tamRec,sizeof(int),1,file);
    fwrite(&tamCh,sizeof(int),1,file);
    int nItens = 0;
    long int next = -1;
    for(int i  = 0; i < nbuckets; i++)
    {
        fwrite(&nItens, sizeof(int), 1, file);
        for(int j = 0; j < numRecPerBkt; j++)
        {
            char* chave = "\0";
            char* valor = "\0";
            fwrite(chave,sizeof(char),tamCh,file);
            fwrite(valor,tamRec,1,file);
        }
        fwrite(&next, sizeof(long int), 1, file);
    }
    fclose(file);
    return hf;
}

Hashfile fopenHF(char *nome)
{
    FILE* file = fopen(nome,"rb");
    if(file == NULL)
    {
        return NULL;
    }
    HashfileStruct* hf = malloc(sizeof(HashfileStruct));
    fread(hf->nomeArq,sizeof(char),80,file);
    fread(&hf->nbuckets,sizeof(int),1,file);
    fread(&hf->numRecPerBucket,sizeof(int),1,file);
    fread(&hf->tamRec,sizeof(int),1,file);
    fread(&hf->tamCh,sizeof(int),1,file);
    fclose(file);
    return hf;
}

void fwriteBalde(FILE* file, Balde *b, int numRecPerBucket, int tamRec, int tamCh)
{
    fwrite(&b->nItens, sizeof(int), 1, file);
    for(int j = 0; j < numRecPerBucket; j++)
    {
        fwrite(getChaveItem(b->itens[j]), sizeof(char),tamCh,file);
        fwrite(getValorItem(b->itens[j]),tamRec,1,file);
    }
    fwrite(&b->next, sizeof(long int), 1, file);
}

void freadBalde(FILE* file, Balde *b, int numRecPerBucket, int tamRec, int tamCh)
{
    fread(&b->nItens, sizeof(int), 1, file);
    for(int j = 0; j < numRecPerBucket; j++)
    {
        fread(getChaveItem(b->itens[j]), sizeof(char),tamCh,file);
        fread(getValorItem(b->itens[j]),tamRec,1,file);
    }
    fread(&b->next, sizeof(long int), 1, file);
}


Balde inicializarBalde(int numRecPerBucket, int tamRec, int tamCh)
{
    Balde balde;
    balde.itens = (Item*)malloc(sizeof(Item) * numRecPerBucket);
    for(int i = 0; i < numRecPerBucket; i++)
    {
        balde.itens[i] = alocarItem(tamCh, tamRec);
    }
    return balde;
}

void desalocarBalde(Balde balde, int numRecPerBucket)
{
    for(int i = 0; i < numRecPerBucket; i++)
    {
        desalocaValorItem(balde.itens[i]);
    }
    free(balde.itens);
}

int fwriteRec(Hashfile hf, Item buf)
{
    HashfileStruct* h = (HashfileStruct*) hf;
    FILE* file = fopen(h->nomeArq,"r+b");
    int posicao = getKey(getChaveItem(buf), h->nbuckets);
    int tamHf = 80*sizeof(char) + 4*sizeof(int);
    int tamBalde = sizeof(long int) + sizeof(int) + h->numRecPerBucket * (h->tamRec + h->tamCh * sizeof(char));
    fseek(file,tamHf + posicao * tamBalde, SEEK_SET);
    long int posIn = ftell(file);
    Balde balde = inicializarBalde(h->numRecPerBucket, h->tamRec, h->tamCh);
    freadBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
    while (balde.nItens == h->numRecPerBucket)
    {
        if(balde.next == -1)
        {
            fseek(file, -tamBalde, SEEK_CUR);
            long int posAnt = ftell(file);
            fseek(file, 0, SEEK_END);
            posIn = ftell(file); 
            balde.next = posIn;
            fseek(file, posAnt, SEEK_SET);
            fwriteBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
            balde.nItens = 0;
            balde.next = -1;
        }
        else
        {
            fseek(file, balde.next, SEEK_SET);
            posIn = ftell(file);
            freadBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
        }
    }
    strcpy(getChaveItem(balde.itens[balde.nItens]), getChaveItem(buf));
    memcpy(getValorItem(balde.itens[balde.nItens]), getValorItem(buf), h->tamRec);
    balde.nItens++;
    fseek(file, posIn, SEEK_SET);
    fwriteBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
    fclose(file);
    desalocarBalde(balde, h->numRecPerBucket);
    return 1;
}

int freadHF(Hashfile hf, char *ch, Item buf)
{
    HashfileStruct* h = (HashfileStruct*) hf;
    Item* i = (Item*) buf;
    FILE* file = fopen(h->nomeArq,"rb");
    int posicao = getKey(ch, h->nbuckets);
    int tamHf = 80*sizeof(char) + 4*sizeof(int);
    int tamBalde = sizeof(long int) + sizeof(int) + h->numRecPerBucket * (h->tamRec + h->tamCh * sizeof(char));
    fseek(file,tamHf + posicao * tamBalde, SEEK_SET);
    Balde balde = inicializarBalde(h->numRecPerBucket, h->tamRec, h->tamCh);
    do{
        freadBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
        for(int j = 0; j < balde.nItens; j++)
        {
            if(strcmp(ch,getChaveItem(balde.itens[j])) == 0)
            {
                Info aux = malloc(h->tamRec);
                memcpy(aux, getValorItem(balde.itens[j]),h->tamRec);
                *i = createItem(getChaveItem(balde.itens[j]), aux);
                fclose(file);
                desalocarBalde(balde, h->numRecPerBucket);
                return 1;
            }
        }
    } while (balde.next != -1);
    fclose(file);
    desalocarBalde(balde, h->numRecPerBucket);
    return 0;
}

void dumpFileHF(Hashfile hf, Info F, PrintRecord p)
{
    HashfileStruct* h = (HashfileStruct*) hf;
    FILE* file = fopen(h->nomeArq,"rb");
    int tamHf = 80*sizeof(char) + 4*sizeof(int);
    fseek(file,tamHf, SEEK_SET);
    Balde balde = inicializarBalde(h->numRecPerBucket, h->tamRec, h->tamCh);
    for(int i = 0; i < h->nbuckets; i++)
    {
        freadBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
        long int aux = ftell(file);
        while(1)
        {
            for(int j = 0; j < balde.nItens; j++)
            {
                Item item = alocarItem(h->tamCh, h->tamRec);
                strcpy(getChaveItem(item), getChaveItem(balde.itens[j]));
                memcpy(getValorItem(item), getValorItem(balde.itens[j]), h->tamRec);
                p(item, F);
            }
            if(balde.next == -1)
            {
                break;
            }
            fseek(file,balde.next,SEEK_SET);
            freadBalde(file, &balde, h->numRecPerBucket, h->tamRec, h->tamCh);
        }
        fseek(file,aux,SEEK_SET);        
    }
    desalocarBalde(balde, h->numRecPerBucket);
    fclose(file);
}

void fcloseHF(Hashfile hf)
{
    free(hf);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>
#include "hashtable.h"

typedef struct hash
{
    char key[200];
    Info info;

}HashStruct;

unsigned int hash (char key[], int tamanhoHash)
{
    int lenght = strlen(key);
    unsigned int hash_value = 0;

    for(int i=0; i < lenght; i++)
    {
        hash_value+=key[i];
        hash_value = (hash_value * key[i]) % tamanhoHash;
    }
    return hash_value;
}

Hash createHashTable(int tamanhoHash)
{
    HashStruct* hash = malloc(sizeof(HashStruct) * tamanhoHash);

    for(int i=0; i < tamanhoHash; i++)
    {
        hash[i].info = NULL;
        strcpy(hash[i].key, "NULL");
    }

    return hash;
}

void adicionarListaNaHashCodt(Hash hashtable, Lista lista)
{
    for(No node = getFirst(lista); node != NULL; node = getNext(node))
    {
        Codt e = getValorItem(getInfo(node));
        insertHashTable(e, getCodtCodt(e), tamanhoDaLista(lista), hashtable);
    }
}

void adicionarListaNaHashPessoa(Hash hashtable, Lista lista)
{
    for(No node = getFirst(lista); node != NULL; node = getNext(node))
    {
        Pessoa p = getValorItem(getInfo(node));
        insertHashTable(p, getPessoaCpf(p), tamanhoDaLista(lista), hashtable);
    }
}

void adicionarListaNaHashMorador(Hash hashtable, Lista lista)
{
    for(No node = getFirst(lista); node != NULL; node = getNext(node))
    {
        Morador m = getValorItem(getInfo(node));
        insertHashTable(getMoradorCep(m), getMoradorCpf(m), tamanhoDaLista(lista), hashtable);
    }
}

void adicionarHashNaListaCodt(Hash hashtable, Lista lista, int tamanho)
{
    HashStruct* h = hashtable;
    for(int i=0; i < tamanho; i++)
    {
        insert(lista, h[i].info);
    }
}

void adicionarHashNaListaPessoa(Hash hashtable, Lista lista, int tamanho)
{
    HashStruct* h = hashtable;
    for(int i=0; i < tamanho; i++)
    {
        insertList(h[i].info, lista);
    }
}

void adicionarHashNaListaMorador(Hash hashtable, Lista lista, int tamanho)
{
    HashStruct* h = hashtable;
    for(int i=0; i < tamanho; i++)
    {
        insertList(h[i].info, lista);
    }
}

void insertHashTable(Info info, char key[], int tamanho, Hash hashtable)
{
    HashStruct* h = hashtable;

    int index = hash(key, tamanho);

    for(int i=0; i < tamanho; i++)
    {
        int try = (i + index) % tamanho;
        if(strcmp(h[try].key, "NULL") == 0)
        {
            strcpy(h[try].key, key);
            h[try].info = info;
            return;
        }
    }
}

void printHashTable(int tamanho, Hash hashtable)
{
    HashStruct* h = hashtable;

    for(int i=0; i < tamanho; i++)
    {
        if(strcmp(h[i].key, "NULL") == 0)
        {
            printf("\t%d\t ---\n", i);
        }
        else
        {
            printf("\t%d\t%s\n", i, h[i].key);
        }
    }
}

Info searchHashTable(char key[], Hash hashtable, int tamanho)
{
    HashStruct* h = hashtable;

    int index = hash(key, tamanho);

    for(int i=0; i < tamanho; i++)
    {
        int try = (i + index) % tamanho;

        if(strcmp(h[try].key, key) == 0)
        {
            return h[try].info;
        }
    }
    return NULL;
}

void removeNodeHashTable(char key[], Hash hashtable, int tamanho)
{
    HashStruct* h = hashtable;

    int index = hash(key, tamanho);

    for(int i=0; i < tamanho; i++)
    {
        int try = (i + index) % tamanho;
        if(strcmp(h[try].key, key) == 0)
        {
            strcpy(h[try].key, "NULL");
            free(h[try].info);

            return;
        }
    }
}

char* getHashInfo(Info info)
{
    char* informacao = (char*) info;
    strcpy(informacao, info);
    return informacao;
}

void deleteHashTable(Hash hashtable, int tamanho, int a)
{
    HashStruct* h = hashtable;

    for(int i=0; i < tamanho; i++)
    {
        if(strcmp(h[i].key, "NULL") != 0)
        {
            strcpy(h[i].key, "NULL");
            if(a==1)
            {
                free(h[i].info);
            }
        }
    }
}

void setHashTable(char key[], Hash hashtable, int tamanho, Info info)
{
    HashStruct* h = hashtable;

    int index = hash(key, tamanho);

    for(int i=0; i < tamanho; i++)
    {
        int try = (i + index) % tamanho;

        if(strcmp(h[try].key, key) == 0)
        {
            h[try].info = info;
        }
    }
}


void buscarMenorValor(Hash hashtable, int tamanho, char idMenorValor[], Hash visitado)
{
    double menorValor = 999999;
    double *valor = malloc(sizeof(double));
    *valor = 0;

    HashStruct* h = hashtable;
    for(int i=0; i < tamanho; i++)
    {
        *valor = *(double*)h[i].info;
        if(searchHashTable(h[i].key, visitado, tamanho) == NULL)
        {
            if(*valor < menorValor)
            {
                strcpy(idMenorValor, h[i].key);
                menorValor = *valor;
            }
        }
    }

    free(valor);
}

int tamanhoDaHashtable(Hash hashtable, int tam)
{
    int j = tam;
    HashStruct* h = hashtable;
    for(int i=0; i < tam; i++)
    {
        if(strcmp(h[i].key, "NULL") == 0)
        {
            j--;
        }
    }
    return j;
}







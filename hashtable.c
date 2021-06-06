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
    int lenght = strnlen(key, 200);
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










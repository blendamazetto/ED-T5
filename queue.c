#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

typedef struct node
{
    Info info;
    struct node* proximo;

}NoStruct;

typedef struct fila
{
    NoStruct *primeiro;
    int tamanho;
    NoStruct *ultimo;

}FilaStruct;

Fila createQueue()
{
    FilaStruct* fila = (FilaStruct*) malloc(sizeof(FilaStruct));
    fila->primeiro = NULL;
    fila->tamanho = 0;
    fila->ultimo = NULL;

    return fila;
}

void insertQueue(Fila f, Info info) 
{
    FilaStruct* fila = (FilaStruct*) f;
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));

    node->info = info;
    node->proximo = NULL;

    if(fila->ultimo == NULL)
    {
        fila->primeiro = node;
        fila->ultimo = node;
    }
    else
    {
        fila->ultimo->proximo = node;
    }

    fila->ultimo = node; 
    fila->tamanho++;
}

Info removeQueue(Fila f) 
{
    FilaStruct* fila = (FilaStruct*) f;
    NoStruct* node = fila->primeiro;
    Info info = node->info;

    fila->primeiro = node->proximo;

    if(fila->ultimo == node)
    {
        fila->ultimo = NULL;
    }
    
    free(node);

    fila->tamanho--;

    return info;
}

int isEmptyQueue(Fila f)
{
    FilaStruct* fila = (FilaStruct*) f;
  
    return fila->primeiro == NULL;
}

No getPrimeiro(Fila f)
{
    FilaStruct* fila = (FilaStruct*) f;

    return fila->primeiro;
}

int getTamanhoQueue(Fila f)
{
    FilaStruct* fila = (FilaStruct*) f;

    return fila->tamanho;
}

void deleteQueue(Fila f)
{
    FilaStruct* fila = (FilaStruct*) f;

    for(int i=0; i<fila->tamanho; i++)
    {
        removeQueue(fila);
    }
}

No getProximo(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;

    return node->proximo;

}

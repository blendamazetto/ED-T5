#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

typedef struct node
{
    Info info;
    struct node* anterior;

}NoStruct;

typedef struct pilha
{
    NoStruct *topo;
    int tamanho;

}PilhaStruct;

Pilha createStack()
{
    PilhaStruct* pilha = (PilhaStruct*) malloc(sizeof(PilhaStruct));
    pilha->topo = NULL;
    pilha->tamanho = 0;

    return pilha;
}

void insertStack(Pilha p, Info info) 
{
    PilhaStruct* pilha = (PilhaStruct*) p;
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));

    node->info = info;

    if(pilha->topo == NULL)
    {
        pilha->topo = node;
        node->anterior = NULL;
    }
    else
    {
        node->anterior = pilha->topo;
        pilha->topo = node;
    }
    
    pilha->tamanho++;
}

Info removeStack(Pilha p) 
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    if(pilha->tamanho == 0)
    {
        return NULL;
    }

    NoStruct* node = pilha->topo;
    Info info = node->info;

    pilha->topo = node->anterior;
    
    free(node);

    pilha->tamanho--;

    return info;
}

int isEmptyStack(Pilha pilha)
{ 
    PilhaStruct* p = (PilhaStruct*) pilha;
    return p->topo == NULL;
}

No getTopo(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    return pilha->topo;
}

int getTamnhoStack(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    return pilha->tamanho;
}

void deleteStack(Pilha p)
{
    PilhaStruct* pilha = (PilhaStruct*) p;

    for(int i=0; i<pilha->tamanho; i++)
    {
        removeStack(pilha);
    }
}

No getAnterior(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;

    return node->anterior;

}




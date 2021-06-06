#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

typedef struct node{

    Info info;
    struct node *anterior;
    struct node *proximo;

}NoStruct;

typedef struct lista{

    NoStruct *primeiro;
    NoStruct *ultimo;
    int tamanho;
    int tamanhoFinal;

}ListaStruct;

Lista create()
{
    ListaStruct* lista = (ListaStruct*) malloc(sizeof(ListaStruct));
    lista->primeiro = NULL;
    lista->ultimo = NULL;
    lista->tamanho = 0;
    return lista;
}

void insert(Lista l, Info info) 
{
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));
    node->info = info;

    if(lista->primeiro == NULL) 
    {
        node->anterior = NULL;
        lista->primeiro = node;

    } else 
    {
        lista->ultimo->proximo = node;
        node->anterior = lista->ultimo;
    }

    node->proximo = NULL;
    lista->ultimo = node;
    lista->tamanho++;
}

void insertList(Info info, Lista l) 
{
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));
    
    node->info = info;
    if(lista->primeiro == NULL) 
    {
        node->anterior = NULL;
        lista->primeiro = node;

    } else 
    {
        lista->ultimo->proximo = node;
        node->anterior = lista->ultimo;
    }

    node->proximo = NULL;
    lista->ultimo = node;
    lista->tamanho++;
}

No criarNo()
{
    NoStruct* node = (NoStruct*) malloc(sizeof(NoStruct));
    node->info = NULL;

    return node;
}

No getFirst(Lista lista)
{
    ListaStruct* l = (ListaStruct*) lista;
    return l->primeiro;
}

No getLast(Lista lista)
{
    ListaStruct* l = (ListaStruct*) lista;
    return l->ultimo;
}

No getNext(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;
    return node->proximo;
}

No getPrevious(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;
    return node->anterior;
}

Info getInfo(No elemento)
{
    NoStruct* node = (NoStruct*) elemento;
    return node->info;
}

void insertAfter(Lista lista, No node, Info info)
{
    ListaStruct* lis = (ListaStruct*) lista;
    NoStruct* nod = (NoStruct*) node;
    NoStruct* novo = (NoStruct*) malloc(sizeof(NoStruct));

    novo->info = info;

    if(nod->proximo == NULL){
        nod->proximo = novo;
        novo->proximo = NULL;
        novo->anterior = nod;
        lis->ultimo = novo;
    }
    else
    {
        NoStruct* aux = nod->proximo;
        nod->proximo = novo;
        novo->proximo = aux;
        novo->anterior = nod;
        aux->anterior = novo;
    }

    lis->tamanho++;

}

void insertBefore(Lista lista, No node, Info info)
{
    ListaStruct* lis = (ListaStruct*) lista;
    NoStruct *nod = (NoStruct*) node;

    NoStruct* novo = (NoStruct*) malloc(sizeof(NoStruct));
    novo->info = info;

    if(nod->anterior == NULL)
    {
        nod->anterior = novo;
        novo->proximo = nod;
        novo->anterior = NULL;
        lis->primeiro = novo;
    }
    else
    {
        NoStruct* aux = nod->anterior;
        nod->anterior = novo;
        novo->proximo = nod;
        novo->anterior = aux;
        aux->proximo = novo;
    }

    lis->tamanho++;
}

void removerNo(Lista l, No elemento, void (*desalocar)(void*))
{
    ListaStruct* lista = (ListaStruct*) l;
    NoStruct* node = (NoStruct*) elemento;

    if(node->anterior == NULL)
    {
        lista->primeiro = node->proximo;
    }
    else
    {
        node->anterior->proximo = node->proximo;
    }
    if(node->proximo == NULL)
    {
        lista->ultimo = node->anterior;
    }else
    {
        node->proximo->anterior = node->anterior;
    }

    if (desalocar != NULL) desalocar(getInfo(node));
    free(node);
    lista->tamanho--;
}

void removeList(Lista l, void (*desalocar)(void*))
{
    ListaStruct* lista = (ListaStruct*) l;

    if(lista == NULL)
    {
        return;
    }
    
    NoStruct* node = lista->primeiro;
    NoStruct* aux;

    while(node != NULL)
    {
        aux = node;
        node = node->proximo;
        if(desalocar != NULL)
        {
            desalocar(getInfo(aux));
        }
        free(aux);
    }
    free(lista);
}

int tamanhoDaLista(Lista listasObjetos)
{
    ListaStruct* lis = (ListaStruct*) listasObjetos;
    return lis->tamanho;
}

int tamanho(Lista listasObjetos)
{
    ListaStruct* lis = (ListaStruct*) listasObjetos;
    return lis->tamanhoFinal;
}

void setTamanhoFinal(Lista listasObjetos, int tamanho)
{
    ListaStruct* lis = (ListaStruct*) listasObjetos;
    lis->tamanhoFinal = tamanho;
}

No buscarPosicao(Lista listasObjetos[], int posicao)
{
    int i=0;
    No node;
    for(node = getFirst(listasObjetos[7]); node != NULL; node = getNext(node))
    {
        if(i==posicao)
        {
            return node;
        } 
    }
    return node=NULL; 
} 

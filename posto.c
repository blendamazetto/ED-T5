#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "posto.h"

typedef struct c{

    char id[20];
    double x;
    double y;
    double distancia; 
    Ponto ponto;

}PostoStruct;

Posto criaPosto(char id[], double x, double y, double distancia)
{
    PostoStruct* posto = (PostoStruct*) malloc(sizeof(PostoStruct));

    strcpy( posto->id, id);
    posto->x = x;
    posto->y = y;
    posto->distancia = distancia;
    posto->ponto = createPonto(x,y);

    return posto;
}

void copiarNo(Posto posto1, Posto posto2)
{
    PostoStruct* p1 = (PostoStruct*) posto1;
    PostoStruct* p2 = (PostoStruct*) posto2;

    *p1 = *p2;
}

char* getPostoId(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->id;
}

double getPostoX(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->x;
}

double getPostoY(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->y;
}

double getPostoDistancia(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->distancia;
}

void setPostoId(Posto posto, char id[])
{
    PostoStruct* post = (PostoStruct*) posto;
    strcpy(post->id, id);
}

void setPostoX(Posto posto, double x)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->x = x;
}

void setPostoY(Posto posto, double y)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->y = y;
}

void setPostoDistancia(Posto posto, double distancia)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->distancia = distancia;
}

Ponto getPostoPonto(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    return post->ponto;
}

void setPostoPonto(Posto posto, Ponto ponto)
{
    PostoStruct* post = (PostoStruct*) posto;
    post->ponto = ponto;
}

void swapPosto(Posto posto1, Posto posto2)
{
    PostoStruct* a = (PostoStruct*) posto1;
    PostoStruct* b = (PostoStruct*) posto2;
    PostoStruct temp = *a;

    *a = *b;
    *b = temp;
}

void desalocarPontoPosto(Posto posto)
{
    PostoStruct* post = (PostoStruct*) posto;
    free(post->ponto);
    free(post);
}



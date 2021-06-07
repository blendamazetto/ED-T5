#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertice.h"

typedef struct v{

    char id[20];
    double x;
    double y;
    Ponto ponto;

}VerticeStruct;

Vertice criaVertice(char id[], double x, double y)
{
    VerticeStruct* vertice = (VerticeStruct*) malloc(sizeof(VerticeStruct));

    strcpy(vertice->id, id);
    vertice->x = x;
    vertice->y = y;
    vertice->ponto = createPonto(x, y);

    return vertice;
}

char* getVerticeId(Vertice vertice)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    return vert->id;
}

double getVerticeX(Vertice vertice)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    return vert->x;
}

double getVerticeY(Vertice vertice)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    return vert->y;
}

Ponto getVerticePonto(Vertice vertice)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    return vert->ponto;
}

void setVerticeId(Vertice vertice, char id[])
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    strcpy(vert->id, id);
}

void setVerticeX(Vertice vertice, double x)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    vert->x = x;
}

void setVerticeY(Vertice vertice, double y)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    vert->y = y;
}

void setVerticePonto(Vertice vertice, Ponto ponto)
{
    VerticeStruct* vert = (VerticeStruct*) vertice;
    vert->ponto = ponto;
}

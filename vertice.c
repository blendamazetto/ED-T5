#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vertice.h"

typedef struct v{

    char id[60];
    double x;
    double y;

}VerticeStruct;

Vertice criaVertice(char id[], double x, double y)
{
    VerticeStruct* vertice = (VerticeStruct*) malloc(sizeof(VerticeStruct));

    strcpy(vertice->id, id);
    vertice->x = x;
    vertice->y = y;

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

Vertice copiarVertice(Vertice vert)
{
    VerticeStruct* vertice = (VerticeStruct*) malloc(sizeof(VerticeStruct));
    VerticeStruct* ver = (VerticeStruct*) vert;

    strcpy(vertice->id, ver->id);
    vertice->x = ver->x;
    vertice->y = ver->y;

    return vertice;
}

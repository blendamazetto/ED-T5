#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aresta.h"

typedef struct a{

    char i[60];
    char j[60];
    char ldir[60];
    char lesq[60];
    double cmp;
    double vm;
    char nomeRua[200];

}ArestaStruct;

Aresta criaAresta(char i[], char j[], char ldir[], char lesq[], double cmp, double vm, char nomeRua[])
{
    ArestaStruct* aresta = (ArestaStruct*) malloc(sizeof(ArestaStruct));

    strcpy(aresta->i, i);
    strcpy(aresta->j, j);
    strcpy(aresta->ldir, ldir);
    strcpy(aresta->lesq, lesq);
    aresta->cmp = cmp;
    aresta->vm = vm;
    strcpy(aresta->nomeRua, nomeRua);

    return aresta;
}

char* getArestaI(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->i;
}

char* getArestaJ(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->j;
}

char* getArestaLdir(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->ldir;
}

char* getArestaLesq(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->lesq;
}

char* getArestaNomeRua(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->nomeRua;
}

double getArestaCmp(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->cmp;
}

double getArestaVm(Aresta aresta)
{
    ArestaStruct* ares = (ArestaStruct*) aresta;
    return ares->vm;
}

void setArestaI(Aresta aresta, char i[])
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    strcpy(are->i, i);
}

void setArestaJ(Aresta aresta, char j[])
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    strcpy(are->j, j);
}

void setArestaLdir(Aresta aresta, char ldir[])
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    strcpy(are->ldir, ldir);
}

void setArestaLesq(Aresta aresta, char lesq[])
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    strcpy(are->lesq, lesq);
}

void setArestaNomeRua(Aresta aresta, char nomeRua[])
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    strcpy(are->nomeRua, nomeRua);
}

void setArestaCmp(Aresta aresta, double cmp)
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    are->cmp = cmp;
}

void setArestaVm(Aresta aresta, double vm)
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    are->vm = vm;
}

double getArestaTempo(Aresta aresta)
{
    ArestaStruct* are = (ArestaStruct*) aresta;
    if(are->vm == 0)
    {
        return are->cmp;
    }
    return are->cmp/are->vm;
}

Aresta copiarAresta(Aresta aresta)
{
    ArestaStruct* arest = (ArestaStruct*) malloc(sizeof(ArestaStruct));
    ArestaStruct* are = (ArestaStruct*) aresta;

    strcpy(arest->i, are->i);
    strcpy(arest->j, are->j);
    strcpy(arest->ldir, are->ldir);
    strcpy(arest->lesq, are->lesq);
    arest->cmp = are->cmp;
    arest->vm = are->vm;
    strcpy(arest->nomeRua, are->nomeRua);

    return arest;
}
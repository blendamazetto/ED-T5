#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "casos.h"

typedef struct c{

    int n;
    double x;
    double y;
    double num;
    char cep[22];
    char face[10];
    Ponto ponto;

}CasosStruct;

Casos criaCasos(int n, double x, double y, char face[], double num, char cep[])
{
    CasosStruct* casos = (CasosStruct*) malloc(sizeof(CasosStruct));
    casos->n = n;
    casos->x = x;
    casos->y = y;
    casos->num = num;
    strcpy(casos->cep, cep);
    strcpy(casos->face, face);
    casos->ponto = createPonto(x, y);

    return casos;
}

int getCasosN(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->n;
}

double getCasosX(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->x;
}

double getCasosY(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->y;
}

double getCasosNum(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->num;
}

char* getCasosCEP(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->cep;
}

char* getCasosFace(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->face;
}

Ponto getCasosPonto(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;
    return c->ponto;
}

void swapCasos(Casos *p1, Casos *p2)
{  
    CasosStruct* a = (CasosStruct*) p1;
    CasosStruct* b = (CasosStruct*) p2;
    CasosStruct temp = *a;  

    *a = *b;  
    *b = temp;  
}

void desalocarPontoCasos(Casos casos)
{
    CasosStruct* c = (CasosStruct*) casos;

    free(c->ponto);
    free(c);
}



#include <stdio.h>
#include <stdlib.h>
#include "ponto.h"

typedef struct ponto
{
    double x;
    double y;
    
}PontoStruct;

Ponto createPonto(double x, double y)
{
    PontoStruct* ponto = (PontoStruct*)malloc(sizeof(PontoStruct));
    ponto->x = x;
    ponto->y = y;
    return ponto;
}

double getPontoX(Ponto ponto)
{
    PontoStruct* p = (PontoStruct*) ponto;
    return p->x;
}

double getPontoY(Ponto ponto)
{
    PontoStruct* p = (PontoStruct*) ponto;
    return p->y;
}

void setPontoX(Ponto ponto, double x)
{
    PontoStruct* p = (PontoStruct*) ponto;
    p->x = x;
}

void setPontoY(Ponto ponto, double y)
{
    PontoStruct* p = (PontoStruct*) ponto;
    p->y = y;
}

void swapPonto(Ponto p1, Ponto p2)
{
    PontoStruct* a = (PontoStruct*) p1;
    PontoStruct* b = (PontoStruct*) p2;
    PontoStruct temp = *a;
    *a = *b;
    *b = temp;
}

void atribuirPonto(Ponto *p1, Ponto *p2)
{  
    PontoStruct* a = (PontoStruct*) p1;
    PontoStruct* b = (PontoStruct*) p2;
    *a = *b;  
}

double getPontoDist(Ponto pont, double x, double y) 
{
    PontoStruct* ponto = (PontoStruct*) pont;
    return distancia(ponto->x, ponto->y, x, y);
}

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "circulo.h"

typedef struct c{

    char i[20];
    double r;
    double x;
    double y;
    char sw[20];
    char corb[20];
    char corp[20];
    Ponto ponto;

}CirculoStruct;

Circulo criaCirculo(char i[], double r, double x, double y, char sw[], char corb[], char corp[])
{
    CirculoStruct* circulo = (CirculoStruct*) malloc(sizeof(CirculoStruct));

    strcpy(circulo->i, i);
    circulo->x = x;
    circulo->y = y;
    circulo->r = r;
    strcpy(circulo->sw, sw);
    strcpy(circulo->corb, corb);
    strcpy(circulo->corp, corp);
    circulo->ponto = createPonto(x, y);

    return circulo;
}

char* getCirculoI(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->i;
}

double getCirculoR(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->r;
}

double getCirculoX(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->x;
}

double getCirculoY(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->y;
}

char* getCirculoSw(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->sw;
}

char* getCirculoCorb(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->corb;
}

char* getCirculoCorp(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->corp;
}

Ponto getCirculoPonto(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    return circ->ponto;
}

void setCirculoI(Circulo circulo, char i[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->i, i);
}

void setCirculoR(Circulo circulo, double r)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->r = r;
}

void setCirculoX(Circulo circulo, double x)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->x = x;
}

void setCirculoY(Circulo circulo, double y)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->y = y;
}

void setCirculoSw(Circulo circulo, char sw[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->sw, sw);
}

void setCirculoCorb(Circulo circulo, char corb[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->corb, corb);
}

void setCirculoCorp(Circulo circulo, char corp[])
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    strcpy(circ->corp, corp);
}

void setCirculoPonto(Circulo circulo, Ponto ponto)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;
    circ->ponto = ponto;
}

void swapCirculo(Circulo c1, Circulo c2)
{
    CirculoStruct* a = (CirculoStruct*) c1;
    CirculoStruct* b = (CirculoStruct*) c2;
    CirculoStruct temp = *a;

    *a = *b;
    *b = temp;
}

void desalocarPontoCirculo(Circulo circulo)
{
    CirculoStruct* circ = (CirculoStruct*) circulo;

    free(circ->ponto);
    free(circ);
}



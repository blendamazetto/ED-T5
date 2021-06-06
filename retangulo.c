#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "retangulo.h"

typedef struct r{

    char i[20];
    double w;
    double h;
    double x;
    double y;
    char sw[20];
    char corb[20];
    char corp[20];
    Ponto ponto;

}RetanguloStruct;

Retangulo criaRetangulo(char i[], double w, double h, double x, double y, char sw[], char corb[], char corp[])
{
    RetanguloStruct* retangulo = (RetanguloStruct*) malloc(sizeof(RetanguloStruct));

    strcpy(retangulo->i, i);
    retangulo->x = x;
    retangulo->y = y;
    retangulo->w = w;
    retangulo->h = h;
    strcpy(retangulo->sw, sw);
    strcpy(retangulo->corb, corb);
    strcpy(retangulo->corp, corp);
    retangulo->ponto = createPonto(x,y);

    return retangulo;
}

char* getRetanguloI(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->i;
}

double getRetanguloW(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->w;
}

double getRetanguloH(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->h;
}

double getRetanguloX(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->x;
}

double getRetanguloY(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->y;
}

char* getRetanguloSw(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->sw;
}

char* getRetanguloCorb(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->corb;
}

char* getRetanguloCorp(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->corp;
}

void setRetanguloI(Retangulo retangulo, char i[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->i, i);
}

void setRetanguloW(Retangulo retangulo, double w)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->w = w;
}

void setRetanguloH(Retangulo retangulo, double h)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->h = h;
}

void setRetanguloX(Retangulo retangulo, double x)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->x = x;
}

void setRetanguloY(Retangulo retangulo, double y)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->y = y;
}

void setRetanguloSw(Retangulo retangulo, char sw[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->sw, sw);
}

void setRetanguloCorb(Retangulo retangulo, char corb[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->corb, corb);
}

void setRetanguloCorp(Retangulo retangulo, char corp[])
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    strcpy(ret->corp, corp);
}

Ponto getRetanguloPonto(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    return ret->ponto;
}

void setRetanguloPonto(Retangulo retangulo, Ponto ponto)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    ret->ponto = ponto;
}

void swapRetangulo(Retangulo retangulo1, Retangulo retangulo2)
{
    RetanguloStruct* a = (RetanguloStruct*) retangulo1;
    RetanguloStruct* b = (RetanguloStruct*) retangulo2;
    RetanguloStruct temp = *a;

    *a = *b;
    *b = temp;
}

void desalocaRetangulo(Retangulo retangulo)
{
    RetanguloStruct* ret = (RetanguloStruct*) retangulo;
    
    free(ret->ponto);
    free(ret);
}



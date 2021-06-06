#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "densidade.h"

typedef struct d{

    double x;
    double y;
    double w;
    double h;
    double d;
    Ponto ponto;

}DensidadeStruct;

Densidade criaDensidade(double x, double y, double w, double h, double d)
{
    DensidadeStruct* densidade = (DensidadeStruct*) malloc(sizeof(DensidadeStruct));
    densidade->x = x;
    densidade->y = y;
    densidade->w = w;
    densidade->h = h;
    densidade->d = d;
    densidade->ponto = createPonto(x, y);

    return densidade;
}

double getDensidadeX(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    return densi->x;
}

double getDensidadeY(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    return densi->y;
}

double getDensidadeW(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    return densi->w;
}

double getDensidadeH(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    return densi->h;
}

double getDensidadeD(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    return densi->d;
}

void setDensidadeX(Densidade densidade, double x)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    densi->x = x;
}

void setDensidadeY(Densidade densidade, double y)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    densi->y = y;
}

void setDensidadeW(Densidade densidade, double w)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    densi->w = w;
}

void setDensidadeH(Densidade densidade, double h)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    densi->h = h;
}

void setDensidadeD(Densidade densidade, double d)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    densi->d = d;
}

Ponto getDensidadePonto(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    return densi->ponto;
}

void setDensidadePonto(Densidade densidade, Ponto ponto)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;
    densi->ponto = ponto;
}

void desalocarPontosDensidade(Densidade densidade)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;

    if(densi == NULL)
    {
        return;
    }

    free(densi->ponto);
    free(densi);
}

void densidadeQuadras(Densidade densidade, QuadTree quadras)
{
    DensidadeStruct* densi = (DensidadeStruct*) densidade;

    Lista list = nosDentroRetanguloQt(quadras, getPontoX(densi->ponto), getPontoY(densi->ponto), getPontoX(densi->ponto) + densi->w, getPontoY(densi->ponto) + densi->h);

    for(No node = getFirst(list); node != NULL; node = getNext(node))
    {
        setQuadraDensidade(getInfoQt(quadras,getInfo(node)),densi->d);
    }
    removeList(list, NULL);
}
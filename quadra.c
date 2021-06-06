#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadra.h"

typedef struct q{

    char cep[20];
    double x;
    double y;
    double w;
    double h;
    double densidade;
    char sw[20];
    char cfill[20];
    char cstrk[20];
    Ponto ponto;

}QuadraStruct;

Quadra criaQuadra(char cep[], double x, double y, double w, double h, char sw[], char cfill[], char cstrk[])
{
    QuadraStruct* quadra = (QuadraStruct*) malloc(sizeof(QuadraStruct));

    strcpy(quadra->cep, cep);
    quadra->x = x;
    quadra->y = y;
    quadra->w = w;
    quadra->h = h;
    quadra->densidade = 0;
    strcpy(quadra->sw, sw);
    strcpy(quadra->cfill, cfill);
    strcpy(quadra->cstrk, cstrk);
    quadra->ponto = createPonto(x,y);
    
    return quadra;
}

char* getQuadraCep(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cep;
}

double getQuadraX(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->x;
}

double getQuadraY(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->y;
}

double getQuadraW(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->w;
}

double getQuadraH(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->h;
}

char* getQuadraSw(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->sw;
}

char* getQuadraCfill(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cfill;
}

char* getQuadraCstrk(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->cstrk;
}

void setQuadraCep(Quadra quadra, char cep[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cep, cep);

}

void setQuadraX(Quadra quadra, double x)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->x = x;
}

void setQuadraY(Quadra quadra, double y)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->y = y;
}

void setQuadraW(Quadra quadra, double w)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->w = w;
}

void setQuadraH(Quadra quadra, double h)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->h = h;
}

void setQuadraSw(Quadra quadra, char sw[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->sw, sw);
}

void setQuadraCfill(Quadra quadra, char cfill[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cfill, cfill);
}

void setQuadraCstrk(Quadra quadra, char cstrk[])
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    strcpy(quad->cstrk, cstrk);
}

double getQuadraDensidade(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->densidade;
}

void setQuadraDensidade(Quadra quadra, double densidade)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->densidade = densidade;
}

Ponto getQuadraPonto(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    return quad->ponto;
}

void setQuadraPonto(Quadra quadra, Ponto ponto)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    quad->ponto = ponto;
}

void swapQuadra(Quadra q1, Quadra q2)
{
    QuadraStruct* a = (QuadraStruct*) q1;
    QuadraStruct* b = (QuadraStruct*) q2;
    QuadraStruct temp = *a;

    *a = *b;
    *b = temp;
}

void desalocaQuadra(Quadra quadra)
{
    QuadraStruct* quad = (QuadraStruct*) quadra;
    
    free(quad->ponto);
    free(quad);
}







#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hidrante.h"

typedef struct h{

    char id[20];
    double x;
    double y;
    char sw[20];
    char cfill[20];
    char cstrk[20];
    Ponto ponto;

}HidranteStruct;

Hidrante criaHidrante(char id[], double x, double y, char sw[], char cfill[], char cstrk[])
{
    HidranteStruct* hidrante = (HidranteStruct*) malloc(sizeof(HidranteStruct));

    strcpy(hidrante->id, id);
    hidrante->x = x;
    hidrante->y = y;
    strcpy(hidrante->sw, sw);
    strcpy(hidrante->cfill, cfill);
    strcpy(hidrante->cstrk, cstrk);
    hidrante->ponto = createPonto(x,y);
    
    return hidrante;
}

char* getHidranteId(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->id;
}

double getHidranteX(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->x;
}

double getHidranteY(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->y;
}

char* getHidranteSw(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->sw;
}

char* getHidranteCfill(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->cfill;
}

char* getHidranteCstrk(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->cstrk;
}

void setHidranteId(Hidrante hidrante, char id[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->id, id);
}

void setHidranteX(Hidrante hidrante, double x)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->x = x;
}

void setHidranteY(Hidrante hidrante, double y)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->y = y;
}

void setHidranteSw(Hidrante hidrante, char sw[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->sw, sw);
}

void setHidranteCfill(Hidrante hidrante, char cfill[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->cfill, cfill);
}

void setHidranteCstrk(Hidrante hidrante, char cstrk[])
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    strcpy(hid->cstrk, cstrk);
}

Ponto getHidrantePonto(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    return hid->ponto;
}

void setHidrantePonto(Hidrante hidrante, Ponto ponto)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    hid->ponto = ponto;
}

void swapHidrante(Hidrante hidrante1, Hidrante hidrante2)
{
    HidranteStruct* a = (HidranteStruct*) hidrante1;
    HidranteStruct* b = (HidranteStruct*) hidrante2;
    HidranteStruct temp = *a;

    *a = *b;
    *b = temp;
}

void desalocarPontoHidrante(Hidrante hidrante)
{
    HidranteStruct* hid = (HidranteStruct*) hidrante;
    free(hid->ponto);
    free(hid);
}

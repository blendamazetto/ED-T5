#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "texto.h"

typedef struct t{

    char i[20];
    double x;
    double y;
    char corb[20];
    char corp[20];
    char texto[1000];
    Ponto ponto;

}TextoStruct;

Texto criaTexto(char i[], double x, double y, char corb[], char corp[], char texto[])
{
    TextoStruct* text = (TextoStruct*) malloc(sizeof(TextoStruct));

    strcpy(text->i, i);
    text->x = x;
    text->y = y;
    strcpy(text->corb, corb);
    strcpy(text->corp, corp);
    strcpy(text->texto, texto);
    text->ponto = createPonto(x, y);

    return text;
}

char* getTextoI(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->i;
}

double getTextoX(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->x;
}

double getTextoY(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->y;
}

char* getTextoCorb(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->corb;
}

char* getTextoCorp(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->corp;
}

char* getTextoTxto(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->texto;
}

void setTextoI(Texto texto, char i[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->i, i);

}

void setTextoX(Texto texto, double x)
{
    TextoStruct* text = (TextoStruct*) texto;
    text->x = x;
}

void setTextoY(Texto texto, double y)
{
    TextoStruct* text = (TextoStruct*) texto;
    text->y = y;
}

void setTextoCorb(Texto texto, char corb[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->corb, corb);
}

void setTextoCorp(Texto texto, char corp[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->corp, corp);
}

void setTextoTxto(Texto texto, char txto[])
{
    TextoStruct* text = (TextoStruct*) texto;
    strcpy(text->texto, txto);
}

Ponto getTextoPonto(Texto texto)
{
    TextoStruct* text = (TextoStruct*) texto;
    return text->ponto;
}

void setTextoPonto(Texto texto, Ponto ponto)
{
    TextoStruct* text = (TextoStruct*) texto;
    text->ponto = ponto;
}

void swapTexto(Texto t1, Texto t2)
{
    TextoStruct* a = (TextoStruct*) t1;
    TextoStruct* b = (TextoStruct*) t2;
    TextoStruct temp = *a;
    *a = *b;
    *b = temp;
}

void desalocaTexto(Texto txt)
{
    TextoStruct* texto = (TextoStruct*) txt;
    
    free(texto->ponto);
    free(texto);
}




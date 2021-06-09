#ifndef __ARESTA_H
#define __ARESTA_H

typedef void* Aresta;

Aresta criaAresta(char i[], char j[], char ldir[], char lesq[], double cmp, double vm, char nomeRua[]);

char* getArestaI(Aresta aresta);

char* getArestaJ(Aresta aresta);

char* getArestaLdir(Aresta aresta);

char* getArestaLesq(Aresta aresta);

char* getArestaNomeRua(Aresta aresta);

double getArestaCmp(Aresta aresta);

double getArestaVm(Aresta aresta);

void setArestaI(Aresta aresta, char i[]);

void setArestaJ(Aresta aresta, char j[]);

void setArestaLdir(Aresta aresta, char ldir[]);

void setArestaLesq(Aresta aresta, char lesq[]);

void setArestaNomeRua(Aresta aresta, char nomeRua[]);

void setArestaCmp(Aresta aresta, double cmp);

void setArestaVm(Aresta aresta, double vm);

Aresta copiarAresta(Aresta aresta);

#endif
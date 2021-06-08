#ifndef __VERTICE_H
#define __VERTICE_H

typedef void* Vertice;

Vertice criaVertice(char id[], double x, double y);

char* getVerticeId(Vertice vertice);

double getVerticeX(Vertice vertice);

double getVerticeY(Vertice vertice);

void setVerticeId(Vertice vertice, char id[]);

void setVerticeX(Vertice vertice, double x);

void setVerticeY(Vertice vertice, double y);

#endif
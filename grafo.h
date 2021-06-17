#ifndef __GRAFO_H
#define __GRAFO_H

#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "quadtree.h"
#include "qry.h"
#include <stdio.h>

typedef void* Grafo;

Grafo createGrafo();

void adicionarVertice(Grafo grafo, Vertice vertice);

void adicionarAresta(Grafo grafo, char i[], char j[], Aresta aresta);

Vertice encontrarVerticeMaisProximo(Grafo grafo, Ponto ponto);

Vertice getVertice(Grafo grafo, char id[]);

char* getVerticebyPonto(Grafo grafo, double x, double y);

Aresta getAresta(Grafo grafo, char i[], char j[]);

No getNodeAdjacencia(Grafo grafo, char i[], char j[]);

void removerAresta(Grafo grafo, char i[], char j[]);

void removerArestabyLdir(Grafo grafo, char ldir[]);

void removerArestabyLesq(Grafo grafo, char lesq[]);

void removerVerticesDentroCirculo(Grafo grafo, double x, double y, double r);

void desalocarNodeAdjacencia(No node);

void desalocarVertice(No node);

void desalocarGrafo(Grafo grafo);

void removerVertice(Grafo grafo, char id[]);

void printarGrafo(Grafo grafo, FILE *svg, char cor[]);

Grafo algoritmoPrim(Grafo grafo, int tam);

Lista dijsktraCMP(Grafo grafo, char inicial[], char fim[], int tam);

Lista dijsktraVM(Grafo grafo, char inicial[], char fim[], int tam);

#endif
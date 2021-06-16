#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "ponto.h"
#include "quadtree.h"

#ifndef __GRAFO_H
#define __GRAFO_H

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

void desalocarNodeAdjacencia(No node);

void desalocarVertice(No node);

void desalocarGrafo(Grafo grafo);

void removerVertice(Grafo grafo, char id[]);

void printarGrafo(Grafo grafo, FILE *svg, char cor[]);

Grafo algoritmoPrim(Grafo grafo, int tam);

Lista dijsktraCMP(Grafo grafo, char inicial[], char fim[], int tam);

Lista dijsktraVM(Grafo grafo, char inicial[], char fim[], int tam);

#endif
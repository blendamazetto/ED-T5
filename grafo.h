#include "vertice.h"
#include "aresta.h"
#include "lista.h"

#ifndef __GRAFO_H
#define __GRAFO_H

typedef void* Grafo;

Grafo createGrafo();

void adicionarVertice(Grafo grafo, Vertice vertice);

void adicionarAresta(Grafo grafo, char i[], char j[], Aresta aresta);

Vertice getVertice(Grafo grafo, char id[]);

Aresta getAresta(Grafo grafo, char i[], char j[]);

No getNodeAdjacencia(Grafo grafo, char i[], char j[]);

void removerAresta(Grafo grafo, char i[], char j[]);

void desalocarNodeAdjacencia(No node);

void desalocarVertice(No node);

void desalocarGrafo(Grafo grafo);

void removerVertice(Grafo grafo, char id[]);

void printarGrafo(Grafo grafo, FILE *svg);

Grafo algoritmoPrim(Grafo grafo, int tam);

#endif
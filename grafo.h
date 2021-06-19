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

void removerBf(Grafo grafo, char face[], char cep[]);

Grafo copiarGrafo(Grafo grafo);

void removerVerticeDesconexo(Grafo grafo);

void removerVerticesDentroPoligono(Grafo grafo, Lista casos);

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

Lista dijsktra(Grafo grafo, char inicial[], char fim[], int tam, double getPeso(Aresta aresta));

Lista getListaAdjacencia(Grafo grafo, char id[]);

#endif
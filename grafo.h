#ifndef __GRAFO_H
#define __GRAFO_H

#include "vertice.h"
#include "aresta.h"
#include "lista.h"
#include "quadtree.h"
#include "qry.h"
#include <stdio.h>

typedef void* Grafo;

/*
    Cria um grafo
*/
Grafo createGrafo();

/*
    Funcao utilizado no comando bf, percorre o grafo analisando as arestas
    analisa a face da quadra, a orientacao da aresta e a quadra a direita ou a esquerda
*/
void removerBf(Grafo grafo, char face[], char cep[]);

/*
    cria um novo grafo com as informacoes do grafo passado como parametro, é usada na funcao sp?
*/
Grafo copiarGrafo(Grafo grafo);

/*
    Remove todos os vertice que não possuem arestas
*/
void removerVerticeDesconexo(Grafo grafo);

/*
    Funcao utilizada no comando "sp?"
    percorre o grafo e verifica cada vertice para ver se ele esta dentro da envoltoria ou nao
    caso o vertice esteja na envoltoria, ele é removido
*/
void removerVerticesDentroPoligono(Grafo grafo, Lista casos);

/*
    adiciona um vertice a um grafo
*/
void adicionarVertice(Grafo grafo, Vertice vertice);

/*
    adiciona uma aresta a um grafo
*/
void adicionarAresta(Grafo grafo, char i[], char j[], Aresta aresta);

/*
    Utilizado nos comandos de armazenar pontos em registradores
    o ponto dado nem sempre corresponde a um pondo do grafo, esse funcao encontra o ponto mais proximo
*/
Vertice encontrarVerticeMaisProximo(Grafo grafo, Ponto ponto);

/*
    retorna um vertice atraves de um id
*/
Vertice getVertice(Grafo grafo, char id[]);

/*
    retorna uma aresta atraves de seu id inicial e final
*/
Aresta getAresta(Grafo grafo, char i[], char j[]);

/*
    utilizada no comando catac, remove todos os vertices dentro do circulo x, y, r
*/
void removerVerticesDentroCirculo(Grafo grafo, double x, double y, double r);

/*
    desaloca um grafo, todas as suas arestas e todos os seus vertices
*/
void desalocarGrafo(Grafo grafo);

/*
    remove um vertice
*/
void removerVertice(Grafo grafo, char id[]);

/*
    escreve um grafo no svg
*/
void printarGrafo(Grafo grafo, FILE *svg, char cor[]);

/*
    Algoritmo de Prim para a arvore geradora minima
*/
Grafo algoritmoPrim(Grafo grafo, int tam);

/*
    Algoritmo de dijsktra para encontrar o menor caminho entre dois vertices
    recebe um funcao definindo o peso que sera usado
    caso receba a funcao "getArestaCmp" ele fara os calculos com base no comprimento da aresta
    caso receba a funcao "getTempo" ele fara os calculos com base no menor tempo para de percorre uma aresta
*/
Lista dijsktra(Grafo grafo, char inicial[], char fim[], int tam, double getPeso(Aresta aresta));

#endif
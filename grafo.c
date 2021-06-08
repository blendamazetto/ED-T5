#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"

typedef struct adjc{
    Vertice vertice;
    Lista adjacencia;
}NodeGrafoStruct;

typedef struct adj{
    Aresta aresta;
    char j[20];
}NodeAdjacenciaStruct;

Grafo createGrafo()
{
    return create();
}

void adicionarVertice(Grafo grafo, Vertice vertice)
{
    NodeGrafoStruct* no = (NodeGrafoStruct*)malloc(sizeof(NodeGrafoStruct));
    no->vertice = vertice;
    no->adjacencia = create();
    insert(grafo, no);
}

void adicionarAresta(Grafo grafo, char i[], char j[], Aresta aresta)
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(strcmp(getVerticeId(no->vertice), i) == 0)
        {
            NodeAdjacenciaStruct* noAdj = (NodeAdjacenciaStruct*)malloc(sizeof(NodeAdjacenciaStruct));
            noAdj->aresta = aresta;
            strcpy(noAdj->j, j);
            insert(no->adjacencia, noAdj);
        }
    }
}

Vertice getVertice(Grafo grafo, char id[])
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(strcmp(getVerticeId(no->vertice), id) == 0)
        {
            return no->vertice;
        }
    }
    return NULL;
}

Aresta getAresta(Grafo grafo, char i[], char j[])
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(strcmp(getVerticeId(no->vertice), i) == 0)
        {
            for(No noAdj = getFirst(no->adjacencia); noAdj!= NULL; noAdj = getNext(noAdj))
            {
                NodeAdjacenciaStruct* aux = getInfo(noAdj);
                if(strcmp(aux->j, j) == 0)
                {
                    return aux->aresta;
                }
            }
        }
    }
    return NULL;
}

No getNodeAdjacencia(Grafo grafo, char i[], char j[])
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(strcmp(getVerticeId(no->vertice), i) == 0)
        {
            for(No noAdj = getFirst(no->adjacencia); noAdj!= NULL; noAdj = getNext(noAdj))
            {
                NodeAdjacenciaStruct* aux = getInfo(noAdj);
                if(strcmp(aux->j, j) == 0)
                {
                    return node;
                }
            }
        }
    }
    return NULL;
}

void removerAresta(Grafo grafo, char i[], char j[])
{
    No node = getNodeAdjacencia(grafo, i, j);
    NodeAdjacenciaStruct* aux = getInfo(node);
    free(aux->aresta);
    removerNo(grafo, node, NULL);
}

void printarGrafo(Grafo grafo, FILE *svg)
{
    double x1, y1, x2, y2;
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))       
    {
        NodeGrafoStruct* no = getInfo(node);
        x1 = getVerticeX(no->vertice);
        y1 = getVerticeY(no->vertice);

        fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", x1, y1, 5.0, "black", "black");

        for(No noAdj = getFirst(no->adjacencia); noAdj!= NULL; noAdj = getNext(noAdj))
        {
            NodeAdjacenciaStruct* aux = getInfo(noAdj);
            x2 = getVerticeX(getVertice(grafo, aux->j));
            y2 = getVerticeY(getVertice(grafo, aux->j));
        
            fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, "black");
        }
    }
}
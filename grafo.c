#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "hashtable.h"

typedef struct adjc{
    Vertice vertice;
    Lista adjacencia;
}NodeGrafoStruct;

typedef struct adj{
    Aresta aresta;
    char j[60];
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
    free(aux);
    removerNo(grafo, node, NULL);
}

void desalocarNodeAdjacencia(No node)
{
    NodeAdjacenciaStruct* aux = (NodeAdjacenciaStruct*) node;
    free(aux->aresta);
    free(aux);
}

void desalocarVertice(No node)
{
    NodeGrafoStruct* no = (NodeGrafoStruct*) node;
    removeList(no->adjacencia, desalocarNodeAdjacencia);
    free(no->vertice);
    free(no);
}

void desalocarGrafo(Grafo grafo)
{
    removeList(grafo, desalocarVertice);
}

No getNodeGrafo(Grafo grafo, char id[])
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(strcmp(getVerticeId(no->vertice), id) == 0)
        {
            return node;
        }
    }
    return NULL;
}

void removerVertice(Grafo grafo, char id[])
{
    No node  = getNodeGrafo(grafo, id);
    if(node == NULL)
    {
        return;
    }
    NodeGrafoStruct* no = getInfo(node);
    if(strcmp(getVerticeId(no->vertice), id) == 0)
    {
        desalocarVertice(no);
        removerNo(grafo, node, NULL);
    }
}

Vertice getVerticebyNo(No node)
{
    NodeGrafoStruct* no = (NodeGrafoStruct*) node;
    return no->vertice;
}

Aresta getArestabyNo(No node)
{
    NodeAdjacenciaStruct* aux = (NodeAdjacenciaStruct*) node;
    return aux->aresta;
}

char* getDestino(No node)
{
    NodeAdjacenciaStruct* aux = (NodeAdjacenciaStruct*) node;
    return aux->j;
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
            if(getVertice(grafo, aux->j) != NULL)
            {
                x2 = getVerticeX(getVertice(grafo, aux->j));
                y2 = getVerticeY(getVertice(grafo, aux->j));
                fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, "black");
            }
        }
    }
}

Grafo algoritmoPrim(Grafo grafo, int tam)
{
    Hash visitado = createHashTable(tam);
    Grafo arvoreMinima = createGrafo();
    Vertice vertice;
    int primeiro = 1;
    double menor;
    char info[2] = "0";
    char inicial[100], final[100];
    Aresta aresta;
    NodeGrafoStruct* no;
    char destino[100];
    Vertice verticeAux;

    for(No node = getFirst(grafo); node != NULL; node = getNext(node))
    {
        no = getInfo(node);
        adicionarVertice(arvoreMinima, copiarVertice(no->vertice));
    }

    vertice = getVerticebyNo(getInfo(getFirst(grafo)));
    insertHashTable(info, getVerticeId(vertice), tam, visitado);
    
    while(1)
    {
        primeiro = 1;
        for(No i = getFirst(grafo); i != NULL; i = getNext(i))
        {
            NodeGrafoStruct* al = getInfo(i);
            vertice = al->vertice;

            if(searchHashTable(getVerticeId(vertice), visitado, tam) != NULL)
            {
                for(No j = getFirst(al->adjacencia); j != NULL; j = getNext(j))
                {
                    NodeAdjacenciaStruct* aux = getInfo(j);
                    strcpy(destino, aux->j);
                    verticeAux = getVertice(grafo, destino);

                    if(searchHashTable(getVerticeId(verticeAux), visitado, tam) == NULL)
                    {
                        if(primeiro)
                        {
                            strcpy(inicial, getVerticeId(vertice));
                            aresta = getArestabyNo(getInfo(j));
                            strcpy(final, getDestino(getInfo(j)));
                            menor = getArestaCmp(aresta);
                            primeiro = 0;
                        }
                        else if(menor > getArestaCmp(getArestabyNo(getInfo(j))))
                        {  
                            strcpy(inicial, getVerticeId(vertice));
                            aresta = getArestabyNo(getInfo(j));
                            strcpy(final, getDestino(getInfo(j)));
                            menor = getArestaCmp(aresta);
                        } 
                    }
                }
            }
        }
        if (primeiro)
        {   
            break;
        }
        adicionarAresta(arvoreMinima, inicial, final, copiarAresta(aresta));
        adicionarAresta(arvoreMinima, final, inicial, copiarAresta(aresta));
        insertHashTable(info, final, tam, visitado);
    }
    deleteHashTable(visitado, tam, 0);
    return arvoreMinima;
}


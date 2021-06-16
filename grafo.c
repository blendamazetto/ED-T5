#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "grafo.h"
#include "hashtable.h"
#include <math.h>

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

Vertice encontrarVerticeMaisProximo(Grafo grafo, Ponto ponto)
{
    double x1, y1, x2, y2, menorDist = 9999, dist;
    Vertice verticeEncontrado;

    x1 = getPontoX(ponto);
    y1 = getPontoY(ponto);

    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        x2 = getVerticeX(no->vertice);
        y2 = getVerticeY(no->vertice);

        dist = sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));

        if(dist < menorDist)
        {
            menorDist = dist;
            verticeEncontrado = no->vertice;
        }
    }
    return verticeEncontrado;
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

char* getVerticebyPonto(Grafo grafo, double x, double y)
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(getVerticeX(no->vertice) == x && getVerticeY(no->vertice) == y)
        {
            return getVerticeId(no->vertice);
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

void printarGrafo(Grafo grafo, FILE *svg, char cor[])
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
                fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cor);
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

int getPosicaoDoVertice(Grafo grafo, char id[])
{
    int cont = 0;
    for(No i = getFirst(grafo); i != NULL; i = getNext(i))
    {
        NodeGrafoStruct* al = getInfo(i);
        if(strcmp(getVerticeId(al->vertice), id) == 0)
        {
            return cont;
        }
        cont++;
    }
    return 0;
}

char* getIdPorPosicao(Grafo grafo, int i, char id[])
{
    int cont = 0;
    for(No ij = getFirst(grafo); ij != NULL; ij = getNext(ij))
    {
        NodeGrafoStruct* aux = getInfo(ij);
        if(strcmp(id, getVerticeId(aux->vertice)) == 0)
        {
            for(No ih = getFirst(aux->adjacencia); ih != NULL; ih = getNext(ih))
            {
                if(cont == i)
                {
                    NodeAdjacenciaStruct* nas = getInfo(ih);
                    return nas->j;
                }
                cont++;
            }
        }
    }
    return NULL;
}

char* getIdPorPosicaoVertice(Grafo grafo, int i)
{
    int cont = 0;
    for(No ij = getFirst(grafo); ij != NULL; ij = getNext(ij))
    {
        NodeGrafoStruct* aux = getInfo(ij);
        if(cont == i)
        {
            return getVerticeId(aux->vertice);
        }
        cont++;     
    }
    return NULL;
}

Vertice getVerticebyPosicao(Grafo grafo, int i)
{
    int cont = 0;
    for(No node = getFirst(grafo); node != NULL; node = getNext(node))
    {
        NodeGrafoStruct* aux = getInfo(node);
        if(cont == i)
        {
            return aux->vertice;
        }
        cont++;     
    }
    return NULL;
}

int indiceMenorDistancia(Hash hashtable, double *distancia, int tam, Grafo grafo)
{
    int indice = -1;
    double menorDistancia = 10000.0;
    char id[60];

    for(int i = 0; i < tam; i++)
    {
        strcpy(id, getIdPorPosicaoVertice(grafo, i));
        if(searchHashTable(id, hashtable, tam) == NULL)
        {
            if(menorDistancia >= distancia[i])
            {
                menorDistancia = distancia[i];
                indice = i;
            }
        }
    }
    return indice;
}

Lista dijsktraCMP(Grafo grafo, char inicial[], char fim[], int tam)
{
    Hash visitado = createHashTable(tam);
    Lista pathInvertido = create();
    Lista path = create();
    Vertice vertice = getVertice(grafo, inicial), verticeAux;
    Aresta aresta, arestaAux;
    No nodeVertice;
    NodeAdjacenciaStruct* aux;
    int anterior[tam], primeiro = 1, contador = 0, loop = 1, idAnt;
    double distancia[tam], menor, dist = 9999, distAtual = 0, distAux;
    char info[2] = "0", final[100], destino[100], buscaAux[60], idAnterior[60], start[60];
    strcpy(buscaAux, fim);
    strcpy(idAnterior, fim);
    strcpy(start, inicial);

    for(int a = 0; a < tam; a++)
    {
        anterior[a] = -1;
        distancia[a] = dist;
    }
    
    while(loop > 0)
    {
        primeiro = 1;
        nodeVertice = getNodeGrafo(grafo, getVerticeId(vertice));
        NodeGrafoStruct* al = getInfo(nodeVertice);

        for(No j = getFirst(al->adjacencia); j != NULL; j = getNext(j))
        {   
            aux = getInfo(j);
            strcpy(destino, aux->j);
            verticeAux = getVertice(grafo, destino);

            if(searchHashTable(getVerticeId(verticeAux), visitado, tam) == NULL)
            {
                if(primeiro)
                {
                    inicial =  getVerticeId(vertice);
                    aresta = getArestabyNo(getInfo(j));
                    strcpy(final, getDestino(getInfo(j)));
                    menor = getArestaCmp(aresta);
                    primeiro = 0;
                    distAux =  getArestaCmp(aresta) + distAtual;

                    if(distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] >  distAux)
                    {
                        dist = distAtual + getArestaCmp(aresta);
                        distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = dist;
                        anterior[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = getPosicaoDoVertice(grafo, getVerticeId(vertice));
                    }
                }
                else
                {
                    arestaAux = getArestabyNo(getInfo(j));
                    distAux =  getArestaCmp(arestaAux) + distAtual;

                    if(menor > getArestaCmp(aux->aresta))
                    {
                        inicial = getVerticeId(vertice);
                        strcpy(final, getDestino(getInfo(j)));
                        menor = getArestaCmp(aresta);
                        aresta = getArestabyNo(getInfo(j));         
                    }
                    if(distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] >  distAux)
                    {
                        dist = distAtual + getArestaCmp(arestaAux);
                        distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = dist;
                        anterior[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = getPosicaoDoVertice(grafo, getVerticeId(vertice));
                    }
                }
            }
        }       
        primeiro = 1;
        insertHashTable(info, getVerticeId(vertice), tam, visitado);
        distAtual = distancia[indiceMenorDistancia(visitado, distancia, tam, grafo)];
        vertice = getVerticebyPosicao(grafo, indiceMenorDistancia(visitado, distancia, tam, grafo));
        contador++;
        loop = indiceMenorDistancia(visitado, distancia, tam, grafo);
    }

    while(1)
    {
        insert(path, copiarVertice(getVertice(grafo, idAnterior)));
        idAnt = anterior[getPosicaoDoVertice(grafo, idAnterior)];

        if(idAnt == -1)
        {
            printf("Não existe caminho");
            return NULL;
        }

        strcpy(idAnterior, getIdPorPosicaoVertice(grafo, idAnt));

        if(strcmp(start, idAnterior) == 0)
        {
            break;
        }
    }

    insert(path, copiarVertice(getVertice(grafo, start)));

    for (No noAux = getLast(path); noAux != NULL; noAux = getPrevious(noAux))
    {
        Vertice v = copiarVertice(getInfo(noAux));
        insert(pathInvertido, v);
    }
    
    removeList(path, free);
    deleteHashTable(visitado, tam, 0);
    return pathInvertido;
}


Lista dijsktraVM(Grafo grafo, char inicial[], char fim[], int tam)
{
    Hash visitado = createHashTable(tam);
    Lista pathInvertido = create();
    Lista path = create();
    Vertice vertice = getVertice(grafo, inicial), verticeAux;
    Aresta aresta, arestaAux;
    No nodeVertice;
    NodeAdjacenciaStruct* aux;
    int anterior[tam], primeiro = 1, contador = 0, loop = 1, idAnt;
    double distancia[tam], menor, dist = 9999, distAtual = 0, distAux;
    char info[2] = "0", final[100], destino[100], buscaAux[60], idAnterior[60], start[60];
    strcpy(buscaAux, fim);
    strcpy(idAnterior, fim);
    strcpy(start, inicial);

    for(int a = 0; a < tam; a++)
    {
        anterior[a] = -1;
        distancia[a] = dist;
    }
    
    while(loop > 0)
    {
        primeiro = 1;
        nodeVertice = getNodeGrafo(grafo, getVerticeId(vertice));
        NodeGrafoStruct* al = getInfo(nodeVertice);

        for(No j = getFirst(al->adjacencia); j != NULL; j = getNext(j))
        {   
            aux = getInfo(j);
            strcpy(destino, aux->j);
            verticeAux = getVertice(grafo, destino);

            if(searchHashTable(getVerticeId(verticeAux), visitado, tam) == NULL)
            {
                if(primeiro)
                {
                    inicial =  getVerticeId(vertice);
                    aresta = getArestabyNo(getInfo(j));
                    strcpy(final, getDestino(getInfo(j)));
                    menor = getArestaVm(aresta);
                    primeiro = 0;
                    distAux =  getArestaVm(aresta) + distAtual;

                    if(distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] >  distAux)
                    {
                        dist = distAtual + getArestaVm(aresta);
                        distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = dist;
                        anterior[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = getPosicaoDoVertice(grafo, getVerticeId(vertice));
                    }
                }
                else
                {
                    arestaAux = getArestabyNo(getInfo(j));
                    distAux =  getArestaVm(arestaAux) + distAtual;

                    if(menor > getArestaVm(aux->aresta))
                    {
                        inicial = getVerticeId(vertice);
                        strcpy(final, getDestino(getInfo(j)));
                        menor = getArestaVm(aresta);
                        aresta = getArestabyNo(getInfo(j));         
                    }
                    if(distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] >  distAux)
                    {
                        dist = distAtual + getArestaVm(arestaAux);
                        distancia[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = dist;
                        anterior[getPosicaoDoVertice(grafo, getVerticeId(verticeAux))] = getPosicaoDoVertice(grafo, getVerticeId(vertice));
                    }
                }
            }
        }       
        primeiro = 1;
        insertHashTable(info, getVerticeId(vertice), tam, visitado);
        distAtual = distancia[indiceMenorDistancia(visitado, distancia, tam, grafo)];
        vertice = getVerticebyPosicao(grafo, indiceMenorDistancia(visitado, distancia, tam, grafo));
        contador++;
        loop = indiceMenorDistancia(visitado, distancia, tam, grafo);
    }

    while(1)
    {
        insert(path, copiarVertice(getVertice(grafo, idAnterior)));
        idAnt = anterior[getPosicaoDoVertice(grafo, idAnterior)];

        if(idAnt == -1)
        {
            printf("Não existe caminho");
            return NULL;
        }

        strcpy(idAnterior, getIdPorPosicaoVertice(grafo, idAnt));

        if(strcmp(start, idAnterior) == 0)
        {
            break;
        }
    }

    insert(path, copiarVertice(getVertice(grafo, start)));

    for (No noAux = getLast(path); noAux != NULL; noAux = getPrevious(noAux))
    {
        Vertice v = copiarVertice(getInfo(noAux));
        insert(pathInvertido, v);
    }
    
    removeList(path, free);
    deleteHashTable(visitado, tam, 0);
    return pathInvertido;
}
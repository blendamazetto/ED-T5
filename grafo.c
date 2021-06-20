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
                    return noAdj;
                }
            }
        }
    }
    return NULL;
}

void removerAresta(Grafo grafo, char i[], char j[])
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
                    free(aux->aresta);
                    free(aux);
                    removerNo(no->adjacencia, noAdj, NULL);
                    return;
                }
            }
        }
    }
}

void removerBf(Grafo grafo, char face[], char cep[])
{
    char orient[10];
    double x1, y1, x2, y2;
    int i =0;

    char * idInicio[tamanhoDaLista(grafo)];
    char * idFim[tamanhoDaLista(grafo)];

    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        for(No noAdj = getFirst(no->adjacencia); noAdj!= NULL; noAdj = getNext(noAdj))
        {
            NodeAdjacenciaStruct* aux = getInfo(noAdj);
            Vertice v1 = no->vertice;
            Vertice v2 = getVertice(grafo, aux->j);
            if(v2 != NULL)
            {
                x1 = getVerticeX(v1);
                y1 = getVerticeY(v1);
                x2 = getVerticeX(v2);
                y2 = getVerticeY(v2);
                getDirecao(x1, x2, y1, y2, orient);

                if(strcmp(face, "S") == 0)
                {
                    if(strcmp(orient, "oeste") == 0)
                    {
                        if(strcmp(getArestaLdir(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                    else if(strcmp(orient, "leste") == 0)
                    {
                        if(strcmp(getArestaLesq(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                }
                else if(strcmp(face, "N") == 0)
                {   
                    if(strcmp(orient, "leste") == 0)
                    {
                        if(strcmp(getArestaLdir(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                    else if(strcmp(orient, "oeste") == 0)
                    {
                        if(strcmp(getArestaLesq(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                }
                else if(strcmp(face, "L") == 0)
                {
                    if(strcmp(orient, "norte") == 0)
                    {
                        if(strcmp(getArestaLesq(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                    else if(strcmp(orient, "sul") == 0)
                    {
                        if(strcmp(getArestaLdir(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                }
                else if(strcmp(face, "O") == 0)
                {
                    if(strcmp(orient, "norte") == 0)
                    {
                        if(strcmp(getArestaLdir(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                    else if(strcmp(orient, "sul") == 0)
                    {
                        if(strcmp(getArestaLesq(aux->aresta), cep) == 0)
                        {
                            idInicio[i] = malloc(sizeof(char) * 60);
                            idFim[i] = malloc(sizeof(char) * 60);
                            strcpy(idInicio[i], getVerticeId(no->vertice));
                            strcpy(idFim[i], aux->j);
                            i++;
                        }
                    }
                }
            }
        }
    }

    for (int b = 0; b < i; b++)
    {
        removerAresta(grafo, idInicio[b], idFim[b]);
    } 
    for (int b = 0; b < i; b++)
    {
        free(idInicio[b]);
        free(idFim[b]);
    }
}

Grafo copiarGrafo(Grafo grafo)
{
    Grafo copia = create();
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        adicionarVertice(copia, copiarVertice(no->vertice));

        for(No noAdj = getFirst(no->adjacencia); noAdj!= NULL; noAdj = getNext(noAdj))
        {
            NodeAdjacenciaStruct* aux = getInfo(noAdj);
            adicionarAresta(copia, getVerticeId(no->vertice), aux->j, copiarAresta(aux->aresta));
        }
    }

    return copia;
}

void removerArestasByDestino(Grafo grafo, char id[])
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        No noAdj = getFirst(no->adjacencia);
        while(noAdj!= NULL)
        {
            NodeAdjacenciaStruct* aux = getInfo(noAdj);
            if(strcmp(id, aux->j) == 0)
            {
                No temporario = noAdj;
                noAdj = getNext(noAdj);
                free(aux->aresta);
                free(aux);
                removerNo(no->adjacencia, temporario, NULL);
            }
            else
            noAdj = getNext(noAdj);
        }
    }
}

int procurarDestino(Grafo grafo, char id[])
{
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        for(No noAdj = getFirst(no->adjacencia); noAdj!= NULL; noAdj = getNext(noAdj))
        {
            NodeAdjacenciaStruct* aux = getInfo(noAdj);
            if(strcmp(aux->j, id) == 0)
            {
                return 1;
            }
        }
    }
    return 0;   
}

void removerVerticeDesconexo(Grafo grafo)
{
    char * listaIndices[tamanhoDaLista(grafo)];
    int i = 0;
    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        if(tamanhoDaLista(no->adjacencia) == 0)
        {
            listaIndices[i] = malloc(sizeof(char) * 60);
            strcpy(listaIndices[i], getVerticeId(no->vertice));
            i++;
        }
    }
    for (int b = 0; b < i; b++)
    {
        if(procurarDestino(grafo, listaIndices[b]) == 0)
        {
            removerVertice(grafo, listaIndices[b]);
        }
    } 
    for (int b = 0; b < i; b++)
    {
        free(listaIndices[b]);
    }
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

void removerVerticesDentroPoligono(Grafo grafo, Lista casos)
{
    Ponto p = createPonto(0,0);
    char * listaIndices[tamanhoDaLista(grafo)];
    int i = 0;

    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        setPontoX(p, getVerticeX(no->vertice));
        setPontoY(p, getVerticeY(no->vertice));

        if(insidePolygon(casos, p))
        {
            listaIndices[i] = malloc(sizeof(char) * 60);
            strcpy(listaIndices[i], getVerticebyPonto(grafo, getVerticeX(no->vertice), getVerticeY(no->vertice)));
            i++;
        }
    }

    for (int b = 0; b < i; b++)
    {
        removerVertice(grafo, listaIndices[b]);
        removerArestasByDestino(grafo, listaIndices[b]);
    } 

    for (int b = 0; b < i; b++)
    {
        free(listaIndices[b]);
    } 

    free(p);
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

void removerVerticesDentroCirculo(Grafo grafo, double x, double y, double r)
{ 
    double pontoX;
    double pontoY;

    for(No node = getFirst(grafo); node!= NULL; node = getNext(node))
    {
        NodeGrafoStruct* no = getInfo(node);
        pontoX = getVerticeX(no->vertice);
        pontoY = getVerticeY(no->vertice);

        if(distancia(pontoX, pontoY, x, y) <= r)
        {
            removerVertice(grafo, getVerticeId(no->vertice));
        }
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

        fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", x1, y1, 5.0, "blue", "white");

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

Lista dijsktra(Grafo grafo, char inicial[], char fim[], int tam, double getPeso(Aresta aresta))
{
    Hash visitado = createHashTable(tam), anterio = createHashTable(tam), distanc = createHashTable(tam);
    Lista path = create();
    Vertice vertice = getVertice(grafo, inicial), verticeAux;
    Aresta aresta, arestaAux;
    No nodeVertice;
    NodeAdjacenciaStruct* aux;
    int primeiro = 1, contador = 0;
    double menor, dist = 9999, distAux;
    char info[2] = "0", final[100], destino[100], buscaAux[60], idAnterior[60], start[60], idAnt[60];
    strcpy(buscaAux, fim);
    strcpy(idAnterior, fim);
    strcpy(start, inicial);
    double *ds = malloc(sizeof(double));
    *ds = 99999;
    char* tempId = malloc(sizeof(char) * 60 + 1);
    strcpy(tempId, "INFO");
    double *distHash =  malloc(sizeof(double));
    double *distAtual =  malloc(sizeof(double));
    *distAtual = 0;
    char idMenorValor[60];

    for(No auxiliar = getFirst(grafo); auxiliar != NULL; auxiliar = getNext(auxiliar))
    {
        NodeGrafoStruct* aux = getInfo(auxiliar);
        insertHashTable(ds, getVerticeId(aux->vertice), tam, distanc);
        insertHashTable(tempId, getVerticeId(aux->vertice), tam, anterio);
    }
    
    while(tamanhoDaHashtable(visitado, tam) < tam)
    {
        primeiro = 1;
        nodeVertice = getNodeGrafo(grafo, getVerticeId(vertice));
        if(nodeVertice != NULL)
        {
            NodeGrafoStruct* al = getInfo(nodeVertice);
            for(No j = getFirst(al->adjacencia); j != NULL; j = getNext(j))
            {
                aux = getInfo(j);
                strcpy(destino, aux->j);
                verticeAux = getVertice(grafo, destino);

                if(verticeAux != NULL)
                {
                    if(searchHashTable(getVerticeId(verticeAux), visitado, tam) == NULL)
                    {
                        *distHash = *(double*)searchHashTable(getVerticeId(verticeAux), distanc, tam);  
                        if(primeiro)
                        {
                            inicial =  getVerticeId(vertice);
                            aresta = getArestabyNo(getInfo(j));
                            strcpy(final, getDestino(getInfo(j)));
                            menor = getPeso(aresta);
                            primeiro = 0;
                            distAux =  getPeso(aresta) + *distAtual;

                            if(*distHash >  distAux)
                            {
                                dist = *distAtual + getPeso(aresta);
                                double *distAuxHash = malloc(sizeof(double));
                                *distAuxHash = dist;
                                setHashTable(getVerticeId(verticeAux), distanc, tam, distAuxHash);
                                setHashTable(getVerticeId(verticeAux), anterio, tam, getVerticeId(vertice));
                            }
                        }
                        else
                        {
                            arestaAux = getArestabyNo(getInfo(j));
                            distAux =  getPeso(arestaAux) + *distAtual;
                            *distHash = *(double*)searchHashTable(getVerticeId(verticeAux), distanc, tam);  

                            if(menor > getPeso(aux->aresta))
                            {
                                inicial = getVerticeId(vertice);
                                strcpy(final, getDestino(getInfo(j)));
                                menor = getPeso(aresta);
                                aresta = getArestabyNo(getInfo(j));       
                            }
                            if(*distHash >  distAux)
                            {
                                dist = *distAtual + getPeso(arestaAux);
                                double *distAuxHash = malloc(sizeof(double));
                                *distAuxHash = dist;
                                setHashTable(getVerticeId(verticeAux), distanc, tam, distAuxHash);
                                setHashTable(getVerticeId(verticeAux), anterio, tam, getVerticeId(vertice));
                            }
                        }
                    }
                }
            }
        }
               
        primeiro = 1;
        insertHashTable(info, getVerticeId(vertice), tam, visitado);
        buscarMenorValor(distanc, tam, idMenorValor, visitado);
        *distAtual = *(double*)searchHashTable(idMenorValor, distanc, tam);
        vertice = getVertice(grafo, idMenorValor);
        contador++;
    }

    while(1)
    {
        insert(path, copiarVertice(getVertice(grafo, idAnterior)));
        strcpy(idAnt, searchHashTable(idAnterior, anterio, tam));
        strcpy(idAnterior, idAnt);

        if(strcmp(start, idAnterior) == 0)
        {
            break;
        }
    }

    insert(path, copiarVertice(getVertice(grafo, start)));
    deleteHashTable(visitado, tam, 0);
    deleteHashTable(distanc, tam, 0);
    deleteHashTable(anterio, tam, 0);

    free(ds);
    free(distHash);
    free(distAtual);
    free(tempId);

    return path;
}
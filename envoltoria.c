#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "envoltoria.h"

typedef struct env{

    int id;
    char cor[25];
    Lista pontos;

}NodeEnvStruct;

Envoltoria createEnvoltoria()
{
    return create();
}

void criarVerticeEnvoltoria(Envoltoria env, int id, char cor[])
{
    NodeEnvStruct* no = (NodeEnvStruct*)malloc(sizeof(NodeEnvStruct));
    no->id = id;
    strcpy(no->cor, cor);
    no->pontos = create();
    insert(env, no);
}

void adicionarPontoEnvoltoria(int id, Ponto ponto, Envoltoria env)
{
    for(No node = getFirst(env); node != NULL; node = getNext(node))
    {
        NodeEnvStruct* no = getInfo(node);
        if(id == no->id)
        {
            insert(no->pontos, ponto);
        }
    }
}

void printarEnvoltoria(Envoltoria env, FILE *svg)
{
    for(No node = getFirst(env); node != NULL; node = getNext(node))
    {
        NodeEnvStruct* no = getInfo(node);
        fprintf(svg,"\t<polygon id=\"%d\" fill=\"%s\" fill-opacity=\"0.2\" stroke=\"red\" stroke-width=\"5px\" points=\"", tamanhoDaLista(no->pontos), no->cor);
        for(No pont = getFirst(no->pontos); pont != NULL; pont = getNext(pont))
        {
            Ponto p = getInfo(pont);
            fprintf(svg," %lf,%lf",getPontoX(p),getPontoY(p));
        }
        fprintf(svg," \"/>\n");
        removeList(no->pontos, free);
    }
}

void desalocarNoEnv(No node)
{
    NodeEnvStruct* no = (NodeEnvStruct*) node;
    free(no);
}

void desalocarEnv(Lista env)
{
    removeList(env, desalocarNoEnv);
}


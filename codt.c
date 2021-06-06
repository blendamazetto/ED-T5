#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "codt.h"

typedef struct c{

    char codt[20];
    char descricao[255];

}CodtStruct;

Codt criaCodt(char codt[], char descricao[])
{
    CodtStruct* c = (CodtStruct*) malloc(sizeof(CodtStruct));

    strcpy(c->codt, codt);
    strcpy(c->descricao, descricao);

    return c;
}

char* getCodtCodt(Codt c)
{
    CodtStruct* co = (CodtStruct*) c;
    return co->codt;
}

void setCodtCodt(Codt c, char codt[])
{
    CodtStruct* co = (CodtStruct*) c;
    strcpy(co->codt, codt);
}

char* getCodtDescricao(Codt c)
{
    CodtStruct* co = (CodtStruct*) c;
    return co->descricao;
}

void setCodtDescricao(Codt c, char descricao[])
{
    CodtStruct* co = (CodtStruct*) c;
    strcpy(co->descricao, descricao);
}

void desalocarCodt(Codt c)
{
    CodtStruct* co = (CodtStruct*) c;

    free(co);
}
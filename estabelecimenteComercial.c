#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "estabelecimentoComercial.h"

typedef struct ec{

    char cnpj[25];
    char cpf[20];
    char codt[20];
    char cep[20];
    char face[2];
    double num;
    char nome[255];
    Ponto ponto;

}EstabelecimentoStruct;

Estabelecimento criaEstabelecimento(char cnpj[], char cpf[], char codt[], char cep[], char face[], double num, char nome[], Ponto ponto)
{
    EstabelecimentoStruct* estab = (EstabelecimentoStruct*) malloc(sizeof(EstabelecimentoStruct));

    strcpy(estab->cnpj, cnpj);
    strcpy(estab->cpf, cpf);
    strcpy(estab->codt, codt);
    strcpy(estab->cep, cep);
    strcpy(estab->face, face);
    estab->num = num;
    strcpy(estab->nome, nome);
    estab->ponto = ponto;

    return estab;
}

char* getEstabelecimentoCnpj(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->cnpj;
}

char* getEstabelecimentoCpf(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->cpf;
}

char* getEstabelecimentoCodt(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->codt;
}

char* getEstabelecimentoCep(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->cep;
}

char* getEstabelecimentoFace(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->face;
}

double getEstabelecimentoNum(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->num;
}

char* getEstabelecimentoNome(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->nome;
}

Ponto getEstabelecimentoPonto(Estabelecimento estabelecimento)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    return e->ponto;
}

void setEstabelecimentoCnpj(Estabelecimento estabelecimento, char cnpj[])
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    strcpy(e->cnpj, cnpj);
}

void setEstabelecimentoCpf(Estabelecimento estabelecimento, char cpf[])
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    strcpy(e->cpf, cpf);
}

void setEstabelecimentoCodt(Estabelecimento estabelecimento, char codt[])
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    strcpy(e->codt, codt);
}

void setEstabelecimentoCep(Estabelecimento estabelecimento, char cep[])
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    strcpy(e->cep, cep);
}

void setEstabelecimentoFace(Estabelecimento estabelecimento, char face[])
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    strcpy(e->face, face);
}

void setEstabelecimentoNum(Estabelecimento estabelecimento, double num)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    e->num = num;
}

void setEstabelecimentoNome(Estabelecimento estabelecimento, char nome[])
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    strcpy(e->nome, nome);
}

void setEstabelecimentoPonto(Estabelecimento estabelecimento, Ponto ponto)
{
    EstabelecimentoStruct* e = (EstabelecimentoStruct*) estabelecimento;
    e->ponto = ponto;
}

void swapEstabelecimento(Estabelecimento e1, Estabelecimento e2)
{
    EstabelecimentoStruct* a = (EstabelecimentoStruct*) e1;
    EstabelecimentoStruct* b = (EstabelecimentoStruct*) e2;
    EstabelecimentoStruct temp = *a;

    *a = *b;
    *b = temp;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "morador.h"

typedef struct m{

    char cpf[20];
    char face[2];
    double num;
    char compl[20];
    char cep[20];
    Ponto ponto;

}MoradorStruct;

Morador criaMorador(char cpf[], char face[], char compl[], char cep[], double num, Ponto ponto)
{
    MoradorStruct* m = (MoradorStruct*) malloc(sizeof(MoradorStruct));

    strcpy(m-> cpf, cpf);
    strcpy(m->face, face);
    strcpy(m->compl, compl);
    strcpy(m->cep, cep);
    m->num = num;
    m->ponto = ponto;

    return m;
}

char* getMoradorCpf(Morador morador)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    return m->cpf;
}

char* getMoradorCep(Morador morador)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    return m->cep;
}

char* getMoradorFace(Morador morador)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    return m->face;
}

double getMoradorNum(Morador morador)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    return m->num;
}

char* getMoradorCompl(Morador morador)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    return m->compl;
}

Ponto getMoradorPonto(Morador morador)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    return m->ponto;
}

void setMoradorCpf(Morador morador, char cpf[])
{
    MoradorStruct* m = (MoradorStruct*) morador;
    strcpy(m->cpf, cpf);
}

void setMoradorPonto(Morador morador, Ponto ponto)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    m->ponto = ponto;
}

void setMoradorCep(Morador morador, char cep[])
{
    MoradorStruct* m = (MoradorStruct*) morador;
    strcpy(m->cep, cep);
}

void setMoradorFace(Morador morador, char face[])
{
    MoradorStruct* m = (MoradorStruct*) morador;
    strcpy(m->face, face);
}

void setMoradorCompl(Morador morador, char compl[])
{
    MoradorStruct* m = (MoradorStruct*) morador;
    strcpy(m->compl, compl);
}

void setMoradorNum(Morador morador, double num)
{
    MoradorStruct* m = (MoradorStruct*) morador;
    m->num = num;
}

void swapMorador(Morador m1, Morador m2)
{
    MoradorStruct* a = (MoradorStruct*) m1;
    MoradorStruct* b = (MoradorStruct*) m2;
    MoradorStruct temp = *a;

    *a = *b;
    *b = temp;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pessoa.h"

typedef struct p{

    char cpf[20];
    char nome[100];
    char sobrenome[100];
    char sexo[2];
    char nascimento[11];

}PessoaStruct;

Pessoa criaPessoa(char cpf[], char nome[], char sobrenome[], char sexo[], char nascimento[])
{
    PessoaStruct* p = (PessoaStruct*) malloc(sizeof(PessoaStruct));

    strcpy(p-> sobrenome, sobrenome);
    strcpy(p->cpf, cpf);
    strcpy(p->sexo, sexo);
    strcpy(p->nascimento, nascimento);
    strcpy(p->nome, nome);

    return p;
}

char* getPessoaCpf(Pessoa pessoa)
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    return p->cpf;
}

char* getPessoaNome(Pessoa pessoa)
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    return p->nome;
}

char* getPessoaSobrenome(Pessoa pessoa)
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    return p->sobrenome;
}

char* getPessoaSexo(Pessoa pessoa)
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    return p->sexo;
}

char* getPessoaNascimento(Pessoa pessoa)
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    return p->nascimento;
}

void setPessoaCpf(Pessoa pessoa, char cpf[])
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    strcpy(p->cpf, cpf);
}

void setPessoaNome(Pessoa pessoa, char nome[])
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    strcpy(p->nome, nome);
}

void setPessoaNascimento(Pessoa pessoa, char nascimento[])
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    strcpy(p->nascimento, nascimento);
}

void setPessoaSexo(Pessoa pessoa, char sexo[])
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    strcpy(p->sexo, sexo);
}

void setPessoaSobrenome(Pessoa pessoa, char sobrenome[])
{
    PessoaStruct* p = (PessoaStruct*) pessoa;
    strcpy(p->sobrenome, sobrenome);
}

void swapPessoa(Pessoa p1, Pessoa p2)
{
    PessoaStruct* a = (PessoaStruct*) p1;
    PessoaStruct* b = (PessoaStruct*) p2;
    PessoaStruct temp = *a;

    *a = *b;
    *b = temp;
}
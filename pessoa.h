#include "ponto.h"

#ifndef __PESSOA_H
#define __PESSOA_H

//Define "Estabelecimento" como um void pointer
typedef void* Pessoa;

/*
* aloca memoria para uma struct pessoa
* precisa dos paremetros necessarios para a criacao de uma pessoa
* retorna um void pointer para a pessoa criada
*/
Pessoa criaPessoa(char cpf[], char nome[], char sobrenome[], char sexo[], char nascimento[]);

/*
* obtem o cpf de uma pessoa
* precisa de um void pointer para a pessoa
* retorna um char com a informacao procurada
*/
char* getPessoaCpf(Pessoa pessoa);

/*
* obtem o nome de uma pessoa
* precisa de um void pointer para a pessoa
* retorna um char com a informacao procurada
*/
char* getPessoaNome(Pessoa pessoa);

/*
* obtem o sobrenome de uma pessoa
* precisa de um void pointer para a pessoa
* retorna um char com a informacao procurada
*/
char* getPessoaSobrenome(Pessoa pessoa);

/*
* obtem o sexo de uma pessoa
* precisa de um void pointer para a pessoa
* retorna um char com a informacao procurada
*/
char* getPessoaSexo(Pessoa pessoa);

/*
* obtem a data de nascimento de uma pessoa
* precisa de um void pointer para a pessoa
* retorna um char com a informacao procurada
*/
char* getPessoaNascimento(Pessoa pessoa);

/*
* seta o cpf de uma pessoa
* precisa de um void pointer para a pessoa e um char com a informacao
* nao retorna nada
*/
void setPessoaCpf(Pessoa pessoa, char cpf[]);

/*
* seta o nome de uma pessoa
* precisa de um void pointer para a pessoa e um char com a informacao
* nao retorna nada
*/
void setPessoaNome(Pessoa pessoa, char nome[]);

/*
* seta a data de nascimento de uma pessoa
* precisa de um void pointer para a pessoa e um char com a informacao
* nao retorna nada
*/
void setPessoaNascimento(Pessoa pessoa, char nascimento[]);

/*
* seta o sexo de uma pessoa
* precisa de um void pointer para a pessoa e um char com a informacao
* nao retorna nada
*/
void setPessoaSexo(Pessoa pessoa, char sexo[]);

/*
* seta o sobrenome de uma pessoa
* precisa de um void pointer para a pessoa e um char com a informacao
* nao retorna nada
*/
void setPessoaSobrenome(Pessoa pessoa, char sobrenome[]);

/*
* troca duas pessoa
* precisa de dois void pointers para as informacoes quer serao invertidas
* nao retorna nada
*/
void swapPessoa(Pessoa p1, Pessoa p2);

#endif

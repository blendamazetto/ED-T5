#include "ponto.h"

#ifndef __ESTABELECIMENTO_H
#define __ESTABELECIMENTO_H

//Define "Estabelecimento" como um void pointer
typedef void* Estabelecimento;

/*
*Aloca a memoria para a criacao de um estabelecimento
*recebe os parametros necessarios para a criacao de um estabelecimento
*Retorna um void pointer para o estabelecimento criado
*/
Estabelecimento criaEstabelecimento(char cnpj[], char cpf[], char codt[], char cep[], char face[], double num, char nome[], Ponto ponto);

/*
*Obtem o cnpj de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um char com o cnpj
*/
char* getEstabelecimentoCnpj(Estabelecimento estabelecimento);

/*
*Obtem o cpf de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um char com o cpf
*/
char* getEstabelecimentoCpf(Estabelecimento estabelecimento);

/*
*Obtem o codt de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um char com o codt
*/
char* getEstabelecimentoCodt(Estabelecimento estabelecimento);

/*
*Obtem o cep de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um char com o cep
*/
char* getEstabelecimentoCep(Estabelecimento estabelecimento);

/*
*Obtem o face de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um char com o face
*/
char* getEstabelecimentoFace(Estabelecimento estabelecimento);

/*
*Obtem o num de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um double com o num
*/
double getEstabelecimentoNum(Estabelecimento estabelecimento);

/*
*Obtem o nome de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um char com o nome
*/
char* getEstabelecimentoNome(Estabelecimento estabelecimento);

/*
*Obtem o ponto de um estabelecimento
*Precisa de um void pointer para o estabelecimento
*Retorna um cvoid pointer com o ponto
*/
Ponto getEstabelecimentoPonto(Estabelecimento estabelecimento);

/*
* seta o cnpj de um estabelecimento
* recebe um void pointer para o estabelecimento e um char com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoCnpj(Estabelecimento estabelecimento, char cnpj[]);

/*
* seta o cpf de um estabelecimento
* recebe um void pointer para o estabelecimento e um char com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoCpf(Estabelecimento estabelecimento, char cpf[]);

/*
* seta o codt de um estabelecimento
* recebe um void pointer para o estabelecimento e um char com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoCodt(Estabelecimento estabelecimento, char codt[]);

/*
* seta o cep de um estabelecimento
* recebe um void pointer para o estabelecimento e um char com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoCep(Estabelecimento estabelecimento, char cep[]);

/*
* seta a face de um estabelecimento
* recebe um void pointer para o estabelecimento e um char com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoFace(Estabelecimento estabelecimento, char face[]);

/*
* seta o num de um estabelecimento
* recebe um void pointer para o estabelecimento e um double com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoNum(Estabelecimento estabelecimento, double num);

/*
* seta o nome de um estabelecimento
* recebe um void pointer para o estabelecimento e um char com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoNome(Estabelecimento estabelecimento, char nome[]);

/*
* seta o ponto de um estabelecimento
* recebe um void pointer para o estabelecimento e um void pointe com o que sera setado
* nao retorna nada
*/
void setEstabelecimentoPonto(Estabelecimento estabelecimento, Ponto ponto);

/*
* Troca dois estabelecimentos
* recebe dois void pointers para os estabelecimentos que serão invertidos
* nao retorna nada
*/
void swapEstabelecimento(Estabelecimento e1, Estabelecimento e2);

#endif

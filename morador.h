#include "ponto.h"

#ifndef __MORADOR_H
#define __MORADOR_H

//Define "Estabelecimento" como um void pointer
typedef void* Morador;

/*
* aloca memoria para a criacao de um morador
* precisa dos parametros para a criacao de um morador
* retorna um void pointer para o morador criado
*/
Morador criaMorador(char cpf[], char face[], char compl[], char cep[], double num, Ponto ponto);

/*
* obtem o cpf de um morador
* precisa de um void pointer para o morador 
* retorna um char* com a informacao procurada 
*/
char* getMoradorCpf(Morador morador);

/*
* obtem o cep de um morador
* precisa de um void pointer para o morador 
* retorna um char* com a informacao procurada 
*/
char* getMoradorCep(Morador morador);

/*
* obtem a face de um morador
* precisa de um void pointer para o morador 
* retorna um char* com a informacao procurada 
*/
char* getMoradorFace(Morador morador);

/*
* obtem o num de um morador
* precisa de um void pointer para o morador 
* retorna um double com a informacao procurada 
*/
double getMoradorNum(Morador morador);

/*
* obtem o compl de um morador
* precisa de um void pointer para o morador 
* retorna um char* com a informacao procurada 
*/
char* getMoradorCompl(Morador morador);

/*
* obtem o ponto de um morador
* precisa de um void pointer para o morador 
* retorna um void pointer com a informacao procurada 
*/
Ponto getMoradorPonto(Morador morador);

/*
* seta o cpf de um morador
* precisa de um void pointer para o morador e um char com a informacao que sera setada
* nao retorna nada
*/
void setMoradorCpf(Morador morador, char cpf[]);

/*
* seta o ponto de um morador
* precisa de um void pointer para o morador e um void pointer com a informacao que sera setada
* nao retorna nada
*/
void setMoradorPonto(Morador morador, Ponto ponto);

/*
* seta o cep de um morador
* precisa de um void pointer para o morador e um char com a informacao que sera setada
* nao retorna nada
*/
void setMoradorCep(Morador morador, char cep[]);

/*
* seta a face de um morador
* precisa de um void pointer para o morador e um char com a informacao que sera setada
* nao retorna nada
*/
void setMoradorFace(Morador morador, char face[]);

/*
* seta o compl de um morador
* precisa de um void pointer para o morador e um char com a informacao que sera setada
* nao retorna nada
*/
void setMoradorCompl(Morador morador, char compl[]);

/*
* seta o num de um morador
* precisa de um void pointer para o morador e um doublecom a informacao que sera setada
* nao retorna nada
*/
void setMoradorNum(Morador morador, double num);

/*
* troca dois moradores
* precisa de dois void pointers para os moradores que serao invertidos
* nao retorna nada
*/
void swapMorador(Morador m1, Morador m2);

#endif

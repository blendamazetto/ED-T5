#include "qry.h"

#ifndef __PONTO__
#define __PONTO__

typedef void* Ponto;

/*
* cria um ponto
* precisa de um double x e um double y
* retorna um void pointer
*/
Ponto createPonto(double x, double y);

/*
* obtem o x de um ponto
* precisa de um void pointer para o ponto
* retorna um double com o x
*/
double getPontoX(Ponto ponto);

/*
* obtem o y de um ponto
* precisa de um void pointer para o ponto
* retorna um double com o y
*/
double getPontoY(Ponto ponto);

/*
* seta o x de um ponto
* precisa de um void pointer para o ponto a ser setado e do valor
* nao retorna nada
*/
void setPontoX(Ponto ponto, double x);

/*
* seta o y de um ponto
* precisa de um void pointer para o ponto a ser setado e do valor 
* nao retorna nada
*/
void setPontoY(Ponto ponto, double y);

/*
* troca dois pontos
* precisa de dois void pointers a serem invertidos
* nao retorna nada
*/
void swapPonto(Ponto p1, Ponto p2);

/*
* atribui um ponto a outro
* precisa de dois void pointers ponto
* nao retorna nada
*/
void atribuirPonto(Ponto *p1, Ponto *p2);

/*
* obtem a distancia entre dois pontos
* recebe um void pointer para um ponto e um x e um y para calcular a distancia
* retorna um double com a distancia
*/
double getPontoDist(Ponto pont, double x, double y);

#endif
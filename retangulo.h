#include "ponto.h"

#ifndef __RETANGULO_H
#define __RETANGULO_H

//Define "Retangulo" como um void pointer
typedef void* Retangulo;

/*
*Cria uma struct retangulo
*Precisa dos parametros necessarios para a criacao de um retangulo
*Retorna um void pointer para a struct retangulo
*/
Retangulo criaRetangulo(char i[], double w, double h, double x, double y, char sw[], char corb[], char corp[]);

/*
*Obtem o indice(i) de um retangulo
*Precisa de um void pointer retangulo 
*Retorna um int com o indice(i) do retangulo
*/
char* getRetanguloI(Retangulo retangulo);

/*
*Obtem a largura de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com a largura(w) do retangulo
*/
double getRetanguloW(Retangulo retangulo);

/*
*Obtem a altura de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com a altura(h) do retangulo
*/
double getRetanguloH(Retangulo retangulo);

/*
*Obtem o x de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com o x de um retangulo
*/
double getRetanguloX(Retangulo retangulo);

/*
*Obtem o y de um retangulo
*Precisa de um void pointer retangulo
*Retorna um double com o y do retangulo 
*/
double getRetanguloY(Retangulo retangulo);

/*
 *Obtem a sw da stroke de um retangulo
 *Precisa de um void pointer retangulo
 *retorna um char com a sw da stroke do retangulo
 */
char* getRetanguloSw(Retangulo retangulo);

/*
*Obtem a cor de stroke de retangulo
*Precisa de um void pointer retangulo
*Retorna uma string com a cor de stroke(Corb) do retangulo
*/
char* getRetanguloCorb(Retangulo retangulo);

/*
*Obtem a cor de fill de um retangulo
*Precisa de um void pointer retangulo
*Retorna uma string com a cor de fill(Corp) do retangulo
*/
char* getRetanguloCorp(Retangulo retangulo);

/*
*Armazena um int no indice(i) de um retangulo
*Precisa de um void pointer retangulo e um int
*Não retorna nada
*/
void setRetanguloI(Retangulo retangulo, char i[]);

/*
*Armazena um double na largura(w) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloW(Retangulo retangulo, double w);

/*
*Armazena um double na altura(h) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloH(Retangulo retangulo, double h);

/*
*Armazena um double no x de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloX(Retangulo retangulo, double x);

/*
*Armazena um double no y de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloY(Retangulo retangulo, double y);

/*Armazena uma string na sw da stroke de um retangulo
 *Precisa de um void pointer retangulo e de um char com a sw
 *Não retorna nada
 */
void setRetanguloSw(Retangulo retangulo, char sw[]);

/*
*Armazena uma string na cor de stroke(Corb) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloCorb(Retangulo retangulo, char corb[]);

/*
*Armazena uma string na cor de fill(Corp) de um retangulo
*Precisa de um void pointer retangulo e um double
*Não retorna nada
*/
void setRetanguloCorp(Retangulo retangulo, char corp[]);

/*
* obtem o ponto de um retangulo
* recebe um void pointer para um retangulo
* retorna um void pointer para o ponto
*/
Ponto getRetanguloPonto(Retangulo retangulo);

/*
* seta o ponto de um retangulo
* recebe um void pointer para um retangulo e um para um ponto
* nao retorna nada
*/
void setRetanguloPonto(Retangulo retangulo, Ponto ponto);

/*
* troca dois retangulos
* recebe dois void pointers para os retangulos a serem invertidos
* nao retorna nada
*/
void swapRetangulo(Retangulo retangulo1, Retangulo retangulo2);

/*
* desaloca a memoria alocado por um retangulo
* recebe um void pointer para um retangulo
* nao retorna nada
*/
void desalocaRetangulo(Retangulo retangulo);

#endif
#include "ponto.h"

#ifndef __TEXTO_H
#define __TEXTO_H

//Define "Texto" como um void pointer
typedef void* Texto;

/*
*Cria uma struct texto
*Precisa dos parametros necessarios para a criacao de um texto
*Retorna um void pointer para a struct texto
*/
Texto criaTexto(char i[], double x, double y, char corb[], char corp[], char texto[]);

/*
*Obtem o indice de um texto
*Precisa de um void pointer texto
*Retorna um int com o indice do texto
*/
char* getTextoI(Texto texto);

/*
*Obtem o x de um texto
*Precisa de um void pointer texto
*Retorna um double com o x do texto
*/
double getTextoX(Texto texto);

/*
*Obtem o y de um texto
*Precisa de um void pointer texto
*Retorna um double com o y do texto
*/
double getTextoY(Texto texto);

/*
*Obtem a cor de stroke de um texto
*Precisa de um void pointer texto
*Retorna uma string com a cor de stroke(Corb) de um texto
*/
char* getTextoCorb(Texto texto);

/*
*Obtem a cor de fill de um texto
*Precisa de um void pointer texto
*Retorna uma string com a cor de fill(Corp) de um texto
*/
char* getTextoCorp(Texto texto);

/*
*Obtem o texto de um texto
*Precisa de um void pointer texto
*Retorna uma string com o texto(txto) de um texto
*/
char* getTextoTxto(Texto texto);

/*
*Armazena um inteiro no indice de um texto
*Precisa de um void pointer texto e um int
*Não retorna nada
*/
void setTextoI(Texto texto, char i[]);

/*
*Armazena um double no x de um texto
*Precisa de um void pointer texto e um double 
*Não retorna nada
*/
void setTextoX(Texto texto, double x);

/*
*Armazena um double no y de um texto
*Precisa de um void pointer texto e um double
*Não retorna nada
*/
void setTextoY(Texto texto, double y);

/*
*Armazena uma string na cor de stroke de um texto
*Precisa de um void pointer texto e uma string
*Não retorna nada
*/
void setTextoCorb(Texto texto, char corb[]);

/*
*Armazena uma string na cor de fill de um texto
*Precisa de um void pointer texto e uma string
*Não retorna nada
*/
void setTextoCorp(Texto texto, char corp[]);

/*
*Armazena uma string no texto(txto) de um texto
*Precisa de um void pointer texto e uma string
*Não retorna nada
*/
void setTextoTxto(Texto texto, char txto[]);

/*
* obtem o ponto de um texto
* recebe um void pointer para o texto
* retorna um void pointer para o ponto
*/
Ponto getTextoPonto(Texto texto);

/*
* seta o ponto de um texto
* recebe dois void pointers, um pro texto e um pro ponto
* nao retorna nada
*/
void setTextoPonto(Texto texto, Ponto ponto);

/*
* troca dois textos
* recebe dois void pointer para o textos a serem invertidos
* nao retorna nada
*/
void swapTexto(Texto t1, Texto t2);

/*
* desaloca a memoria alocada por um texto
* recebe um void pointer para um texto
* nao retorna nada
*/
void desalocaTexto(Texto txt);

#endif

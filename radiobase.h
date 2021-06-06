#include "ponto.h"

#ifndef __RADIOBASE_H
#define __RADIOBASE_H

//Define "Radiobase" como um void pointer 
typedef void* Radiobase;

/*
*Cria uma struct radiobase
*Precisa dos parametros necessarios para a criação de uma radiobase
*Retorna um void pointer para a struct radiobase
*/
Radiobase criaRadiobase(char id[], double x, double y, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o Id de uma radiobase
*Precisa de um void pointer radiobase
*Retorna o Id de uma radiobase
*/
char* getRadiobaseId(Radiobase radiobase);

/*
*Obtem o x de uma radiobase
*Precisa de um void pointer radiobase
*Retorna o x de uma radiobase
*/
double getRadiobaseX(Radiobase radiobase);

/*
*Obtem o y de uma radiobase
*Precisa de um void pointer radiobase
*Retorna o y de uma radiobase
*/
double getRadiobaseY(Radiobase radiobase);

/*
*Obtem a sw de uma radiobase
*Precisa de um void pointer radiobase
*Retorna a sw(Sw) de uma radiobase
*/
char* getRadiobaseSw(Radiobase radiobase);

/*
*Obtem a cor de stroke de uma radiobase
*Precisa de um void pointer radiobase
*Retorna a cor de stroke(Cfill) de uma radiobase
*/
char* getRadiobaseCfill(Radiobase radiobase);

/*
*Obtem a cor de fill de uma radiobase
*Precisa de um void pointer radiobase
*Retorna a cor de fill(Cstrk) de uma radiobase
*/
char* getRadiobaseCstrk(Radiobase radiobase);

/*
*Armazena um char Id em uma radiobase
*Precisa de um void pointer radiobase e uma string 
*Não retorna nada
*/
void setRadiobaseId(Radiobase radiobase, char id[]);

/*
*Armazena um valor x em uma radiobase
*Precisa de um void pointer radiobase e um double
*Não retorna nada
*/
void setRadiobaseX(Radiobase radiobase, double x);

/*
*Armazena um valor y em uma radiobase
*Precisa de um void pointer radiobase e um double
*Não retorna nada
*/
void setRadiobaseY(Radiobase radiobase, double y);

/*
*Armazena uma string com a sw em uma radiobase
*Precisa de um void pointer radiobase e uma string
*Não retorna nada
*/
void setRadiobaseSw(Radiobase radiobase, char sw[]);

/*
*Armazena uma string com a cor de stroke em uma radiobase
*Precisa de um void pointer radiobase e uma string
*Não retorna nada
*/
void setRadiobaseCfill(Radiobase radiobase, char cfill[]);

/*
*Armazena uma string com a cor de fill em uma radiobase
*Precisa de um void pointer radiobase e uma string
*Não retorna nada
*/
void setRadiobaseCstrk(Radiobase radiobase, char cstrk[]);

/*
* obtem o ponto de uma radio base
* precisa de um void pointer para um radiobase
* retorna um void pointer para o ponto
*/
Ponto getRadiobasePonto(Radiobase radiobase);

/*
* seta o ponto de uma radiobase
* recebe um void pointer para a radiobase e um para o ponto
* nao retorna nada
*/
void setRadiobasePonto(Radiobase radiobase, Ponto ponto);

/*
* troca duas radiobases
* recebe dois void pointers para as radiobases a serem invertidas
* nao retorna nada
*/
void swapRadiobase(Radiobase rb1, Radiobase rb2);

/*
* desaloca a memoria alocada por uma radiobase
* precisa de um void pointer para uma radiobase
* nao retorna nada
*/
void desalocaRadiobase(Radiobase radiobase);

#endif
#include "ponto.h"

#ifndef __SEMAFARO_H
#define __SEMAFARO_H

//Define "Semaforo" como um void pointer
typedef void* Semaforo;

/*
*Cria uma struct semaforo
*Precisa dos parametros necessarios para criacao de um semaforo
*Retorna um void pointer para a struct semaforo
*/
Semaforo criaSemaforo(char id[], double x, double y, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o id de um semaforo
*Precisa de um void pointer semaforo
*Retorna a string id do semaforo
*/
char* getSemaforoId(Semaforo semaforo);

/*
*Obtem o x de um semaforo
*Precisa de um void pointer semaforo
*Retorna um double com o x do semaforo
*/
double getSemaforoX(Semaforo semaforo);

/*
*Obtem o y de um semaforo
*Precisa de um void pointer semaforo
*Retorna um double com o y do semaforo
*/
double getSemaforoY(Semaforo semaforo);

/*
*Obtem a sw do semaforo
*Precisa de um void pointer semaforo
*Retorna uma string com a sw(Sw) do semaforo
*/
char* getSemaforoSw(Semaforo semaforo);

/*
*Obtem a cor de stroke do semaforo
*Precisa de um void pointer semaforo
*Retorna uma string com a cor de stroke(Cfill) do semaforo
*/
char* getSemaforoCfill(Semaforo semaforo);

/*
*Obtem a cor de fill do semaforo
*Precisa de um void pointer semaforo
*Retorna uma string com a cor de fill(Cstrk) do semaforo
*/
char* getSemaforoCstrk(Semaforo semaforo);

/*
*Armazena uma string no id do semaforo 
*Precisa de um void pointer semaforo e uma string
*Não retorna nada
*/
void setSemaforoId(Semaforo semaforo, char id[]);

/*
*Armazena um valor double no x do semaforo
*Precisa de um void pointer semaforo e um double
*Não retorna nada
*/
void setSemaforoX(Semaforo semaforo, double x);

/*
*Armazena um valor double no y do semaforo
*Precisa de um void pointer semaforo e um double
*Não retorna nada
*/
void setSemaforoY(Semaforo semaforo, double y);

/*
*Armazena uma string na sw do semaforo
*Precisa de um void pointer semaforo e uma string com a sw(Sw)
*Não retorna nada
*/
void setSemaforoSw(Semaforo semaforo, char sw[]);

/*
*Armazena uma string na cor de stroke do semaforo
*Precisa de um void pointer semaforo e uma string com a cor de stroke(Cfill)
*Não retorna nada
*/
void setSemaforoCfill(Semaforo semaforo, char cfill[]);

/*
*Armazena uma string na cor de fill do semaforo
*Precisa de um void pointer semaforo e uma string com a cor de fill(Cstrk)
*Não retorna nada
*/
void setSemaforoCstrk(Semaforo semaforo, char cstrk[]);

/*
* obtem o ponto de um semaforo
* precisa de um void pointer para um semaforo
* retorna um void pointer para o ponto
*/
Ponto getSemaforoPonto(Semaforo semaforo);

/*
* seta o ponto de um semaforo
* recebe um void pointer para o semaforo e um para o ponto
* nao retorna nada
*/
void setSemaforoPonto(Semaforo semaforo, Ponto ponto);

/*
* troca dois semaforos
* recebe dois semaforos a serem invertidos
* nao retorna nada
*/
void swapSemaforo(Semaforo semaforo1, Semaforo semaforo2);

/*
* desaloca a memoria alocada por um semaforo
* recebe um voind pointer para um semaforo
* nao retorna nada
*/
void desalocaSemaforo(Semaforo semaforo);


#endif
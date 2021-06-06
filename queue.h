#include "stack.h"
#include "lista.h"

#ifndef __FILA__
#define __FILA__

//Define "Lista" como um void pointer
typedef void* Fila;

/*
* cria uma fila
* nao recebe parametros
* retorna um void pointer para uma fila
*/
Fila createQueue();

/*
* insere um elemento na fila
* precisa de um void pointer pra fila e um para a info que sera inserida
* nao retorna nada
*/
void insertQueue(Fila f, Info info);

/*
* remove o primeiro elemento da fila
* recebe um void pointer para a fila
* retorna a info removida
*/
Info removeQueue(Fila f);

/*
* retorna se a fila esta vazia ou nao
* recebe um void pointer para a fila
* retorna um int
*/
int isEmptyQueue(Fila f);

/*
* obtem o primeito elemeto da fila
* recebe um void pointer para a fila
* retorna um void pointer para o primeiro no
*/
No getPrimeiro(Fila f);

/*
* obtem o tamanho da fila
* recebe um void pointer para a fila
* retorna um int com o tamanho
*/
int getTamanhoQueue(Fila f);

/*
* deleta a fila
* recebe um void pointer para a fila a seer deletada
* nao retorna nada
*/
void deleteQueue(Fila f);

/*
* obtem o proximo elemento de um node
* recebe um void pointer no
* retorna um void pointe no
*/
No getProximo(No elemento);

#endif
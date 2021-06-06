#include "lista.h"

#ifndef __STACK__
#define __STACK__

//Define "Lista" como um void pointer
typedef void* Pilha;

/*
* cria uma pilha 
* nao recebe parametros
* retorna um void pointer para a pilha criada
*/
Pilha createStack();

/*
*insere uma info na pilha
*recebe um void pointer para a pilha e um para a info
* nao retorna nada
*/
void insertStack(Pilha p, Info info);

/*
* remove o ultimo elemento da pilha
* recebe um void pointer para a pilha
* retorna um void pointer para a informacao removida
*/
Info removeStack(Pilha p);

/*
* cria um no
* nao recebe parametros
* retorna o no criado
*/
No criarNo();

/*
* retorna se a pilha esta vazia
* recebe um void pointer para a pilha
* retorna um int
*/
int isEmptyStack(Pilha pilha);

/*
* retorna o topo de uma pilha
* recebe um void pointer
* retorno o no do topo
*/
No getTopo(Pilha p);

/*
* obtem o tamanho da pilha
* recebe um void pointer para a pilha
* retorna um int tamanho
*/
int getTamnhoStack(Pilha p);

/*
* deleta a pilha
* recebe um void pointer pilha
* nao retorna nada
*/
void deleteStack(Pilha p);

/*
* obtem o node anterior
* recebe um void pointer pra um node
* retorna um void pointer no
*/
No getAnterior(No elemento);

#endif
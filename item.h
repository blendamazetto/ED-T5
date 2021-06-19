#ifndef __ITEM__
#define __ITEM__

#include <stdio.h>
#include "lista.h"

typedef void *Item;

//Cria um item que sera salvo na hashfile
Item createItem(char chave[], Info valor);

//aloca esse item
Item alocarItem(int tamCh, int tamRec);

//atraves da funcao de hashing, retorna uma chave
char* getChaveItem(Item item);

//retorna um ponteiro para a informacao desse item
Info getValorItem(Item item);

//desaloca o valor de um item
void desalocaValorItem(Item item);

//desaloca o item em si
void desalocaItem(Item item);

#endif
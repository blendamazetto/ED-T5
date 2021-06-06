#include "ponto.h"

#ifndef __POSTO_H
#define __POSTO_H

//Define "Posto" como um void pointer
typedef void* Posto;

/*
*Cria uma struct posto
*Precisa dos parametros necessarios para a criação de um posto
*Retorna um void pointer para a struct posto
*/
Posto criaPosto(char id[], double x, double y, double distancia);

/*
*Copia o valor contido em um no para outro no
*Precisa de um void pointer casos como parametro
*Retorna nada
*/
void copiarNo(Posto posto1, Posto posto2);

/*
*Obtem o identificador para o posto
*Precisa de um void pointer casos como parametro
*Retorna o identificador (id) do posto
*/
char* getPostoId(Posto posto);

/*
*Obtem o eixo x do posto
*Precisa de um void pointer casos como parametro
*Retorna o eixo x (x) do posto
*/
double getPostoX(Posto posto);

/*
*Obtem o eixo y do posto
*Precisa de um void pointer casos como parametro
*Retorna o eixo y (y) do posto
*/
double getPostoY(Posto posto);

/*
*Obtem a distancia dada para o Posto
*Precisa de um void pointer casos como parametro
*Retorna a distando (distancia) para o posto
*/
double getPostoDistancia(Posto posto);

/*
*Armazena um valor que é passado como parametro no identificador também passado por parametro
*Precisa de um void pointer Posto e de um valor para o identificador
*Não retorna nada
*/
void setPostoId(Posto posto, char id[]);

/*
*Armazena um valor que é passado como parametro no eixo x também passado por parametro
*Precisa de um void pointer Posto e de um valor para o eixo x
*Não retorna nada
*/
void setPostoX(Posto posto, double x);

/*
*Armazena um valor que é passado como parametro no eixo y também passado por parametro
*Precisa de um void pointer Posto e de um valor para o eixo y
*Não retorna nada
*/
void setPostoY(Posto posto, double y);

/*
*Armazena um valor que é passado como parametro para a distancia também passada por parametro
*Precisa de um void pointer Posto e de um valor para a distancia
*Não retorna nada
*/
void setPostoDistancia(Posto posto, double distancia);

/*
* obtem o ponto de um posto
* precisa de um void pointer para um posto
* retorna um void pointer para o ponto do posto
*/
Ponto getPostoPonto(Posto posto);

/*
* seta um ponto em um posto
* recebe um void pointer para o posto e um void pointer para o ponto 
* nao retorna nada
*/
void setPostoPonto(Posto posto, Ponto ponto);

/*
* troca dois postos
* recebe dois void pointers para os postos que serao invertidos
* nao retorna nada
*/
void swapPosto(Posto posto1, Posto posto2);

/*
* desaloca a memoria alocada por um ponto
* precisa de um void pointer para o posto
* nao retorna nada
*/
void desalocarPontoPosto(Posto posto);

#endif

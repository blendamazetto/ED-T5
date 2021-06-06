#include "ponto.h"
#include "quadtree.h"

#ifndef __QUADRA_H
#define __QUADRA_H

//Define "Quadra" como um void pointern 
typedef void* Quadra;

/*
*Cria uma struct quadra
*Precisa dos parametros necessarios para a criação de uma quadra
*Retorna um void pointer para a struct quadra
*/
Quadra criaQuadra(char cep[], double x, double y, double w, double h, char sw[], char cfill[], char cstrk[]);

/*
*Obtem o cep de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna o indice (i) do circulo
*/
char* getQuadraCep(Quadra quadra);

/*
*Obtem o x de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna o eixo x de uma quadra
*/
double getQuadraX(Quadra quadra);

/*
*Obtem o y de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna o eixo y de uma quadra
*/
double getQuadraY(Quadra quadra);

/*
*Obtem a largura de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a largura(W) de uma quadra
*/
double getQuadraW(Quadra quadra);

/*
*Obtem a altura de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a altura(H) de uma quadra
*/
double getQuadraH(Quadra quadra);

/*
*Obtem a sw de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a sw(Sw) de uma quadra
*/
char* getQuadraSw(Quadra quadra);

/*
*Obtem a cor de stroke de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a cor de stroke(Cfill) de uma quadra
*/
char* getQuadraCfill(Quadra quadra);

/*
*Obtem a cor de fill de uma quadra
*Precisa de um void pointer quadra como parametro
*Retorna a cor de fill(Cstrk) de uma quadra
*/
char* getQuadraCstrk(Quadra quadra);

/*
*Armazena uma string cep em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraCep(Quadra quadra, char cep[]);

/*
*Armazena um valor de x em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraX(Quadra quadra, double x);

/*
*Armazena um valor de y em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraY(Quadra quadra, double y);

/*
*Armazena um valor de w em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraW(Quadra quadra, double w);

/*
*Armazena um valor h em uma quadra
*Precisa de um void pointer quadra e um valor double
*Não retorna nada
*/
void setQuadraH(Quadra quadra, double h);

/*
*Armazena uma string de sw em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraSw(Quadra quadra, char sw[]);

/*
*Armazena uma string com a cor de stroke em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraCfill(Quadra quadra, char cfill[]);

/*
*Armazena uma string com a cor de fill em uma quadra
*Precisa de um void pointer quadra e uma string
*Não retorna nada
*/
void setQuadraCstrk(Quadra quadra, char cstrk[]);

/*
* obtem a densidade de uma quadra
* precisa de um void pointer para um quadra
* retorna a densidade da quadra
*/
double getQuadraDensidade(Quadra quadra);

/*
* seta um double na densidade da quadra 
* precisa de um void pointer quadra e um valor para ser setado
* nao retorna nada
*/
void setQuadraDensidade(Quadra quadra, double densidade);

/*
* obtem o ponto de uma quadra
* precisa de um void pointer para uma quadra
* retorna um void pointer para o ponto da quadra
*/
Ponto getQuadraPonto(Quadra quadra);

/*
* seta o ponto de uma quadra
* precisa de um void pointer pra quadra e um void pointer para um ponto 
* nao retorna nada
*/
void setQuadraPonto(Quadra quadra, Ponto ponto);

/*
* troca duas quadras
* precisa de dois void pointers para as quadras que sera invertidas
* nao retorna nada
*/
void swapQuadra(Quadra q1, Quadra q2);

/*
* desaloca a memoria alocada por uma quadra
* precisa de um void pointer para uma quadra
* nao retorna nada
*/
void desalocaQuadra(Quadra quadra);

#endif
#include "ponto.h"

#ifndef __CIRCULO_H
#define __CIRCULO_H

//Define "Circulo" como um void pointer
typedef void* Circulo;

/*
*Cria uma struct circulo
*Precisa dos parametros necessarios para a criação de um circulo
*Retorna um void pointer para a struct circulo
*/
Circulo criaCirculo(char i[], double r, double x, double y, char sw[], char corb[], char corp[]);

/*
*Obtem o indice do circulo
*Precisa de um void pointer circulo como parametro
*Retorna o indice (i) do circulo
*/
char* getCirculoI(Circulo circulo);

/*
*Obtem o raio do circulo
*Precisa de um void pointer circulo como parametro
*Retorna o raio (r) do circulo
*/
double getCirculoR(Circulo circulo);

/*
*Obtem o eixo x do circulo
*Precisa de um void pointer circulo como parametro
*Retorna o eixo x (x) do circulo
*/
double getCirculoX(Circulo circulo);

/*
*Obtem o eixo y do circulo
*Precisa de um cvoid pointer irculo como parametro
*Retorna o eixo y (y) do circulo
*/
double getCirculoY(Circulo circulo);

/*
 *Obtem a sw do circulo
 *Precisa de void pointer circulo como parametro
 *Retorna a sw sw do circulo
 */
char* getCirculoSw(Circulo circulo);

/*
*Obtem a cor da stroke do circulo
*Precisa de um void pointer circulo como parametro
*Retorna a cor da stroke (corb) do circulo
*/
char* getCirculoCorb(Circulo circulo);

/*
*Obtem o cor de fill do circulo
*Precisa de um void pointer circulo como parametro
*Retorna a cor de fill (corp) do circulo
*/
char* getCirculoCorp(Circulo circulo);

/*
*Armazena um valor que é passado como parametro no indice do circulo também passado por parametro
*Precisa de um void pointer circulo e de um valor inteiro
*Não retorna nada
*/
void setCirculoI(Circulo circulo, char i[]);

/*
*Armazena um valor que é passado como parametro no raio do circulo também passado por parametro
*Precisa de um void pointer circulo e de um valor para o raio
*Não retorna nada
*/
void setCirculoR(Circulo circulo, double r);

/*
*Armazena um valor que é passado como parametro no eixo x do circulo também passado por parametro
*Precisa de um void pointer circulo e de um valor para o eixo x
*Não retorna nada
*/
void setCirculoX(Circulo circulo, double x);

/*
*Armazena um valor que é passado como parametro no eixo y do circulo também passado por parametro
*Precisa de um void pointer circulo e de um valor para o eixo y
*Não retorna nada
*/
void setCirculoY(Circulo circulo, double y);

/*
 *Armazena um valor que e passado como parametro da sw do circulo tambem passado por parametro
 *Precisa de um void pointer circulo e do valor para a sw que sera alterada
 *Não retorna nada
 */
void setCirculoSw(Circulo circulo, char sw[]);

/*
*Armazena um valor que é passado como parametro na cor da stroke do circulo também passado por parametro
*Precisa de um void pointer circulo e de uma string
*Não retorna nada
*/
void setCirculoCorb(Circulo circulo, char corb[]);

/*
*Armazena um valor que é passado como parametro na cor de fill do circulo também passado por parametro
*Precisa de um void pointer circulo e de uma string
*Não retorna nada
*/
void setCirculoCorp(Circulo circulo, char corp[]);

/*
*Obtem o ponto de um circulo
*precisa de um void pointer para um circulo
*retorna um ponteiro para o ponto
*/
Ponto getCirculoPonto(Circulo circulo);

/*
*seta o ponto de um circulo
*precisa de um void pointer para o circulo e um void pointer ponto que sera setado 
*não retorna nada
*/
void setCirculoPonto(Circulo circulo, Ponto ponto);

/*
*Troca dois circulos
*precisa de dois void pointer circulo para serem invertidos
*
*/
void swapCirculo(Circulo c1, Circulo c2);

/*
*Desaloca a memoria alocada por um ciculo
*precisa de um void pointer circulo
*não retorna nada
*/
void desalocarPontoCirculo(Circulo circulo);

#endif

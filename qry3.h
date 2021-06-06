#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY3_h
#define __QRY3_h

/*
    *Faz contas para colocar um retangulo laranja na face determinada no comando
    *Precisamos de um void ointer com as listas, os dois arquivos de saida como parametro para a funcao
    *Alem dos dados necessarios para a criacao do retangulo
    *Retorna nada
*/
void cv (QuadTree arvoresObjetos[], double n, char cep[], char face[], double num, Lista listasQry[]);

/*
    *Comando soc do QRY
    *Precisamos dos parametros passados no comando, a lista que contem os postos e parametros pra gerar as saidas 
    *Retorna nada
    
*/
void soc(QuadTree arvoresObjetos[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[]);

/*
    *Utilizando funcoes determinadas implementa o comando ci
    *Precisamos de um void pointer para lista os eixos e raio e tambem o documento de saida
    *Nao retorna nada
*/
void ci(FILE* saida, QuadTree arvoresObjetos[], double x, double y, double r, Lista listasQry[], FILE* saidaSvgQry);

#endif
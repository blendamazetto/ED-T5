#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY2_h
#define __QRY2_h

/*
    *Verifica as quadras dentro de uma certa regiao do equipamente urbano
    *Precizamos do void pointer com as listas, os dois arquivos de s aida como parametro para a funcao, o id de 
    *identificacao, a distancia e o identificador para saber se ha ou nao um # no comando
    *Retorna nada
    
*/
void dq(FILE *saida, QuadTree arvoresObjetos[], int flag, char id[], double r, Lista listasQry[]);

/*
    *Remove a forma dos equipamentos urbanos de identificacao j
    *Precizamos do vetor lista, a identificacao, e os arquivos de saida como parametro para a funcao
    *Retorna nada
    
*/
void del(FILE* saida, QuadTree arvoresObjetos[], char j[], Lista listasQry[]);

/*
    *Muda a cor da borda das quadras contidas dentro de um determinado espaco em circulo
    *Precizamos das coordenadas, a cor para ser alterada, o vetor lista, e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
    * 
*/
void cbq(QuadTree arvoresObjetos[], double x, double y, double r, char corb[], FILE* saida);

/*
    *Imprime no arquivo as coordenadas e qual o tipo de equipamento urbano e
    *Precizamos do vetor lista, a identificacao, e o arquivo de saida como parametro para a funcao
    *Retorna nada
    
*/
void crd(QuadTree arvoresObjetos[], char id[], FILE* saida);

/*
    *Faz os calculos para ver a area da quadra e equipamentos urbanos dentro de um retangulo
    *Precizamos das coordenadas e tamanhos do retangulo, o vetor lista, e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
*/
void car (QuadTree arvoresObjetos[], double x, double y, double w, double h, FILE* saida, Lista listasQry[]);

#endif
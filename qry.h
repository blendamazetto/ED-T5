#ifndef __QRY_h
#define __QRY_h
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "posto.h"
#include "densidade.h"
#include <math.h>
#include "textoNumerico.h"
#include "linha.h"
#include "poligono.h"
#include "casos.h"
#include "ponto.h"
#include "lista.h"
#include "stack.h"
#include "quadtree.h"

/*
    *Calcula a distancia entre duas figuras
    *Precisamos das coordenadas dessas figuras
    *Retorna a distancia entre elas
*/
double distancia(double x1, double y1, double x2, double y2);

/*
    *Faz contas para saber se ha um ponto interno no circulo
    *Precisamos dos eixos x, y de ambos Ponto e Circulo e do raio do circulo
    *Retorna a distancia
*/
int pontoInternoCirc(Ponto ponto, double xCirc, double yCirc, double r);

/*
    *Faz as contar para saber se um ponto e interno a um retangulo
    *recebe os paramentros do ponto e do retangulo
    *retorna um int 
*/
int pontoInternoRet(Ponto ponto, double xRet, double yRet, double w, double h);

/*
    *Faz contas para saber a orientacao 
    *Precisamos de tres elementos para calculo da area
    *Retorna 1 para area > 1, -1 para area <1 e 0 caso nao satisfaca nenhum dos dois
*/
int orientacao(Ponto a, Ponto b, Ponto c);

/*
    *Faz contas para saber a comparacao entre tres pontos
    *Precisamos de tres elementos
    *Retorna a funcao de distancia caso aux == 0 ou aux == 1
*/
int comparar(Ponto p0, Ponto a, Ponto b);

/*
    *Faz contas para saber a particao de dois pontos
    *Precisamos de um void pointer para lista e dois pontos primeiro e ultimo
    *Retorna i do tipo No
*/
No partition(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

/*
    *Faz utilizacao de recursividade e implementa quicksort
    *Precisamos de um void pointer para lista e de dois nos primeiro e ultimo
    *Nao retorna nada
*/
void quickSortList(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

/*
    *Faz contas para a envoltoria convexa
    *Precisamos de um void pointer para lista
    *Retorna o resultado da envoltoria convexa
*/
Lista convexHull(Lista list, Ponto (*getPonto)(Info), void (*swap)(Info, Info));

/*
    *obtem a info de um ponto
    *precisa de um void pointer ponto
    *retorna um void pointer ponto
*/
Ponto defaultGetPonto(Ponto info);

/*
    * balanceia uma quadtree
    * recebe uma quadtree, uma lista e dois ponteiros pra funcao
    * nao retorna nada
*/
void balancearQuadTree(QuadTree qt, Lista l, Ponto (*getPonto)(void*), void (*swap)(void*, void*));

/*
    * usa o cep, a face e o num pra descobrir o ponto
    * recebe o cep, a face e o num e a quadtree de quadras
    * retorna o ponto descoberto
*/
Ponto descobrirPonto(char cep[], char face[], double num, QuadTree tree);

/*
    *Calcula se um numero e maior ou menor que o outro
    *Precizamos de dois numeros passando pelo parametro para serem comparados
    *Retorna o numero maior
    
*/
float max(float n1, float n2);

/*
    *Calcula se um numero e maior ou menor que o outro
    *Precizamos de dois numeros passando pelo parametro para serem comparados
    *Retorna o numero menor
    
*/
float min(float n1, float n2);

/*
    *Faz os calculos para ver se ha colisao entre um retangulo e um circulo
    *Precizamos de dois void pointer e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
    
*/
void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[]);

/*
    *Faz os calculos para ver se ha colisao entre um circulo e outro circulo
    *Precizamos de dois void pointer e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
    
*/
void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[]);

/*
    *Faz os calculos para ver se ha colisao entre um retangulo e outro retangulo
    *Precizamos de dois void pointer e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
    
*/
void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[]);

/*
    *verifica se um retangulo e interno a um circulo
    *recebe os parametros de um retangulo e de um circulo
    *retorna um int
*/
int retInternoCirc(double xRet, double yRet, double w, double h, double x, double y, double r);

/*
    *Ordena um vetor
    *Precisamos de um ponteiro para um vetor e o tamanho do vetor
    *Retorna nada
    
*/
void shellSort(double *vet, int size);

/*
    *Faz as contas necessarias para obter a area da regiao
    *Precisamos de um void pointer para lista
    *Retorna a area
*/
double obterArea(Lista l);

/*
    *Faz contas para saber o centroide em uma determinada regiao
    *Precisamos de um void pointer para lista e da area
    *Retorna a funcao criaPosto com dados obtidos 
*/
Ponto centroide(Lista l, double area);

#endif
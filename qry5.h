#ifndef __QRY5_h
#define __QRY5_h

#include "lista.h"
#include "quadtree.h"
#include "qry.h"
#include "hashtable.h"
#include "morador.h"
#include "pessoa.h"
#include "estabelecimentoComercial.h"
#include "svg.h"
#include "grafo.h"
#include "ponto.h"
#include "path.h"

/*
    *Armazena no registrador r a posição geográfica da residência do morador de cpf.
*/
void mQuestionMark(int r, char cpf[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[]);

/*
    *Armazena no registrador r a posição geográfica do endereço cep/face/num
    SVG: linha vertical com identificação do registrador.
*/
void eQuestionMark(int r, char cep[], char face[], double num, QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[]);

/*
    *Armazena no registrador r a posição geográfica do equipamento urbano cujo identificador é id
*/
void gQuestionMark(int r, char id[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[]);

/*
    *Armazena no registrador r a posição geográfica (x,y)
*/
void xy(int r, double x, double y, Ponto registradores[], Lista listasQry[]);

/*
    *Produz uma árvore geradora mínima que representa as ciclovias implantadas na cidade.
*/
void ccv(Grafo grafo, char sufx[], char saidaQry[]);

/*
    *melhor trajeto de carro entre a rigem que está que no registrador r1 e o
    destino que está no registrador r2.
*/
void pQuestionMark(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg,  int idPInt);

/*
    Calcula o percurso por ciclovias. Semelhante a p?, mas o cálculo considera a árvore geradora mínima.
*/
void pb(int r1, int r2, char cmc[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg, int idPInt);

/*
    *Interdita trechos de ruas (face de quadra)
    com mais que max casos de covid.
*/
void bf(int max, Grafo grafo, Lista casosCovid, FILE* saida, Lista listasQry[], QuadTree arvoresObjetos[]);

/*
    *melhor trajeto de carro entre a rigem que está que no registrador r1 e o
    destino que está no registrador r2. 
    evita toda a região com casos de covid.
*/
void sp(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Lista casosCovid, FILE* saida, Ponto registradores[], FILE *svg, int idPInt, Envoltoria env, int idEnv);

#endif
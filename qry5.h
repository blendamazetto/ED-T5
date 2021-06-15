#include "lista.h"
#include "quadtree.h"
#include "qry.h"
#include "hashtable.h"
#include "morador.h"
#include "pessoa.h"
#include "estabelecimentoComercial.h"
#include "svg.h"
#include "grafo.h"

#ifndef __QRY5_h
#define __QRY5_h

void mQuestionMark(int r, char cpf[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[]);

void eQuestionMark(int r, char cep[], char face[], double num, QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[]);

void gQuestionMark(int r, char id[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[]);

void xy(int r, double x, double y, Ponto registradores[], Lista listasQry[]);

void ccv(Grafo grafo, char saida[], char sufx[]);

void pQuestionMark(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg);

void pb(int r1, int r2, char cmc[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg);

#endif
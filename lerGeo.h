#ifndef __LERGEO_H
#define __LERGEO_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "posto.h"
#include "densidade.h"
#include "estabelecimentoComercial.h"
#include "pessoa.h"
#include "morador.h"
#include "quadtree.h"
#include "hashtable.h"
#include "codt.h"
#include "aresta.h"
#include "vertice.h"
#include "grafo.h"

/*
*Le o arquivo geo
*precisa do nome do arquivo geo, o nome do svg que sera gerado, uma lista para salvar as informacoes inicialmente, uma quadtree na qual as informacoes serao salvas, e um hashtable
*não retorna nada
*/
void lerGeo(char arqGeo[], char nomeSvgGeo[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[], Lista hashAux[]);

/*
*Le o arquivo geo
*precisa do nome do arquivo geo, uma lista para salvar as informacoes inicialmente, uma quadtree na qual as informacoes serao salvas, e um hashtable
*não retorna nada
*/
void lerEc(char arqEc[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[], Lista hashAux[]);

/*
*Le o arquivo geo
*precisa do nome do arquivo geo, uma lista para salvar as informacoes inicialmente, uma quadtree na qual as informacoes serao salvas, e um hashtable
*não retorna nada
*/
void lerPm(char arqPm[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[], Lista hashAux[]);

void lerVia(char arqVia[], Grafo grafo);


#endif
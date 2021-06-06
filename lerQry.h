#ifndef __leitura_h
#define __leitura_h
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "qry.h"
#include "posto.h"
#include "densidade.h"
#include "textoNumerico.h"
#include "linha.h"
#include "casos.h"
#include "poligono.h"
#include "quadtree.h"
#include "hashtable.h"
#include "qry1.h"
#include "qry2.h"
#include "qry3.h"
#include "qry4.h"

/*
*Le o arquivo Qry e realiza suas funçcoes
*precisa do nome do arquivo qry e a lista
*não retorna nada
*/
void lerQry (char saidaQry[], char arqQry[], Lista listasQry, QuadTree arvoresObjetos[], Hash tabelas[], Lista listasObjetos[]);

#endif
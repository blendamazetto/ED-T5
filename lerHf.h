#ifndef __LERHF__
#define __LERHF__

#include <stdio.h>
#include "lista.h"
#include "quadtree.h"
#include "hashfile.h"
#include "item.h"
#include "pessoa.h"
#include "morador.h"
#include "estabelecimentoComercial.h"
#include "codt.h"
#include "hashtable.h"

void saveHashfile(char nomebase[], Hash tabelas[], QuadTree arvoresObjetos[], int tamanhoCodt, int tamanhoPessoa);

void readHashfile(char nomebase[], Hash tabelas[], Lista est, Lista mor, Lista listasObjetos[]);

#endif
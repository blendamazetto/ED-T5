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

/*
    Utlizada no comando "-k", salva as informacoes em uma hashfile
    recebe parametros para fazer a conversao das informacoes nas estruturas de dados para hashfile 
*/
void saveHashfile(char nomebase[], Hash tabelas[], QuadTree arvoresObjetos[], int tamanhoCodt, int tamanhoPessoa);

/*
    Utlizada no comando "-u", le as infomacoes salvas em arquivos binarios e os armazena nas estruturas de dados
    recebe parametros para fazer a conversao da hashfile nas estruturas de dados
*/
void readHashfile(char nomebase[], Hash tabelas[], Lista est, Lista mor, Lista listasObjetos[]);

#endif
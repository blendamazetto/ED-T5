#include "lista.h"
#include "quadtree.h"
#include "qry.h"
#include "hashtable.h"
#include "morador.h"
#include "pessoa.h"
#include "estabelecimentoComercial.h"
#include "svg.h"

#ifndef __QRY4_h
#define __QRY4_h

/*
    * lista os moradores de uma quadra
    * recebe uma quadtree, uma hashtable, um file saida, um cep, e uma lista
    * nao retorna nada
*/
void m(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cep[], Lista listasObjetos[]);

/*
    * Imprime todos os dados do morador identificad pelo cpf
    * recebe uma quadtree, uma hashtable, um file saida, um cpf, e duas listas
    * nao retorna nada
*/
void dm (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], Lista listasObjetos[]);

/*
    * Imprime todos os dados do estabelecimento comercial identificado por cnpj
    * recebe uma quadtree, uma hashtable, um file saida, um cnpj, e duas listas
    * nao retorna nada
*/
void de(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cnpj[], Lista listasObjetos[]);

/*
    * A pessoa identificada por cpf muda-se para o endereço determinado pelos parâmetros.
    * recebe uma quadtree, uma hashtable, um file saida, parametors do comando, e duas listas
    * nao retorna nada
*/
void mud(QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], char cep[], char face[], double num, char compl[], Lista listasObjetos[]);

/*
    * Imprime o estado atual de uma árvore
    * recebe uma quadtree, um char, um file saida, um char com o sufixo
    * nao retorna nada
*/
void dmprbt(QuadTree arvoresObjetos[], char t, char saida[], char sfx[]);

/*
    * imprime e destaca dados sobre os estabelecimentos comerciais dentro de uma area
    * recebe uma quadtree, uma hashtable, um file saida, parametros do comando, e duas listas
    * nao retorna nada
*/
void epgl (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], double x, double y, double w, double h, Lista listasObjetos[], char tp[]);

/*
    * Remover os nos que estejam inteiramente contidas na circunferênciade raio r e centro em x e y
    * recebe uma quadtree, uma hashtable, um file saida, parametros do comando, e duas listas
    * nao retorna nada
*/
void catac (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], double x, double y, double r);

#endif
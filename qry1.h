#include "lista.h"
#include "quadtree.h"
#include "qry.h"

#ifndef __QRY1_h
#define __QRY1_h

/*
    *Faz as comparacoes do comando o? para saber qual funcao de colisao chamar
    *Precizamos dos dois ids, o vetor lista, e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
    
*/
void o(char j[], char k[], QuadTree arvoresObjetos[], Lista listasQry[], FILE* saida);

/*
    *Faz as comparacoes do comando i? para saber qual funcao deve ser chamada chamar
    *Precizamos do vetor lista, o id, as coordenadas e os dois arquivos de saida como parametro para a funcao
    *Retorna nada
    
*/
void i (char j[], double x, double y, QuadTree arvoresObjetos[], Lista listasQry[], FILE* saida);

/*
    *Muda a cor das bordas e do preenchimento dos elementos selecionados
    *Precizamos das coordenadas, a cor para ser alterada, o vetor lista, e o arquivo de saida como parametro para a funcao
    *Retorna nada
    
*/
void pnt (char j[], char corb[], char corp[], QuadTree arvoresObjetos[], FILE* saida);

/*
    *Remove a forma de identificacao j
    *Precizamos do vetor lista, a identificacao, e o arquivo de saida como parametro para a funcao
    *Retorna nada
    
*/
void delf(FILE* saida, QuadTree arvoresObjetos[], char j[]);

#endif
#ifndef __VERTICE_H
#define __VERTICE_H

typedef void* Vertice;

//Cria um vertice
Vertice criaVertice(char id[], double x, double y);

/*
    Retorna o Id de um vertice
*/
char* getVerticeId(Vertice vertice);

/*
    retorna o valor x de um vertice
*/
double getVerticeX(Vertice vertice);

/*
    retorna o valor y de um vertice
*/
double getVerticeY(Vertice vertice);

/*
    aloca um novo vertice com as informacoes do vertice passado como parametro
*/
Vertice copiarVertice(Vertice vert);

#endif
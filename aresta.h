#ifndef __ARESTA_H
#define __ARESTA_H

typedef void* Aresta;

Aresta criaAresta(char i[], char j[], char ldir[], char lesq[], double cmp, double vm, char nomeRua[]);

//Função para retornar o Id de uma aresta
char* getArestaI(Aresta aresta);

//retorna o destino de uma aresta
char* getArestaJ(Aresta aresta);

//retorna a quadra a direita de uma aresta
char* getArestaLdir(Aresta aresta);

//retorna a quadra a esquerda de uma aresta
char* getArestaLesq(Aresta aresta);

//retorna o nome da rua de uma aresta
char* getArestaNomeRua(Aresta aresta);

//retorna o comprimento de uma aresta
double getArestaCmp(Aresta aresta);

//retorna a velocidade media de uma aresta
double getArestaVm(Aresta aresta);

//retorna o o tempo gasto para percorre uma aresta dividindo o comprimento pela velocidade media
double getArestaTempo(Aresta aresta);

//aloca uma nova aresta com as informacoes da aresta passada como parametro
Aresta copiarAresta(Aresta aresta);

#endif
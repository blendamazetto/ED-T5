#ifndef __PESSOA_H_
#define __PESSOA_H_

#include "grafo.h"
#include "ponto.h"
#include "lista.h"

typedef void* Path;

//Cria um "path", utilizado para fazer as animacoes no svg
Path criaPath(Grafo grafo, Ponto inicial, Ponto final, Lista vertices, char cor[], int idPInt);

//desenha no svg um path, contendo as animacoes
void desenhaPathSvg(Path path, FILE *svg);

//desaloca as informacoes de um path, incluindo a lista de pontos
void desalocarPath(No node);

#endif
#ifndef __PESSOA_H_
#define __PESSOA_H_

#include "grafo.h"
#include "ponto.h"
#include "lista.h"

typedef void* Path;

Path criaPath(Grafo grafo, Ponto inicial, Ponto final, Lista vertices, char cor[], int idPInt);

void desenhaPathSvg(Path path, FILE *svg);

#endif
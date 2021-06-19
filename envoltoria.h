#ifndef __ENVOLTORIA__
#define __ENVOLTORIA__

#include "ponto.h"
#include "lista.h"

typedef void* Envoltoria;

//cria uma envoltoria convexa
Envoltoria createEnvoltoria();

//adiciona um "vertice" na envoltoria, cada vertice é uma envoltoria
void criarVerticeEnvoltoria(Envoltoria env, int id, char cor[]);

//adiciona um ponto em uma envoltoria
void adicionarPontoEnvoltoria(int id, Ponto ponto, Envoltoria env);

//printa a envoltoria no svg
void printarEnvoltoria(Envoltoria env, FILE *svg);

//desaloca as listas e os pontos usados na envoltoria
void desalocarEnv(Lista env);

#endif
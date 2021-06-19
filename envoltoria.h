#ifndef __ENVOLTORIA__
#define __ENVOLTORIA__

#include "ponto.h"
#include "lista.h"

typedef void* Envoltoria;

Envoltoria createEnvoltoria();

void criarVerticeEnvoltoria(Envoltoria env, int id, char cor[]);

void adicionarPontoEnvoltoria(int id, Ponto ponto, Envoltoria env);

void printarEnvoltoria(Envoltoria env, FILE *svg);

void desalocarEnv(Lista env);

#endif
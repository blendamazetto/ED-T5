#ifndef __TRATAMENTO_H
#define __TRATAMENTO_H

#include "lerGeo.h"
#include "lista.h"
#include "lerQry.h"
#include "quadtree.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "posto.h"
#include "hashtable.h"
#include "grafo.h"
#include "lerHf.h"

/*
    Pega os argumentos passados, faz as adaptacoes e chama as funcoes de leitura
*/
void tratamento(char *dir_entrada, char *arq_geoNome, char *arq_consulta, char *dir_saida, char *arq_ecNome, char *arq_pmNome, char *arq_viaNome, char*nomebaseRead, char *nomebaseWrite);

#endif
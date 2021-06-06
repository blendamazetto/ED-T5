#ifndef __SVG_H
#define __SVG_H
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "lista.h"
#include "svg.h"
#include "qry.h"
#include "posto.h"
#include "densidade.h"
#include "textoNumerico.h"
#include "linha.h"
#include "poligono.h"
#include <string.h>


/*
    *Inicia o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto e passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void iniciaSvg(FILE* svg);

/*
    *Desenha um circulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o circulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaCirculo(Circulo c, FILE* svg);

/*
    *Desenha um retangulo tracejado no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetanguloTracejado(Retangulo r, FILE* svg);

/*
    *Desenha um retangulo arredondade no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetanguloArredondado(Retangulo r, FILE* svg);

/*
    *Desenha um retangulo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRetangulo(Retangulo r, FILE* svg);

/*
    *Escreve um texto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTexto(Texto t, FILE* svg);

/*
    *Escreve um texto do tipo numerico no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o texto e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void escreveTextoNumerico(TextoNumerico t, FILE* svg);

/*
    *Desenha uma quadra no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a quadra, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaQuadra(Quadra q, FILE* svg);

/*
    *Desenha um hidrante no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o hidrante, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaHidrante(Hidrante h, FILE* svg);

/*
    *Desenha um semaforo no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o semaforo, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaSemaforo(Semaforo s, FILE* svg);

/*
    *Desenha uma torre no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a torre, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaRadioBase(Radiobase rb, FILE* svg);

/*
    *Desenha um posto no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a criacao do posto, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaPosto(Posto p, FILE* svg);

/*
    *Desenha uma linha no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinha(Linha l, FILE* svg);

/*
    *Desenha uma linha tracejada no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para a linha tracejada, o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaLinhaTracejada(Linha l, FILE* svg);

/*
    *Desenha um circulo meio transparente no arquivo svg, colcocando o comando adequado para isso
    *E passado como parametro todos os dados necessarios para o retangulo e o arquivo svg para ser aberto
    *Retorna nada, fecha o svg apenas.
    * 
*/
void desenhaCirculoTransparente(Circulo c, FILE* svg);

/*
    *Finaliza o arquivo svg colocando o comando necessario nele
    *Apenas o arquivo svg a ser aberto e passado como parametro
    *Retorna nada, fecha o svg apenas.
    * 
*/
void finalizaSvg(FILE* svg);

/*
* gera o svg de acordo com as quadtrees
* precisa de um ponteiro file
* nao retorna nada
*/
void gerarSvgGeo(FILE* svg, QuadTree tree[], Lista l);

/*
    *Imprime os elementos guardados na quadtree no arquivo svg feito para o qry
    *Precisa das quadtrees e do arquivo a ser editado
    *Retorna nada.
    * 
*/
void gerarSvgQry(QuadTree arvoresObjetos[], Lista listasQry[], FILE* saidaSvgQry);


#endif

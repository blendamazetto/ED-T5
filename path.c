#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "path.h"

typedef struct{
    Grafo grafo;
    Ponto inicial;
    Ponto final;
    Lista vertices;
    char cor[100];
    int idPInt;
}PathStruct;

Path criaPath(Grafo grafo, Ponto inicial, Ponto final, Lista vertices, char cor[], int idPInt)
{
    PathStruct* ps = (PathStruct*) malloc(sizeof(PathStruct));

    ps->grafo = grafo;
    ps->inicial = createPonto(getPontoX(inicial), getPontoY(inicial));
    ps->final = createPonto(getPontoX(final), getPontoY(final));
    strcpy(ps->cor, cor);
    ps->idPInt = idPInt;

    ps->vertices = create();

    for(No node = getFirst(vertices); node != NULL; node = getNext(node))
    {
        Vertice v = getInfo(node);
        insert(ps->vertices, copiarVertice(v));
    }

    return ps;
}

void desenhaPathSvg(Path path, FILE *svg)
{
    PathStruct* ps = (PathStruct*) path;
    
    int primeiro = 1;
    fprintf(svg, "\n\t<path style=\"fill:none;stroke:%s;stroke-width:2px;stroke-linecap:butt;stroke-linejoin:miter;stroke-opacity:1\"\n\t d=\" M", ps->cor);

    for(No node = getFirst(ps->vertices); node != NULL; node = getNext(node))
    {
        Vertice v = getInfo(node);

        if(primeiro == 1)
        {
            fprintf(svg, " %f %f", getVerticeX(v), getVerticeY(v));
            primeiro = 0;
        }
        else
        {
            fprintf(svg, "L %f %f", getVerticeX(v), getVerticeY(v));
        }
    }
    fprintf(svg, "\" id=\"%d\" />", ps->idPInt);
    fprintf(svg, "\n\t<circle cx=\"\" cy=\"\" r=\"5\" fill=\"red\"><animateMotion dur=\"6s\" repeatCount=\"indefinite\"><mpath xlink:href=\"#%d\"/></animateMotion></circle>\n", ps->idPInt);
}
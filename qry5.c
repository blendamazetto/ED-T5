#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry5.h"

void mQuestionMark(int r, char cpf[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[])
{
    Info morador = getInfoByIdQt(arvoresObjetos[9], cpf);

    if(morador == NULL)
    {
        return;
    }

    setPontoX(registradores[r], getPontoX(getMoradorPonto(morador)));
    setPontoY(registradores[r], getPontoY(getMoradorPonto(morador)));

    Linha l = criaLinha(getPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)), getPontoX(getMoradorPonto(morador)), 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", getPontoX(getMoradorPonto(morador)), 11, "black", "black", texto);
    insert(listasQry[4], t);

}

void eQuestionMark(int r, char cep[], char face[], double num, QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[])
{
    setPontoX(registradores[r], getPontoX(descobrirPonto(cep, face, num, arvoresObjetos[3])));
    setPontoY(registradores[r], getPontoY(descobrirPonto(cep, face, num, arvoresObjetos[3])));

    Linha l = criaLinha(getPontoX(registradores[r]), getPontoY(registradores[r]), getPontoX(registradores[r]), 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", getPontoX(registradores[r]), 11, "black", "black", texto);
    insert(listasQry[4], t);
}

void gQuestionMark(int r, char id[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[])
{
    Info info;
    double x,y;

    switch(id[0]) 
    {
        case 'h':
            info = getInfoByIdQt(arvoresObjetos[4], id);
            x = getHidranteX(info);
            y = getHidranteY(info);

            break;
        
        case 's':
            info = getInfoByIdQt(arvoresObjetos[5], id);
            x = getSemaforoX(info);
            y = getSemaforoY(info);

            break;

        case 'r':
            info = getInfoByIdQt(arvoresObjetos[6], id);
            x = getRadiobaseX(info);
            y = getRadiobaseY(info);

            break;
    }

    setPontoX(registradores[r], x);
    setPontoY(registradores[r], y);

    Linha l = criaLinha(x, y, x, 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", x, 11, "black", "black", texto);
    insert(listasQry[4], t);
}

void xy(int r, double x, double y, Ponto registradores[], Lista listasQry[])
{
    setPontoX(registradores[r], x);
    setPontoY(registradores[r], y);

    Linha l = criaLinha(x, y, x, 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", x, 11, "black", "black", texto);
    insert(listasQry[4], t);
}

void ccv(Grafo grafo, char sufx[], char saidaQry[])
{
    int tam = tamanhoDaLista(grafo);

    char* pathSvg = malloc((6 + strlen(sufx) + strlen(saidaQry))*sizeof(char));
    sprintf(pathSvg,"%s-%s.svg", saidaQry, sufx);
    FILE* svg = fopen(pathSvg, "w");
    iniciaSvg(svg);

    Grafo prim = algoritmoPrim(grafo, tam);

    printarGrafo(grafo, svg, "black");
    printarGrafo(prim, svg, "yellow");

    finalizaSvg(svg);
    free(pathSvg);
    fclose(svg);
}

void pQuestionMark(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg)
{
    char inicial[60];
    char final[60];
    int tam = tamanhoDaLista(grafo);
    double x1, y1, x2, y2;

    strcpy(inicial, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r1])));
    strcpy(final, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r2])));

    Lista maisCurto = dijsktraCMP(grafo, inicial, final, tam);
    Lista maisRapido = dijsktraVM(grafo, inicial, final, tam);

    if(maisCurto == NULL || maisRapido == NULL)
    {
        return;
    }

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">INICIO</text>\n", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), "black", "black");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ",getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">FIM</text>\n", getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), "black", "black");

    fprintf(saida, "PERCURSO MAIS CURTO:\n");
    fprintf(saida, "Inicia no vertice com ID: %s\n", inicial);
    
    for(No node = getFirst(maisCurto); getNext(node) != NULL; node = getNext(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getNext(node));
        if(vertice2 == NULL)
        {
            break;
        }
        x1 = getVerticeX(vertice1) + 1;
        y1 = getVerticeY(vertice1) + 1;
        x2 = getVerticeX(vertice2) + 1;
        y2 = getVerticeY(vertice2) + 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"5\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmc);

        fprintf(saida, "vai para o vertice com ID: %s\n", getVerticeId(vertice2));
    }

    fprintf(saida, "FINAL PERCURSO MAIS CURTO\n");
    fprintf(saida, "PERCURSO MAIS RAPIDO:\n");
    fprintf(saida, "Inicia no vertice com ID: %s\n", inicial);

    for(No node = getFirst(maisRapido); getNext(node) != NULL; node = getNext(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getNext(node));
        if(vertice2 == NULL)
        {
            break;
        }
        x1 = getVerticeX(vertice1) - 1;
        y1 = getVerticeY(vertice1) - 1;
        x2 = getVerticeX(vertice2) - 1;
        y2 = getVerticeY(vertice2) - 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"5\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmr);

        fprintf(saida, "vai para o vertice com ID: %s\n", getVerticeId(vertice2));
    }

    fprintf(saida, "FINAL PERCURSO MAIS RAPIDO\n");
}

void pb(int r1, int r2, char cmc[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg)
{
    char inicial[60];
    char final[60];
    int tam = tamanhoDaLista(grafo);
    double x1, y1, x2, y2;

    strcpy(inicial, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r1])));
    strcpy(final, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r2])));

    Lista maisCurto = dijsktraCMP(grafo, inicial, final, tam);

    if(maisCurto == NULL)
    {
        return;
    }

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">INICIO</text>\n", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), "black", "black");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ",getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">FIM</text>\n", getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), "black", "black");

    fprintf(saida, "PERCURSO MAIS CURTO:\n");
    fprintf(saida, "Inicia no vertice com ID: %s\n", inicial);
    
    for(No node = getFirst(maisCurto); getNext(node) != NULL; node = getNext(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getNext(node));
        if(vertice2 == NULL)
        {
            break;
        }
        x1 = getVerticeX(vertice1) + 1;
        y1 = getVerticeY(vertice1) + 1;
        x2 = getVerticeX(vertice2) + 1;
        y2 = getVerticeY(vertice2) + 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"5\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmc);

        fprintf(saida, "vai para o vertice com ID: %s\n", getVerticeId(vertice2));
    }

    fprintf(saida, "FINAL PERCURSO MAIS CURTO\n");
}

void bf(int max, Grafo grafo, Lista casosCovid, FILE* saida, Lista listasQry[], QuadTree arvoresObjetos[])
{
    char quadra[25];
    int somaLeste = 0;
    int somaOeste = 0;

    for(No node = getFirst(casosCovid); node != NULL; node = getNext(node))
    {
        somaLeste = 0;
        somaOeste = 0;

        Info info = getInfo(node);
        strcpy(quadra, getCasosCEP(info));

        for(No no = getFirst(casosCovid); no != NULL; no = getNext(no))
        {
            Info inf = getInfo(node);
            if(strcmp(quadra, getCasosCEP(inf)) == 0)
            {
                if(strcmp(getCasosFace(inf), "L") == 0)
                {
                    somaLeste = somaLeste + getCasosN(inf);
                }
                if(strcmp(getCasosFace(inf), "O") == 0)
                {
                    somaOeste = somaOeste + getCasosN(inf);
                }
            }
        }

        if(somaLeste > max)
        {
            Info q = getInfoByIdQt(arvoresObjetos[3], quadra);

            removerArestabyLdir(grafo, quadra);
            fprintf(saida, "CEP: %s FACE: %s\n", quadra, getCasosFace(info));

            Linha l = criaLinha((getQuadraX(q) - 2), getQuadraY(q), (getQuadraX(q) - 2), (getQuadraY(q) + getQuadraH(q)), "red");
            insert(listasQry[2], l);
        }

        if(somaOeste > max)
        {
            Info q = getInfoByIdQt(arvoresObjetos[3], quadra);

            removerArestabyLesq(grafo, quadra);
            fprintf(saida, "CEP: %s FACE: %s\n", quadra, getCasosFace(info));

            Linha l = criaLinha((getQuadraX(q) + getQuadraW(q) + 2), getQuadraY(q), (getQuadraX(q) + getQuadraW(q) + 2), (getQuadraY(q) + getQuadraH(q)), "red");
            insert(listasQry[2], l);
        }
    }
}


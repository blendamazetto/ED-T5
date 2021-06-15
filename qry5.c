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

    double x = getPontoX(getMoradorPonto(morador));
    double y = getPontoY(getMoradorPonto(morador));

    registradores[r] = createPonto(GetPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)));

    Linha l = criaLinha(GetPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)), GetPontoX(getMoradorPonto(morador)), 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", GetPontoX(getMoradorPonto(morador)), 0, "black", "black", texto);
    insert(listasQry[4], t);

}

void eQuestionMark(int r, char cep[], char face[], double num, QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[])
{
    registradores[r] = criaPonto(getPontoX(descobrirPonto(cep, face, num, arvoresObjetos[3])), getPontoY(descobrirPonto(cep, face, num, arvoresObjetos[3])));

    Linha l = criaLinha(getPontoX(registradores[r]), getPontoY(registradores[r]), getPontoX(registradores[r]), 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", getPontoX(registradores[r]), 0, "black", "black", texto);
    insert(listasQry[4], t);
}

void gQuestionMark(int r, char id[], QuadTree arvoresObjetos[], Ponto registradores[], Lista listasQry[])
{
    Info info;
    Ponto p;
    double x,y;

    switch(id[0]) 
    {
        case 'h':
            info = getInfoByIdQt(arvoresObjetos[4], id);
            p = getHidrantePonto(info);
            x = getHidranteX(info);
            y = getHidranteY(info);

            break;
        
        case 's':
            info = getInfoByIdQt(arvoresObjetos[5], id);
            p = getSemaforoPonto(info);
            x = getSemaforoX(info);
            y = getSemaforoY(info);

            break;

        case 'r':
            info = getInfoByIdQt(arvoresObjetos[6], id);
            p = getRadiobasePonto(info);
            x = getRadiobaseX(info);
            y = getRadiobaseY(info);

            break;
    }

    registradores[r] = criaPonto(x, y);

    Linha l = criaLinha(x, y, x, 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", x, 0, "black", "black", texto);
    insert(listasQry[4], t);
}

void xy(int r, double x, double y, Ponto registradores[], Lista listasQry[])
{
    registradores[r] = criaPonto(x, y);

    Linha l = criaLinha(x, y, x, 0, "black");
    insert(listasQry[2], l);

    char texto[30];
    sprintf(texto,"REGISTRADOR %i", r);

    Texto t = criaTexto("0", x, 0, "black", "black", texto);
    insert(listasQry[4], t);
}

void ccv(Grafo grafo, char saida[], char sufx[])
{
    int tam = tamanhoDaLista(grafo);

    char* pathSvg = malloc((6 + strlen(sufx) + strlen(saida))*sizeof(char));
    sprintf(pathSvg,"%s-%s.svg", saida, sufx);

    FILE* svg = fopen(pathSvg, "w");

    Grafo prim = algoritmoPrim(grafo, tam);
    
    iniciaSvg(svg);

    printarGrafo(grafo, svg, "black");
    printarGrafo(prim, svg, "yellow");

    finalizaSvg(svg);
    free(pathSvg);
}

void pQuestionMark(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg)
{
    char inicial[60];
    char final[60];
    int tam = tamanhoDaLista(grafo);
    double x1, y1, x2, y2;

    if (getVerticebyPonto(grafo, GetPontoX(registradores[r1]), getPontoY(registradores[r1])) == NULL && getVerticebyPonto(grafo, GetPontoX(registradores[r2]), getPontoY(registradores[r2])) == NULL)
    {
        fprintf(saida,"VERTICE INEXISTENTE\n");
        return;
    }

    strcpy(inicial, getVerticebyPonto(grafo, GetPontoX(registradores[r1]), getPontoY(registradores[r1])));
    strcpy(final, getVerticebyPonto(grafo, GetPontoX(registradores[r2]), getPontoY(registradores[r2])));

    Lista maisCurto = dijsktraCMP(grafo, inicial, final, tam);
    Lista maisRapido = dijsktraVM(grafo, inicial, final, tam);

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getVerticeX(getFirst(maisCurto)), getVerticeY(getFirst(maisCurto)), 5, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">INICIO</text>\n", getVerticeX(getFirst(maisCurto)), getVerticeY(getFirst(maisCurto)), "black", "black");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ",getVerticeX(getLast(maisCurto)), getVerticeY(getLast(maisCurto)), 5, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">FIM</text>\n", getVerticeX(getLast(maisCurto)), getVerticeY(getLast(maisCurto)), "black", "black");

    fprintf(saida, "PERCURSO MAIS CURTO:\n");
    fprintf(saida, "Inicia no vertice com ID: %s\n", inicial);
    
    for(No node = getFirst(maisCurto); getNext(node) != NULL; node = getNext(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getNext(node));
        x1 = getVerticeX(vertice1) + 1;
        y1 = getVerticeY(vertice1) + 1;
        x2 = getVerticeX(vertice2) + 1;
        y2 = getVerticeY(vertice2) + 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmc);

        fprintf(saida, "vai para o vertice com ID: %s\n", getVerticeId(vertice2));
    }

    fprintf(saida, "FINAL PERCURSO MAIS CURTO\n");
    fprintf(saida, "PERCURSO MAIS RAPIDO:\n");
    fprintf(saida, "Inicia no vertice com ID: %s\n", inicial);

    for(No node = getFirst(maisRapido); getNext(node) != NULL; node = getNext(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getNext(node));
        x1 = getVerticeX(vertice1) - 1;
        y1 = getVerticeY(vertice1) - 1;
        x2 = getVerticeX(vertice2) - 1;
        y2 = getVerticeY(vertice2) - 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmr);

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

    if (getVerticebyPonto(grafo, GetPontoX(registradores[r1]), getPontoY(registradores[r1])) == NULL && getVerticebyPonto(grafo, GetPontoX(registradores[r2]), getPontoY(registradores[r2])) == NULL)
    {
        fprintf(saida,"VERTICE INEXISTENTE\n");
        return;
    }

    strcpy(inicial, getVerticebyPonto(grafo, GetPontoX(registradores[r1]), getPontoY(registradores[r1])));
    strcpy(final, getVerticebyPonto(grafo, GetPontoX(registradores[r2]), getPontoY(registradores[r2])));

    Lista maisCurto = dijsktraCMP(grafo, inicial, final, tam);

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getVerticeX(getFirst(maisCurto)), getVerticeY(getFirst(maisCurto)), 5, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">INICIO</text>\n", getVerticeX(getFirst(maisCurto)), getVerticeY(getFirst(maisCurto)), "black", "black");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ",getVerticeX(getLast(maisCurto)), getVerticeY(getLast(maisCurto)), 5, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">FIM</text>\n", getVerticeX(getLast(maisCurto)), getVerticeY(getLast(maisCurto)), "black", "black");

    fprintf(saida, "PERCURSO MAIS CURTO:\n");
    fprintf(saida, "Inicia no vertice com ID: %s\n", inicial);
    
    for(No node = getFirst(maisCurto); getNext(node) != NULL; node = getNext(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getNext(node));
        x1 = getVerticeX(vertice1) + 1;
        y1 = getVerticeY(vertice1) + 1;
        x2 = getVerticeX(vertice2) + 1;
        y2 = getVerticeY(vertice2) + 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmc);

        fprintf(saida, "vai para o vertice com ID: %s\n", getVerticeId(vertice2));
    }

    fprintf(saida, "FINAL PERCURSO MAIS CURTO\n");
}


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

void pQuestionMark(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg, int idPInt)
{
    char inicial[60];
    char final[60];
    int tam = tamanhoDaLista(grafo);
    double x1, y1, x2, y2;
    char ultimaRua[200] = "\0";
    char direcao[10];

    strcpy(inicial, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r1])));
    strcpy(final, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r2])));

    Ponto pInicial = createPonto(getVerticeX(encontrarVerticeMaisProximo(grafo, registradores[r1])), getVerticeY(encontrarVerticeMaisProximo(grafo, registradores[r1])));
    Ponto pFinal = createPonto(getVerticeX(encontrarVerticeMaisProximo(grafo, registradores[r2])), getVerticeY(encontrarVerticeMaisProximo(grafo, registradores[r2])));

    Lista maisCurto = dijsktra(grafo, inicial, final, tam, getArestaCmp);
    Lista maisRapido = dijsktra(grafo, inicial, final, tam, getArestaTempo);

    if(maisCurto == NULL || maisRapido == NULL)
    {
        return;
    }

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">INICIO</text>\n", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), "black", "black");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ",getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">FIM</text>\n", getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), "black", "black");

    fprintf(saida, "PERCURSO MAIS CURTO:\n");
    
    for(No node = getLast(maisCurto); getNext(node) != NULL; node = getPrevious(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getPrevious(node));
        if(vertice2 == NULL)
        {
            break;
        }
        x1 = getVerticeX(vertice1) + 1;
        y1 = getVerticeY(vertice1) + 1;
        x2 = getVerticeX(vertice2) + 1;
        y2 = getVerticeY(vertice2) + 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"5\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmc);

        if(strcmp(ultimaRua, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2)))) != 0)
        {
            getDirecao(x1, x2, y1, y2, direcao);
            fprintf(saida, "Siga na direcao %s na Rua: %s\n", direcao, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2))));
            strcpy(ultimaRua, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2))));
        }
    }

    fprintf(saida, "FINAL PERCURSO MAIS CURTO\n");
    fprintf(saida, "PERCURSO MAIS RAPIDO:\n");

    for(No node = getLast(maisRapido); getNext(node) != NULL; node = getPrevious(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getPrevious(node));
        if(vertice2 == NULL)
        {
            break;
        }
        x1 = getVerticeX(vertice1) - 1;
        y1 = getVerticeY(vertice1) - 1;
        x2 = getVerticeX(vertice2) - 1;
        y2 = getVerticeY(vertice2) - 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"5\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmr);

        if(strcmp(ultimaRua, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2)))) != 0)
        {
            getDirecao(x1, x2, y1, y2, direcao);
            fprintf(saida, "Siga na direcao %s na Rua: %s\n", direcao, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2))));
            strcpy(ultimaRua, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2))));
        }    
    }

    fprintf(saida, "FINAL PERCURSO MAIS RAPIDO\n");

    Path pathMaisCurto = criaPath(grafo, pInicial, pFinal, maisCurto, cmc, idPInt);
    idPInt = idPInt + 1;
    Path pathMaisRapido = criaPath(grafo, pInicial, pFinal, maisRapido, cmc, idPInt);

    desenhaPathSvg(pathMaisCurto, svg);
    desenhaPathSvg(pathMaisRapido, svg);

    free(pInicial);
    free(pFinal);

    desalocarPath(pathMaisCurto);
    desalocarPath(pathMaisRapido);

    removeList(maisCurto, free);
    removeList(maisRapido, free);
}

void pb(int r1, int r2, char cmc[], Grafo grafo, Ponto registradores[], FILE *saida, FILE *svg, int idPInt)
{
    char inicial[60];
    char final[60];
    int tam = tamanhoDaLista(grafo);
    double x1, y1, x2, y2;
    char ultimaRua[200] = "\0";
    char direcao[10];

    strcpy(inicial, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r1])));
    strcpy(final, getVerticeId(encontrarVerticeMaisProximo(grafo, registradores[r2])));

    Ponto pInicial = createPonto(getVerticeX(encontrarVerticeMaisProximo(grafo, registradores[r1])), getVerticeY(encontrarVerticeMaisProximo(grafo, registradores[r1])));
    Ponto pFinal = createPonto(getVerticeX(encontrarVerticeMaisProximo(grafo, registradores[r2])), getVerticeY(encontrarVerticeMaisProximo(grafo, registradores[r2])));

    Lista maisCurto = dijsktra(grafo, inicial, final, tam, getArestaCmp);

    if(maisCurto == NULL)
    {
        return;
    }

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">INICIO</text>\n", getVerticeX(getVertice(grafo, inicial)), getVerticeY(getVertice(grafo, inicial)), "black", "black");
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ",getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), 5.0, "yellow", "yellow");
    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">FIM</text>\n", getVerticeX(getVertice(grafo, final)), getVerticeY(getVertice(grafo, final)), "black", "black");

    fprintf(saida, "PERCURSO MAIS CURTO:\n");
    
    for(No node = getLast(maisCurto); getNext(node) != NULL; node = getPrevious(node))
    {
        Vertice vertice1 = getInfo(node);
        Vertice vertice2 = getInfo(getPrevious(node));
        if(vertice2 == NULL)
        {
            break;
        }
        x1 = getVerticeX(vertice1) + 1;
        y1 = getVerticeY(vertice1) + 1;
        x2 = getVerticeX(vertice2) + 1;
        y2 = getVerticeY(vertice2) + 1;

        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke-width=\"5\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cmc);

        if(strcmp(ultimaRua, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2)))) != 0)
        {
            getDirecao(x1, x2, y1, y2, direcao);
            fprintf(saida, "Siga na direcao %s na Rua: %s\n", direcao, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2))));
            strcpy(ultimaRua, getArestaNomeRua(getAresta(grafo, getVerticeId(vertice1), getVerticeId(vertice2))));
        }
    }

    fprintf(saida, "FINAL PERCURSO MAIS CURTO\n");

    Path pathMaisCurto = criaPath(grafo, pInicial, pFinal, maisCurto, cmc, idPInt);

    desenhaPathSvg(pathMaisCurto, svg);

    free(pInicial);
    free(pFinal);

    desalocarPath(pathMaisCurto);

    removeList(maisCurto, free);
}

void bf(int max, Grafo grafo, Lista casosCovid, FILE* saida, Lista listasQry[], QuadTree arvoresObjetos[])
{
    FILE *svaaab;
    svaaab = fopen("./testes/antes.svg", "w");
    fprintf(svaaab, "<svg version=\"1.1\" baseProfile=\"full\" width=\"10000\" height=\"10000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    printarGrafo(grafo, svaaab, "red");
    fprintf(svaaab, "</svg>");

    char quadra[25];
    int somaLeste = 0;
    int somaOeste = 0;
    int somaSul = 0;
    int somaNorte = 0;

    for(No node = getFirst(casosCovid); node != NULL; node = getNext(node))
    {
        somaLeste = 0;
        somaOeste = 0;
        somaSul = 0;
        somaNorte = 0;

        Info info = getInfo(node);
        strcpy(quadra, getCasosCEP(info));

        for(No no = getFirst(casosCovid); no != NULL; no = getNext(no))
        {
            Info inf = getInfo(no);
            if(strcmp(quadra, getCasosCEP(inf)) == 0)
            {
                if(strcmp(getCasosFace(inf), "L") == 0)
                {
                    somaLeste = somaLeste + getCasosN(inf);
                }
                else if(strcmp(getCasosFace(inf), "O") == 0)
                {
                    somaOeste = somaOeste + getCasosN(inf);
                }
                else if(strcmp(getCasosFace(inf), "N") == 0)
                {
                    somaNorte = somaNorte + getCasosN(inf);
                }
                else if(strcmp(getCasosFace(inf), "S") == 0)
                {
                    somaSul = somaSul + getCasosN(inf);
                }
            }
        }
        if(somaLeste > max)
        {
            Info q = getInfoByIdQt(arvoresObjetos[3], quadra);
            fprintf(saida, "CEP: %s FACE: %s\n", quadra, getCasosFace(info));
            Linha l = criaLinha((getQuadraX(q) - 3), getQuadraY(q), (getQuadraX(q) - 3), (getQuadraY(q) + getQuadraH(q)), "red");
            insert(listasQry[2], l);
            removerBf(grafo, "L", quadra);

        }
        if(somaOeste > max)
        {
            Info q = getInfoByIdQt(arvoresObjetos[3], quadra);
            fprintf(saida, "CEP: %s FACE: %s\n", quadra, getCasosFace(info));
            Linha l = criaLinha((getQuadraX(q) + getQuadraW(q) + 3), getQuadraY(q), (getQuadraX(q) + getQuadraW(q) + 3), (getQuadraY(q) + getQuadraH(q)), "red");
            insert(listasQry[2], l);
            removerBf(grafo, "O", quadra);

        }
        if(somaNorte > max)
        {
            Info q = getInfoByIdQt(arvoresObjetos[3], quadra);
            fprintf(saida, "CEP: %s FACE: %s\n", quadra, getCasosFace(info));
            Linha l = criaLinha(getQuadraX(q), (getQuadraY(q) + getQuadraH(q) + 3) ,(getQuadraX(q) + getQuadraW(q)), (getQuadraY(q) + getQuadraH(q) + 3), "red");
            insert(listasQry[2], l);
            removerBf(grafo, "N", quadra);

        }
        if(somaSul > max)
        {
            Info q = getInfoByIdQt(arvoresObjetos[3], quadra);
            fprintf(saida, "CEP: %s FACE: %s\n", quadra, getCasosFace(info));
            Linha l = criaLinha(getQuadraX(q), (getQuadraY(q) - 3) ,(getQuadraX(q) + getQuadraW(q)), (getQuadraY(q) - 3), "red");
            insert(listasQry[2], l);
            removerBf(grafo, "S", quadra);
        }
    }

    //removerVerticeDesconexo(grafo);

    FILE *svaaa;
    svaaa = fopen("./testes/depois.svg", "w");
    fprintf(svaaa, "<svg version=\"1.1\" baseProfile=\"full\" width=\"10000\" height=\"10000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    printarGrafo(grafo, svaaa, "red");
    fprintf(svaaa, "</svg>");
}

void sp(int r1, int r2, char cmc[], char cmr[], Grafo grafo, Lista casosCovid, FILE* saida, Ponto registradores[], FILE *svg,  int idPInt, Envoltoria env, int idEnv)
{
    Grafo copia = copiarGrafo(grafo);
    Ponto ponto;
    Lista l = create();
    Lista casos = NULL;

    for(No node = getFirst(casosCovid); node != NULL; node = getNext(node))
    {
        Info info = getInfo(node);
        ponto = getCasosPonto(info);
        insert(l, ponto);
    }
    if(tamanhoDaLista(l) > 2)
    {
        casos = convexHull(l,NULL,swapPonto);
    }
    if(casos == NULL)
    {
        casos = l;
    }
    else
    {
        removeList(l,NULL);
    }

    criarVerticeEnvoltoria(env, idEnv, "yellow");
    
    for(No node = getFirst(casos); node != NULL; node = getNext(node))
    {
        Info a = getInfo(node);
        Ponto p = createPonto(getPontoX(a), getPontoY(a));
        adicionarPontoEnvoltoria(idEnv, p, env);
    }

    removerVerticesDentroPoligono(copia, casos);

    pQuestionMark(r1, r2, cmc, cmr, copia, registradores, saida, svg, idPInt);

    removeList(casos, NULL);

    desalocarGrafo(copia);
}
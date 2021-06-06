#include<stdio.h>
#include<stdlib.h>
#include"svg.h"

void iniciaSvg(FILE* svg)
{
    char* corSombra[6] = {"#FFFF00", "#FF9955", "#FF0000", "#FF00CC", "#6600FF", "#A02C5A"};

    fprintf(svg, "<svg>\n\t<defs>\n");

    for(int i = 0; i < 6; i++)
    {
        fprintf(svg, "\t\t<filter id=\"shadow%d\">\n\t\t\t<feDropShadow dx=\"2\" dy=\"2\" stdDeviation=\"0.2\" flood-color=\"%s\"/>\n\t\t</filter>\n", i, corSombra[i]);
    }
    fprintf(svg, "\t</defs>\n");
}

void desenhaCirculo(Circulo c, FILE* svg)
{
    double x = getCirculoX(c);
    double y = getCirculoY(c);
    double raio = getCirculoR(c);
    char cor_b[22];
    char cor_p[22];
    strcpy(cor_b, getCirculoCorb(c));
    strcpy(cor_p, getCirculoCorp(c));

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, cor_p);
}

void desenhaRetangulo(Retangulo r, FILE* svg)
{   
    double x = getRetanguloX(r);
    double y = getRetanguloY(r);
    double h = getRetanguloH(r);
    double w = getRetanguloW(r);
    char cor_p[22];
    char cor_b[22];
    strcpy(cor_b, getRetanguloCorb(r));
    strcpy(cor_p, getRetanguloCorp(r));

    fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width =\"1\"/>\n",x,y,w,h,cor_p,cor_b);
}

void desenhaRetanguloTracejado(Retangulo r, FILE* svg)
{
    double x = getRetanguloX(r);
    double y = getRetanguloY(r);
    double h = getRetanguloH(r);
    double w = getRetanguloW(r);
    char cor_b[22];
    strcpy(cor_b, getRetanguloCorb(r));

    fprintf(svg, "\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke=\"%s\" stroke-width =\"1\" stroke-dasharray=\"1\" />\n",x,y,w,h,cor_b);
}

void desenhaRetanguloArredondado(Retangulo r, FILE* svg)
{
    double x = getRetanguloX(r);
    double y = getRetanguloY(r);
    double h = getRetanguloH(r);
    double w = getRetanguloW(r);
    char sw[22];
    strcpy(sw, getRetanguloSw(r));

    fprintf(svg, "\n<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"beige\" stroke=\"olive\"  stroke-width=\"%s\" rx=\"20\"/>\n",x,y,w,h,sw);
}

void escreveTexto(Texto t, FILE* svg)
{
    double x = getTextoX(t);
    double y = getTextoY(t);
    char cor_b[22];
    char cor_p[22];
    char text[1000];
    strcpy(cor_b, getTextoCorb(t));
    strcpy(cor_p, getTextoCorp(t));
    strcpy(text, getTextoTxto(t));

    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%s</text>\n",x,y,cor_b,cor_p,text);
}

void escreveTextoNumerico(TextoNumerico t, FILE* svg)
{
    double x = getTextoNumericoX(t);
    double y = getTextoNumericoY(t);
    char cor_b[22];
    char cor_p[22];
    double texto = getTextoNumericoTexto(t);
    strcpy(cor_b, getTextoNumericoCorb(t));
    strcpy(cor_p, getTextoNumericoCorp(t));

    fprintf(svg,"\t<text x=\"%lf\" y=\"%lf\" stroke=\"%s\" stroke-width=\"0.3\" fill=\"%s\">%lf</text>\n", x, y, cor_b, cor_p, texto);
}


void desenhaQuadra(Quadra q, FILE* svg)
{
    int aux;
    double x = getQuadraX(q);
    double y = getQuadraY(q);
    double h = getQuadraH(q);
    double w = getQuadraW(q);
    double d = getQuadraDensidade(q);
    char cor_p[22];
    char cor_b[22];
    char qSW[22];
    char cep[22];
    strcpy(cor_b, getQuadraCstrk(q));
    strcpy(cor_p, getQuadraCfill(q));
    strcpy(qSW, getQuadraSw(q));
    strcpy(cep, getQuadraCep(q));

    if(d <= 500)
    {
        aux = 0;
    }
    else if(d <= 1500)
    {
        aux = 1;
    }
    else if(d <= 3000)
    {
        aux = 2;
    }
    else if(d <= 4500)
    {
        aux = 3;
    }
    else if(d <= 6000)
    {
        aux = 4;
    }
    else
    {
        aux = 5;
    }

    fprintf(svg,"\t<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" stroke-width=\"%s\" filter=\"url(#shadow%d)\" />\n",x, y, w, h, cor_p, cor_b, qSW, aux);
    fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\" fill=\"black\">%s</text>\n", x+w/4, y+h/2, cep);
}

void desenhaHidrante(Hidrante h, FILE* svg)
{
    double raio = 1;
    double x = getHidranteX(h);
    double y = getHidranteY(h);
    char cor_b[22];
    char cor_p[22]; 
    char hSW[22];
    strcpy(cor_b, getHidranteCstrk(h));
    strcpy(cor_p, getHidranteCfill(h));
    strcpy(hSW, getHidranteSw(h));

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, hSW,cor_p);
}

void desenhaSemaforo(Semaforo s, FILE* svg)
{
    double raio = 1;
    double x = getSemaforoX(s);
    double y = getSemaforoY(s);
    char cor_b[22];
    char cor_p[22]; 
    char sSW[22];
    strcpy(cor_b, getSemaforoCstrk(s));
    strcpy(cor_p, getSemaforoCfill(s));
    strcpy(sSW, getSemaforoSw(s));

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, sSW, cor_p);
}

void desenhaRadioBase(Radiobase rb, FILE* svg)
{
    double raio = 1;
    double x = getRadiobaseX(rb);
    double y = getRadiobaseY(rb);
    char cor_b[22];
    char cor_p[22]; 
    char rbSW[22];
    strcpy(cor_b, getRadiobaseCstrk(rb));
    strcpy(cor_p, getRadiobaseCfill(rb));
    strcpy(rbSW, getRadiobaseSw(rb));

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" stroke-width=\"%s\" fill=\"%s\"/>\n ", x, y, raio, cor_b, rbSW, cor_p);
}

void desenhaPosto(Posto p, FILE* svg)
{
    double x = getPostoX(p);
    double y = getPostoY(p);
    
    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%d\" stroke=\"%s\" fill=\"%s\"/>\n ", x, y, 5, "green", "blue");
}

void desenhaLinha(Linha l, FILE* svg)
{
    double x1 = getLinhaX1(l);
    double x2 = getLinhaX2(l);
    double y1 = getLinhaY1(l);
    double y2 = getLinhaY2(l);
    char cor[22];
    strcpy(cor, getLinhaCor(l));

    fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"%s\"/>\n", x1, y1, x2, y2, cor);
}

void desenhaLinhaTracejada(Linha l, FILE* svg)
{
    double x1 = getLinhaX1(l);
    double x2 = getLinhaX2(l);
    double y1 = getLinhaY1(l);
    double y2 = getLinhaY2(l);

    fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" stroke=\"black\" stroke-width=\"2\" stroke-dasharray=\"5\" />\n ", x1, y1, x2, y2);
}

void desenhaCirculoTransparente(Circulo c, FILE* svg)
{
    double x = getCirculoX(c);
    double y = getCirculoY(c);
    double raio = getCirculoR(c);
    char cor_b[22];
    char cor_p[22];
    strcpy(cor_b, getCirculoCorb(c));
    strcpy(cor_p, getCirculoCorp(c));

    fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" stroke=\"%s\" fill=\"%s\" opacity=\"0.5\" />\n ", x, y, raio, cor_b, cor_p);
}

void finalizaSvg(FILE* svg)
{
    fprintf(svg, "</svg>");
}

void gerarSvgGeo(FILE* svg, QuadTree tree[], Lista l)
{
    No node;

    void (*desenhar[8])(void*, FILE*) = {desenhaCirculo, desenhaRetangulo, escreveTexto, desenhaQuadra, desenhaHidrante, desenhaSemaforo, desenhaRadioBase, desenhaPosto};

    for(int i = 0; i < 8; i++)
    {
        percorreLarguraQt(tree[i],(void(*)(void*, void*))desenhar[i],svg);
    }

    if(l != NULL)
    {
        for(node = getFirst(l); node != NULL; node = getNext(node))
        {
            fprintf(svg,"\t<use xlink:href=\"#%d\"/>",*(int*)getInfo(node));
        }
    }
}

void gerarSvgQry(QuadTree arvoresObjetos[], Lista listasQry[], FILE* saidaSvgQry)
{
    gerarSvgGeo(saidaSvgQry, arvoresObjetos, NULL);

    int i=0;

    if(i==0)
    { 
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info textNum = getInfo(node);
            escreveTextoNumerico(textNum, saidaSvgQry);
        } 
        i++;
    }
    if(i==1)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetangulo(r, saidaSvgQry);         
        } 
        i++;
    }
    if(i==2)
    {
         No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info lin = getInfo(node);
            desenhaLinha(lin, saidaSvgQry);
        } 
        i++;
    }
    if(i==3)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info c = getInfo(node);
            desenhaCirculo(c, saidaSvgQry);
        } 
        i++;
    }
    if(i==4)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info t = getInfo(node);
            escreveTexto(t, saidaSvgQry);
        } 
        i++;
    }
    if(i==5)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetanguloTracejado(r, saidaSvgQry);
        } 
        i++;
    }
    if(i==6)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info r = getInfo(node);
            desenhaRetanguloArredondado(r, saidaSvgQry);
        } 
        i++;
    }
    if(i==7)
    { 
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info lin = getInfo(node);
            desenhaLinhaTracejada(lin, saidaSvgQry);
        } 
        i++;
    }
    if(i==8)
    {
        No node;
        for(node = getFirst(listasQry[i]); node != NULL; node = getNext(node))
        {
            Info circ = getInfo(node);
            desenhaCirculoTransparente(circ, saidaSvgQry);
        }
    }
}
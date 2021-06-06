#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry.h"

double distancia(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2,2) + pow(y1 - y2,2));
}

int pontoInternoCirc(Ponto ponto, double xCirc, double yCirc, double r)
{
    return distancia(getPontoX(ponto), getPontoY(ponto), xCirc, yCirc) <= r;
}

int pontoInternoRet(Ponto ponto, double xRet, double yRet, double w, double h)
{
    double dx = getPontoX(ponto) - xRet;
    double dy = getPontoY(ponto) - yRet;
    return dx >= 0 && dx <= w && dy >= 0 && dy <= h;
}

int orientacao(Ponto a, Ponto b, Ponto c)
{
    double area = (getPontoX(c) - getPontoX(b)) * (getPontoY(b) - getPontoY(a)) - (getPontoY(c) - getPontoY(b)) * (getPontoX(b) - getPontoX(a));

    if(area > 1)
    {
        return -1; //horario
    }
    if(area < 1)
    {
        return 1; //anti-horario
    }
    return 0; //colinear
}

int comparar(Ponto p0, Ponto a, Ponto b)
{
    int aux = orientacao(p0,a,b);

    if(aux == 0)
    {
        return distancia(getPontoX(p0),getPontoY(p0),getPontoX(b),getPontoY(b)) < distancia(getPontoX(p0),getPontoY(p0),getPontoX(a),getPontoY(a));
    }
    return aux == 1;
}

No partition(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info))
{
    No i = getPrevious(primeiro);

    for(No j = primeiro; j != ultimo; j = getNext(j))
    {
        if(comparar(getPonto(getInfo(getFirst(l))), getPonto(getInfo(j)), getPonto(getInfo(ultimo))))
        { 
            i = (i == NULL) ? primeiro : getNext(i); 
            swap(getInfo(i), getInfo(j));
        }
    }
    i = (i == NULL) ? primeiro : getNext(i); 
    swap(getInfo(i), getInfo(ultimo));
    return i; 
}

void quickSortList(Lista l, No primeiro, No ultimo, Ponto (*getPonto)(Info), void (*swap)(Info, Info))
{
    if(ultimo != NULL && primeiro != ultimo && getNext(ultimo) != primeiro)
    { 
        No p = partition(l, primeiro, ultimo, getPonto, swap);

        quickSortList(l, primeiro,getPrevious(p), getPonto, swap);
        quickSortList(l, getNext(p),ultimo, getPonto, swap);
    }
}

Lista convexHull(Lista list, Ponto (*getPonto)(Info), void (*swap)(Info, Info))
{
    if (getPonto == NULL) 
    {
        getPonto = defaultGetPonto;
    }

    if(tamanhoDaLista(list) < 3)
    {
        return NULL;
    }

    No primeiro = getFirst(list), i;
    Info aux = getInfo(primeiro);
    Ponto p2, p1;

    for(i = getNext(primeiro); i != NULL; i = getNext(i))
    {
        p2 = getPonto(getInfo(i));
        p1 = getPonto(aux);

        if(getPontoY(p2) < getPontoY(p1) || (getPontoY(p2) == getPontoY(p1) && getPontoX(p2) < getPontoX(p1)))
        {
            aux = getInfo(i);
        }
    }

    swap(getInfo(primeiro),aux);

    quickSortList(list, getNext(primeiro), getLast(list), getPonto, swap);

    int j = tamanhoDaLista(list);

    for(i = getNext(getNext(primeiro)); i != NULL; i = getNext(i))
    {
        p1 = getPonto(getInfo(i));
        p2 = getPonto(getInfo(getPrevious(i)));

        if(orientacao(getPonto(getInfo(primeiro)),p2,p1) == 0)
        {
            removerNo(list, getPrevious(i), 0);
            j--;
        }
    }
    if (j < 3)
    {
        return NULL;
    }

    Lista envConv = create();

    for(i = primeiro, j = 0; j < 3; j++, i = getNext(i))
    {
        insert(envConv, getPonto(getInfo(i)));
    }

    while(i != NULL)
    {
        while (orientacao(getInfo(getPrevious(getLast(envConv))), getInfo(getLast(envConv)), getPonto(getInfo(i))) != 1)
        {
            removerNo(envConv,getLast(envConv), 0);
        }
        insert(envConv, getPonto(getInfo(i)));
        i = getNext(i);
    }
    return envConv;
}

Ponto defaultGetPonto(Ponto info)
{
    return info;
}

void balancearQuadTree(QuadTree qt, Lista l, Ponto (*getPonto)(void*), void (*swap)(void*, void*))
{
    if (getPonto == NULL) 
    {
        getPonto = defaultGetPonto;
    }

    No i,j;
    Lista envCov;
    Pilha pilha = createStack();

    do{
        envCov = convexHull(l,getPonto,swap);

        if(envCov != NULL)
        {
            for(i = getFirst(envCov); i != NULL; i = getNext(i))
            {
                for(j = getFirst(l); j != NULL; j = getNext(j))
                {
                    if(getPonto(getInfo(j)) == getInfo(i))
                    {
                        insertStack(pilha, getInfo(j));
                        removerNo(l,j,0);
                        break;
                    }
                }
            }
            removeList(envCov,NULL);
        }
    }while (tamanhoDaLista(l) > 3);

    for(i = getFirst(l); i != NULL; i = getNext(i))
    {
        insertStack(pilha, getInfo(i));
    }
    while(!isEmptyStack(pilha))
    {
        j = removeStack(pilha);
        insereQt(qt,getPonto(j),j);
    }
    
    free(pilha);
}

Ponto descobrirPonto(char cep[], char face[], double num, QuadTree tree)
{
    double x, y;

    Info q = getInfoByIdQt(tree, cep);

    if(q != NULL)
    {
        if(strcmp(face, "N"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q) + getQuadraH(q);
        }

        else if(strcmp(face, "S"))
        {
            x = getQuadraX(q) + num;
            y = getQuadraY(q);
        }

        else if(strcmp(face, "L"))
        {
            x = getQuadraX(q);
            y = getQuadraY(q) + num;
        }

        else if(strcmp(face, "O"))
        {
            x = getQuadraX(q) + getQuadraW(q);
            y = getQuadraY(q) + num;
        }
    }
    Ponto p = createPonto(x,y);
    return p;
}

float max(float n1, float n2)
{
    if(n1 > n2)
    {
        return n1;
    }
    return n2;
}

float min(float n1, float n2)
{
    if(n1 > n2)
    {
        return n2;
    }
    return n1;
}

void retanguloxCirculo(Info circ, Info ret, FILE* saida, Lista listasQry[])
{
    float deltaX, deltaY, x, y, w, h;

    if(getCirculoX(circ) > getRetanguloX(ret))
    {
        deltaX = pow(getRetanguloX(ret) + getRetanguloW(ret) - getCirculoX(circ),2);
    }
    else
    {
        deltaX = pow(getRetanguloX(ret) - getCirculoX(circ),2);
    }
    if(getCirculoY(circ) > getRetanguloY(ret))
    {
        deltaY = pow(getRetanguloY(ret) + getRetanguloH(ret) - getCirculoY(circ),2);
    }
    else
    {
        deltaY = pow(getRetanguloY(ret) - getCirculoY(circ),2);
    }

    x = min(getRetanguloX(ret),getCirculoX(circ) - getCirculoR(circ));
    w = max(getRetanguloX(ret) + getRetanguloW(ret),getCirculoX(circ) + getCirculoR(circ)) - x;
    y = min(getRetanguloY(ret),getCirculoY(circ) - getCirculoR(circ));
    h = max(getRetanguloY(ret) + getRetanguloH(ret),getCirculoY(circ) + getCirculoR(circ)) - y;

    if(sqrt(deltaX + deltaY) <= getCirculoR(circ))
    {
        fprintf(saida,"%s: circulo %s: retangulo SIM\n", getCirculoI(circ), getRetanguloI(ret));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%s: circulo %s: retangulo NAO\n", getCirculoI(circ), getRetanguloI(ret));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);

    }
}

void circuloInt(Info c1, Info c2, FILE* saida, Lista listasQry[])
{
    float dist,x,y,w,h;

    dist = sqrt(pow(getCirculoX(c1) - getCirculoX(c2),2) + pow(getCirculoY(c1) - getCirculoY(c2),2));
    x = min(getCirculoX(c1) - getCirculoR(c1), getCirculoX(c2) - getCirculoR(c2));
    w = max(getCirculoX(c1) + getCirculoR(c1), getCirculoX(c2) + getCirculoR(c2)) - x;
    y = min(getCirculoY(c1) - getCirculoR(c1), getCirculoY(c2) - getCirculoR(c2));
    h = max(getCirculoY(c1) + getCirculoR(c1), getCirculoY(c2) + getCirculoR(c2)) - y;

    if(dist <= getCirculoR(c2) + getCirculoR(c1))
    {
        fprintf(saida,"%s: circulo %s: circulo SIM\n", getCirculoI(c1),getCirculoI(c2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%s: circulo %s: circulo NAO\n",getCirculoI(c1),getCirculoI(c2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);

    }
}

void retanguloInt(Info r1, Info r2, FILE* saida, Lista listasQry[])
{
    float x,w,y,h;
    x = min(getRetanguloX(r1),getRetanguloX(r2));
    w = max(getRetanguloX(r1) + getRetanguloW(r1),getRetanguloX(r2) + getRetanguloW(r2)) - x;
    y = min(getRetanguloY(r1),getRetanguloY(r2));
    h = max(getRetanguloY(r1) + getRetanguloH(r1),getRetanguloY(r2) + getRetanguloH(r2)) - y;

    if (w <= getRetanguloW(r1) + getRetanguloW(r2) && h <= getRetanguloH(r1) + getRetanguloH(r2))
    {
        fprintf(saida,"%s: retangulo %s: retangulo SIM\n", getRetanguloI(r1),getRetanguloI(r2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[1], ret);
    }
    else
    {
        fprintf(saida,"%s: retangulo %s: retangulo NAO\n", getRetanguloI(r1),getRetanguloI(r2));

        Retangulo ret = criaRetangulo("0", w,h,x,y, "1", "black", "none");
        insert(listasQry[5], ret);
    }
}

int retInternoCirc(double xRet, double yRet, double w, double h, double x, double y, double r)
{
    if(distancia(xRet,yRet,x,y) <= r && distancia(xRet + w ,yRet + h,x,y) <= r)
    {
        if(distancia(xRet + w, yRet,x,y) <= r && distancia(xRet, yRet + h,x,y) <= r)
        {
            return 1;
        }
    }
    return 0;
}

void shellSort(double *vet, int size) 
{
    int i, j;
    double value;
    int h = 1;

    while(h < size) 
    {
        h = 3*h+1;
    }
    while (h > 0) 
    {
        for(i = h; i < size; i++) 
        {
            value = vet[i];
            j = i;
            while (j > h-1 && value <= vet[j - h]) 
            {
                vet[j] = vet[j - h];
                j = j - h;
            }
            vet[j] = value;
        }
        h = h/3;
    }
}

double obterArea(Lista l){
    double a = 0;
    Info i, j;
    No node;
    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node)){
        i = getInfo(node);
        j = getInfo(getNext(node));
        a += getPontoX(i) * getPontoY(j) - getPontoY(i) * getPontoX(j);
    }
    i = getInfo(node);
    j = getInfo(getFirst(l));
    a += getPontoX(i) * getPontoY(j) - getPontoY(i) * getPontoX(j);
    return a/2;
}

Ponto centroide(Lista l, double area)
{
    double x = 0, y = 0;
    Info i, j;
    No node;
    for(node = getFirst(l); getNext(node) != NULL; node = getNext(node)){
        i = getInfo(node);
        j = getInfo(getNext(node));
        x += (getPontoX(i) + getPontoX(j)) * getPontoX(i) * getPontoY(j) - getPontoY(i) * getPontoX(j);
        y += (getPontoY(i) + getPontoY(j)) * getPontoX(i) * getPontoY(j) - getPontoY(i) * getPontoX(j);
    }
    i = getInfo(node);
    j = getInfo(getFirst(l));
    x += (getPontoX(i) + getPontoX(j)) * getPontoX(i) * getPontoY(j) - getPontoY(i) * getPontoX(j);
    y += (getPontoY(i) + getPontoY(j)) * getPontoX(i) * getPontoY(j) - getPontoY(i) * getPontoX(j);
    return createPonto(x/(6 * area), y/(6 * area));
}
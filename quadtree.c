#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "quadtree.h"
#include "lista.h"
#include "ponto.h"
#include "queue.h"
#include "qry.h"

#define nw 0
#define ne 1
#define sw 2
#define se 3
#define dx 250
#define dy 250

typedef struct node
{
    struct node *filho[4];
    struct node *pai;
    Ponto ponto;
    QtInfo info;

}NodeStruct;

typedef struct quadtree
{
    NodeStruct* root;
    char* (*fun)(QtInfo);

}QuadtreeStruct;

QuadTree criaQt(funcGetChave f)
{
    QuadtreeStruct* qt = (QuadtreeStruct*)malloc(sizeof(QuadtreeStruct));
    qt->root = NULL;
    qt->fun = f;
    return qt;
}

void dentroRetanguloQt(QuadTree qt, NodeStruct* node, Lista l, double x1, double y1, double x2, double y2, void* (*fun)(void*, void*))
{
    if(node == NULL)
    {
        return;
    }
    if(pontoInternoRet(node->ponto, x1, y1, x2 - x1, y2 - y1))
    {
        if(fun != NULL)
        {
            insert(l,fun(qt, node));
        }
        else
        {
            insert(l,node);
        }
    }
    for(int i = 0; i < 4; i++)
    {
        dentroRetanguloQt(qt, node->filho[i], l, x1, y1, x2, y2, fun);
    }
}

QtInfo getInfoQt(QuadTree qt, QtNo pNo)
{
    NodeStruct* node = (NodeStruct*) pNo;
    qt = qt;
   
    if(node == NULL)
    {
       return NULL;
    }
    else
    {
       return node->info;
    }
}

char* getChaveQt(QuadTree qt, QtNo pNo)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = (NodeStruct*) pNo;

    return quadtree->fun(getInfoQt(quadtree, node));
}

Lista chavesDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroRetanguloQt(qt, node, l, x1, y1, x2, y2, (void*(*)(void*, void*))getChaveQt);
    return l;

}

void dentroCirculoQt(QuadTree qt, NodeStruct* node, Lista l, double x, double y, double r, void* (*fun)(void*, void*))
{
    if(node == NULL)
    {
        return;
    }
    if(pontoInternoCirc(node->ponto, x, y, r))
    {
        if(fun != NULL)
        {
            insert(l,fun(qt, node));
        }
        else
        {
            insert(l,node);
        }
        
    }
    for(int i = 0; i < 4; i++)
    {
        dentroCirculoQt(qt, node->filho[i], l, x, y, r, fun);
    }
}

Lista chavesDentroCirculoQt(QuadTree qt,double x, double y, double r)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroCirculoQt(qt, node, l, x, y, r, (void*(*)(void*, void*))getChaveQt);
    return l;
}

Ponto getPontoQt(QuadTree qt, QtNo pNo)
{
    NodeStruct* node = (NodeStruct*) pNo;
    return node->ponto;
    qt = qt;
}

Lista pontosDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();

    dentroRetanguloQt(qt, node, l, x1, y1, x2, y2, getPontoQt);
    return l;

}

Lista pontosDentroCirculoQt(QuadTree qt,double x, double y, double r)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroCirculoQt(qt, node, l, x, y, r, getPontoQt);
    return l;
}

Lista nosDentroRetanguloQt(QuadTree qt, double x1, double y1, double x2, double y2)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroRetanguloQt(qt, node, l, x1, y1, x2, y2, NULL);
    return l;

}

Lista nosDentroCirculoQt(QuadTree qt,double x, double y, double r)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    Lista l = create();
    dentroCirculoQt(qt, node, l, x, y, r, NULL);
    return l;
}

void percorreProfundidade(QuadTree qt, NodeStruct* node, funcVisita f,ExtraInfo ei)
{
    if(node == NULL)
    {
        return;
    }
    
    f(getInfoQt(qt, node),ei);

    for(int i = 0; i < 4; i++)
    {
        percorreProfundidade(qt, node->filho[i],f,ei);
    }
}

void percorreProfundidadeQt(QuadTree qt,funcVisita f,ExtraInfo ei)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = quadtree->root;

    percorreProfundidade(qt, node, f, ei);
}

void percorreLarguraQt(QuadTree qt,funcVisita f,ExtraInfo ei)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* aux;

    if(quadtree->root == NULL)
    {
        return;
    }
    
    Fila fila = createQueue();

    insertQueue(fila, quadtree->root);
    
    do
    {
        aux = removeQueue(fila);
        for(int i = 0; i < 4; i++)
        {
            if(aux->filho[i] != NULL)
            {
                insertQueue(fila, aux->filho[i]);
            }
        }
        f(getInfoQt(quadtree, aux),ei);

    }while(!isEmptyQueue(fila));

    free(fila);
}

QtNo insereQt(QuadTree qt,Ponto p, QtInfo pInfo)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = (NodeStruct*)malloc(sizeof(NodeStruct));
    NodeStruct* aux = quadtree->root; 

    node->ponto = p;
    node->info = pInfo;
    node->pai = NULL;

    for(int i = 0; i < 4; i++)
    {
        node->filho[i] = NULL;
    }
    if(aux == NULL)
    {
        quadtree->root = node;
        return node;
    }
    Ponto pAux;

    do
    {
        pAux = aux->ponto;
        if(getPontoX(p) >= getPontoX(pAux))
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->filho[ne] == NULL)
                {
                    aux->filho[ne] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[ne];
                }
            }
            else
            {
                if(aux->filho[se] == NULL)
                {
                    aux->filho[se] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[se];
                }
            }
        }
        else
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->filho[nw] == NULL)
                {
                    aux->filho[nw] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[nw];
                }
            }
            else
            {
                if(aux->filho[sw] == NULL)
                {
                    aux->filho[sw] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[sw];
                }
            }
        }
    }while(node->pai == NULL);

    return node;
}

void insere(QuadtreeStruct* quadtree, NodeStruct* node)
{
    NodeStruct* aux = quadtree->root;
    node->pai = NULL;
    for(int i = 0; i < 4; i++)
    {
        node->filho[i] = NULL;
    }
    if(aux == NULL)
    {
        quadtree->root = node;
        return;
    }
    do
    {
        Ponto pAux = aux->ponto;
        Ponto p = node->ponto;
        if(getPontoX(p) >= getPontoX(pAux))
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->filho[ne] == NULL)
                {
                    aux->filho[ne] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[ne];
                }
            }
            else
            {
                if(aux->filho[nw] == NULL)
                {
                    aux->filho[nw] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[nw];
                }
            }
        }
        else
        {
            if(getPontoY(p) >= getPontoY(pAux))
            {
                if(aux->filho[se] == NULL)
                {
                    aux->filho[se] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[se];
                }
            }
            else
            {
                if(aux->filho[sw] == NULL)
                {
                    aux->filho[sw] = node;
                    node->pai = aux;
                }
                else
                {
                    aux = aux->filho[sw];
                }
            }
        }
    }while(node->pai == NULL);
}

QtNo getNodeById(QuadTree qt, QtNo no, char* chave)
{
    NodeStruct* node = (NodeStruct*) no;
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;

    if(strcmp(quadtree->fun(getInfoQt(qt, node)), chave) == 0)
    {
        return node;
    }

    QtNo aux;
    for(int i = 0; i < 4; i++)
    {
        if(node->filho[i] != NULL)
        {
            aux = getNodeById(qt,node->filho[i],chave);
            if(aux != NULL)
            {
                return aux;
            }
        }
    }
    return NULL;
}

QtNo getNodeByIdQt(QuadTree qt, char* chave)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;

    if(quadtree->root == NULL)
    {
        return NULL;
    }

    return getNodeById(qt, quadtree->root, chave);
}

QtInfo removeNoQt(QuadTree qt,QtNo pNo)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* node = (NodeStruct*) pNo;
    NodeStruct* aux;
    int i;
    QtInfo info;

    Fila fila = createQueue();

    if(node->pai == NULL)
    {
        for(i = 0; i < 4; i++)
        {
            if(node->filho[i] != NULL)
            {
                insertQueue(fila, node->filho[i]);
            }
        }
        quadtree->root = NULL;
    }
    else{
        for(i = 0; i < 4; i++)
        {
            if(node->filho[i] != NULL)
            {
                if(node->pai->filho[i] == NULL)
                {
                    node->pai->filho[i] = node->filho[i];
                    node->filho[i]->pai = node->pai;
                }
                else
                {
                    insertQueue(fila, node->filho[i]);
                }
            }
        }
        for(i = 0; i < 4; i++)
        {
            if(node->pai->filho[i] == node)
            {
                node->pai->filho[i] = NULL;
                break;
            }
        }
    }
    while(!isEmptyQueue(fila))
    {
        aux = removeQueue(fila);
        for(i = 0; i < 4; i++)
        {
            if(aux->filho[i] != NULL)
            {
                insertQueue(fila, aux->filho[i]);
            }
        }
        insere(quadtree,aux);
    }
    info = getInfoQt(quadtree, node);
    free(node);
    free(fila);
    return info;
}

QtNo getNoQt(QuadTree qt, double x, double y)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    NodeStruct* aux = quadtree->root;
    Ponto p;

    while (aux != NULL)
    {
        p = aux->ponto;
        if(x == getPontoX(p) && y == getPontoY(p))
        {
            return aux;
        }
        if(x > getPontoX(p))
        {
            if(y > getPontoY(p))
            {

                aux = aux->filho[ne];
            }
            else
            {
                aux = aux->filho[se];
            }
        }
        else
        {
            if(y > getPontoY(p))
            {
                aux = aux->filho[nw];
            }
            else
            {
                aux = aux->filho[sw];
            }
        }
    }
    return NULL;
}

QtInfo getInfoById(QuadTree qt, QtNo no, char* chave)
{
    NodeStruct* node = (NodeStruct*) no;
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;

    if(node == NULL)
    {
        return NULL;
    }

    if(strcmp(quadtree->fun(getInfoQt(qt, node)), chave) == 0)
    {
        return getInfoQt(qt, node);
    }
    QtInfo aux;
    for(int i = 0; i < 4; i++)
    {
        if(node->filho[i] != NULL)
        {
            aux = getInfoById(qt,node->filho[i],chave);
            if(aux != NULL)
            {
                return aux;
            }
        }
    }
    return NULL;
}

QtInfo getInfoByIdQt(QuadTree qt, char* chave)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;

    return getInfoById(qt, quadtree->root, chave);
}

void desalocaNos(NodeStruct* node)
{
    if(node == NULL)
    {
        return;
    }
    for(int i = 0; i < 4; i++)
    {
        desalocaNos(node->filho[i]);
    }
    if(node->ponto != node->info)
    {
        free(node->ponto);
    }
    free(node->info);
    free(node);
}

void desalocaQt(QuadTree qt)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    desalocaNos(quadtree->root);

    free(qt);
}

void desenhaNosQt(QuadtreeStruct* qt, NodeStruct* no, FILE* svg, double *x, double y, Lista ant)
{
    if(no == NULL)
    {
        return;
    }
    Lista atual = create();

    for(int i = 0; i < 2; i++)
    {
        desenhaNosQt(qt, no->filho[i], svg, x, y + dy, atual);
    }
    *x += dx;

    double aux = *x;
    fprintf(svg, "<rect x='%lf' y='%lf' width='240' height='12' fill='none' stroke='blue' />\n",aux, y - 10);
    fprintf(svg, "\t<text x=\"%lf\" y=\"%lf\">%s: %lf,%lf</text>\n",aux, y, qt->fun(getInfoQt(qt, no)), getPontoX(no->ponto), getPontoY(no->ponto));
    
    if(ant != NULL)
    {
        insertList(createPonto(aux,y - 10), ant);
    }
    else
    {
        fprintf(svg, "\t<circle cx=\"%lf\" cy=\"%lf\" r=\"5\" fill=\"blue\"/>\n", aux, y - 150);
        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke: blue; stroke-width: 1\" />\n", aux, y + 2, aux, y - 150);
    }
    for(int i = 2; i < 4; i++)
    {
        desenhaNosQt(qt, no->filho[i], svg, x, y + dy, atual);
    }
    for(No node = getFirst(atual); node != NULL; node = getNext(node))
    {
        fprintf(svg, "\t<line x1=\"%lf\" y1=\"%lf\" x2=\"%lf\" y2=\"%lf\" style=\"stroke: blue; stroke-width: 1\" />\n", aux, y + 2, getPontoX(getInfo(node)), getPontoY(getInfo(node)));
    }
    removeList(atual,free);
}

void desenharQt(QuadTree qt, FILE* svg)
{
    QuadtreeStruct* quadtree = (QuadtreeStruct*) qt;
    double *x = (double*)malloc(sizeof(double));

    *x = 0;
    
    desenhaNosQt(quadtree, quadtree->root, svg, x, dy, NULL);
    free(x);
}
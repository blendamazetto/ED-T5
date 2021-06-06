#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry3.h"

void cv (QuadTree arvoresObjetos[], double n, char cep[], char face[], double num, Lista listasQry[])
{
    double x, y;

    if(getNodeByIdQt(arvoresObjetos[3],cep) != NULL)
    {
        Info q = getInfoByIdQt(arvoresObjetos[3], cep);


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
  
        Casos caso = criaCasos(n, x, y, face, num, cep);
        insereQt(arvoresObjetos[10], getCasosPonto(caso), caso);

        Retangulo ret = criaRetangulo("0", 10, 10, x, y, "2", "orange", "orange");
        insert(listasQry[1], ret);

        TextoNumerico textNum = criaTextoNumerico(x, y, "white", "white", n);
        insert(listasQry[0], textNum);
    }
}

void soc(QuadTree arvoresObjetos[], int k, char cep[], char face[], double num, FILE* saida, Lista listasQry[])
{
    double x, y;

    if(getNodeByIdQt(arvoresObjetos[3], cep) != NULL)
    {
        Info q = getInfoByIdQt(arvoresObjetos[3], cep);

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

    Retangulo ret = criaRetangulo("0", 10, 10, x, y, "2", "white", "blue");
    insert(listasQry[1], ret);

    Lista l = create();
    percorreLarguraQt(arvoresObjetos[7],insertList,l);

    double vet[tamanhoDaLista(l)];
    int size = 0;

    No node;
    for(node = getFirst(l); node != NULL; node = getNext(node))
    {
        Info po = getInfo(node);

        double dist = distancia(x, y, getPostoX(po), getPostoY(po));
        setPostoDistancia(po, dist);
        vet[size] = dist;
        size++;
    }

    shellSort(vet, tamanhoDaLista(l));

    No aux;
    Info inf;

    for(int cont=0; cont<k; cont++)
    {
        for(aux = getFirst(l); aux != NULL; aux = getNext(aux))
        {   
            inf = getInfo(aux);

            if(getPostoDistancia(inf) == vet[cont])
            {
                Linha lin = criaLinha(x, y, getPostoX(inf), getPostoY(inf), "black");
                insert(listasQry[7], lin);

                fprintf(saida,"X: %lf Y: %lf\n", getPostoX(inf), getPostoY(inf));
            }
        }
    }
}

void ci(FILE* saida, QuadTree arvoresObjetos[], double x, double y, double r, Lista listasQry[], FILE* saidaSvgQry)
{
    No node;
    Info fig, c;
    int n = 0;
    double d, inc, area;
    char cor[22];
    Ponto ponto;

    c = criaCirculo("0",r,x,y,"5px","green","none");
    insert(listasQry[3], c);

    Lista aux;
    Lista casos = NULL;

    aux = nosDentroCirculoQt(arvoresObjetos[10],x,y,r);
    if(getFirst(aux) == NULL)
    {
        removeList(aux,NULL);
        return;
    }

    node = getNodeByIdQt(arvoresObjetos[3],getCasosCEP(getInfoQt(arvoresObjetos[10],getInfo(getFirst(aux)))));
    if (node == NULL)
    {
        removeList(aux,NULL);
        return;
    }

    d = getDensidadeD(getInfoQt(arvoresObjetos[3], node));
    Lista l = create();

    for(node = getFirst(aux); node != NULL; node = getNext(node))
    {
        fig = getInfoQt(arvoresObjetos[10], getInfo(node));
        ponto = getCasosPonto(fig);
        insert(l, ponto);
        fprintf(saida,"X : %lf Y : %lf\n", getPontoX(ponto),getPontoY(ponto));
        n += getCasosN(fig);
    }
    removeList(aux,NULL);

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

    area = obterArea(casos);
    fprintf(saida,"NUMERO DE CASOS : %d\nAREA : %lf\n",n,area);

    if(area != 0)
    {
        inc = 10 * n/(d * area);

        if(inc < 0.1)
        {
            strcpy(cor, "00FFFF");
            fprintf(saida,"CATEGORIA A \n");
        }
        else if(inc < 5)
        {
            strcpy(cor, "008080");
            fprintf(saida,"CATEGORIA B \n");
        }
        else if(inc < 10)
        {
            strcpy(cor, "FFFF00");
            fprintf(saida,"CATEGORIA C \n");
        }
        else if(inc < 20)
        {
            strcpy(cor, "FF0000");
            fprintf(saida,"CATEGORIA D \n");
        }
        else
        {
            strcpy(cor, "800080");
            fprintf(saida,"Categoria E \n");

            aux = pontosDentroCirculoQt(arvoresObjetos[10], x, y, r);
            if(getFirst(aux) == NULL)
            {
                ponto = centroide(casos,area);
                fprintf(saida,"Necessário novo posto em (%lf,%lf)\n",getPontoX(ponto),getPontoY(ponto));
            }
            removeList(aux, NULL);
        }
    }
    else
    {
        fprintf(saida,"Não é possivel obter a categoria da região\n");
        removeList(casos,NULL);
        return;
    }

    fprintf(saidaSvgQry,"\t<polygon id=\"%d\" fill=\"%s\" fill-opacity=\"0.2\" stroke=\"red\" stroke-width=\"5px\" points=\"",tamanhoDaLista(casos), cor);
    
    for(node = getFirst(casos); node != NULL; node = getNext(node))
    {
        fig = getInfo(node);
        fprintf(saidaSvgQry," %lf,%lf",getPontoX(fig),getPontoY(fig));
    }
    fprintf(saidaSvgQry," \"/>\n");

    removeList(casos,NULL);
}
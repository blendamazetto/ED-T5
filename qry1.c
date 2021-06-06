#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry1.h"

void o(char j[], char k[], QuadTree arvoresObjetos[], Lista listasQry[], FILE* saida)
{
    if(getInfoByIdQt(arvoresObjetos[0], j) != NULL && getInfoByIdQt(arvoresObjetos[0], k) != NULL)
    {
        Info c1 = getInfoByIdQt(arvoresObjetos[0], j);
        Info c2 = getInfoByIdQt(arvoresObjetos[0], k);
        circuloInt(c1, c2, saida, listasQry);
    }

    else if(getInfoByIdQt(arvoresObjetos[0], j) != NULL && getInfoByIdQt(arvoresObjetos[1], k) != NULL)
    {
        Info c = getInfoByIdQt(arvoresObjetos[0], j);
        Info r = getInfoByIdQt(arvoresObjetos[1], k);
        retanguloxCirculo(c, r, saida, listasQry);
    }

    else if(getInfoByIdQt(arvoresObjetos[1], j) != NULL && getInfoByIdQt(arvoresObjetos[0], k) != NULL)
    {
        Info r = getInfoByIdQt(arvoresObjetos[1], j);
        Info c = getInfoByIdQt(arvoresObjetos[0], k);
        retanguloxCirculo(c, r, saida, listasQry);
    }

    else if(getInfoByIdQt(arvoresObjetos[1], j) != NULL && getInfoByIdQt(arvoresObjetos[1], k) != NULL)
    {
        Info r1 = getInfoByIdQt(arvoresObjetos[1], j);
        Info r2 = getInfoByIdQt(arvoresObjetos[1], k);
        retanguloInt(r1, r2, saida, listasQry);
    }
}

void i (char j[], double x, double y, QuadTree arvoresObjetos[], Lista listasQry[], FILE* saida)
{
    if(getInfoByIdQt(arvoresObjetos[0], j) != NULL) 
    {
        Info c = getInfoByIdQt(arvoresObjetos[0], j);
        float dist = sqrt(pow(x - getCirculoX(c),2) + pow(y - getCirculoY(c),2));

        if (getCirculoR(c) >= dist)
        {
            fprintf(saida,"circulo interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "blue", "blue");
            insert(listasQry[3], circ);

            Linha lin = criaLinha(x, y, getCirculoX(c), getCirculoY(c), "blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"circulo nao interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "magenta", "magenta");
            insert(listasQry[3], circ);

            Linha lin = criaLinha(x, y, getCirculoX(c), getCirculoY(c), "magenta");
            insert(listasQry[2], lin);
        }
    }
    else if (getInfoByIdQt(arvoresObjetos[1], j) != NULL)
    {
        Info r = getInfoByIdQt(arvoresObjetos[1], j);
        float difx = x - getRetanguloX(r);
        float dify = y - getRetanguloY(r);

        if(difx >= 0 && difx <= getRetanguloW(r) && dify >= 0 && dify <= getRetanguloH(r))
        {
            fprintf(saida,"retangulo interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "blue", "blue");
            insert(listasQry[3], circ);

            Linha lin = criaLinha(x ,y ,getRetanguloX(r)+getRetanguloW(r)/2 ,getRetanguloY(r)+getRetanguloH(r)/2 ,"blue");
            insert(listasQry[2], lin);
        }
        else
        {
            fprintf(saida,"retangulo nao interno\n");

            Circulo circ = criaCirculo("0", 5, x, y, "1", "magenta", "magenta");
            insert(listasQry[3], circ);

            Linha lin = criaLinha(x ,y ,getRetanguloX(r)+getRetanguloW(r)/2 ,getRetanguloY(r)+getRetanguloH(r)/2 ,"magenta");
            insert(listasQry[2], lin);
        }
    }
}

void pnt (char j[], char corb[], char corp[], QuadTree arvoresObjetos[], FILE* saida)
{
    if(getInfoQt(arvoresObjetos[0], getNodeByIdQt(arvoresObjetos[0],j)) != NULL)
    {
        Info c = getInfoByIdQt(arvoresObjetos[0], j);

        fprintf(saida,"X: %lf Y: %lf\n", getCirculoX(c), getCirculoY(c));
        setCirculoCorb(c, corb);
        setCirculoCorp(c, corp);
    }

    else if(getInfoQt(arvoresObjetos[1], getNodeByIdQt(arvoresObjetos[1],j)) != NULL)
    {
        Info r = getInfoByIdQt(arvoresObjetos[1], j);

        fprintf(saida,"X: %lf Y: %lf\n", getRetanguloX(r), getRetanguloY(r));
        setRetanguloCorb(r, corb);
        setRetanguloCorp(r, corp);
    }

    else if(getInfoQt(arvoresObjetos[2], getNodeByIdQt(arvoresObjetos[2],j)) != NULL)
    {
        Info t = getInfoByIdQt(arvoresObjetos[2], j);

        fprintf(saida,"X: %lf Y: %lf\n", getTextoX(t), getTextoY(t));
        setTextoCorb(t, corb);
        setTextoCorp(t, corp);
    }
}

void delf(FILE* saida, QuadTree arvoresObjetos[], char j[])
{
    if(getNodeByIdQt(arvoresObjetos[0],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[0],j);
        Info c = removeNoQt(arvoresObjetos[0], node);
        fprintf(saida,"ID: %s R: %lf X: %lf Y: %lf CORB: %s CORP :%s \n", getCirculoI(c), getCirculoR(c), getCirculoX(c), getCirculoY(c), getCirculoCorb(c), getCirculoCorp(c));
        desalocarPontoCirculo(c);
    }

    else if(getNodeByIdQt(arvoresObjetos[1],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[1],j);
        Info r = removeNoQt(arvoresObjetos[1], node);
        fprintf(saida,"ID: %s W: %lf H: %lf X: %lf Y: %lf CORB: %s CORP: %s \n", getRetanguloI(r), getRetanguloW(r), getRetanguloH(r), getRetanguloX(r), getRetanguloY(r), getRetanguloCorb(r), getRetanguloCorp(r));
        desalocaRetangulo(r);
    }

    else if(getNodeByIdQt(arvoresObjetos[2],j) != NULL)
    {
        QtNo node = getNodeByIdQt(arvoresObjetos[2],j);
        Info t = removeNoQt(arvoresObjetos[2], node);
        fprintf(saida,"ID: %s X: %lf Y: %lf CORB: %s CORP: %s TEXTO: %s\n",getTextoI(t), getTextoX(t), getTextoY(t), getTextoCorb(t), getTextoCorp(t), getTextoTxto(t));
        desalocaTexto(t);
    }
}

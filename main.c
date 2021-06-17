#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerGeo.h"
#include "lista.h"
#include "lerQry.h"
#include "quadtree.h"
#include "circulo.h"
#include "retangulo.h"
#include "texto.h"
#include "hidrante.h"
#include "radiobase.h"
#include "semaforo.h"
#include "quadra.h"
#include "posto.h"
#include "hashtable.h"
#include "grafo.h"

char *concatenacao(char dir_entrada[])
{	
	char* arqGeoConcatenado = NULL;
    char* aux = strrchr(dir_entrada,'/');
    if(aux == NULL)
	{
		arqGeoConcatenado=strtok(dir_entrada,".");
        return(arqGeoConcatenado);
    }
	arqGeoConcatenado=strtok(&aux[1],".");
	return(arqGeoConcatenado);
}

int main (int argc, char *argv[])
{
    Lista listasObjetos[13];
    for (int i = 0; i < 13; i++)
    {
        listasObjetos[i] = create();
    }

    char* (*getId[11])(void*) = {getCirculoI, getRetanguloI, getTextoI, getQuadraCep, getHidranteId, getSemaforoId, getRadiobaseId, getPostoId, getEstabelecimentoCnpj, getMoradorCpf, NULL};   

    QuadTree arvoresObjetos[11];
    for (int i = 0; i < 11; i++)
    {
        arvoresObjetos[i] = criaQt(getId[i]);
    }

    Lista listasQry[9];
    for (int i = 0; i < 9; i++)
    {
        listasQry[i] = create();
    }

    Lista hashAux[3];
    for (int i = 0; i<3; i++)
    {
        hashAux[i] = create();
    }

    Hash tabelas[4];

    Grafo grafo[2];

    grafo[0] = createGrafo();
    grafo[1] = createGrafo();

    char *dir_entrada = NULL;
    char *arq_geoNome = NULL;
    char *arq_consulta = NULL;
    char *dir_saida = NULL;
    char *arqGeo = NULL;
    char *arqQry = NULL;
    char *nomeSvgGeo = NULL;
    char *nomeGeo = NULL;
    char *nomeQry = NULL;
    char *saidaQry = NULL;   
    char *saida = NULL;
    char *arq_ecNome = NULL;
    char *arq_pmNome = NULL;
    char *arqEc = NULL;
    char *arqPm = NULL;
    char *arq_viaNome = NULL;
    char *arqVia = NULL;

    int i;
    for(i=1;i<argc;i++)
    {
        if(strcmp("-e", argv[i]) == 0 )
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nDiretorio de entrada nao encontrado\n");
                exit(1);
            }
            dir_entrada = (char*) malloc((strlen(argv[i]) +1)*sizeof (char));
            strcpy(dir_entrada,argv[i]);
        }
        else if(strcmp("-f", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nParametro nao foi encontrado em -f\n");
                exit(1);
            }
            arq_geoNome = (char*) malloc((strlen(argv[i]) +1)*sizeof (char));
            strcpy(arq_geoNome,argv[i]);
        }
        else if(strcmp("-q", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nParametro nao foi econtrado em -q\n");
                exit(1);
            }

            arq_consulta = (char*) malloc((strlen(argv[i]) +1)*sizeof (char));
            strcpy(arq_consulta,argv[i]);
        }
        else if(strcmp("-o", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nDiretorio de saida nao foi econtrado\n");
                exit(1);
            }
            dir_saida = (char*) malloc((strlen(argv[i]) +1) *sizeof (char));
            strcpy(dir_saida,argv[i]);      
        }
        else if(strcmp("-ec", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nArquivo EC nao encontrado\n");
                exit(1);
            }
            arq_ecNome = (char*) malloc((strlen(argv[i]) +1)*sizeof (char));
            strcpy(arq_ecNome,argv[i]);      
        }
        else if(strcmp("-pm", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nArquivo PM nao encontrado\n");
                exit(1);
            }
            arq_pmNome = (char*) malloc((strlen(argv[i]) +1)*sizeof (char));
            strcpy(arq_pmNome,argv[i]);      
        }
        else if(strcmp("-v", argv[i]) == 0)
        {
            i++;
            if(argv[i] == NULL)
            {
                printf("\nERRO\nArquivo VIA nao encontrado\n");
                exit(1);
            }
            arq_viaNome = (char*) malloc((strlen(argv[i]) +1)*sizeof (char));
            strcpy(arq_viaNome,argv[i]);      
        }
    }

    if(arq_geoNome == NULL || dir_saida == NULL)
    {
        printf("\nERRO\nArgumento essencial nao inserido\n");
        exit(1);
    }
    else if (dir_entrada != NULL) 
    {
        if(dir_entrada[strlen(dir_entrada) - 1] != '/')
        {
            arqGeo = (char *)malloc((strlen(arq_geoNome)+ strlen(dir_entrada) +2)*sizeof(char));
    	    sprintf(arqGeo,"%s/%s",dir_entrada,arq_geoNome); 
        }
		else
        {
            arqGeo = (char *)malloc((strlen(arq_geoNome)+ strlen(dir_entrada) +1)*sizeof(char));
    	    sprintf(arqGeo,"%s%s",dir_entrada,arq_geoNome);
        }
        if (arq_consulta!= NULL)
        {
            arqQry = (char *)malloc((strlen(arq_consulta)+strlen(dir_entrada) +2)*sizeof(char));
            sprintf(arqQry,"%s/%s",dir_entrada,arq_consulta);
        }
        if (arq_pmNome!= NULL)
        {
            if(dir_entrada[strlen(dir_entrada) - 1] != '/')
            {
                arqPm = (char *)malloc((strlen(arq_pmNome)+strlen(dir_entrada)+2)*sizeof(char));
    	        sprintf(arqPm,"%s/%s",dir_entrada,arq_pmNome);
            }
            else
            {
                arqPm = (char *)malloc((strlen(arq_pmNome)+strlen(dir_entrada)+1)*sizeof(char));
    	        sprintf(arqPm,"%s%s",dir_entrada,arq_pmNome);
            } 
        }
        if (arq_ecNome!= NULL)
        {
            if(dir_entrada[strlen(dir_entrada) - 1] != '/')
            {
                arqEc = (char *)malloc((strlen(arq_ecNome)+strlen(dir_entrada)+2)*sizeof(char));
    	        sprintf(arqEc,"%s/%s",dir_entrada,arq_ecNome);
            }
            else
            {
                arqEc = (char *)malloc((strlen(arq_ecNome)+strlen(dir_entrada)+1)*sizeof(char));
    	        sprintf(arqEc,"%s%s",dir_entrada,arq_ecNome);
            }
        }
        if (arq_viaNome!= NULL)
        {
            if(dir_entrada[strlen(dir_entrada) - 1] != '/')
            {
                arqVia = (char *)malloc((strlen(arq_viaNome)+strlen(dir_entrada)+2)*sizeof(char));
    	        sprintf(arqVia,"%s/%s",dir_entrada,arq_viaNome);
            }
            else
            {
                arqVia = (char *)malloc((strlen(arq_viaNome)+strlen(dir_entrada)+1)*sizeof(char));
    	        sprintf(arqVia,"%s%s",dir_entrada,arq_viaNome);
            }
        }
	} 
    else 
    {
		arqGeo = (char *)malloc((strlen(arqGeo)+1)*sizeof(char));
    	strcpy(arqGeo, arq_geoNome);

        arqPm = (char *)malloc((strlen(arqPm)+1)*sizeof(char));
        strcpy(arqPm, arq_pmNome);

        arqEc = (char *)malloc((strlen(arqEc)+1)*sizeof(char));
        strcpy(arqEc, arq_ecNome);

        arqVia = (char *)malloc((strlen(arqVia)+1)*sizeof(char));
        strcpy(arqVia, arq_viaNome);

        if(arq_consulta!= NULL)
        {
            arqQry = (char *)malloc((strlen(arq_consulta)+1)*sizeof(char));
            strcpy(arqQry, arq_consulta);
        }
	}
    nomeGeo = concatenacao(arq_geoNome);
    if (dir_saida[strlen(dir_saida) - 1] == '/')
    {
        saida = (char*)malloc((strlen(nomeGeo) + strlen(dir_saida) + 1)*sizeof(char));
        sprintf(saida,"%s%s",dir_saida,nomeGeo);
    }
    else
    {
        saida = (char*)malloc((strlen(nomeGeo) + strlen(dir_saida) + 2)*sizeof(char));
        sprintf(saida,"%s/%s",dir_saida,nomeGeo);
    }
    nomeSvgGeo = (char*)malloc((strlen(saida) + 5)*sizeof(char));
    sprintf(nomeSvgGeo,"%s.svg",saida);

    lerGeo(arqGeo,nomeSvgGeo, listasObjetos, arvoresObjetos, tabelas, hashAux);

    if(arq_ecNome != NULL)
    {
        lerEc(arqEc, listasObjetos, arvoresObjetos, tabelas, hashAux);
    }

    if(arq_pmNome != NULL)
    {
        lerPm(arqPm, listasObjetos, arvoresObjetos, tabelas, hashAux);
    }

    if(arq_viaNome != NULL)
    {
        lerVia(arqVia, grafo);
    }


    if (arq_consulta!= NULL)
    {
        nomeQry = concatenacao(arq_consulta);
        saidaQry = (char*)malloc((strlen(dir_saida) + strlen(saida) + 6)* sizeof(char));
        sprintf(saidaQry,"%s-%s",saida,nomeQry);

        lerQry(saidaQry,arqQry, listasQry, arvoresObjetos, tabelas, listasObjetos, grafo);
    }

    deleteHashTable(tabelas[0], tamanho(listasObjetos[11]), 0);
    deleteHashTable(tabelas[2], tamanho(listasObjetos[10]), 1);
    deleteHashTable(tabelas[3], tamanho(listasObjetos[3]), 0);
    deleteHashTable(tabelas[1], tamanho(listasObjetos[12]), 0);

    for(i = 0; i < 12; i++)
    {
        if(i != 8)
        {
            removeList(listasObjetos[i],NULL);
        }
        else if(i==8)
        {
            removeList(listasObjetos[8],desalocarPontosDensidade);
        }
    }
    removeList(listasObjetos[12], free);

    for(i = 0; i < 11; i++)
    {
        desalocaQt(arvoresObjetos[i]);
    }

    for(i = 0; i < 3; i++)
    {
        removeList(hashAux[i],NULL);
    }

    for(i = 0; i < 9; i++)
    {
        removeList(listasQry[i],NULL);
    }

    FILE *svg;
    svg = fopen("./teste/teste.svg", "w");
    fprintf(svg, "<svg version=\"1.1\" baseProfile=\"full\" width=\"10000\" height=\"10000\" xmlns=\"http://www.w3.org/2000/svg\">\n");
    printarGrafo(grafo[0], svg, "red");
    fprintf(svg, "</svg>");

    desalocarGrafo(grafo[0]);
    desalocarGrafo(grafo[1]);

    free(dir_entrada);
    free(dir_saida);
    free(arqGeo);
    free(arqQry);
    free(nomeSvgGeo);
    free(nomeGeo);
    free(nomeQry);
    free(saidaQry);   
    free(saida);
    free(arq_ecNome);
    free(arq_pmNome);
    free(arqPm);
    free(arqEc);
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerQry.h"

void lerQry (char saidaQry[], char arqQry[], Lista listasQry, QuadTree arvoresObjetos[], Hash tabelas[], Lista listasObjetos[], Grafo grafo[])
{
    char* saidaTxt = malloc((5 + strlen(saidaQry))*sizeof(char));
    char* saidaSvg = malloc((5 + strlen(saidaQry))*sizeof(char));
    sprintf(saidaTxt,"%s.txt",saidaQry);
    sprintf(saidaSvg,"%s.svg",saidaQry);

    FILE* qry = fopen(arqQry,"r");
    FILE* saida = fopen(saidaTxt,"w");
    FILE* saidaSvgQry = fopen(saidaSvg,"w");
    FILE* svg;

    iniciaSvg(saidaSvgQry);

    if(saida == NULL || qry == NULL)
    {
        printf("Erro ao abrir o QRY ou ao gerar o TXT\n");
        exit(1);
    }

    char j[20], k[20], cmc[22], cmr[22];
    int ident, intJ, intK, max;
    double x, y, r, w ,h, num, n;
    char tipo[5], sufx[20], corb[20], corp[20], id[20], identificacao[20], parametroOpcional[1], face[1], cep[20], cpf[20], cnpj[25], compl[20], t, sfx[25], tp[20], indiceRegistrador[3], indiceRegistrador2[3], sufxAux[25], lastSufx[25];
    int b;

    Ponto registradores[11]; 

    for(int b = 0; b < 11; b++)
    {
        registradores[b] = createPonto(0,0);
    }

    while(fscanf(qry,"%s",tipo) != EOF)
    {
        if(strcmp(tipo,"o?") == 0)
        {
            fscanf(qry,"%s %s",j,k);
            fprintf(saida,"%s %s %s\n",tipo,j,k);
            o(j, k, arvoresObjetos, listasQry, saida);
        }
        else if(strcmp(tipo,"i?") == 0)
        {
            fscanf(qry,"%s %lf %lf",j,&x,&y);
            fprintf(saida,"%s %s %lf %lf\n",tipo,j,x,y);  
            i(j, x, y, arvoresObjetos, listasQry, saida);
        }
        else if(strcmp(tipo,"pnt") == 0)
        {
            fscanf(qry,"%s %s %s",j,corb,corp);
            fprintf(saida,"%s %s %s %s\n",tipo,j,corb,corp);
            pnt(j, corb, corp, arvoresObjetos, saida);
        }
        else if(strcmp(tipo,"pnt*") == 0)
        {
            fscanf(qry,"%d %d %s %s",&intJ,&intK,corb,corp);
            fprintf(saida,"%s %d %d %s %s\n",tipo,intJ,intK,corb,corp);
            for(int a = intJ; a <= intK; a++)
            {
                sprintf(j,"%d",a);
                pnt(j, corb, corp, arvoresObjetos, saida);
            }
        }
        else if(strcmp(tipo,"delf") == 0)
        {
            fscanf(qry,"%s",j);
            fprintf(saida,"%s %s\n",tipo,j); 
            delf(saida, arvoresObjetos, j);
        }
        else if(strcmp(tipo,"delf*") == 0)
        {
            fscanf(qry,"%d %d",&intJ,&intK);
            fprintf(saida,"%s %d %d\n",tipo,intJ,intK);
            for(int a = intJ; a <= intK; a++)
            {
                sprintf(j,"%d",a);
                delf(saida, arvoresObjetos, j);
            }
        }
       else if(strcmp(tipo, "dq") == 0) 
        {
            fscanf(qry,"%s", parametroOpcional);

             if(strcmp(parametroOpcional,"#")==0)
            {
                ident=1;
                fscanf(qry,"%s %lf",identificacao, &r);
                fprintf(saida,"dq# %s %lf\n", identificacao, r);
            }
            else
            {
                ident=0;
                fscanf(qry,"%lf", &r);
                strcpy(identificacao, parametroOpcional);
                fprintf(saida,"dq %s %lf\n",identificacao, r);
            }
            dq(saida, arvoresObjetos, ident, identificacao, r, listasQry);
        }
        else if(strcmp(tipo, "del")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            del(saida, arvoresObjetos, identificacao, listasQry);
        }
        else if(strcmp(tipo, "cbq")==0)
        {
            fscanf(qry,"%lf %lf %lf %s",&x, &y, &r, corb);
            fprintf(saida,"%s %lf %lf %lf %s\n",tipo,x, y, r, corb);
            cbq(arvoresObjetos, x, y, r, corb, saida);
        }
        else if(strcmp(tipo, "crd?")==0)
        {
            fscanf(qry,"%s",identificacao);
            fprintf(saida,"%s %s\n",tipo, identificacao);
            crd(arvoresObjetos, identificacao, saida);
        }
        else if(strcmp(tipo, "car")==0)
        {
            fscanf(qry,"%lf %lf %lf %lf",&x, &y, &w, &h);
            fprintf(saida,"%s %lf %lf %lf %lf\n",tipo, x, y, w, h);
            car(arvoresObjetos, x, y, w, h, saida, listasQry);
        }
        else if(strcmp(tipo, "cv")==0)
        {
            fscanf(qry,"%lf %s %s %lf",&n, cep, face, &num);
            fprintf(saida,"cv %lf %s %s %lf\n", n, cep, face, num);
            cv(arvoresObjetos, n, cep, face, num, listasQry);
        }
        else if(strcmp(tipo, "soc")==0)
        {
            fscanf(qry,"%d %s %s %lf",&b, cep, face, &num);
            fprintf(saida,"soc %d %s %s %lf\n", b, cep, face, num);
            soc(arvoresObjetos, b, cep, face, num, saida, listasQry);
        }
        else if(strcmp(tipo, "ci")==0)
        {
            fscanf(qry,"%lf %lf %lf",&x, &y, &r);
            fprintf(saida,"%s %lf %lf %lf\n",tipo, x, y, r);
            ci(saida, arvoresObjetos, x, y, r, listasQry, saidaSvgQry);
        }
        else if(strcmp(tipo, "m?")==0)
        {
            fscanf(qry,"%s",cep);
            fprintf(saida,"%s %s\n",tipo, cep);
            m(arvoresObjetos, saida, tabelas, cep, listasObjetos);
        }
        else if(strcmp(tipo, "dm?")==0)
        {
            fscanf(qry,"%s",cpf);
            fprintf(saida,"%s %s\n",tipo, cpf);
            dm(arvoresObjetos, saida, listasQry, tabelas, cpf, listasObjetos);
        }
        else if(strcmp(tipo, "de?")==0)
        {
            fscanf(qry,"%s",cnpj);
            fprintf(saida,"%s %s\n",tipo, cnpj);
            de(arvoresObjetos, saida, tabelas, cnpj, listasObjetos);
        }
        else if(strcmp(tipo, "mud")==0)
        {
            fscanf(qry,"%s %s %s %lf %s",cpf, cep, face, &num, compl);
            fprintf(saida,"mud %s %s %s %lf %s\n", cpf, cep, face, num, compl);
            mud(arvoresObjetos, saida, listasQry, tabelas, cpf, cep, face, num, compl, listasObjetos);
        }
        else if(strcmp(tipo, "dmprbt")==0)
        {
            fscanf(qry," %c %s", &t, sfx);
            fprintf(saida,"%s %c %s\n", tipo, t, sfx);
            dmprbt(arvoresObjetos, t, saidaQry, sfx);
        }
        else if(strcmp(tipo, "eplg?")==0)
        {
            fscanf(qry,"%s %lf %lf %lf %lf",tp, &x, &y, &w, &h);
            fprintf(saida,"%s %s %lf %lf %lf %lf\n", tipo, tp, x, y, w, h);
            epgl(arvoresObjetos, saida, listasQry, tabelas, x, y, w, h, listasObjetos, tp);
        }
        else if (strcmp(tipo, "catac")==0)
        {
            fscanf(qry,"%lf %lf %lf",&x, &y, &r);
            fprintf(saida,"%s %lf %lf %lf\n",tipo, x, y, r);
            catac(arvoresObjetos, saida, listasQry, x, y, r);
        }
        else if (strcmp(tipo, "@m?")==0)
        {
            fscanf(qry,"%s %s", indiceRegistrador, cpf);
            fprintf(saida, "%s %s %s\n", tipo, indiceRegistrador, cpf);
            mQuestionMark(indiceReg(indiceRegistrador), cpf, arvoresObjetos, registradores, listasQry);
        }
        else if (strcmp(tipo, "@e?")==0)
        {
            fscanf(qry,"%s %s %s %lf", indiceRegistrador, cep, face, &num);
            fprintf(saida,"%s %s %s %s %lf\n", tipo, indiceRegistrador, cep, face, num);
            eQuestionMark(indiceReg(indiceRegistrador), cep, face, num, arvoresObjetos, registradores, listasQry);
        }
        else if (strcmp(tipo, "@g?")==0)
        {
            fscanf(qry,"%s %s", indiceRegistrador, id);
            fprintf(saida,"%s %s %s\n",tipo, indiceRegistrador, id);
            gQuestionMark(indiceReg(indiceRegistrador), id, arvoresObjetos, registradores, listasQry);
        }
        else if (strcmp(tipo, "@xy")==0)
        {
            fscanf(qry,"%s %lf %lf",indiceRegistrador, &x, &y);
            fprintf(saida,"%s %s %lf %lf\n",tipo,indiceRegistrador, x, y);
            xy(indiceReg(indiceRegistrador), x, y, registradores, listasQry);
        }
        else if (strcmp(tipo, "ccv")==0)
        {
            fscanf(qry,"%s", sufx);
            fprintf(saida,"%s %s\n",tipo, sufx);
            strcpy(lastSufx, sufx);
            ccv(grafo[1], saidaQry, sufx);
        }
       
        else if (strcmp(tipo, "p?")==0)
        {
            fscanf(qry,"%s %s %s %s %s", sufxAux, indiceRegistrador, indiceRegistrador2, cmc, cmr);
            fprintf(saida,"%s %s %s %s %s %s\n",tipo, sufx, indiceRegistrador, indiceRegistrador2, cmc, cmr);
            if(strcmp(sufxAux, "-") == 0)
            {
                char* pathSvg = malloc((6 + strlen(lastSufx) + strlen(saidaQry))*sizeof(char));
                sprintf(pathSvg,"%s-%s.svg", saidaQry, lastSufx);
                svg = fopen(pathSvg, "w");
                pQuestionMark(indiceReg(indiceRegistrador), indiceReg(indiceRegistrador), cmc, cmr, grafo[0], registradores, saida, svg);
                free(pathSvg);
                fclose(svg);
            }
            else
            {
                char* pathSvg = malloc((6 + strlen(sufxAux) + strlen(saidaQry))*sizeof(char));
                sprintf(pathSvg,"%s-%s.svg", saidaQry, sufxAux);
                strcpy(lastSufx, sufxAux);
                svg = fopen(pathSvg, "w");
                iniciaSvg(svg);
                pQuestionMark(indiceReg(indiceRegistrador), indiceReg(indiceRegistrador2), cmc, cmr, grafo[0], registradores, saida, svg);
                free(pathSvg);
            }
            finalizaSvg(svg);
            fclose(svg);
        }
        else if (strcmp(tipo, "bf")==0)
        {
            fscanf(qry,"%d",&max);
            fprintf(saida,"%s %d\n",tipo, max);
        }
        else if (strcmp(tipo, "sp?")==0)
        {
            fscanf(qry,"%s %s %s %s %s", sufx, indiceRegistrador, indiceRegistrador2, cmc, cmr);
            fprintf(saida,"%s %s %s %s %s %s\n",tipo, sufx, indiceRegistrador, indiceRegistrador2, cmc, cmr);
        }
        else if (strcmp(tipo, "pb?")==0)
        {
            fscanf(qry,"%s %s %s %s", sufx, indiceRegistrador, indiceRegistrador2, cmc);
            fprintf(saida,"%s %s %s %s %s\n", tipo, sufx, indiceRegistrador, indiceRegistrador2, cmc);
            pb(indiceReg(indiceRegistrador), indiceReg(indiceRegistrador2), cmc, grafo[1], registradores, saida, svg);
        }
    }

    gerarSvgQry(arvoresObjetos, listasQry, saidaSvgQry);
     
    finalizaSvg(saidaSvgQry);

    fclose(saida);
    fclose(qry);
    free(saidaSvg);
    free(saidaTxt);
    fclose(saidaSvgQry);
}
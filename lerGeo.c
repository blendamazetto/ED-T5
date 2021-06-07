#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerGeo.h"

void lerGeo(char arqGeo[], char nomeSvgGeo[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[], Lista hashAux[])
{ 
    int max;
    double x, y, h, w, d, r, distancia = 0;
    char i[20], id[20], txt[1000], tipo[10], cep[20];
    char sw[20], hSW[20], qSW[20], sSW[20], rbSW[20], cSW[20], rSW[20];
    char stroke[22], fill[22], Qstroke[22], Qfill[22], RBstroke[22], RBfill[22], Sstroke[22], Sfill[22], Hstroke[22], Hfill[22];
    strcpy(sw,"5");
    strcpy(hSW,"5");
    strcpy(qSW,"5");
    strcpy(sSW,"5");
    strcpy(rbSW,"5");
    strcpy(cSW,"5");
    strcpy(rSW,"5");
    strcpy(stroke,"black");
    strcpy(fill,"blue");
    strcpy(Qstroke,"black");
    strcpy(Qfill,"blue");
    strcpy(RBstroke,"black");
    strcpy(RBfill,"blue");
    strcpy(Sstroke,"black");
    strcpy(Sfill,"blue");
    strcpy(Hstroke,"black");
    strcpy(Hfill,"blue");

    FILE *geo = fopen(arqGeo,"r");
    FILE *svg = fopen(nomeSvgGeo,"w");

    if(geo == NULL)
    {
        printf("\nERRO\nArquivo .geo nao pode ser aberto\n");
        exit(1);
    }
    
    iniciaSvg(svg);
    
    while(!feof(geo))
    {
        fscanf(geo, "%s", tipo);

        if(strcmp(tipo, "nx")==0)
        {
            fscanf(geo,"%d\n", &max);
        }
        else if(strcmp(tipo, "c")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %s %s\n", i, &r, &x, &y, stroke, fill);
            Circulo circulo = criaCirculo(i, r, x, y, cSW, stroke, fill);
            insert(listasObjetos[0], circulo);
        }
        else if(strcmp(tipo, "r")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf %s %s\n", i, &w, &h, &x, &y, stroke, fill);
            Retangulo retangulo = criaRetangulo(i, w, h, x, y, rSW, stroke, fill);
            insert(listasObjetos[1], retangulo);
        }
        else if(strcmp(tipo, "t")==0)
        {
            fscanf(geo,"%s %lf %lf %s %s", i, &x, &y, stroke, fill);
            fgets(txt, 255, geo);
            Texto texto = criaTexto(i, x, y, stroke, fill, txt);
            insert(listasObjetos[2], texto);
        }
        else if(strcmp(tipo, "q")==0)
        {
            fscanf(geo,"%s %lf %lf %lf %lf\n", cep, &x, &y, &w, &h);
            Quadra quadra = criaQuadra(cep, x, y, w, h, qSW, Qfill, Qstroke);
            insert(listasObjetos[3], quadra);
            insert(hashAux[0], quadra);
        }
        else if(strcmp(tipo, "h")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id, &x, &y);
            Hidrante hidrante = criaHidrante(id, x, y, hSW, Hfill, Hstroke);
            insert(listasObjetos[4], hidrante);
        }
        else if(strcmp(tipo, "s")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id, &x, &y);
            Semaforo semaforo = criaSemaforo(id, x, y, sSW, Sfill, Sstroke);
            insert(listasObjetos[5], semaforo);
        }
        else if(strcmp(tipo, "rb")==0)
        {
            fscanf(geo,"%s %lf %lf\n", id, &x, &y);
            Radiobase radioBase = criaRadiobase(id, x, y, rbSW, RBfill, RBstroke);
            insert(listasObjetos[6], radioBase);
        }
        else if(strcmp(tipo, "cq")==0)
        {
            fscanf(geo,"%s %s %s\n", sw, fill, stroke);

            strcpy(qSW, sw);
            strcpy(Qfill, fill);
            strcpy(Qstroke, stroke);
        }
        else if(strcmp(tipo, "ch")==0)
        {
            fscanf(geo,"%s %s %s\n", sw, fill, stroke);

            strcpy(hSW, sw);
            strcpy(Hfill, fill);
            strcpy(Hstroke, stroke);
        }
        else if(strcmp(tipo, "cr")==0)
        {
            fscanf(geo,"%s %s %s\n", sw, fill, stroke);
            strcpy(rbSW, sw);
            strcpy(RBfill, fill);
            strcpy(RBstroke, stroke);
        }
        else if(strcmp(tipo, "cs")==0)
        {
            fscanf(geo,"%s %s %s\n", sw, fill, stroke);
            
            strcpy(sSW, sw);
            strcpy(Sfill, fill);
            strcpy(Sstroke, stroke);
        }
        else if(strcmp(tipo, "sw")==0)
        {
            fscanf(geo,"%s %s\n", cSW, rSW); 
        }
        else if(strcmp(tipo, "ps")==0)
        {
            fscanf(geo,"%lf %lf\n",&x, &y);
            Posto posto = criaPosto("posto", x, y, distancia);
            insert(listasObjetos[7], posto);
        }
        else if(strcmp(tipo, "dd")==0)
        {
            fscanf(geo,"%lf %lf %lf %lf %lf\n", &x, &y, &w, &h, &d);
            Densidade densidade = criaDensidade(x, y, w, h, d);
            insert(listasObjetos[8], densidade);
        }
    }

    tabelas[3] = createHashTable(tamanhoDaLista(hashAux[0]));
    setTamanhoFinal(listasObjetos[3], tamanhoDaLista(listasObjetos[3]));

    for(No node = getFirst(hashAux[0]); node != NULL; node = getNext(node))
    {
        Info info = getInfo(node);

        char auxCep[20];
        strcpy(auxCep, getQuadraCep(info));

        insertHashTable(info, auxCep, tamanhoDaLista(hashAux[0]), tabelas[3]);
    }

    void* (*getPonto[8])(void*) = {getCirculoPonto, getRetanguloPonto, getTextoPonto, getQuadraPonto, getHidrantePonto, getSemaforoPonto, getRadiobasePonto, getPostoPonto};
    
    void (*swap[8])(void*, void*) = {swapCirculo, swapRetangulo, swapTexto, swapQuadra, swapHidrante, swapSemaforo, swapRadiobase, swapPosto};
   
    for(int i = 0; i < 8; i++)
    {
        balancearQuadTree(arvoresObjetos[i], listasObjetos[i], getPonto[i], swap[i]);
    }

    for(No node = getFirst(listasObjetos[8]); node != NULL; node = getNext(node))
    {
        densidadeQuadras(getInfo(node),arvoresObjetos[3]);
    }

    gerarSvgGeo(svg, arvoresObjetos, NULL);
    finalizaSvg(svg);
    fclose(geo);
    fclose(svg);
}

void lerEc(char arqEc[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[], Lista hashAux[])
{
    FILE *ec = fopen(arqEc,"r");

    if(ec == NULL)
    {
        //printf("\nERRO\nArquivo .ec nao pode ser aberto\n");
        exit(1);
    }

    char tipo[10];
    char codt[20];
    char descricao[255];
    char cnpj[25];
    char cpf[20];
    char cep[20];
    char face[2];
    double num;
    char nome[255];

    while(!feof(ec))
    {
        fscanf(ec, "%s", tipo);

        if(strcmp(tipo, "t")==0)
        {
            fscanf(ec,"%s %s\n", codt, descricao);
            Codt cod = criaCodt(codt, descricao);
            insert(listasObjetos[12], cod);
            insert(hashAux[1], cod);
        }

        else if(strcmp(tipo, "e")==0)
        {
            fscanf(ec,"%s %s %s %s %s %lf %s\n", cnpj, cpf, codt, cep, face, &num, nome);
            Estabelecimento estabelecimento = criaEstabelecimento(cnpj, cpf, codt, cep, face, num, nome, descobrirPonto(cep, face, num, arvoresObjetos[3]));
            insert(listasObjetos[9], estabelecimento);
        }
    }

    tabelas[1] = createHashTable(tamanhoDaLista(hashAux[1]));
    setTamanhoFinal(listasObjetos[12],tamanhoDaLista(listasObjetos[12]));

    for(No node = getFirst(hashAux[1]); node != NULL; node = getNext(node))
    {
        Info info = getInfo(node);
        insertHashTable(getCodtDescricao(info), getCodtCodt(info), tamanhoDaLista(hashAux[1]), tabelas[1]);
    }

    balancearQuadTree(arvoresObjetos[8], listasObjetos[9], getEstabelecimentoPonto, swapEstabelecimento);

    fclose(ec);
}

void lerPm(char arqPm[], Lista listasObjetos[], QuadTree arvoresObjetos[], Hash tabelas[], Lista hashAux[])
{
    FILE *pm;
    pm = fopen(arqPm,"r");

    if(pm == NULL)
    {
        //printf("\nERRO\nArquivo .pm nao pode ser aberto\n");
        exit(1);
    }

    char tipo[10];
    char cpf[20];
    char nome[100];
    char sobrenome[100];
    char sexo[2];
    char nascimento[11];
    char face[2];
    double num;
    char compl[20];
    char cep[20];

    while(!feof(pm))
    {   
        fscanf(pm, "%s", tipo);

        if(strcmp(tipo, "p")==0)
        {
            fscanf(pm,"%s %s %s %s %s\n", cpf, nome, sobrenome, sexo, nascimento);
            Pessoa pessoa = criaPessoa(cpf, nome, sobrenome, sexo, nascimento);
            insert(listasObjetos[10], pessoa);
        }

        else if(strcmp(tipo, "m")==0)
        {
            fscanf(pm, "%s %s %s %lf %s", cpf, cep, face, &num, compl);
            Morador morador = criaMorador(cpf, face, compl, cep, num, descobrirPonto(cep, face, num, arvoresObjetos[3]));
            insert(listasObjetos[11], morador);
            insert(hashAux[2], morador);
        }
    }
    fclose(pm);

    balancearQuadTree(arvoresObjetos[9], listasObjetos[11], getMoradorPonto, swapMorador);

    tabelas[0] = createHashTable(tamanhoDaLista(hashAux[2]));
    setTamanhoFinal(listasObjetos[11],tamanhoDaLista(listasObjetos[11]));

    for(No node = getFirst(hashAux[2]); node != NULL; node = getNext(node))
    {
        Info info = getInfo(node);
        insertHashTable(getMoradorCep(info), getMoradorCpf(info), tamanhoDaLista(hashAux[2]), tabelas[0]);
    }

    tabelas[2] = createHashTable(tamanhoDaLista(listasObjetos[10]));
    setTamanhoFinal(listasObjetos[10], tamanhoDaLista(listasObjetos[10]));

    for(No node = getFirst(listasObjetos[10]); node != NULL; node = getNext(node))
    {
        Info info = getInfo(node);

        char auxCpf[20];
        strcpy(auxCpf, getPessoaCpf(info));

        insertHashTable(info, auxCpf, tamanhoDaLista(listasObjetos[10]), tabelas[2]);
    }
}

void lerVia(char arqVia[])
{
    char tipo[10];
    char id[20];
    double x, y, cmp, vm;
    char nomeRua[200];
    char ldir[20];
    char lesq[20];
    char i[20], j[20];

    FILE *via;
    via = fopen(arqVia,"r");

    if(via == NULL)
    {
        printf("\nERRO\nArquivo .via nao pode ser aberto\n");
        exit(1);
    }

    while(!feof(via))
    {   
        fscanf(via, "%s", tipo);

        if(strcmp(tipo, "v")==0)
        {
            fscanf(via,"%s %lf %lf\n", id, &x, &y);
            Vertice vertice = criaVertice(id, x, y);
        }

        else if(strcmp(tipo, "e")==0)
        {
            fscanf(via, "%s %s %s %s %lf %lf %s\n", i, j, ldir, lesq, &cmp, &vm, nomeRua);
            Aresta aresta = criaAresta(i, j, ldir, lesq, cmp, vm, nomeRua);
        }
    }

    fclose(via);

}
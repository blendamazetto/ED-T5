#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "qry4.h"

void m(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cep[], Lista listasObjetos[])
{
    Info info = searchHashTable(cep, tabelas[3], tamanho(listasObjetos[3]));

    if(info == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    double x = getPontoX(getQuadraPonto(info));
    double y = getPontoY(getQuadraPonto(info));
    double x2 = x + getQuadraW(info);
    double y2 = y + getQuadraH(info);

    Lista moradores = nosDentroRetanguloQt(arvoresObjetos[9], x, y, x2, y2);

    for(No node = getFirst(moradores); node != NULL; node = getNext(node))
    {
        Info inf = getInfoQt(arvoresObjetos[9], getInfo(node));
        Info pessoa = searchHashTable(getMoradorCpf(inf), tabelas[2], tamanho(listasObjetos[10]));

        fprintf(saida,"NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s ", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
        fprintf(saida,"CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCep(inf), getMoradorFace(inf), getMoradorNum(inf), getMoradorCompl(inf));
    }
    removeList(moradores, NULL);
}

void dm(QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], Lista listasObjetos[])
{
    Info morador = getInfoByIdQt(arvoresObjetos[9], cpf);
    Info pessoa = searchHashTable(cpf, tabelas[2], tamanho(listasObjetos[10]));

    if(morador == NULL || pessoa == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    double x = getPontoX(getMoradorPonto(morador));
    double y = getPontoY(getMoradorPonto(morador));

    fprintf(saida,"NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s ", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
    fprintf(saida,"CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCep(morador), getMoradorFace(morador), getMoradorNum(morador), getMoradorCompl(morador));
    
    Linha l = criaLinha(x, y ,x, 0, "black");
    insert(listasQry[2], l);

    char texto[1000];

    sprintf(texto,"CPF:%s NOME:%s CEP:%s FACE:%s NUM:%lf",getMoradorCpf(morador), getPessoaNome(pessoa), getMoradorCep(morador), getMoradorFace(morador), getMoradorNum(morador));

    Texto text = criaTexto("0", x, 0, "black", "black", texto);
    insert(listasQry[4], text);
}

void de(QuadTree arvoresObjetos[], FILE* saida, Hash tabelas[], char cnpj[], Lista listasObjetos[])
{
    Info e = getInfoByIdQt(arvoresObjetos[8], cnpj);

    if(e == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    char cpf[20];
    strcpy(cpf, getEstabelecimentoCpf(e));
    Info pessoa = searchHashTable(cpf, tabelas[2], tamanho(listasObjetos[10]));
    char descricao[255];
    strcpy(descricao, searchHashTable(getEstabelecimentoCodt(e), tabelas[1], tamanho(listasObjetos[12])));

    if(e == NULL || pessoa == NULL)
    {
        return;
    }

    fprintf(saida, "ESTABELECIMENTO - NOME: %s CNPJ: %s CODT: %s DESCRICAO: %s CEP: %s FACE: %s NUM: %lf \n", getEstabelecimentoNome(e),getEstabelecimentoCnpj(e), getEstabelecimentoCodt(e), descricao, getEstabelecimentoCep(e), getEstabelecimentoFace(e), getEstabelecimentoNum(e));
    fprintf(saida,"DONO - NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s \n", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
}

void mud(QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], char cpf[], char cep[], char face[], double num, char compl[], Lista listasObjetos[])
{
    Info morador = getInfoByIdQt(arvoresObjetos[9], cpf);
    Info pessoa = searchHashTable(cpf, tabelas[2], tamanho(listasObjetos[10]));
    Ponto p = descobrirPonto(cep, face, num, arvoresObjetos[3]);

    if(morador == NULL || pessoa == NULL)
    {
        fprintf(saida,"INEXISTENTE\n");
        return;
    }

    Linha l = criaLinha(getPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)), getPontoX(p), getPontoY(p), "red");
    insert(listasQry[2], l);

    Circulo c = criaCirculo("0", 8, getPontoX(getMoradorPonto(morador)), getPontoY(getMoradorPonto(morador)), "3", "white", "red");
    insert(listasQry[3], c);

    Circulo c1 = criaCirculo("0", 8, getPontoX(p), getPontoY(p), "3", "white", "blue");
    insert(listasQry[3], c1);

    char auxCep[20], auxFace[2], auxCompl[20];
    double AuxNum = getMoradorNum(morador);
    strcpy(auxCep, getMoradorCep(morador));
    strcpy(auxFace, getMoradorFace(morador));
    strcpy(auxCompl, getMoradorCompl(morador));

    setMoradorCep(morador, cep);
    setMoradorFace(morador, face);
    setMoradorNum(morador, num);
    setMoradorCompl(morador, compl);
    setMoradorPonto(morador, p);

    fprintf(saida,"NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s \n", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
    fprintf(saida,"ENDERECO ANTIGO: CEP: %s FACE: %s NUM: %lf COMPL: %s\n", auxCep, auxFace, AuxNum, auxCompl);
    fprintf(saida,"ENDERECO NOVO: CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCep(morador), getMoradorFace(morador), getMoradorNum(morador), getMoradorCompl(morador));
}

void dmprbt(QuadTree arvoresObjetos[], char t, char saida[], char sfx[])
{
    int i;
    switch(t) {
    case 'q':
        i = 3;
        break;
    case 'h':
        i = 4;
        break;
    case 's':
        i = 5;
        break;
    case 't':
        i = 6;
        break;
    default:
        return;
    }

    char* pathSvg = malloc((6 + strlen(sfx) + strlen(saida))*sizeof(char));

    sprintf(pathSvg,"%s-%s.svg",saida,sfx);

    FILE* svg = fopen(pathSvg, "w");

    iniciaSvg(svg);
    desenharQt(arvoresObjetos[i], svg);
    finalizaSvg(svg);

    free(pathSvg);
}

void epgl (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], Hash tabelas[], double x, double y, double w, double h, Lista listasObjetos[], char tp[])
{
    Lista l = nosDentroRetanguloQt(arvoresObjetos[8], x, y, x+w, y+h);
    Info pessoa, e;

    if(l == NULL)
    {
        return;
    }

    if(strcmp(tp, "*"))
    {
        for(No node = getFirst(l) ; node != NULL; node = getNext(node))
        {
            e = getInfoQt(arvoresObjetos[8], getInfo(node));
         
            fprintf(saida, "ESTABELECIMENTO - NOME: %s CNPJ: %s CODT: %s CEP: %s FACE: %s NUM: %lf \n", getEstabelecimentoNome(e),getEstabelecimentoCnpj(e), getEstabelecimentoCodt(e), getEstabelecimentoCep(e), getEstabelecimentoFace(e), getEstabelecimentoNum(e));
            pessoa = searchHashTable(getEstabelecimentoCpf(e), tabelas[2], tamanho(listasObjetos[10]));

            if(pessoa != NULL)
            {
                fprintf(saida,"PROPRIETARIO - NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s \n", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
            }
        
            Circulo c = criaCirculo("0", 7, getPontoX(getEstabelecimentoPonto(e)), getPontoY(getEstabelecimentoPonto(e)), "3", "red", "black");
            insert(listasQry[3], c);
        }
    }
    else
    {
        for(No node = getFirst(l) ; node != NULL; node = getNext(node))
        {
            e = getInfoQt(arvoresObjetos[8], getInfo(node));
            if(strcmp(getEstabelecimentoCodt(e), tp) == 0)
            {
                pessoa = searchHashTable(getEstabelecimentoCpf(e), tabelas[2], tamanho(listasObjetos[10]));
                fprintf(saida, "ESTABELECIMENTO - NOME: %s CNPJ: %s CODT: %s CEP: %s FACE: %s NUM: %lf \n", getEstabelecimentoNome(e),getEstabelecimentoCnpj(e), getEstabelecimentoCodt(e), getEstabelecimentoCep(e), getEstabelecimentoFace(e), getEstabelecimentoNum(e));
                
                if(pessoa != NULL)
                {
                    fprintf(saida,"PROPRIETARIO - NOME: %s %s CPF: %s NASCIMENTO: %s SEXO: %s \n", getPessoaNome(pessoa), getPessoaSobrenome(pessoa), getPessoaCpf(pessoa), getPessoaNascimento(pessoa), getPessoaSexo(pessoa));
                }                
                
                Circulo c = criaCirculo("0", 7, getPontoX(getEstabelecimentoPonto(e)), getPontoY(getEstabelecimentoPonto(e)), "3", "red", "black");
                insert(listasQry[3], c);
            }
        }
    }
}

void catac (QuadTree arvoresObjetos[], FILE* saida, Lista listasQry[], double x, double y, double r)
{
    Lista q = nosDentroCirculoQt(arvoresObjetos[3], x, y, r);
    Lista h = nosDentroCirculoQt(arvoresObjetos[4], x, y, r);
    Lista s = nosDentroCirculoQt(arvoresObjetos[5], x, y, r);
    Lista rb = nosDentroCirculoQt(arvoresObjetos[6], x, y ,r);
    Lista m = nosDentroCirculoQt(arvoresObjetos[9], x, y, r);
    Lista e = nosDentroCirculoQt(arvoresObjetos[8], x, y, r);
    char id[20];

    Circulo c = criaCirculo("0", r, x, y, "3", "#6C6753", "#CCFF00");
    insert(listasQry[8], c);

    for(No node = getFirst(q) ; node != NULL; node = getNext(node))
    {
        Info quad = getInfoQt(arvoresObjetos[3], getInfo(node));
        strcpy(id, getQuadraCep(quad));

        if(getNodeByIdQt(arvoresObjetos[3],id) != NULL)
        {
            Info r1 = getInfoQt(arvoresObjetos[3], getInfo(node));
            if(distancia(getQuadraX(r1),getQuadraY(r1),x,y) <= r && distancia(getQuadraX(r1) + getQuadraW(r1) ,getQuadraY(r1) + getQuadraH(r1),x,y) <= r)
            {
                if(distancia(getQuadraX(r1) + getQuadraW(r1), getQuadraY(r1) ,x,y) <= r && distancia(getQuadraX(r1), getQuadraY(r1) + getQuadraH(r1),x,y) <= r)
                {
                    QtNo node = getNodeByIdQt(arvoresObjetos[3],id);
                    Info c = removeNoQt(arvoresObjetos[3], node);
                    fprintf(saida,"QUADRA - CEP: %s X: %lf Y: %lf W: %lf H: %lf \n", getQuadraCep(c), getQuadraX(c), getQuadraY(c), getQuadraW(c), getQuadraH(c));
                }
            }
        }
    }

    for(No node = getFirst(h) ; node != NULL; node = getNext(node))
    {
        Info hid = getInfoQt(arvoresObjetos[4], getInfo(node));
        strcpy(id, getQuadraCep(hid));

        if(getNodeByIdQt(arvoresObjetos[4],id) != NULL)
        {
            QtNo node = getNodeByIdQt(arvoresObjetos[4],id);
            Info c = removeNoQt(arvoresObjetos[4], node);
            fprintf(saida,"HIDRANTE - ID: %s X: %lf Y: %lf \n", getHidranteId(c), getHidranteX(c), getHidranteY(c));
        }
    }

    for(No node = getFirst(s) ; node != NULL; node = getNext(node))
    {
        Info sem = getInfoQt(arvoresObjetos[5], getInfo(node));
        strcpy(id, getQuadraCep(sem));

        if(getNodeByIdQt(arvoresObjetos[5],id) != NULL)
        {
            QtNo node = getNodeByIdQt(arvoresObjetos[5],id);
            Info c = removeNoQt(arvoresObjetos[5], node);
            fprintf(saida,"SEMAFORO - ID: %s X: %lf Y: %lf \n", getSemaforoId(c), getSemaforoX(c), getSemaforoY(c));
        }
    }

    for(No node = getFirst(rb) ; node != NULL; node = getNext(node))
    {
        Info radiob = getInfoQt(arvoresObjetos[6], getInfo(node));
        strcpy(id, getQuadraCep(radiob));

        if(getNodeByIdQt(arvoresObjetos[6],id) != NULL)
        {
            QtNo node = getNodeByIdQt(arvoresObjetos[6],id);
            Info c = removeNoQt(arvoresObjetos[6], node);
            fprintf(saida,"RADIOBASE - ID: %s X: %lf Y: %lf \n", getRadiobaseId(c), getRadiobaseX(c), getRadiobaseY(c));
        }
    }

    for(No node = getFirst(m) ; node != NULL; node = getNext(node))
    {
        Info mor = getInfoQt(arvoresObjetos[9], getInfo(node));
        strcpy(id, getQuadraCep(mor));

        if(getNodeByIdQt(arvoresObjetos[9],id) != NULL)
        {
            QtNo node = getNodeByIdQt(arvoresObjetos[9],id);
            Info c = removeNoQt(arvoresObjetos[9], node);
            fprintf(saida,"MORADOR - CPF: %s CEP: %s FACE: %s NUM: %lf COMPL: %s\n", getMoradorCpf(c), getMoradorCep(c), getMoradorFace(c), getMoradorNum(c), getMoradorCompl(c));
        }
    }

    for(No node = getFirst(e) ; node != NULL; node = getNext(node))
    {
        Info est = getInfoQt(arvoresObjetos[8], getInfo(node));
        strcpy(id, getQuadraCep(est));

        if(getNodeByIdQt(arvoresObjetos[8],id) != NULL)
        {
            QtNo node = getNodeByIdQt(arvoresObjetos[8],id);
            Info c = removeNoQt(arvoresObjetos[8], node);
            fprintf(saida, "ESTABELECIMENTO - NOME: %s CNPJ: %s CODT: %s CEP: %s FACE: %s NUM: %lf \n", getEstabelecimentoNome(c),getEstabelecimentoCnpj(c), getEstabelecimentoCodt(c), getEstabelecimentoCep(c), getEstabelecimentoFace(c), getEstabelecimentoNum(c));
        }
    }
}

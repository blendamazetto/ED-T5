#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lerHf.h"

void listToHashfile(Hashfile hf, Lista l)
{
    for(No node = getFirst(l); node != NULL; node = getNext(node))
    {
        fwriteRec(hf, getInfo(node));
    }
}

void saveHashfile(char nomebase[], Hash tabelas[], QuadTree arvoresObjetos[], int tamanhoCodt, int tamanhoPessoa)
{
    char fileEC[80], fileDes[80], fileP[80], fileEnd[80];

    sprintf(fileEC,"%s-ec.dat", nomebase);
    sprintf(fileDes,"%s-codt.dat", nomebase);
    sprintf(fileP,"%s-pessoa.dat", nomebase);
    sprintf(fileEnd,"%s-morador.dat", nomebase);

    Hashfile hf[4];

    hf[0] = fcreateHF(fileDes,107,10,getSizeCodt(),20);
    hf[1] = fcreateHF(fileEC,107,10,getSizeEstabelecimento(),20);
    hf[2] = fcreateHF(fileP,107,10,getSizePessoa(),20);
    hf[3] = fcreateHF(fileEnd,107,10,getSizeMorador(),20);

    Lista lAux[4], est = create(), mor = create(), cod = create(), pes = create();

    for(int i = 0; i < 4; i++)
    {
        lAux[i] = create();
    }
    
    adicionarHashNaListaCodt(tabelas[1], cod, tamanhoCodt);
    for(No node = getFirst(cod); node != NULL; node = getNext(node)) 
    {
        insertList(createItem(getCodtCodt(getInfo(node)), getInfo(node)), lAux[0]);
    }

    percorreLarguraQt(arvoresObjetos[8], insertList, est);
    for(No node = getFirst(est); node != NULL; node = getNext(node)) 
    {
        insertList(createItem(getEstabelecimentoCnpj(getInfo(node)), getInfo(node)), lAux[1]);
    }
    
    adicionarHashNaListaPessoa(tabelas[2], pes, tamanhoPessoa);
    for(No node = getFirst(pes); node != NULL; node = getNext(node)) 
    {
        insertList(createItem(getPessoaCpf(getInfo(node)), getInfo(node)), lAux[2]);
    }
    
    percorreLarguraQt(arvoresObjetos[9], insertList, mor);
    for(No node = getFirst(mor); node != NULL; node = getNext(node)) 
    {
        insertList(createItem(getMoradorCpf(getInfo(node)), getInfo(node)), lAux[3]);
    }

    for(int i = 0; i < 4; i++)
    {
        listToHashfile(hf[i], lAux[i]);
        fcloseHF(hf[i]);
    }

    for(int i = 0; i < 4; i++)
    {
        removeList(lAux[i], desalocaItem);
    }

    removeList(est, NULL);
    removeList(mor, NULL);
    removeList(pes, NULL);
    removeList(cod, NULL);
}

void readHashfile(char nomebase[], Hash tabelas[], Lista est, Lista mor, Lista listasObjetos[])
{
    char fileEC[80], fileDes[80], fileP[80], fileEnd[80];

    sprintf(fileEC,"%s-ec.dat", nomebase);
    sprintf(fileDes,"%s-codt.dat", nomebase);
    sprintf(fileP,"%s-pessoa.dat", nomebase);
    sprintf(fileEnd,"%s-morador.dat", nomebase);

    Lista lAux[4];

    for(int i = 0; i < 4; i++)
    {
        lAux[i] = create();
    }

    Hashfile hf[4];

    hf[0] = fopenHF(fileDes);
    hf[1] = fopenHF(fileEC);
    hf[2] = fopenHF(fileP);
    hf[3] = fopenHF(fileEnd);

    for(int i = 0; i < 4; i++)
    {
        dumpFileHF(hf[i], lAux[i], insertList);
        fcloseHF(hf[i]);
    }

    tabelas[1] = createHashTable(tamanhoDaLista(lAux[0]));
    tabelas[2] = createHashTable(tamanhoDaLista(lAux[2]));
    tabelas[0] = createHashTable(tamanhoDaLista(lAux[3]));

    setTamanhoFinal(listasObjetos[12], tamanhoDaLista(lAux[0]));
    setTamanhoFinal(listasObjetos[10], tamanhoDaLista(lAux[2]));
    setTamanhoFinal(listasObjetos[11], tamanhoDaLista(lAux[3]));

    adicionarListaNaHashCodt(tabelas[1], lAux[0]);
    adicionarListaNaHashPessoa(tabelas[2], lAux[2]);
    adicionarListaNaHashMorador(tabelas[0], lAux[3]);

    for(No node = getFirst(lAux[1]); node != NULL; node = getNext(node))
    {
        Estabelecimento e = getValorItem(getInfo(node));
        setEstabelecimentoPonto(e, createPonto(getEstabelecimentoX(e), getEstabelecimentoY(e)));
        insertList(e, est);
    }

    for(No node = getFirst(lAux[3]); node != NULL; node = getNext(node))
    {
        Morador m = getValorItem(getInfo(node));
        setMoradorPonto(m, createPonto(getMoradorX(m), getMoradorY(m)));
        insertList(m, mor);
    }

    for(int i = 0; i < 4; i++)
    {
        removeList(lAux[i], desalocaItem);
    }
}
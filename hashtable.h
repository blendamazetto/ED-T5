
#ifndef __HASHTABLE__
#define __HASHTABLE__

#include "lista.h"
#include "codt.h"
#include "pessoa.h"
#include "morador.h"
#include "item.h"
//Define "Hash" como um void pointer
typedef void* Hash;

/*
* Calcula o indice do vetor utilizando uma tecnica de codificacao
* precisa de um char que sera codificado e o tamanho do vetor
* retorna um unsigned int com o numero do indice
*/
unsigned int hash (char key[], int tamanhoHash);

/*
* cria uma hashtable
* precisa do tamanho da hashtable que sera criada
* retorna um ponteiro para a hashtable que foi criada
*/
Hash createHashTable(int tamanhoHash);

//Faz a conversão de uma lista para um hashtable, no caso, a lista de CODT
void adicionarListaNaHashCodt(Hash hashtable, Lista lista);

//Faz a conversão de uma lista para um hashtable no caso, a lista de Pessoas
void adicionarListaNaHashPessoa(Hash hashtable, Lista lista);

//Faz a conversão de uma lista para um hashtable no caso, a lista de Moradores
void adicionarListaNaHashMorador(Hash hashtable, Lista lista);

//Faz a conversão de uma Hashtable para uma lista, no caso, a hash de CODT
void adicionarHashNaListaCodt(Hash hashtable, Lista lista, int tamanho);

//Faz a conversão de uma Hashtable para uma lista, no caso, a hash de Pessoas
void adicionarHashNaListaPessoa(Hash hashtable, Lista lista, int tamanho);

//Faz a conversão de uma Hashtable para uma lista, no caso, a hash de Moradores
void adicionarHashNaListaMorador(Hash hashtable, Lista lista, int tamanho);

/*
* insere um elemento na hashtable
* precisa da info que sera inserida, da chave de busca, do tamanho da hashtable e de um void pointer para a hashtable
* nao retorna nada
*/
void insertHashTable(Info info, char key[], int tamanho, Hash hashtable);

/*
* printa a hashtable
* recebe o tamanho da hashtable e um void pointer para a hashtable
* nao retorna nada
*/
void printHashTable(int tamanho, Hash hashtable);

/*
* busca um elemento na hashtable
* precisa da chave de busca, de um void pointer para a hashtable e o tamanho da hashtable
* retorna um ponteiro pra info procurada
*/
Hash searchHashTable(char key[], Hash hashtable, int tamanho);

/*
* remove um no da hashtable
* precisa de uma chave de busca, um void pointer para a hashtable e o tamanho da hashtable
* nao retorna nada
*/
void removeNodeHashTable(char key[], Hash hashtable, int tamanho);

/*
* converte uma info da hashtable
* precisa de um void pointer info
* retorna um char* para a informacao convertida
*/
char* getHashInfo(Info info);

/*
* deleta a hashtable 
* precida de um void pointer para a hashtable que sera deletada e o tamanho de hashtable
* nao retorna nada
*/
void deleteHashTable(Hash hashtable, int tamanho,  int a);

/*
* seta uma info na hashtable
* precisa de uma chave, um void pointer para a hashtable, o tamanho, e a info a ser setada
* nao retorna nada
*/
void setHashTable(char key[], Hash hashtable, int tamanho, Info info);

/*
    Retorna o menor valor presente em uma hashtable
*/
void buscarMenorValor(Hash hashtable, int tamanho, char idMenorValor[], Hash visitado);

/*
    Retorna o tamanho real de uma hashtable, a hashtable é alocada com o tamanho inicial tam
    esse funcao retorna quantos itens foram alocados na hashtable
*/
int tamanhoDaHashtable(Hash hashtable, int tam);


#endif
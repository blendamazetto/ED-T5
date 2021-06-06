#ifndef __CODT_H
#define __CODT_H

//Define "Circulo" como um void pointer
typedef void* Codt;

/*
*Aloca uma struct codt com os valores dos parametros
*Precisa de um codt e uma descrição
*Retorna um void pointer para o codt criado
*/
Codt criaCodt(char codt[], char descricao[]);

/*
*Obtem o codt de uma info codt
*Precisa de um void pointer pra um codt
*Retorna um char contendo o codt
*/
char* getCodtCodt(Codt c);

/*
*Seta uma string no codt
*Precisa de um char que sera setado e um void pointer para o codt onde ira setar
*Não retorna nada
*/
void setCodtCodt(Codt c, char codt[]);

/*
*Obtem a descricao de uma info codt
*Precisa de um void pointer pra um codt
*Retorna um char contendo a descricao
*/
char* getCodtDescricao(Codt c);

/*
*Seta uma string na descricao
*Precisa de um char que sera setado e um void pointer para o codt onde ira setar
*Não retorna nada
*/
void setCodtDescricao(Codt c, char descricao[]);

/*
*Desaloca a info de um codt
*precisa de um void pointer para um codt
*nao retorna nada
*/
void desalocarCodt(Codt c);

#endif
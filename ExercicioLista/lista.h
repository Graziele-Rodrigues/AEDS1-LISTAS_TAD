#ifndef header_lista // macro inicial
#define header_lista //macro inicial

#include <stdlib.h>
#include <stdio.h>

typedef struct TProduto{
  int codigo;
  char nome[100];
  float preco;
} TProduto;

typedef struct Tcelula {
  TProduto Item; //tem um item do tipo produto
  struct celula *prox; //ponteiro para andar na lista
} TCelula;

typedef struct TLista{
  TCelula *primeiro;
  TCelula *ultimo;
} TLista;

/** prototipos funcoes **/
void lerProduto();
void imprimirProduto();
void Iniciar();
void Inserir();
void Imprimir();
void Pesquisar();
void Excluir();

#endif
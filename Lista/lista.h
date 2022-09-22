
/* se ja existe biblioteca, existe o arquivo objeto o lista.h nao é compilado novamente */

#ifndef header_lista // macro inicial
#define header_lista //macro inicial

#include <stdlib.h>
#include <stdio.h>

//structs: TProduto, TCelula, TLista
//assinatura das funcoes: LerProduto, ImprimirProduto, FLVazia, Inserir, Pesquisar, Excluir, Imprimir


typedef struct {
  int codigo;
  char nome[100];
  int quantidade;
  float preco;
} TProduto;

typedef struct celula {
  TProduto item;
  struct celula *prox;
} TCelula;

typedef struct {
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;


void LerProduto(TProduto *x);
void ImprimirProduto(TProduto x);
void FLVazia(TLista *Lista);
int Vazia(TLista Lista);
int Tamanho(TLista lista);
void Inserir(TProduto x, TLista *Lista);
void Imprimir(TLista lista);
TCelula *Pesquisar(TProduto Item, TLista Lista);
void Excluir(TProduto *Item, TLista *Lista);
void Liberar(TLista *TLista);


#endif //macro final
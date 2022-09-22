#include <stdio.h>
#include <stdlib.h>
#include "lista.h"  //usa aspas duplas pois esta na raiz do projeto

/* corpo das funcoes que possuem assinatura em lsita.h */

void LerProduto(TProduto *x) { // passando por referencia
  printf("\ndigite o nome: ");
  fflush(stdin);
  fgets(x->nome, 100, stdin);
  printf("\ndigite o codigo: ");
  fflush(stdin);
  scanf("%d", &x->codigo);
  printf("\ndigite a quantidade: ");
  fflush(stdin);
  scanf("%d", &x->quantidade);
  printf("\ndigite o preco: ");
  fflush(stdin);
  scanf("%f", &x->preco);
}

void ImprimirProduto(TProduto x) { // passagem por valor
  printf("Produto: %s", x.nome);
  printf("Codigo: %d\n", x.codigo);
  printf("Quantidade: %d\n", x.quantidade);
  printf("Preco: %.2f\n", x.preco);
  printf("\n-------------------------------\n");
}

void FLVazia(TLista *Lista) {                           // deixa a lista vazia
  Lista->primeiro = (TCelula *)malloc(sizeof(TCelula)); // inicializa o ponteiro
  Lista->ultimo = Lista->primeiro;
  Lista->primeiro->prox = NULL; // aterra o ponteiro da celula cabeça
  Lista->tamanho = 0;
}

int Vazia(TLista Lista) { // verifica se a lista ta vazia
  return (Lista.primeiro ==
          Lista.ultimo); // retorna verdadeiro ou falso, comparando os dois, se
                         // forem iguais retorna 1, diferentes 0.
}

int Tamanho(TLista lista) { return lista.tamanho; } 

void Inserir(TProduto x, TLista *Lista) { // passagem valor e por referencia
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox; // cria a próxima celula
  Lista->ultimo->item = x; // adicionando o valor de item, já vem pronto
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

void Imprimir(TLista lista) { // passagem por valor
  TCelula *Aux;
  Aux = lista.primeiro->prox; // aux recebe o prox depois da cabeca
  while (Aux != NULL) {
    ImprimirProduto(Aux->item);
    Aux = Aux->prox;
  }
}

TCelula *Pesquisar(TProduto Item, TLista Lista) {
  TCelula *Aux;
  Aux = Lista.primeiro;
  while (Aux->prox != NULL) {
    if (Aux->prox->item.codigo == Item.codigo) {
      return Aux;
    }
    Aux = Aux->prox;
  }
  return NULL;
}

void Excluir(TProduto *Item, TLista *Lista) {
  TCelula *Aux1, *Aux2;
  Aux1 = Pesquisar(*Item, *Lista);
  if (Aux1 != NULL) {
    Aux2 = Aux1->prox;
    Aux1->prox = Aux2->prox;
    *Item = Aux2->item;
    if (Aux1->prox == NULL)
      Lista->ultimo = Aux1;
    free(Aux2);
    Lista->tamanho--;
  } else {
    Item->codigo = -1;
  }
}

void Liberar(TLista *TLista){
	TCelula* aux;
	for (int i = 0; i <TLista->tamanho; i++)
	{
		aux = TLista->primeiro->prox;
		TLista->primeiro->prox = aux->prox;
		free(aux);
	}
	free(TLista->primeiro);
	TLista->tamanho= 0;
}


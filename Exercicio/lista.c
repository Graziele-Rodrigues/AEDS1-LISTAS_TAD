#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

void lerProduto(TProduto *p){
   printf("digite o codigo: ");
    fflush(stdin);
    scanf("%d",&p->codigo);
    fflush(stdin);
    printf("digite o nome: ");
    fflush(stdin);
    fgets(p->nome,100,stdin);
    printf("digite o preco: ");
    fflush(stdin);
    scanf("%f",&p->preco);
    fflush(stdin);
}

void imprimirProduto(TProduto p) { // passagem por valor
  printf("\n-------------------------------\n");
  printf("Produto: %s", p.nome);
  printf("Preco: %.2f", p.preco);
  printf("\n-------------------------------\n");
}

void Iniciar(TLista *Lista) {    //passagem por referencia  
  Lista->primeiro = (TCelula *)malloc(sizeof(TCelula)); // inicializa o ponteiro
  Lista->ultimo = Lista->primeiro;
  Lista->primeiro->prox = NULL; // aterra o ponteiro da celula cabeça
}

void Inserir(TLista *Lista, TProduto p){
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox; // cria a próxima celula
  Lista->ultimo->Item = p; // adicionando o valor de item
  Lista->ultimo->prox = NULL;
}


void Imprimir(TLista Lista) { // passagem por referencia
  TCelula *aux;
  aux = Lista.primeiro->prox; // aux recebe o prox depois da cabeca
  while (aux != NULL) { //diferente de null
    imprimirProduto(aux->Item);
    aux = aux->prox; //mostrar proximo
  }
}

/*TCelula* Pesquisar(TLista Lista, TProduto item){
	TCelula* aux;
	aux = Lista.primeiro;
	while (aux->prox != NULL)
	{
		if (aux->prox->Item.codigo == item.codigo)
			return aux;
		aux = aux->prox;
	}
	return NULL;
}

void Excluir(TLista *Lista, TProduto *item){
	TCelula *aux1, * aux2;
	aux1 = Pesquisar(*Lista, *item);
	if (aux1 != NULL){
		aux2 = aux1->prox;
		aux1->prox = aux2->prox;
		*item = aux2->Item;
		if (aux1->prox == NULL)
		{
			Lista->ultimo = aux1;
		}
		free(aux2);
	}
}*/

#include <stdlib.h>
#include <stdio.h>

typedef struct TLetras{
  char letra; 
} TLetras;

typedef struct Tcelula {
  TLetras item;
  struct celula *prox; //ponteiro para andar na lista
} TCelula;

typedef struct TLista{
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;


void lerLetra(TLetras *l){
    printf("digite a letra:");
    scanf("%s", &l->letra);
}

void imprimirLetra(TLetras l){ 
    printf("%c", l.letra);
}

void Iniciar(TLista *Lista) {    //passagem por referencia  
  Lista->primeiro = (TCelula *)malloc(sizeof(TCelula)); // inicializa o ponteiro
  Lista->ultimo = Lista->primeiro;
  Lista->primeiro->prox = NULL; // aterra o ponteiro da celula cabeça
  Lista->tamanho = 0;
}

int Vazia(TLista Lista) { // verifica se a lista ta vazia
    return (Lista.primeiro == Lista.ultimo); 
  // retorna verdadeiro ou falso, comparando os dois, se forem iguais retorna 1, diferentes 0.
}

int Tamanho(TLista lista){ 
    return lista.tamanho; 
} 

void Inserir(TLista *Lista, TLetras letra){
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox; 
  Lista->ultimo->item = letra; 
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

void Imprimir(TLista Lista){ 
  TCelula *aux;
  aux = Lista.primeiro->prox; 
  while (aux != NULL) { 
    imprimirLetra(aux->item);
    aux = aux->prox; 
  }
}

void Concatenar(TLista *Lista1, TLista *Lista2){
	if (!Vazia(*Lista1) && !Vazia(*Lista2)){
		TCelula* aux;
		aux = Lista2->primeiro->prox;
		while (aux != NULL){
			Inserir(Lista1, aux->item);
			aux = aux->prox;
		}
	}
	else{
		printf("\n\t\t UMA DAS LISTAS ESTA VAZIA!");
	}
}



int main(){
  TLetras l1, l2;
  TLista Lista1, Lista2;

  Iniciar(&Lista1);
  Iniciar(&Lista2);

  printf("LISTA1\n");
  for (int i=0; i<3; i++){
    lerLetra(&l1);
    Inserir(&Lista1, l1);
  }
  
  printf("LISTA2\n");
  for (int i=0; i<2; i++){
    lerLetra(&l2);
    Inserir(&Lista2, l2);
  }

  Concatenar(&Lista1, &Lista2);
  Imprimir(Lista1);

  return 0;
}

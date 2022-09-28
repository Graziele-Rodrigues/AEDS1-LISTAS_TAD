
#include <stdlib.h>
#include <stdio.h>

typedef struct TCode{
  char nome[100]; 
} TCode;

typedef struct Tcelula {
  TCode item;
  struct celula *prox; //ponteiro para andar na lista
} TCelula;

typedef struct TLista{
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;


void LerCode(TCode *n){
    printf("digite o nome:");
    fflush(stdin);
    fgets(n->nome, 100, stdin);
}

void ImprimirNomes(TCode n){
    printf("%s", n.nome);
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

void Inserir(TLista *Lista, TCode Item){
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox; 
  Lista->ultimo->item = Item; 
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}



void OrdemCrescente(TLista *Lista, TCode Item){
	if (Vazia(*Lista)){
		Inserir(Lista, Item);
	}else if (strcmp(Lista->ultimo->item.nome, Item.nome) <= 0){
		Inserir(Lista, Item);
	}else{
		TCelula *novo = (TCelula*)malloc(sizeof(TCelula));
		novo->item = Item;
		TCelula *aux, *celula, *prox_celula;
		aux = Lista->primeiro;
		while (strcmp(Lista->ultimo->item.nome, Item.nome) <= 0){
			aux = aux->prox;
		}
		prox_celula = aux->prox;
        celula = aux;
		novo->prox = prox_celula;
		celula->prox = novo;
		Lista->tamanho++;
	}
}

void Imprimir(TLista Lista){ 
  TCelula *aux;
  aux = Lista.primeiro->prox; 
  while (aux != NULL) { 
    ImprimirNomes(aux->item);
    aux = aux->prox; 
  }
}



int main(){
  TCode n;
  TLista Lista;
  int continuar=0;

  Iniciar(&Lista);

  printf("LISTA\n");
  do{
    LerCode(&n);
    OrdemCrescente(&Lista, n);
    printf("\nDeseja continuar?\n(1 - Sim, 0 - Nao):");
    scanf("%d", &continuar);
  }while(continuar==1);
  
  Imprimir(Lista);

  return 0;
}

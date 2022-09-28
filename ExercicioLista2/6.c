
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


void RemoveItem(TLista *Lista, int i){
	if (Lista->tamanho < i){
		printf("\n\t\t NAO EXISTE \n");
	}else{
    int count=1;
		TCelula *aux1, *aux2;
    aux2 = aux1->prox;
		aux1->prox = aux2->prox;
		while(count<i){
			aux2 = aux2->prox;
			count++;
		}
    Lista->ultimo = aux1; 
    free(atual);
    /*
    if(atual == Lista->primeiro){
      Lista->primeiro = Lista->primeiro->prox;
      free(atual);
    }else{
        if(atual == Lista->ultimo){
          Lista->ultimo = anterior;
        }
        anterior->prox = atual->prox;
        free(atual);
    }*/
  }
}



void Imprimir(TLista Lista){ 
  TCelula *aux;
  aux = Lista.primeiro->prox;
  while (aux != NULL) { 
    printf("%c", aux->item.letra);
    aux = aux->prox; 
  }
}

int main(){
  TLetras l;
  TLista Lista;
  int continuar=0;

  Iniciar(&Lista);

  printf("LISTA\n");
  do{
    lerLetra(&l);
    Inserir(&Lista, l);
    printf("\nDeseja continuar?\n(1 - Sim, 0 - Nao):");
    scanf("%d", &continuar);
  }while(continuar==1);
  
  RemoveItem(&Lista, 3);
  printf("\n\t\tNova lista\n");
  Imprimir(Lista);

  return 0;
}

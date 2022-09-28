
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

void Dividir(TLista Lista1, TLista Lista2, TLista Lista3){
    
}




int main(){
  TLetras l;
  TLista Lista1, Lista2, Lista3;
  int continuar=0;

  Iniciar(&Lista1);
  Iniciar(&Lista2);
  Iniciar(&Lista3);

  printf("LISTA\n");
  do{
    lerLetra(&l);
    Inserir(&Lista1, l);
    printf("\nDeseja continuar?\n(1 - Sim, 0 - Nao):");
    scanf("%d", &continuar);
  }while(continuar==1);
  
  Dividir(Lista1, Lista2, Lista3)

  return 0;
}

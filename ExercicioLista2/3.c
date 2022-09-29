
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

void Imprimir(TLista Lista){ 
  TCelula *aux;
  aux = Lista.primeiro->prox;
  while (aux != NULL) { 
    printf("%c", aux->item.letra);
    aux = aux->prox; 
  }
}

void Inserir(TLista *Lista, TLetras letra){
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox; 
  Lista->ultimo->item = letra; 
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

void Dividir(TLista Lista1, TLista Lista2, TLista Lista3){
    TCelula *aux1;
    int n = 0, metade1=0, metade2=0, count1=0, count2=0;
    n = Lista1.tamanho+1;
    metade1=n/2;
    metade2 = n - metade1;
    aux1 = Lista1.primeiro;
    while(count1<metade1){
      aux1 = aux1->prox;
      Inserir(&Lista2, aux1->item);
      count1++;
    }
    while(count2<metade2){
      aux1 = aux1->prox;
      if(aux1!=NULL)
        Inserir(&Lista3, aux1->item);
      count2++;
    }
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
  
  Dividir(Lista1, Lista2, Lista3);
  Imprimir(Lista2);
  printf("\n================\n");
  Imprimir(Lista3);


  return 0;
}

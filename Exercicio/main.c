#include <stdio.h>
#include <stdlib.h>
#include "lista.c" //por estar usando no vscode
//#include "lista.h"


int main(){
  TProduto p;
  TLista Lista1, Lista2;

  Iniciar(&Lista1);
  Iniciar(&Lista2);


  for (int i=1; i<=3; i++){
    printf("\n######### LER PRODUTO %d da LISTA 1 ##########\n", i);
    lerProduto(&p);
    Inserir(&Lista1, p);
  }

  for (int i=1; i<=3; i++){
    printf("\n######### LER PRODUTO %d da LISTA 2 ##########\n", i);
    lerProduto(&p);
    Inserir(&Lista2, p);
  }

  
  Excluir(&Lista1, &Lista1.primeiro->prox->prox->prox->Item);
	Excluir(&Lista1, &Lista1.primeiro->prox->Item);
	Excluir(&Lista1, &Lista1.primeiro->prox->prox->Item);
	Excluir(&Lista1, &Lista1.primeiro->prox->Item);
  

  printf("\n############# INFORMACAO LISTA 1 #############\n");
  Imprimir(Lista1);

  printf("\n############# INFORMACAO LISTA 2 #############\n");
  Imprimir(Lista2);
 
  return 0;
}

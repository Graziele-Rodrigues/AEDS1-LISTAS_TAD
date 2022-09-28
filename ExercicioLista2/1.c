
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct TAluno{
  int matricula;
  char nome[100];
} TAluno;

typedef struct Tcelula {
  TAluno aluno; //tem um item do tipo produto
  struct celula *prox; //ponteiro para andar na lista
} TCelula;

typedef struct TLista{
  TCelula *primeiro;
  TCelula *ultimo;
  int tamanho;
} TLista;


void lerAluno(TAluno *a){
    printf("digite a matricula: ");
    scanf("%d",&a->matricula);
    fflush(stdin);
    printf("digite o nome: ");
    fflush(stdin);
    fgets(a->nome,100,stdin);
    fflush(stdin);
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

void Inserir(TLista *Lista, TAluno a){
  Lista->ultimo->prox = (TCelula *)malloc(sizeof(TCelula));
  Lista->ultimo = Lista->ultimo->prox; // cria a próxima celula
  Lista->ultimo->aluno = a; // adicionando o valor de item
  Lista->ultimo->prox = NULL;
  Lista->tamanho++;
}

int Comparar(TLista Lista1, TLista Lista2){
	if(!Vazia(Lista1) && !Vazia(Lista2)){
		if (Lista1.tamanho == Lista2.tamanho){
			TCelula * aux1, * aux2;
			aux1 = Lista1.primeiro->prox;
			aux2 = Lista2.primeiro->prox;
			for (int i = 0; i < Lista1.tamanho; i++){
				if ((aux1->aluno.matricula == aux2->aluno.matricula) && (strcmp(aux1->aluno.nome,aux2->aluno.nome)==0)){
					return 0;
                }else{
                    return 1;
                }
				aux1 = aux1->prox;
				aux2 = aux2->prox;
			}
            return 1;
		}else{
			return 1;
		}
	}else{
        return 1;
    }
}
	
int main(){
  TAluno a;
  TLista Lista1, Lista2;

  Iniciar(&Lista1);
  Iniciar(&Lista2);

  for (int i=1; i<=2; i++){
    printf("\n######### LER ALUNO %d da LISTA 1 ##########\n", i);
    lerAluno(&a);
    Inserir(&Lista1, a);
  }

for (int i=1; i<=2; i++){
    printf("\n######### LER ALUNO %d da LISTA 2 ##########\n", i);
    lerAluno(&a);
    Inserir(&Lista2, a);
}

  int igual = 0;
  igual = Comparar(Lista1, Lista2);
  if(igual==0){
    printf("Listas sao iguais");
  }
  else{
    printf("Listas sao diferentes");
  }
 
  return 0;
}

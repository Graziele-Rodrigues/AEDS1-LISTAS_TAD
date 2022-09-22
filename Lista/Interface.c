#include <stdio.h>
#include <stdlib.h>

#include "interface.h"


void MSG_MENU( )
{
    system("clear");
    printf("\n\n\t>>>>>>>>>>>>>>>>>>>>>>> OPCOES DE MENU <<<<<<<<<<<<<<<<<<<<<<<<");
    printf("\n\n\t1. INSERIR");
    printf("  \n\t2. PESQUISAR");
    printf("  \n\t3. EXCLUIR");
    printf("  \n\t4. IMPRIMIR");
    printf("  \n\t5. SAIR");
}

void MENU(TLista *lista){
    TProduto *x;
    TProduto valor;
    x = (TProduto *)calloc(1, sizeof(TProduto));
   
    int opcao=0;
    do
    {
        MSG_MENU();
        printf("\n\nDigite uma opcao: ");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao)
        {
            case 1:
                    LerProduto(x);
                    Inserir(*x, lista);
                system("PAUSE");
                break;
            case 2:
                 printf("\nDigite o codigo do produto desejado:");
                 scanf("%d", &valor.codigo);
                 if ((Pesquisar(valor, *lista) != NULL)) {
                    printf("\nItem pesquisado com sucesso\n");
                    printf("\n#############################\n");
                    ImprimirProduto((Pesquisar(valor, *lista))->prox->item);
                    } else {
                        printf("\nItem nao encontrado");
                    }
                system("PAUSE");
                break;
            case 3:
                 printf("\nQual produto deve ser excluido:");
                 scanf("%d", &valor.codigo);
                 printf("\n-------------------------------\n");
                 Excluir(&valor, lista);
                 if(valor.codigo==-1){
                    printf("Produto não existe");
                }else{
                    printf("\nProduto excluido:\n");
                    ImprimirProduto(valor);
                    
                }
                system("PAUSE");
                break;
            case 4:
                Imprimir(*lista);
                system("PAUSE");
                break;
            case 5:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Saindo do MODULO...!!! <<<<<<");
                system("PAUSE");
                break;
            default:
                system("clear");
                printf("\n\n\n\t >>>>>> MSG: Digite uma opcao valida!!! <<<<<<");
                Liberar(lista);
                system("PAUSE");
            } // fim do bloco switch
    } while(opcao != 5);
}

#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>


void main(){
  Pilha pilha;
  Node *retornoPop;
  int opt, num, retornoPush;

    /* -- MENU -- */
    printf("Escolha a opcao\n");
    printf("0. Sair\n");
    printf("1. Inic Pilha\n");
    printf("2. Exibir PILHA\n");
    printf("3. PUSH\n");
    printf("4. POP\n");
    /* -- END MENU -- */

    inicPilha(&pilha);

  do{
    printf("Opcao: "); scanf("%d", &opt);
    switch(opt){
      case 0:
      break;

      case 1:
        inicPilha(&pilha);
      break;
      case 2:
        exibePilha(&pilha);
      break;
      case 3:
        printf("Digite o numero que deseja inserir no topo:"); scanf("%d", &num);
        push(&pilha, num);
      break;
      case 4:
        retornoPop = pop(&pilha);
        printf("%d", retornoPop->num);
        free(retornoPop);
      break;
      default:
        printf("Digite outro valor para opcao!");
      break;
    }
  }while(opt != 0);
}

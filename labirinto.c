#include "lista.h"
#include <stdio.h>
#include "pilha.h"
#include "labirinto.h"


/*
  LEMBRETES:
  - DEVEMOS INICIARLIZAR A PILHA ACHANDO A ORIGEM
  - FUNC TOTAL PREMIOS
*/

void moverRobo(Labirinto *l, Pilha *p_l, Fila *f_l);
  if(PilhaVazia(p_l)) return;
  elem_t retorno = elemTopo(p_l); //

  int num_premios = 0;

  /*  ACHANDO OS PREMIOS NO LABIRINTO  */
  /* MOVER_SE*/
    //Esquerda
    do{
      if(((l->p[retorno.x-1][retorno.y].tipo == ' ') || (l->p[retorno.x-1][retorno.y].tipo == 'p'))  && (l->p[retorno.x-1][retorno.y].visitado == 0)){
        if(l->p[retorno.x-1][retorno.y].tipo == 'p'){
          pushFila(f_l);
          num_premios++;
        }
        l->[retorno.x-1][retorno.y].visitado == 1;
        pushPilha(p_l, l->p[retorno.x-1][retorno.y]);
      }
      //Direita
      else if ((l->p[retorno.x+1][retorno.y].tipo == ' ') ||  (l->p[retorno.x+1][retorno.y].tipo == 'p'))&& (l->p[retorno.x-1][retorno.y].visitado == 0)){
        if (l->p[retorno.x+1][retorno.y].tipo == 'p'){
          pushFila(f_l);
          num_premios++;
        }
        l->p[retorno.x-1][retorno.y].visitado == 1;
        pushPilha(p_l, l->p[retorno.x+1][retorno.y]);
      }
      //Cima
      else if ((l->p[retorno.x][retorno.y+1].tipo == ' ') || (l->p[retorno.x][retorno.y+1].tipo == 'p')) && (l->p[retorno.x-1][retorno.y].visitado == 0)){
        if (l->p[retorno.x][retorno.y+1].tipo == 'p'){
          pushFila(f_l);
          num_premios++;
        }
        l->p[retorno.x-1][retorno.y].visitado == 1;
        pushPilha(p_l, l->p[retorno.x][retorno.y+1]);
      }
      //Baixo
      else if ((l->p[retorno.x][retorno.y-1].tipo == ' ') || (l->p[retorno.x][retorno.y-1].tipo == 'p')) && (l->p[retorno.x-1][retorno.y].visitado == 0)){
        if (l->p[retorno.x][retorno.y-1].tipo == 'p'){
          pushFila(f_l);
          num_premios++;
        }
        l->p[retorno.x-1][retorno.y].visitado == 1;
        pushPilha(p_l, l->p[retorno.x][retorno.y-1]);
      }
      //Nenhum lugar
      else
        pop(p_l);
    }while(aux != 200);
}

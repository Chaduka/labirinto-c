#include <stdio.h>
#include "lista.h"
#include "pilha.h"
#include "labirinto.h"

void moverRobo(Labirinto *l, Pilha *p_l, Fila *f_l);
  if(PilhaVazia(p_l)) return; Se a pilha esta vazia

  elem_t retorno = elemTopo(p_l);
  int num_premios = 0;

  //Esquerda
  if(((l->p[retorno.(x-1)][retorno.y].tipo == ' ') || (l->p[retorno.(x-1)][retorno.y].tipo == 'p'))  && (l->[retorno.x-1][retorno.y].visitado == 0)){
    if(l->p[retorno.(x-1)][retorno.y].tipo == 'p'){
      pushFila(f_l);
      num_premios++;
    }
    pushPilha(p_l, l->p[retorno.x-1][retorno.y]);
  }
  //Direita
  else if ((l->p[retorno.x+1][retorno.y].tipo == ' ') ||  (l->p[retorno.x+1][retorno.y].tipo == 'p'))&& (l->[retorno.x-1][retorno.y].visitado == 0)){
    if (l->p[retorno.x+1][retorno.y].tipo == 'p'){
      pushFila(f_l);
      num_premios++;
    }
    pushPilha(p_l, l->p[retorno.x+1][retorno.y]);
  }
  //Cima
  else if ((l->p[retorno.x][retorno.y+1].tipo == ' ') || (l->p[retorno.x][retorno.y+1].tipo == 'p')) && (l->[retorno.x-1][retorno.y].visitado == 0)){
    if (l->p[retorno.x][retorno.y+1].tipo == 'p'){
      pushFila(f_l);
      num_premios++;
    }
    pushPilha(p_l, l->p[retorno.x][retorno.y+1]);
  }
  //Baixo
  else if ((l->p[retorno.x][retorno.y-1].tipo == ' ') || (l->p[retorno.x][retorno.y-1].tipo == 'p')) && (l->[retorno.x-1][retorno.y].visitado == 0)){
    if (l->p[retorno.x][retorno.y-1].tipo == 'p'){
      pushFila(f_l);
      num_premios++;
    }
    pushPilha(p_l, l->p[retorno.x][retorno.y-1]);
  }
  //Nenhum lugar
  else{
    pop(p_l);
}

#include <stdio.h>
#include "fila.h"
#include "pilha.h"
#include "labirinto.h"



void inicLabirinto(Labirinto *l, Pilha *p_l, int linha, int coluna){
  int i, j, flag = 0;
  char aux;
  elem_t_pilha origem;

  for(i = 0 ; i < linha ; i++){
    for(j = 0 ; j < coluna ; j++){
      if(l->p[i][j].tipo == 'o'){
        l->p[i][j].visitado = 1; //Visitado
        origem.x = i;
        origem.y = j;
        push(p_l, origem);
      }
    }
  }
}


void moverRobo(Labirinto *l, Pilha *p_l, Fila *f_l){
  if(PilhaVazia(p_l)) return;
  elem_t_pilha retorno;
  elem_t_fila premio;
  int num_premios = 0;

  do{
    /*  ACHANDO OS PREMIOS NO LABIRINTO  */
    retorno = elemTopo(p_l); //Pegando elemento do topo da pilha - atual.
    /* MOVER_SE*/
    //Esquerda
    if(((l->p[retorno.x][retorno.y-1].tipo == ' ') ||  (l->p[retorno.x][retorno.y-1].tipo == 'p'))&& (l->p[retorno.x][retorno.y-1].visitado == 0)){
      retorno.y -= 1  ;
      if(l->p[retorno.x][retorno.y].tipo == 'p'){
        premio.x = retorno.x;
        premio.y = retorno.y;
        insereFila(f_l, premio);
        num_premios++;
      }
      l->p[retorno.x][retorno.y].visitado = 1;
      push(p_l, retorno);
    }
    //Direita
    else if (((l->p[retorno.x][retorno.y+1].tipo == ' ') ||  (l->p[retorno.x][retorno.y+1].tipo == 'p'))&& (l->p[retorno.x][retorno.y+1].visitado == 0)){
      retorno.y += 1;
      if (l->p[retorno.x][retorno.y].tipo == 'p'){
        premio.x = retorno.x;
        premio.y = retorno.y;
        insereFila(f_l,premio);
        num_premios++;
      }
      l->p[retorno.x][retorno.y].visitado = 1;
      push(p_l,retorno);
    }
    //Cima
    else if (((l->p[retorno.x-1][retorno.y].tipo == ' ') || (l->p[retorno.x-1][retorno.y].tipo == 'p')) && (l->p[retorno.x-1][retorno.y].visitado == 0)){
      retorno.x -= 1;
      if (l->p[retorno.x][retorno.y].tipo == 'p'){
        premio.x = retorno.x;
        premio.y = retorno.y;
        insereFila(f_l, premio);
        num_premios++;
      }
      l->p[retorno.x][retorno.y].visitado = 1;
      push(p_l,retorno);
    }
    //Baixo
    else if (((l->p[retorno.x+1][retorno.y].tipo == ' ') || (l->p[retorno.x+1][retorno.y].tipo == 'p')) && (l->p[retorno.x+1][retorno.y].visitado == 0)){
      retorno.x += 1;
      if (l->p[retorno.x][retorno.y].tipo == 'p'){
        premio.x = retorno.x;
        premio.y = retorno.y;
        insereFila(f_l, premio);
        num_premios++;
      }
      l->p[retorno.x][retorno.y].visitado = 1;
      push(p_l, retorno);
    }
    //Nenhum lugar
    else{
      pop(p_l);
    }
  }while(!PilhaVazia(p_l));
}


void verPremios(Labirinto *l, Fila *f_l, int linhas, int colunas){
  elem_t_fila premio;
  int i , j, contador = 0;

  //Imprimindo as coordenadas dos premios
  while(!FilaVazia(f_l)){
    premio = removeFila(f_l);
    printf("(%d,%d) ", premio.x, premio.y);
    contador++;
  }
  printf("\nPremios encontrados: %d", contador);

  //Total de premios
  contador = 0;
  for(i = 0 ; i < linhas ; i++){
    for (j = 0 ; j < colunas ; j++){
      if(l->p[i][j].tipo == 'p') contador++;
    }
  }
  printf("\nTotal de premios no labirinto: %d\n", contador);
}

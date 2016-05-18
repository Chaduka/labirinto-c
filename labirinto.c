#include <stdio.h>
#include "fila.h"
#include "pilha.h"
#include "labirinto.h"


/*
  LEMBRETES:
  - DEVEMOS INICIARLIZAR A PILHA ACHANDO A ORIGEM
  - FUNC TOTAL PREMIOS
*/
void inicLabirinto(Labirinto *l, Pilha *p_l, int linha, int coluna){
  int i, j, flag = 0;
  elem_t_pilha origem;

  for(i = 0 ; i < linha && flag != 1 ; i++){
    for(j = 0 ; j < coluna && flag != 1 ; j++){
      if(l->p[i][j].tipo == 'o'){
        flag = 1;
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
    if(((l->p[retorno.x-1][retorno.y].tipo == ' ') || (l->p[retorno.x-1][retorno.y].tipo == 'p'))  && (l->p[retorno.x-1][retorno.y].visitado == 0)){
      retorno.x -= 1;
      if(l->p[retorno.x-1][retorno.y].tipo == 'p'){
        premio.x = retorno.x-1;
        premio.y = retorno.y;
        insereFila(f_l, premio);
        num_premios++;
      }
      l->p[retorno.x-1][retorno.y].visitado == 1;
      push(p_l, retorno);
    }
    //Direita
    if (((l->p[retorno.x+1][retorno.y].tipo == ' ') ||  (l->p[retorno.x+1][retorno.y].tipo == 'p'))&& (l->p[retorno.x-1][retorno.y].visitado == 0)){
      retorno.x += 1;
      if (l->p[retorno.x+1][retorno.y].tipo == 'p'){
        premio.x = retorno.x+1;
        premio.y = retorno.y;
        insereFila(f_l,premio);
        num_premios++;
      }
      l->p[retorno.x-1][retorno.y].visitado == 1;
      push(p_l,retorno);
    }
    //Cima
    if (((l->p[retorno.x][retorno.y+1].tipo == ' ') || (l->p[retorno.x][retorno.y+1].tipo == 'p')) && (l->p[retorno.x-1][retorno.y].visitado == 0)){
      retorno.y += 1;
      if (l->p[retorno.x][retorno.y+1].tipo == 'p'){
        premio.x = retorno.x;
        premio.y = retorno.y+1;
        insereFila(f_l, premio);
        num_premios++;
      }
      l->p[retorno.x-1][retorno.y].visitado == 1;
      push(p_l,retorno);
    }
    //Baixo
    if (((l->p[retorno.x][retorno.y-1].tipo == ' ') || (l->p[retorno.x][retorno.y-1].tipo == 'p')) && (l->p[retorno.x-1][retorno.y].visitado == 0)){
      retorno.y -= 1;
      if (l->p[retorno.x][retorno.y-1].tipo == 'p'){
        premio.x = retorno.x;
        premio.y = retorno.y-1;
        insereFila(f_l, premio);
        num_premios++;
      }
      l->p[retorno.x-1][retorno.y].visitado == 1;
      push(p_l, retorno);
    }
    //Nenhum lugar
    else{
      pop(p_l); // Implementar aqui
    }
  }while(!PilhaVazia(p_l));
}


void verPremios(Labirinto *l, Fila *f_l, int linhas, int colunas){
  elem_t_fila premio;
  int contador = 0;

  //Imprimindo as coordenadas dos premios
  while(!filaVazia(f_l)){
    premio = removeFila(p_l);
    printf("(%d,%d) ", premio.x, premio.y);
    contador++;
  }
  printf("Premios encontrados: %d", contador);

  //Total de premios
  contador = 0;
  for(i = 0 ; i < linhas ; i++){
    for (j = 0 ; j < colunas ; j++){
      if(l->p[i][j].info == 'p') contador;
    }
  }
  printf("Total de premios no labirinto: %d", contador);
}

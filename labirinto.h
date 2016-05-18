#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "fila.h"
#include "pilha.h"

typedef struct posicao{
    char tipo;
    int visitado;
}Posicao;

typedef struct labirinto{
  Posicao **p;
}Labirinto;

void moverRobo(Labirinto *l, Pilha *p_l, Fila *f_l);

void inicLabirinto(Labirinto *l, Pilha *p_l, int linha, int coluna);

void verPremios(Labirinto *l, Fila *f_l, int linhas, int colunas);


#endif

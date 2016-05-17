#ifndef LABIRINTO_H
#define LABIRINTO_H

#include "lista.h"
#include "pilha.h"

typedef struct posicao{
    char tipo;
    int visitado;
}Posicao;

typedef struct labirinto{
  Posicao **p;
}Labirinto;

typedef struct robo{
  int x, y;
}elem_t;

void moverRobo(Labirinto *l, Fila *f_l);




#endif

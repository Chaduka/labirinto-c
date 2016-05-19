/*
 *
 */

#ifndef FILA_H
#define FILA_H

typedef struct robo_fila{
  int x, y;
}elem_t_fila;

typedef struct nof{
  elem_t_fila info;
  struct nof *prox;
}No_Fila;

typedef No_Fila Fila;


/* Inicializa uma Fila */
void inicFila(Fila *f_l);

/* Verifica se a Fila est� vazia ou nao */
int FilaVazia(Fila *f_l);

/* Insere um elemento na Fila */
void insereFila(Fila *f_l, elem_t_fila e);

/* Remove um elemento da Fila */
elem_t_fila removeFila(Fila *f_l);


#endif

/*
 *
 */

#ifndef FILA_H
#define FIlA_H

typedef struct robo_fila{
  int x, y;
}elem_t_fila;

typedef struct no{
  elem_t_pilha info;
  struct no *prox;
} No_Fila;

typedef struct fila{
  int tamanho;
  struct no *fila;
} Fila;


/* Inicializa uma Pilha */
void inicPilha(Fila *f_l);

/* Verifica se a Pilha est� vazia ou nao */
int PilhaVazia(Fila *f_l);

/* Insere um elemento na Pilha */
void insereFila(Fila *f_l, elem_t_fila e);

/* Remove um elemento da Pilha */
elem_t_fila removeFila(Fila *f_l);


#endif

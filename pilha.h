/*
 *
 */

#ifndef PILHA_H
#define PILHA_H

typedef struct robo_pilha{
  int x, y;
}elem_t_pilha;

typedef struct no{
  elem_t_pilha info;
  struct no *prox;
} No_Pilha;

typedef No_Pilha Pilha;

/* Inicializa uma Pilha */
void inicPilha(Pilha *p_l);

/* Verifica se a Pilha est� vazia ou nao */
int PilhaVazia(Pilha *p_l);

/* Insere um elemento na Pilha */
void push(Pilha *p_l, elem_t_pilha e);

/* Remove um elemento da Pilha */
elem_t_pilha pop(Pilha *p_l);

/* Retorna o elemento do topo da pilha */
elem_t_pilha elemTopo(Pilha *p_l);


#endif

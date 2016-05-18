/*
 * Implementacao de Pilha
 */

#include"fila.h"
#include<stdio.h>
#include<stdlib.h>

/* Inicializa uma Pilha */
void inicFila(Fila *p_l){
  f_l->tamanho = 0;
  f_l->fila = NULL;
}

/* Verifica se a Pilha est� vazia ou nao */
int FilaVazia(Fila *f_l){
	if (f_l->tamanho == 0)
		return 1;
	return 0;
}


/*
  JA FOI IMPLEMENTADO, VERIFIQUE A LOGICA E TESTE
*/
/* Insere um elemento na Pilha */
void push(Fila *f_l, elem_t_fila e){
	No_Fila *novo = malloc(sizeof(No_Fila));
  No_Fila *aux;
	novo->info = e;
	novo->prox = NULL;

  if(FilaVazia(f_l))
    f_l->fila = novo;
    f_l->tamanho++;
  else{
    aux = f_l->fila;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}


/* Remove um elemento da Fila.
   Retorna 0 caso a Fila esteja vazia */
elem_t_fila pop(Fila *f_l){
	No_Pilha *topo;
	elem_t_pilha ret;
	topo = p_l->prox;
	p_l->prox = topo->prox;
	ret = topo->info;
	free (topo);
	return ret;
}

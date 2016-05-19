/*
 * Implementacao de Pilha
 */

#include "fila.h"
#include<stdio.h>
#include<stdlib.h>

/* Inicializa uma Pilha */
void inicFila(Fila *f_l){
  f_l->prox = NULL;
}

/* Verifica se a Pilha est� vazia ou nao */
int FilaVazia(Fila *f_l){
  if (f_l->prox == NULL)
		return 1;
	return 0;
}


/*
  JA FOI IMPLEMENTADO, VERIFIQUE A LOGICA E TESTE
*/
/* Insere um elemento na Pilha */
void insereFila(Fila *f_l, elem_t_fila e){
	No_Fila *novo = malloc(sizeof(Fila));
  No_Fila *aux;
	novo->info = e;
	novo->prox = NULL;

  if(FilaVazia(f_l))
    f_l->prox = novo;
  else{
    aux = f_l->prox;
    while(aux->prox != NULL){
      aux = aux->prox;
    }
    aux->prox = novo;
  }
}


/* Remove um elemento da Fila.
   Retorna 0 caso a Fila esteja vazia */
elem_t_fila removeFila(Fila *f_l){
	Fila *topo;
	elem_t_fila ret;
	topo = f_l->prox;
	f_l->prox = topo->prox;
	ret = topo->info;
	free (topo);
	return ret;
}

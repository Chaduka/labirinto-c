/*
 * Implementacao de Pilha
 */

#include"pilha.h"
#include<stdio.h>
#include<stdlib.h>

/* Inicializa uma Pilha */
void inicPilha(Pilha *p_l){
	p_l->prox = NULL;
}

/* Verifica se a Pilha está vazia ou nao */
int PilhaVazia(Pilha *p_l){
	if (p_l->prox == NULL)
		return 1;
	return 0;
}

/* Insere um elemento na Pilha */
void push(Pilha *p_l, elem_t_pilha e){
	No_Pilha *novo;
	novo = malloc(sizeof(No_Pilha));
	novo->info = e;
	novo->prox = p_l->prox;
	p_l->prox = novo;
}


/* Remove um elemento da Pilha.
   Retorna 0 caso a Pilha esteja vazia */
elem_t_pilha pop(Pilha *p_l){
	No_Pilha *topo;
	elem_t_pilha ret;
	// o usuario da pilha deveria testar se a pilha nao esta vazia antes da chamada desta funcao
	topo = p_l->prox;
	p_l->prox = topo->prox;
	ret = topo->info;
	free (topo);
	return ret;
}

/* Retorna o elemento do topo da pilha */
elem_t_pilha elemTopo(Pilha *p_l){
	return p_l->prox->info;
}

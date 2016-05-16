/*
 * Implementacao de lista sem n� cabe�a.
 */

#include"lista_dinamica.h"
#include<stdio.h>
#include<stdlib.h>

#define MSG_ALOC "Erro ao alocar memoria!"
#define MSG_VAZIA "Sua lista ja esta liberada"

/* Inicializa uma lista */
void inicLista(Lista *p_l){
	*p_l == NULL;
}

/* Verifica se a lista est� vazia ou nao */
int listaVazia(Lista *p_l){
	if(*p_l == NULL) return 1;

	return 0;
}

int tamanho(Lista *p_l){
	int tam = 0;
	if(!listaVazia(p_l)){
		tam++;
		No_lista* aux = *p_l;
		while(aux->prox!=NULL){
			tam++;
			aux = aux->prox;
		}
	}
	return tam;
}

/* Insere um elemento no inicio da lista */
void insereInicio(Lista *p_l, elem_t e){
	No_lista *novo = (No_lista*) malloc(sizeof(No_lista)); //Alocando espaco para No_lista

	if(No_lista == NULL) printf(MSG_ALOC);
	novo->info = e; //Recebendo o elemento
	novo->prox = *p_l;
	*p_l = novo;
}

/* Insere um elemento no final da lista */
void insereFim(Lista *p_l, elem_t e){
	No_lista *aux = *p_l;
	No_lista *novo = (No_lista*) malloc(sizeof(No_lista)); //Alocando espaco para No_Lista

	if(No_lista == NULL) printf(MSG_ALOC);
	novo->prox = NULL;
	if(listaVazia(p_l)) *p_l = novo;
	else{
		while(aux->prox != NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
	}
}

/* Insere um elemento na lista de maneira ordenada.
   Caso a lista nao esteja ordenada, ordena antes da insercao */
void insereOrdenado(Lista *p_l, elem_t e){
	No_lista *novo;
	No_lista *aux = *p_l;
	if(ordenada(p_l)){
		novo = (No_lista*) malloc(sizeof(No_lista));
		novo->info = e;
		if(aux==NULL || (aux!=NULL && aux->info > e)){
			novo->prox = aux;
			*p_l = novo;
		}
		else{
			while(aux->prox!=NULL && aux->prox->info < e)
				aux = aux->prox;
			novo->prox = aux->prox;
			aux->prox = novo;
		}
	}
}

/* Verifica se a lista esta ordenada */
int ordenada(Lista *p_l){
	int varOrd = 1;
	No_lista *atual = *p_l, *ant;
	if(*p_l == NULL || (*p_l)->prox == NULL)
		return 1;
	while(atual->prox != NULL && varOrd == 1){
		ant = atual;
		atual = atual->prox;
		if(ant->info > atual->info)
			return 0;
	}
	return 1;
}

/* Ordena a lista */
void ordena(Lista *p_l){
	if(!listaVazia){
		No_lista anterior = NULL;
		No_lista atual = *p_l;
		No_lista posterior = atual->prox;
		int i, j;
		int tam = tamanho(p_l);

		for (i = tam-1 ; i > 0 ; i--){
			for(j = 0 ; j < i ; j++){
				if(atual->info > posterior->info){
					if(anterior == NULL) anterior->prox = atual->prox;
					else *p_l = proximo;

					atual->prox = posterior->prox;
					posterior->prox = atual;

					anterior = posterior;
					atual = anterior->prox;
					posterior = atual->prox;
				}else{
					anterior = atual;
					atual = atual->prox;
					posterior = posterior->prox;
				}
			}
			anterior = NULL;
			atual = *p_l;
			posterior = atual->prox;
		}
	}
}

/* Remove o elemento que esta no inicio da lista.
   Retorna 0 caso a lista esteja vazia */
int removeInicio(Lista *p_l, elem_t *p_e){
	No_lista *aux;
	if(listaVazia(p_l))
		return 0;
	aux = *p_l;
	*p_l = aux->prox;
	*p_e = aux->info;
	free(aux);
	return 1;
}

/* Remove o elemento que esta no final da lista.
   Retorna 0 caso a lista esteja vazia */
int removeFim(Lista *p_l, elem_t *p_e){
	if(listaVazia(pl)) return 0;
	No_lista *frente = *p_l;
	No_lista *tras = *p_l;

	//se tiver somente um elemento
	if(frente->prox == NULL){
		*p_l = NULL;
		free(frente);
	}
	else{
		frente = frente->prox;
		//andando com os dois ponteiros
		while(frente->prox != NULL){
			frente = frente->prox;
			tras = tras->prox;
		}
		free(frente);
		tras->prox = NULL;
	return 1;
	}
}

/* Remove o numero de valor e.
   Retorna 0 caso este numero n�o tenha sido encontrado */
int removeValor(Lista *p_l, elem_t e){
	if(listaVazia(pl)) return 0;
	No_lista *frente = *p_l;
	No_lista *tras = *p_l;

	//se tiver somente um elemento
	if(frente->prox == NULL){
		if(frente->info == e) {
			free(frente);
			*pl = NULL;
			return 1;
		}
	return 0;
	}
	else{
		frente = frente->prox;
		//andando com os dois ponteiros
		while(frente->prox != NULL){
			frente = frente->prox;
			tras = tras->prox;

			if(frente->info == e) {
				tras->prox = frente->prox;
				free(frente);
				return 1;
			}
		}
		return 0;
	}

}

/* Inverte os elementos de uma lista */
void inverte(Lista *p_l){
	No_lista *anterior;
	No_lista *prox;
	No_lista *atual;
	anterior = NULL;
	atual = *p_l;
	while(atual != NULL){
		prox = atual->prox;
		atual->prox = anterior;
		anterior = atual;
		atual = prox;
	}
	*p_l = anterior;

}

/* Remove todos os numeros da lista */
void libera(Lista *p_l){
	if(p_l != NULL){
		No_lista* no;
		while((*p_l) != NULL){
			no = *p_l;
			*p_l = (*p_l)->prox;
			free(no);
		}
		free(p_l);
	}

}

/* Exibe o conteudo da lista */
void exibe(Lista *p_l){
	Lista aux;
	aux = *p_l;
	while(aux != NULL){
		printf("%d ", aux->info);
		aux = aux->prox;
	}
}

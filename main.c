#include <stdio.h>
#include "pilha.h"
#include "fila.h"

#include "labirinto.h"

int main(){
  FILE *fp;
  int height, width, opt, i = 0, j = 0;
  fp = fopen("labirinto.txt", "r");
  char robo[6];
  char beni[3], tmp;
  Labirinto *l = (Labirinto*) malloc(sizeof(Labirinto));

  Pilha p;
  Fila f;

  inicPilha(&p);
  inicFila(&f);

  if(fp == NULL){
    printf("Erro.\n");
    return 0;
  }

  /*
    LENDO AS ENTRADAS VIA ARQUIVO
  */
  fscanf(fp,"%s %d %d", robo, &height, &width);
  fscanf(fp, "%c", &beni);
  char lab[height][width];
  /*
    CONSTRUINDO O LABIRINTO DE CHAR
  */
  while(!feof(fp)){
    fscanf(fp, "%c", &tmp);
    if(tmp != '\n'){
      lab[i][j] = tmp;
      j++;
    }else{
      j = 0;
      i++;
    }
  }
 /*
    CONSTRUINDO O  LABINTO DE POSICOES
 */
  l->p = (Posicao**) malloc (height * sizeof (Posicao *));
      for (i = 0; i < height; i++)
          l->p[i] = (Posicao*) malloc (width * sizeof (Posicao));

  for(i = 0 ; i < height ; i++){
    for(j = 0 ; j < width ; j++){
      l->p[i][j].tipo = lab[i][j];
      l->p[i][j].visitado = 0;
    }
  }



  /*
    IMPRIMINDO O LABIRINTO
  */
  printf("\n\n");
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++)
      printf("%c ", l->p[i][j].tipo);
    printf("\n");
  }
  printf("\n");
  inicLabirinto(l, &p, height, width);
  moverRobo(l, &p, &f);
  verPremios(l, &f, height, width);

  fclose(fp);
  return 0;
}

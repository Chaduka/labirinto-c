#include <stdio.h>


#include "labirinto.h"

int main(){
  FILE *fp;
  int height, width, i = 0, j = 0;
  fp = fopen("labirinto.txt", "r");
  char robo[6];
  char beni[3], tmp;
  Labirinto l;

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
  //fscanf(fp,"%s %d %d %c", robo, &height, &width, &beni);
  printf("height: %d widgth: %d", height, width);

  char lab[height][width];

  /*
    CONSTRUINDO O LABIRINTO NA MATRIZ
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
    IMPRIMINDO O LABIRINTO
  */
  printf("\n\n");
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++)
      printf("%c ", lab[i][j]);
    printf("\n");
  }

  fclose(fp);
  return 0;
}

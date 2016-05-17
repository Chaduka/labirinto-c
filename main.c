#include <stdio.h>

int main(){
  FILE *fp;
  int height, width, i = 0, j = 0;
  fp = fopen("labirinto.txt", "r");
  char robo[6];
  char beni[3], tmp;


  if(fp == NULL){
    printf("Erro.\n");
    return 0;
  }
  fscanf(fp,"%s %d %d", robo, &height, &width);
  fscanf(fp, "%c", &beni);
  //fscanf(fp,"%s %d %d %c", robo, &height, &width, &beni);
  printf("\n beni %s\n", beni);
  printf("height: %d widgth: %d", height, width);
  printf("\n\n\n\n\n");

  char lab[height][width];

  while(!feof(fp)){
    fscanf(fp, "%c", &tmp);
    if(tmp != '\n'){
      lab[i][j] = tmp;
      j++;
    }else{
      printf("\n");
      printf("%d", j);
      j = 0;
      i++;
    }
  }
  printf("\n");
  for(i = 0; i < height; i++){
    for(j = 0; j < width; j++)
      printf("%c ", lab[i][j]);
    printf("\n");
  }
  fclose(fp);
  return 0;
}

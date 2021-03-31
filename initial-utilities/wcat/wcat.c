#include <stdio.h>
#include <stdlib.h>

void catFile(FILE *fp){
  if(fp == NULL){
    printf("wcat: cannot open file\n");
    exit(1);
  }

  char* line = NULL;
  size_t n = 0;

  while(getline(&line, &n, fp) != -1){
    printf("%s", line);
  }

  free(line);
  fclose(fp);
}

int main(int argc, char *argv[]){
  if(argc == 1){
    exit(0); 
  }

  int i;
  for(i = 1; i < argc; i++){
    FILE *fp = fopen(argv[i], "r");
    catFile(fp);
  }  

  return 0;
}

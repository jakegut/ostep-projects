#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int num = 0;
char currentChar = '\0';

void zipFile(FILE *fp){
  if(fp == NULL){
    printf("wzip: cannot open file\n");
    exit(1);
  }

  char* line = NULL;
  size_t n = 0;  

  while(getline(&line, &n, fp) != -1){
    size_t i = 0;  
    while(line[i] != '\0'){
      if(line[i] == currentChar){
        num++;
      } else {
        if(currentChar != '\0'){
          fwrite(&num, sizeof(num), 1, stdout);
          fwrite(&currentChar, sizeof(currentChar), 1, stdout);
        }
        num = 1;
      }
      currentChar = line[i];
      i++;
    }
  }

  free(line);
  fclose(fp);
}

int main(int argc, char *argv[]){
  if(argc == 1){
    printf("wzip: file1 [file2 ...]\n");
    exit(1); 
  }
  
  int i;
  for(i = 1; i < argc; i++){
    FILE *fp = fopen(argv[i], "r");
    zipFile(fp);
  }  

  fwrite(&num, sizeof(num), 1, stdout);
  fwrite(&currentChar, sizeof(currentChar), 1, stdout);

  return 0;
}

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
  int len;
  char newChar;

  if(argc == 1){
    printf("wunzip: file1 [file2 ...]\n");
    exit(1);
  } else {
    int i = 1;
    for(; i < argc; i++){
      FILE *fp = fopen(argv[i], "r");
      if (fp == NULL){
        printf("wunzip: cannot open file\n");
        exit(1);
      } else {
        while(fread(&len, 4, 1, fp) > 0){
          fread(&newChar, 1, 1, fp);
          int j = 0;
          for(; j < len; j++){
            printf("%c", newChar);
          }
        }
      }
      fclose(fp);
    }
  }
  return 0;
}
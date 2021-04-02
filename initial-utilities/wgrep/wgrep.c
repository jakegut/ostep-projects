#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void grepFile(FILE *fp, char *searchterm){
  if(fp == NULL){
    printf("wgrep: cannot open file\n");
    exit(1);
  }

  char* line = NULL;
  size_t n = 0;

  while(getline(&line, &n, fp) != -1){
    if(strstr(line, searchterm) != NULL)
      printf("%s", line);
  }

  free(line);
  fclose(fp);
}

int main(int argc, char *argv[]){
  char* searchterm = "";
  if(argc == 1){
    printf("wgrep: searchterm [file ...]\n");
    exit(1); 
  } else if(argc >= 2) {
    searchterm = argv[1];
  }

  if(argc >= 3){
    int i;
    for(i = 2; i < argc; i++){
      FILE *fp = fopen(argv[i], "r");
      grepFile(fp, searchterm);
    }  
  } else {
    grepFile(stdin, searchterm);
  }
  

  return 0;
}

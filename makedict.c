#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define BUFSIZE 64
#define MAX 235886

int compare(const void *a, const void *b){
  int len1,len2,ret;
  char **a2,**b2;

  a2 = (char **)a;
  b2 = (char **)b;

  len1 = strlen(*a2);
  len2 = strlen(*b2);

  ret = len2-len1;
  if(ret > 0){
    return 1;
  }else if(ret == 0){
    return 0;
  }else{
    return -1;
  }
 
}

int main(void){

  FILE *fp1,*fp2;
  char *dict[MAX];
  char get[BUFSIZE];
  int i=0;
  char *ret;
  char *n="\n";

  if((fp2 = fopen("words","r")) == NULL){
    fprintf(stderr,"Error: fail to make file");
    exit(EXIT_FAILURE);
  }
 
  while(fgets(get,BUFSIZE-1,fp2) != NULL){
    dict[i]=(char *)malloc(BUFSIZE);
    strncpy(dict[i], get, BUFSIZE);
    i++;
  }

  qsort(dict,MAX,sizeof(char *),compare);

  if((fp1 = fopen("sortdict.csv","wt")) == NULL){
    fprintf(stderr,"Error: fail to make file");
    exit(EXIT_FAILURE);
  }

  for(i=0; i<MAX; i++){
    int write;
    write = strlen(dict[i]);
    if(write <= 17){
      fprintf(fp1,"%s",dict[i]);
    }
    free(dict[i]);
  }
  
}

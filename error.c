
#include <stdio.h>
#include <stdlib.h>

#include "error.h"

FILE *efopen(char *filename,char *flag){
  FILE *file;

  if((file=fopen(filename,flag))==NULL) {
    printf("open error about %s\n",filename);
    exit(1);
  }
  return file;
}



#define _GNU_SOURCE  

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <getopt.h>

#include "error.h"

void USAGE(char *progname);

int main(int argc, char *argv[]) {
  int i,j,k,d,m;
  int a;
  int i_a,j_a,k_a,l_a;
  int numres;
  
  char *inputfilename;
  char *outputfilename;
  
  FILE *inputfile;
  FILE *outputfile;

  int c;
  extern char *optarg;
  extern int optind,opterr,optopt;
  
  char *progname;
  char *version="XXXX";
  int opt_idx=1;
  
  /* STEP 0: Get options */
  struct option long_opt[] = {
    {"m",1,NULL,'m'},
    {"h",0,NULL,'h'},
    {0,0,0,0}
  };
  
  m=10;
  while((c=getopt_long(argc,argv,"m:h",long_opt,&opt_idx))!=-1) {
    switch(c) {
    case 'm':
      m = atoi(optarg); break;
    case 'h':
      USAGE(progname);
      return 1;
      exit(1);
    default:
      USAGE(progname);
      return 1;
      exit(1);
    }
  }
  
  progname=*argv;  argc-=optind;  argv+=optind;
  
  if (argc < 3) {
    USAGE(progname);
    exit(1);
  }
  inputfilename  = *argv;
  outputfilename = *++argv;
  numres         = atoi(*++argv);

  inputfile=efopen(inputfilename,"r");
  outputfile=efopen(outputfilename,"w");
  while ( (d=fscanf(inputfile,"%d%d%d%d",&i_a,&j_a,&k_a,&l_a)) != EOF )  {
    a=0;
    for (i=1;i<(i_a-1)/m;++i) {
      a += (numres / m - i)*m*m + m*(m-1)/2 + (numres % m)*m;
    }
    a += (j_a/m - 1)*m*(m-1)/2 + m*m;
    a += (i_a % m)*m + (j_a % m);
    fprintf(outputfile,"%4d ",a);

    a=0;
    for (i=1;i<(k_a-1)/m;++i) {
      a += (numres / m - i)*m*m + m*(m-1)/2 + (numres % m)*m;
    }
    a += (l_a/m - 1)*m*(m-1)/2 + m*m;
    a += (k_a % m)*m + (l_a % m);
    fprintf(outputfile,"%4d\n",a);
  }
  fclose(inputfile);
  fclose(outputfile);
  
  return 0;
}

/* Show usage */
void USAGE(char *progname) {
  printf("USAGE: ");
  printf("%s [ options ] input output numres\n",progname);
  printf("Options: \n");
  printf("[-h] help \n");
}

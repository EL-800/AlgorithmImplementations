#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#define TIPO int

int maiiin(){
  int n;
  lista l1, l2;
  TIPO *x;
  char sal[5000];
  lis_crea(&l1);
  lis_crea(&l2);
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    x = (TIPO*)malloc(sizeof(TIPO));
    scanf("%d", x);
    lis_insi(&l1, (datogen)x);
  }
  for(int i = 0; i < n; i++){
    x = (TIPO*)malloc(sizeof(TIPO));
    scanf("%d", x);
    lis_insi(&l2, (datogen)x);
  }
  concatena(&l1, l2);
  printf("%s\n", lis_mue(&l1, sal));
  return 0;
}

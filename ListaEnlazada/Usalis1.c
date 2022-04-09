#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#define TIPO int

int man(){
  int n, ini, fin, pos;
  lista l;
  TIPO *x;
  char sal[5000];
  lis_crea(&l);
  scanf("%d", &n);
  for(int i = 0; i < n; i++){
    x = (TIPO*)malloc(sizeof(TIPO));
    scanf("%d", x);
    lis_insi(&l, (datogen)x);
  }
  scanf("%d%d%d", &ini, &fin, &pos);
  printf("%s\n", lis_mue(&l, sal));
  cut_paste(&l, ini, fin, pos);
  printf("%s\n", lis_mue(&l, sal));
  return 0;
}

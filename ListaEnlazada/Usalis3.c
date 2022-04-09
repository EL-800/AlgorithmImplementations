#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "lista.h"
#define TIPO int

int fint(datogen);

int main(){
  int n, c;
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
  coincidencias(&l, &c, fint);
  printf("%s\n", lis_mue(&l, sal));
  printf("%d\n", c);
  return 0;
}

int fint(datogen x){
    int *a = (int*)x;
    if (*a <= 3)
        return 1;
    return 0;
}

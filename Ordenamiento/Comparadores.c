#include "Comparadores.h"

/*Son las funciones que nos permitiran conocer dados dos valores, cual es mayor que el otro
En este caso solo devuelve 0 o 1, siendo 1 si el primer valor es menor o igual al segundo y 0 que el segundo es menor que el primero*/
int ComparadorEntero(void *a, void *b){
    int *i_a, *i_b;
    i_a = (int*)a;
    i_b = (int*)b;
    return *i_a <= *i_b ? 1 : 0;
}

int ComparadorCadena(void *a,void *b){
  char** s_a,**s_b;
  s_a = (char**)a;
  s_b = (char**)b;
  int v = strcmp(*s_a,*s_b);
  return v <= 0 ? 1 : 0;
}

int ComparadorFlotante(void *a, void *b){
    float *f_a, *f_b;
    f_a = (float*)a;
    f_b = (float*)b;
    return *f_a <= *f_b ? 1 : 0;
}

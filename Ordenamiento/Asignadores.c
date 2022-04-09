#include "Asignadores.h"

/*En lugar de intercambiar posciones, aqui ocupo asignadores, que son funciones que dados dos datos asigne el valor de B a A*/
void AsignarEntero(void *a, void *b){
    int *i_a, *i_b;
    i_a = (int*)a;
    i_b = (int*)b;
    *i_a = *i_b;
    return;
}

void AsignarCadena(void *a, void *b){
    char **s_a, **s_b;
    s_a = (char**)a;
    s_b = (char**)b;
    *s_a = *s_b;
}

void AsignarFloatante(void *a, void *b){
    float *f_a, *f_b;
    f_a = (int*)a;
    f_b = (int*)b;
    *f_a = *f_b;
    return;
}

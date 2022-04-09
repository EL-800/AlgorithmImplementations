#include <stdlib.h>

typedef int (*comparador)(void*, void*);
typedef void (*asignar)(void*, void*);

void MergeSort(void*, int, int, comparador, asignar, int, int*);

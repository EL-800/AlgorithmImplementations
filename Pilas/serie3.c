#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define TAM_ENT    7

/*Objetivo:
  Comenzando de una cadena, simular el ejercicio de las
  vias del tren y obtener otra utilizando una pila.
*/

int maiiiin(){
  char salida[10000];

  int entrada[TAM_ENT] = {1,2,3,4,5,6,7};
  pila p;
  int err,tope,i;

  inic_pil(&p);
  crea_pil(&p);
  /*Incia aquí tu código */
  push_pil(&p, entrada[i++]);
  push_pil(&p, entrada[i++]);
  push_pil(&p, entrada[i++]);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  push_pil(&p, entrada[i++]);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  push_pil(&p, entrada[i++]);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  push_pil(&p, entrada[i++]);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  push_pil(&p, entrada[i++]);
  tope_pil(&tope, &p);
  printf("%d ", tope);
  pop_pil(&p);
  /*termina aquí tu código */
  printf("\n");
  elim_pil(&p);
  return 0;
}

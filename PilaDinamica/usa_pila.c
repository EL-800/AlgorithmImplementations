#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

/*Objetivo:
  Verificar el funcionamiento de la pila de enteros
  invocando de forma aleatoria a todas las funciones
  que se implementan.
*/

int main(){
  char salida[10000];

  DATO eltope;
  pila p;
  int i,err,opc;

  inic_pil(&p);

  for(i=0;i<500;i++){
    opc = rand()%7;
    printf("La pila es:%s",tostr_pil(salida,&p));
    switch(opc){
      case 0:
        printf("Crea pila\n");
        err = crea_pil(&p);
        break;
      case 1:
        printf("Elimina toda la pila\n");
        err = elim_pil(&p);
        break;
      case 2:
          printf("Elimina dato de la pila y muestra su valor\n");
          err = pop_pil2(&eltope, &p);
          printf("El valor eliminado de la pila es %d\n", eltope);
          break;
      case 3:
        printf("Inserta %d en pila\n",eltope=rand());
        err = push_pil(&p,eltope);
        break;
      case 4:
        printf("Elimina dato de la pila\n");
        err = pop_pil(&p);
        break;
      case 5:
        err = tope_pil(&eltope, &p);
        printf("El tope de la pila es %d\n", eltope);
        break;
      default:
        err = fondo_pil(&eltope, &p);
        printf("El fondo de la pila es %d\n", eltope);
    }
    printf("Regresa: %d %s\n",err,tostr_pil(salida,&p));
  }
  elim_pil(&p);
  return 0;
}

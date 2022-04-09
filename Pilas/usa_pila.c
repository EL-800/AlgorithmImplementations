#include <stdio.h>
#include <stdlib.h>
#include "pila.h"

#define TAM_ENT    7

/*Objetivo:
  Comenzando de una cadena, simular el ejercicio de las
  vias del tren y obtener otra utilizando una pila.
*/

int main(){
  char salida[1000];

  int entrada[TAM_ENT] = {1, 2, 3, 4, 5, 6, 7};
  pila p;
  int err, tope;

  inic_pil(&p);

  /*Ciclo para todas las pruebas*/
  while(1){
    crea_pil(&p);
    int objetivo[TAM_ENT];
    char linea[1000];
    for(int i = 0; i < TAM_ENT; i++)
        scanf("%d", &objetivo[i]);
    /*Incia aquí tu código */
    int indSol = 0;
    for (int i = 0; i < TAM_ENT; i++){
        push_pil(&p, entrada[i]);
        sprintf(linea, "Pasar el tren %d a la pila(push)\n", entrada[i]);
        strcat(salida, linea);
        while(!VAC_PIL(&p)){
            tope_pil(&tope, &p);
            if(tope != objetivo[indSol])
                break;
            sprintf(linea, "Sacar el tren %d de la pila (pop)\n", tope);
            strcat(salida, linea);
            pop_pil(&p);
            indSol++;
        }
      }
      if(VAC_PIL(&p))
        printf("%s", salida);
      else
        printf("No hay solucion\n");
      strcpy(salida, "");
    /*termina aquí tu código */
  }

  printf("\n");
  elim_pil(&p);
  return 0;
}

#ifndef PILA_H
#define PILA_H
/**********************************************************
Definir pila que crece dinámicamente cunado al insertar un
  dato ya está llena.
Por: Juan Jesús Gutiérrez García
Para: Ejemplos de programación
Fecha: Nov-2020
**********************************************************/
#include <stdio.h>
#include <string.h>
#include "err.h"
/**********************************************************
                C O N S T A N T E S
**********************************************************/
/* Para el tamaños de los arrelgos*/
#define TAMMAX    100   /*Tamaño inicial del arreglo*/
#define TAMCRE    10    /*Tamaño que se agrega cada vez
                          que crece el arreglo*/
#define TAMDAT    20    /*Tamaño de cadena para convertir
                          cada dato almacenado en char* */
/* De error */
#define OVERFLOW  20    /*Insertar en pila llena*/
#define UNDERFLOW 30    /*Extraer de pila vacía*/

#define DATO      int   /*Tipo de dato almacenado*/
#define FORMATO " %3d " /*Formato para converir dato a 
                          cadena*/
/**********************************************************
                   M A C R O S
**********************************************************/
/*Si tiene datos la pila*/
#define TIE_DAT(p)  ((p)->tope>0)
/*Si la pila está vacía*/
#define VAC_PIL(p)  ((p)->tope==0)
/*Si tiene espacio el arreglo de la pila*/
#define TIE_ESP(p)  (AP_VAL(p->dato)&&(p)->tope<(p)->tam)
/*Si la pila está llena*/
#define LLE_PIL(p)  ((p)->tope==(p)->tam)
/**********************************************************
             T I P O S    D E    D A T O S
**********************************************************/
typedef struct{
  DATO *dato;    /*Arreglo que almacena los datos*/
  int tope;      /*Primer elemento libre en la pila*/
  int tam;       /*Tamaño del arreglo *dato */
} pila;
/**********************************************************
                P R O T O T I P O S
**********************************************************/

/**********************************************************
                C O N S T R U C T O R E S
/*********************************************************/
/* Inicializar la pila.
Objetivo: Dar valores iniciales. Se debe invocar después
   de declarar una variable tipo pila.
RECIBE:
   Apuntador a pila a ser inicializada
REGRESA:
   Código de error. 
REQUIERE: 
   Que el apuntador que recibie no sea NULL
*/
int inic_pil(pila* p);

/* Asignar memoria dinámica.
Objetivo: Dar valores iniciales. Y solicitar memoria para
   El arreglo que almacenará los datos. Crea una pila vacía.
RECIBE:
   Apuntador a pila a ser creada
REGRESA:
   Código de error. 
REQUIERE: 
   Que el apuntador que recibie no sea NULL y que 
   se invoque a la función eliminar cuando ya no se use
   la pila.
*/
int crea_pil(pila*);

/* Regresa la memoria dinámica.
Objetivo: Destruir la pila y regresar la memoria dinámica.
RECIBE:
   Apuntador a pila a ser creada
REGRESA:
   Código de error. 
REQUIERE: 
   Que la pila haya sido creada. Y pasa la pila al estado de
   Cavía sin memoria.
*/
int elim_pil(pila*);
/**********************************************************
                M O D I F I C A D O R E S
/*********************************************************/

/* Inserta un dato en la pila.
Objetivo: Insertar un dato en la pila. En caso de que la
  pila esté llena busca hacer crecer el arreglo. Si no hay
  memoria regresará OVERFLOW
RECIBE:
   Apuntador a pila a ser creada
   Dato a ser insertado en la pila
REGRESA:
   Código de error. 
REQUIERE: 
   Que la pila haya sido creada y un apuntador no NULL
*/
int push_pil(pila*,DATO);

/* Eliminar un dato en la pila.
Objetivo: Eliminar un dato de la pila. En caso de que
   la pila esté vacía regresa UNDERFLOW.
RECIBE:
   Apuntador a pila de que se sacará el dato
REGRESA:
   Código de error. 
REQUIERE: 
   Que haya datos en la pila, apuntador no NULL
*/
int pop_pil(pila*);
/**********************************************************
                O B S E R V A D O R A S
/*********************************************************/
/* Tope de la pila
Objetivo: Regresa dato en el tope de la pila.
RECIBE:
   Apuntador a pila de que se sacará el dato
   Apuntador a dato en que se regresará el valor
      que está en el tope de la pila
REGRESA:
   Código de error. 
REQUIERE: 
   Que haya datos en la pila, apuntadores no NULL
*/
int tope_pil(DATO*, const pila*);

/* A cadena
Objetivo: Generar una representación de la pila 
   Como cadena. Usa la constante FORMATO para 
   convertir cada dato de la pila a cadena.
   Debe garantizar la cadena de salida tiene espacio
     para almcenar la representación completa.
RECIBE:
   Apuntador a cadena que tendrá la representación
   Apuntador pila que será convertida a cadena.
REGRESA:
   El mismo apuntador que regresa. En caso de erro
   Agrega a la cadena el valor "NULL"   
REQUIERE: 
   Apuntadores no NULL
*/
char* tostr_pil(char*, const pila*);

#endif







#include "Ordenamiento.h"

void MergeSort(void* arre, int ini, int fin, comparador cmp, asignar s, int tamDato, int *operaciones){
    /*Es el caso base, si el inicio es igual o mayor al fin, entonces ya no se puede hacer mas pequeña la division, por lo que retornamos*/
    if (ini >= fin)
        return;
    /*Se saca la mitad del arreglo a dividir y se llama la funcion en la primera mitad, y nuevamente en la segunda mitad*/
    int mitad = (ini + fin) / 2;
    MergeSort(arre, ini, mitad, cmp, s, tamDato, operaciones);
    MergeSort(arre, mitad + 1, fin, cmp, s, tamDato, operaciones);
    /*Si llega aqui significa que tanto la parte izquierda, como la derecha fueron resultas, por lo que se deben combinar ambas soluciones para solucionar la disvsion actual*/
    /*Se obtiene el tamaño del arreglo auxiliar izquierdo, y el derecho, se crean punteros genericos donde guardaran las divisiones mas pequeñas
    y se les aparta el tamaño necesario para alamcenar la informacion*/
    int nI = mitad - ini + 1, nD = fin - mitad;
    void *izq, *der;
    izq = malloc((nI + 2) * tamDato);
    der = malloc((nD + 2) * tamDato);
    /*Se hace la copia de la division izquierda de la division actual*/
    for (int i = 0; i < nI; i++)
        s(izq + i * tamDato, arre + ((i + ini) * tamDato));
        *operaciones = (*operaciones) + 1; ////Si se quita esto obtenemos un valor muy cercano a la complejidad teorica
    /*Se hace la copia de la division der de la division actual*/
    for (int j = 0; j < nD; j++)
        s(der + j * tamDato, arre + ((j + mitad + 1) * tamDato));
        *operaciones = (*operaciones) + 1; ////Si se quita esto obtenemos un valor muy cercano a la complejidad teorica
    /*Se crean variables que nos permitan controlar la posicion tanto del lado izquierdo, derecho y el actual*/
    int l = 0, r = 0, k = ini;
    /*Aqui es donde se combinaran la solucion del lado izquierdo y derecho para resolver el actual*/
    /*Mientras que ninguno de los lados se quede sin datos, se seguiran combinando*/
    while (l < nI && r < nD){
    /*Si el lado izquerdo es menor o igual al derecho, entonces sera el siguiente elemento a añadir a nuestra division actual y sigue con el siguiente elemento de la izquierda*/
        if (cmp(izq + (l * tamDato), der + (r * tamDato))){
            s(arre + k * tamDato, izq + (l * tamDato));
            l++;
        }
    /*Si no sucede lo primero, entonces se hara lo mismo, pero con el lado derecho*/
        else{
            s(arre + k * tamDato, der + (r * tamDato));
            r++;
        }
        *operaciones = (*operaciones) + 1; ////Estas serian parte de las operaciones que realiza el algoritmo
        k++;
    }
    /*Por lo general alguna de las divisiones se quedara con algun dato, asi que vaciamos lo que quedo en estas en la division actual*/
    for (; l < nI; l++){
        s(arre + k * tamDato, izq + l * tamDato);
        *operaciones = (*operaciones) + 1; ////Estas serian parte de las operaciones que realiza el algoritmo
        k++;
    }
    for (; r < nD; r++){
        s(arre + k * tamDato, der + r * tamDato);
        *operaciones = (*operaciones) + 1; ////Estas serian parte de las operaciones que realiza el algoritmo
        k++;
    }
    /*Se libera la memeoria de los arreglos auxiliares*/
    free(izq);
    free(der);
    return;
}

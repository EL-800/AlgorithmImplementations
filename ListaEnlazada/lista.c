#include "lista.h"

int lis_crea(lista* l){
  /*validar¿?*/
  *l = NULL;
  return OK;
}

int lis_elim(lista* l){
  datogen d;

  while(!lis_vac(l))
    lis_elii(l,&d);
  return OK;
}


int lis_vac(const lista* l){
  return *l==NULL;
}

int lis_insi(lista* l ,datogen d){
  lista x;

  x = (lista) malloc(sizeof(nodo));
  if(!x)
    return ERR_INSMEM;
  nsetd((ptrnod)x,d);
  nsets((ptrnod)x,(ptrnod)*l);
  *l = x;
  return OK;
}

int lis_elii(lista* l ,datogen *d){
  lista x;

  if(lis_vac(l))
    return ERR_LISVAC;
  x = *l;
  ngetd((ptrnod)x,d);
  ngets((ptrnod)x,(ptrnod*)l);
  free(x);
  return OK;
}

int lis_inve(lista* l){
  lista ant2,ant1,aux;
  if(!lis_vac(l)){
    ant2 = NULL;
    ant1 = NULL;
    aux = *l;
    while(aux){
      ant2=ant1;
      ant1=aux;
      aux=aux->sig;
      ant1->sig=ant2;
    }
    *l = ant1;
  }
  return OK;
}

char* lis_mue (const lista* l,char* sal){
  lista x;
  char tmp[TAMCAD];
  datogen dato;
  int *ls;

  sal[0]='\0';
  sprintf(sal,"[");
  x = *l;
  while (!lis_vac(&x)){
    ngetd((ptrnod)x,&dato);
    ls = (int*)dato;
    sprintf(tmp," %d ",*ls);
    ngets((ptrnod)x,(ptrnod*)&x);
    strcat(sal,tmp);
  }
  strcat(sal, "]");
  return sal;
}

int cut_paste(lista *l, int ini, int fin, int nvoPos){
  int i = 0;
  lista iniL = NULL, finL = NULL, nvoPosL = NULL, faltante = NULL, x;
  if(lis_vac(l))
    return ERR_LISVAC;
  if(ini > fin || (nvoPos >= ini && nvoPos <= fin) || ini < 0 || fin < 0 || nvoPos < 0)
    return ERR_INDINV;
  x = *l;
  while (!lis_vac(&x)){
    if (ini - 1 == i)
      iniL = x;
    if (fin == i)
      finL = x;
    if (nvoPos == i)
      nvoPosL = x;
    x = x->sig;
    i++;
  }
  if (lis_vac(&iniL) || lis_vac(&finL) || lis_vac(&nvoPosL))
    return ERR_DIMINV;
  faltante = nvoPosL->sig;
  nsets((ptrnod)nvoPosL, (ptrnod)iniL->sig);
  nsets((ptrnod)iniL, (ptrnod)finL->sig);
  nsets((ptrnod)finL, (ptrnod)faltante);
  return OK;
}

int concatena(lista *l1, lista l2){
  lista x, aux;
  if(lis_vac(l1) || lis_vac(&l2))
    return ERR_LISVAC;
  x = *l1;
  while(!lis_vac(&x)){
    aux = x;
    ngets((ptrnod)x, (ptrnod*)&x);
  }
  nsets((ptrnod)aux, (ptrnod)l2);
  return OK;
}

int coincidencias(const lista *l, int* c, funcion a){
  *c = 0;
  lista x;
  if(lis_vac(l))
    return ERR_LISVAC;
  x = *l;
  while(!lis_vac(&x)){
    if (a(x->d))
        (*c)++;
    ngets((ptrnod)x, (ptrnod*)&x);
  }
  return OK;
}

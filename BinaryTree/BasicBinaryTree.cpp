#include <iostream>

using namespace std;

struct nodo{
    int x;
    nodo *izq, *der;
}*arbol = NULL;

nodo* CrearNvo(int valor){
    nodo *nvo;
    nvo = (nodo*) malloc(sizeof(nodo));
    nvo->x = valor;
    nvo->izq = NULL;
    nvo->der = NULL;
    return nvo;
}

void Insertar (nodo* &act, int valor){
    if (!act){
        act = CrearNvo(valor);
        return;
    }
    if (act->x > valor)
        Insertar(act->izq, valor);
    else
        Insertar(act->der, valor);
}

nodo* Buscar (nodo* &act, int valor){
    if (!act)
        return NULL;
    if (act->x == valor)
        return act;
    else if (act->x > valor)
        return Buscar(act->izq, valor);
    else
        return Buscar(act->der, valor);
}

void Inorden(nodo* &act){
    if (!act)
        return;
    Inorden(act->izq);
    cout << act->x << " ";
    Inorden(act->der);
}

int main()
{
    for (int i = 0; i < 5; i++){
        int a;
        cin >> a;
        Insertar(arbol, a);
    }
    Inorden(arbol);
    if(Buscar(arbol, 4))
        cout << "\nLo encontre";
    else
        cout << "\nNel";
    return 0;
}

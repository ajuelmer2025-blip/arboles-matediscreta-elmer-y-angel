#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* izq;
    Nodo* der;
    Nodo(int d){ dato=d; izq=der=NULL; }
};

Nodo* insertar(Nodo* r, int d){
    if(r==NULL) return new Nodo(d);
    if(d < r->dato) r->izq = insertar(r->izq, d);
    else r->der = insertar(r->der, d);
    return r;
}

void preorden(Nodo* r){
    if(r){ cout<<r->dato<<" "; preorden(r->izq); preorden(r->der); }
}
void inorden(Nodo* r){
    if(r){ inorden(r->izq); cout<<r->dato<<" "; inorden(r->der); }
}
void posorden(Nodo* r){
    if(r){ posorden(r->izq); posorden(r->der); cout<<r->dato<<" "; }
}

int main(){
    Nodo* raiz = NULL;
    raiz = insertar(raiz, 50);
    insertar(raiz, 30);
    insertar(raiz, 70);
    insertar(raiz, 20);
    insertar(raiz, 40);
    insertar(raiz, 60);
    insertar(raiz, 80);

    cout<<"Preorden: "; preorden(raiz); cout<<endl;
    cout<<"Inorden: "; inorden(raiz); cout<<endl;
    cout<<"Posorden: "; posorden(raiz); cout<<endl;
    return 0;
}

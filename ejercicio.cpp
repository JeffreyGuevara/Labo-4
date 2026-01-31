#include <iostream>
#include <string>
using namespace std;

struct Nodo {
    int id;
    string nombre;
    float peso;
    Nodo* sig;
    Nodo* ant;
};


void mostrarAdelante(Nodo* head) {
    if (head == nullptr) {
        cout << "La lista esta vacia\n";
        return;
    }

    Nodo* aux = head;
    while (aux != nullptr) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << endl;
        aux = aux->sig;
    }
}

void mostrarAtras(Nodo* tail) {
    if (tail == nullptr) {
        cout << "La lista esta vacia\n";
        return;
    }

    Nodo* aux = tail;
    while (aux != nullptr) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << endl;
        aux = aux->ant;
    }
}


int contarPaquetes(Nodo* head) {
    int contador = 0;
    Nodo* aux = head;

    while (aux != nullptr) {
        contador++;
        aux = aux->sig;
    }
    return contador;
}

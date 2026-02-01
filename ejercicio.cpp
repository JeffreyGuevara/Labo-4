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


Nodo* buscarPorId(Nodo* head, int id) {
    Nodo* aux = head;
    while (aux != NULL) {
        if (aux->id == id)
            return aux;
        aux = aux->sig;
    }
    return NULL;
}


bool insertarInicio(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    if (buscarPorId(head, id) != NULL) {
        cout << "ID repetido. No permitido.\n";
        return false;
    }

    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = head;
    nuevo->ant = NULL;

    if (head == NULL) {          
        head = tail = nuevo;
    } else {
        head->ant = nuevo;
        head = nuevo;
    }
    return true;
}


bool insertarFinal(Nodo*& head, Nodo*& tail, int id, string nombre, float peso) {
    if (buscarPorId(head, id) != NULL) {
        cout << "ID repetido. No permitido.\n";
        return false;
    }

    Nodo* nuevo = new Nodo();
    nuevo->id = id;
    nuevo->nombre = nombre;
    nuevo->peso = peso;
    nuevo->sig = NULL;
    nuevo->ant = tail;

    if (tail == NULL) {         
        head = tail = nuevo;
    } else {
        tail->sig = nuevo;
        tail = nuevo;
    }
    return true;
}

bool eliminarPorId(Nodo*& head, Nodo*& tail, int id) {
    Nodo* act = buscarPorId(head, id);
    if (act == NULL) return false;

    if (act == head && act == tail) {
        head = tail = NULL;
    }
    else if (act == head) {
        head = head->sig;
        head->ant = NULL;
    }
    else if (act == tail) {
        tail = tail->ant;
        tail->sig = NULL;
    }
    else {
        act->ant->sig = act->sig;
        act->sig->ant = act->ant;
    }
    delete act;
    return true;
}


int main() {
    Nodo* head = NULL;
    Nodo* tail = NULL;

    int op, id;
    string nombre;
    float peso;

    do {
        cout << "\n--- SISTEMA DE PAQUETES (INSERTAR) ---\n";
        cout << "1. Insertar paquete al final\n";
        cout << "2. Insertar paquete al inicio\n";
        cout << "3. Salir\n";
        cout << "Opcion: ";
        cin >> op;

        switch (op) {
        case 1:
            cout << "ID: ";
            cin >> id;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Peso: ";
            cin >> peso;
            insertarFinal(head, tail, id, nombre, peso);
            break;

        case 2:
            cout << "ID: ";
            cin >> id;
            cout << "Nombre: ";
            cin >> nombre;
            cout << "Peso: ";
            cin >> peso;
            insertarInicio(head, tail, id, nombre, peso);
            break;
        }

    } while (op != 2);

    return 0;
}

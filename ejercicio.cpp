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

void mostrarAdelante(Nodo* head) {
    if (head == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* aux = head;
    while (aux != NULL) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << " kg\n";
        aux = aux->sig;
    }
}
void mostrarAtras(Nodo* tail) {
    if (tail == NULL) {
        cout << "Lista vacia.\n";
        return;
    }

    Nodo* aux = tail;
    while (aux != NULL) {
        cout << "ID: " << aux->id
             << " | Nombre: " << aux->nombre
             << " | Peso: " << aux->peso << " kg\n";
        aux = aux->ant;
    }
}

bool editarPaquete(Nodo* head, int id) {
    Nodo* aux = head;

    while (aux != NULL) {
        if (aux->id == id) {
            cout << "Nuevo nombre: ";
            cin >> aux->nombre;
            cout << "Nuevo peso: ";
            cin >> aux->peso;
            return true;
        }
        aux = aux->sig;
    }
    return false;
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

int contar(Nodo* head) {
    int c = 0;
    Nodo* aux = head;
    while (aux != NULL) {
        c++;
        aux = aux->sig;
    }
    return c;
}

void liberarLista(Nodo*& head, Nodo*& tail) {
    Nodo* aux = head;
    while (aux != NULL) {
        Nodo* borrar = aux;
        aux = aux->sig;
        delete borrar;
    }
    head = tail = NULL;
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
        cout << "3. Mostrar lista adelante\n";
        cout << "4. Insertar lista atras\n";
        cout << "5. Buscar paquete por id\n";
        cout << "6. Eliminar paque por id\n";
        cout << "7. Mostrar cantidad\n";
        cout << "8. Editar paquete por id\n";
        cout << "9. Salir\n";
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

        case 3:
            mostrarAdelante(head);
            break;

        case 4:
            mostrarAtras(tail);
            break;

        case 5: {
            cout << "ID a buscar: ";
            cin >> id;
            Nodo* r = buscarPorId(head, id);
            if (r)
                cout << "Encontrado: " << r->nombre << " | Peso: " << r->peso << "\n";
            else
                cout << "No encontrado.\n";
            break;
        }

        case 6:
            cout << "ID a eliminar: ";
            cin >> id;
            if (eliminarPorId(head, tail, id))
                cout << "Eliminado.\n";
            else
                cout << "No existe.\n";
            break;

        case 7:
            cout << "Cantidad de paquetes: " << contar(head) << "\n";
            break;
        case 8:
             cout << "ID del paquete a editar: ";
            cin >> id;
            if (editarPaquete(head, id))
            cout << "Paquete editado correctamente.\n";
            else
            cout << "No se encontro el paquete.\n";
            break;
        
        }

    } while (op != 9);

    return 0;
}

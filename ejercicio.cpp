

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




case 3:
    mostrarAdelante(head);
    break;

case 4:
    mostrarAtras(tail);
    break;

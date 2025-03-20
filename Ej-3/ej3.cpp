#include <iostream>
#include <memory>

using namespace std;

struct Node{
    int value; 
    shared_ptr<Node> next; 
};

typedef struct List{ 
    shared_ptr<Node> head;
    shared_ptr<Node> tail;
    int size;
} list_t;

// Elegí usar shared pointers porque me permite tener un puntero al tail de la lista,
// lo cual me facilita agregar nodos al final de la lista sin tener que recorrerla entera.

shared_ptr<Node> create_node(int value){
    auto new_node = make_shared<Node>(); //creo un shared_ptr de tipo Node
    //no chequeo porque si no se puede asignar memoria, el programa tira error y termina
    new_node->value = value;  //asigno el valor al nodo
    new_node->next = nullptr; //inicializo el puntero al siguiente nodo en nullptr
    return new_node;
}

void push_front(shared_ptr<Node> node, shared_ptr<list_t> list){
    node->next = list->head; //asigno que el siguiente nodo al nodo que quiero agregar sea la cabeza de la lista
    list->head = node;       //actualizo el head
    if (list->size == 0) list->tail = node; //si la lista esta vacia, el nodo que agrego tambien es la cola
    list->size++; 
}

void push_back(shared_ptr<Node> node, shared_ptr<list_t> list){
    if (list->size == 0) { //si la lista esta vacia, el nodo que agrego es la cabeza y la cola
        list->head = node;
        list->tail = node;
    } else { //si no, el nodo que agrego es la cola y actualizo la cola
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void insert(shared_ptr<Node> node, shared_ptr<list_t> list, int position){
    if (position <= 0 || list->size == 0){ //si la posicion es menor o igual a 0 o la lista esta vacia, agrego el nodo al principio
        push_front(node, list);
        return;
    }
    if (position >= list->size){ //si la posicion es mayor o igual al tamaño de la lista, agrego el nodo al final y aviso
        push_back(node, list);
        cout << "Position " << position << " is greater than list size, node added at the end of the list" << endl;
        return;
    }
    
    shared_ptr<Node> current = list->head;
    for (int i = 0; i < position - 1; i++){
        current = current->next;
    }
    // inserto el nodo
    node->next = current->next;
    current->next = node;
    list->size++;
}

void erase(shared_ptr<list_t> list, int position){
    if (list->size == 0) return; //si la lista esta vacia, no hago nada
    
    if (list->size == 1){ //si la lista tiene un solo nodo, borro ese nodo
        list->head = nullptr;
        list->tail = nullptr;
        list->size--;
        return;
    }
    if (position <= 0){ //si la posicion es menor o igual a 0, borro el primer nodo
        list->head = list->head->next;
        if (list->head == nullptr){
            list->tail = nullptr;
        }
        list->size--;
        return;
    }
    if (position >= list->size){ //si la posicion es mayor o igual al tamaño de la lista, borro el ultimo nodo y aviso
        position = list->size - 1;
        cout << "Position " << position << " is greater than list size, the node deleted will be the last one" << endl;
    }
    
    // Busco el nodo anterior al que quiero borrar
    auto curr_node = list->head;
    for (int i = 0; i < position - 1 && curr_node->next; i++){
        curr_node = curr_node->next;
    }
    if (curr_node->next == list->tail){ //si el nodo que quiero borrar es el ultimo, actualizo la cola
        list->tail = curr_node;
    }
    // Borro el nodo
    curr_node->next = curr_node->next->next;
    list->size--;
}

void print_list(shared_ptr<list_t> list) {
    auto curr_node = list->head;
    while (curr_node) { //mientras el nodo no sea nullptr
        cout << curr_node->value << " -> "; //imprimo el valor del nodo
        curr_node = curr_node->next;
    }
    cout << "nullptr" << endl;
}

int main(){
    // Creo la lista
    auto list = make_shared<list_t>();
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;
    // Creo los nodos
    int node_ammount = 3;
    // Ejemplo de uso de push back
    for (int i = 0; i<node_ammount; i++){
        auto node = create_node(i);
        cout << "--- Push back iteration: " << i << " ---" << endl;
        push_back(node, list);
        print_list(list);
    }
    cout << endl;
    // Ejemplo de uso de push front
    for (int i = 0; i<node_ammount; i++){
        auto node = create_node(i);
        cout << "--- Push front iteration: " << i << " ---" << endl;
        push_front(node, list);
        print_list(list);
    }
    cout << endl;
    // Ejemplo de uso de insert
    int pos_insert = 5;
    for (int i = 0; i<node_ammount; i++){
        auto node = create_node(i);
        cout << "--- Insert iteration: " << i << ". At pos: " << pos_insert << " ---" << endl;
        insert(node, list, pos_insert);   //inserto el nodo 
        pos_insert += 2;                  //incremento para que la proxima insercion sea en una posicion mayor, y atacar 
        print_list(list);                 //el caso de que la posicion sea mayor al tamaño de la lista
    }

    // Imprimo la lista actual
    cout << endl; cout << endl;
    cout << "The list looks currently like this: " << endl;
    print_list(list);
    cout << "List size: " << list->size << endl;
    cout << endl; cout << endl;
    
    // Borro los nodos
    int erase_ammount = list->size;
    for (int i = 0; i<erase_ammount; i++){
        cout << "--- Erase Iteration: " << i << " ---" << endl;
        erase(list, 3);     //borro el nodo en la posicion 3, cuando la lista tenga menos de 3 nodos, se borrara el ultimo
        print_list(list);   //y se avisara que la posicion es mayor al tamaño de la lista.
        cout << "List size: " << list->size << endl;
    }
    return 0;
}
/*
Implemente una lista enlazada que utilice nodos que simplemente contengan un 
valor y una dirección de memoria de un nodo. Adicionalmente, agregue las siguientes 
funciones para manejar la lista: 
i. 
    create_node(): devuelve un nodo. 
ii. 
    push_front(): inserta un nodo al frente de la lista. 
iii. 
    push_back(): inserta un nodo al final de la lista. 
iv. 
    insert(): inserta un nodo en la posición que se le pase a la función. Si se le pasa 
    una posición mayor al largo de la lista, se debe indicar lo ocurrido y se debe de 
    agregar el nodo al final de la lista. 
v. 
    erase(): borra un nodo en la posición que se le pase a la función. Similar a la 
    función insert(), si la posición es mayor que el largo de la lista, se debe de borrar 
    el último nodo. 
vi. 
    print_list(): imprime la lista completa, separando el valor en cada nodo con “->”. 
    Presentar ejemplos que verifiquen el funcionamiento requerido en las funciones i-vi y, 
    muy importante para el ejercicio, sólo utilizar smart pointers.
*/

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

shared_ptr<Node> create_node(int value){
    auto new_node = make_shared<Node>();
    if (new_node == nullptr) return nullptr;
    new_node->value = value;
    new_node->next = nullptr;
    return new_node;
}

void push_front(shared_ptr<Node> node, shared_ptr<list_t> list){
    node->next = list->head;
    list->head = node;
    if (list->size == 0) list->tail = node;
    list->size++; 
}

void push_back(shared_ptr<Node> node, shared_ptr<list_t> list){
    if (list->size == 0) {
        list->head = node;
        list->tail = node;
    } else {
        list->tail->next = node;
        list->tail = node;
    }
    list->size++;
}

void insert(shared_ptr<Node> node, shared_ptr<list_t> list, int position){
    if (position <= 0 || list->size == 0){
        push_front(node, list);
        return;
    }
    if (position >= list->size){
        push_back(node, list);
        cout << "Position is greater than list size, node added at the end of the list" << endl;
        return;
    }
    shared_ptr<Node> current = list->head;
    for (int i = 0; i < position - 1; i++){
        current = current->next;
    }
    node->next = current->next;
    current->next = node;
    list->size++;
}

void erase(shared_ptr<list_t> list, int position){
    if (list->size == 0) return;
    
    if (list->size == 1){
        list->head = nullptr;
        list->tail = nullptr;
        list->size--;
        return;
    }
    if (position <= 0){
        list->head = list->head->next;
        if (list->head == nullptr){
            list->tail = nullptr;
        }
        list->size--;
        return;
    }
    if (position >= list->size){
        position = list->size - 1;
        cout << "Position is greater than list size, node deleted at the end of the list" << endl;
    }
    
    auto curr_node = list->head;
    for (int i = 0; i < position - 1 && curr_node->next; i++){
        curr_node = curr_node->next;
    }
    if (curr_node->next == list->tail){
        list->tail = curr_node;
    }
    curr_node->next = curr_node->next->next;
    list->size--;
}

void print_list(shared_ptr<list_t> list) {
    auto curr_node = list->head;
    while (curr_node) {
        cout << curr_node->value << " -> ";
        curr_node = curr_node->next;
    }
    cout << "nullptr" << endl;
}

int main(){
    auto list = make_shared<list_t>();
    list->head = nullptr;
    list->tail = nullptr;
    list->size = 0;

    int node_ammount = 15;
    int pos_insert = 4;
    for (int i = 0; i<node_ammount; i++){
        auto node = create_node(i);
        push_back(node, list);
    }
    for (int i = 0; i<node_ammount; i++){
        auto node = create_node(i);
        push_front(node, list);
    }
    for (int i = 0; i<node_ammount; i++){
        auto node = create_node(i);
        insert(node, list, pos_insert);
    }
    for (int i = 0; i<list->size; i++){
        erase(list, i);
    }
    print_list(list);

}
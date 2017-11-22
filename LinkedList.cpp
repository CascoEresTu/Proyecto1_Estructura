//#pragma once
#include "LinkedList.h"

LinkedList::Node::Node(Object* e){
    //Se inicializa nuestra lista;
    data = e;
    next = NULL;;
}

LinkedList::Node::~Node(){
    if (data) {
        delete data;
	}
    if (next) {
        delete next;
    }
}
LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){
    if (head) {
		delete head;
	}
}


bool LinkedList::insert(Object* e, int position){
    if(position <0 || position > size){
      return false; // "MISSION FAILED"
    }
    //Se crea el nodo a insertar en la lista.
    Node* neo = new Node(e);

    if(!head){ //en caso de que la lista esté vacia;
      head = neo;
    }
      else if(position==0 && head){
         //inserción al principio de la lista.
        neo->next = head;
        head = NULL;
        head = neo;
     }
      else if (position >0 && position < Size()){
        //Incersión enmedio de la lista.
        Node* temp = head;
        //Se recorre hasta la posicion a insertar.
        for(int i =1 ; i < position ; i++){
            temp = temp->next;
            }
            //se enlaza el nodo.
        neo->next = temp->next;
        temp->next = neo;
        }

    else{
        //insercion al final de la lista.
        Node* temp = head;
        //se recorre hasta el final.
		for (int i = 1; i < position; ++i) {
			temp = temp->next;
		}
        //se enlaza el nodo
		temp->next = neo;
    }

    size++;
    return true;
}


Object* LinkedList::remove(int position){

  if(position< 0 || position> Size()){
      return NULL;
    }

  if(position == 0){
        Node * temp ;
        Object* retval;

        temp = head->next;
        retval = head->data;
        head->next = NULL;
        delete head;
        head = temp;
        size--;
        return retval;
    }

    else if(position == Size() -1){
        Node* temp ;
        Object* retval;
        temp = head;

        for(int i =1 ; i< position ; i++){
          std::cout << "holis" << '\n';
          temp = temp->next;
        }

        Node* temp2 = temp->next;
        retval = temp->next->data;
//        temp->next->data = NULL;
        temp->next = NULL;
        delete temp2;
        size--;
        //std::cout << "holis" << '\n';
        return retval;
    }

   else if (position > 0 && position < Size()-1){
    Node* temp ;
    Object* retval;

    temp = head;
    for(int i =0 ; i< position ; i++){
        temp = temp->next;
    }

    Node* temp2 = temp->next->next;
    retval = temp->next->data;
    temp->next = temp->next->next;

    delete temp->next;
    temp->next = NULL;
    size--;
    return retval;
    }
}

Object* LinkedList::first()const{
    if(!head){
        return NULL; // "MISSION FAILED"
    }
    return head->data;
}

Object* LinkedList::last()const{
    if (head){
        Node* temp = head;
        //Se recorre hasta llegar al final.
        for (int i = 1; i < Size(); i++) {
            temp = temp->next;
        }
        return temp->data;
    }
    return NULL; // "MISSION FAILED"
}

void LinkedList::clear(){
    //limpia todos nuestra lista.
    if(head){
        delete head;
    }
    head = NULL;
    size = 0;
}

int LinkedList::indexOf(Object* element)const{
    Node* temp = head;

    for (int i=0; i < Size(); i++){
        // Se compara cada uno de los elementos con el parámetro.
        if (temp->data->equals(element)){
                return i;
            }
        temp = temp->next;
    }
    // En el caso de no encontrarlo
    return -1; // "MISSION FAILED"
}

Object* LinkedList::get(int position)const{

    if(position< 0 || position> Size()){
        return NULL; // "MISSION FAILED"
    }

    Node* temp = head;
    //Se hace recorrido hasta la posicion deseada.
    for (int i = 0; i < position; i++) {
        temp = temp->next;
    }
    return temp->data; //"MISSION COMPLETE"
}

bool LinkedList::isEmpty()const{
    if (!head) {
        return true;
    }else{
        return false;
    }
}

bool LinkedList::isFull()const{
    return false; //las listas enlazadas NUNCA se llenan.
}

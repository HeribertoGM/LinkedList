#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include "Node.h"
template <class T>

class LinkedList{
public:
	LinkedList();
	LinkedList(LinkedList &LL);
	~LinkedList();
	void addFirst(T data);
	void addLast(T data);
	bool add(T data, int pos);
	void deleteFirst();
	void deleteLast();
	void del(int pos);
	int deleteAll();
	T get(int pos);
	T set(T data, int pos);
	bool change(int pos1, int pos2);
	int getSize();
	bool isEmpty();
	void print();
	void reverse();
	bool operator==(LinkedList<T> _lista);
	void operator+=(T data);
	void operator+=(LinkedList<T> _lista);

private:
	Node<T> *head;
	int Size;
	void deleteHelper();
};

// constructor de lista vacia
template <class T>
LinkedList<T>::LinkedList(){
	head=NULL;
	Size=0;
}

// destructor de clase
template <class T>
LinkedList<T>::~LinkedList(){
	deleteHelper();
}

// agrega elemento n al principio de la lista
template <class T>
void LinkedList<T>::addFirst(T data){
	head=new Node<T>(data,head);
	Size++;
}

// agrega elemento n al final de la lista
template <class T>
void LinkedList<T>::addLast(T data){
	if(this->isEmpty()){
		addFirst(data);
	}
	else{
		Node<T> *curr = head;
		while(curr->getNext() != NULL){
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data));
		Size++;
	}
}

// agrega elemento n en la posicion m de la lista
template <class T>
bool LinkedList<T>::add(T data, int pos){
	if(pos == 0){
		addFirst(data);
	}
	if(pos > Size){
		return false;
	}
	if(pos == Size){
		addLast(data);
	}
	else{
		Node<T> *curr = head;
		for(int i=1; i<pos; i++){
			curr = curr->getNext();
		}
		curr->setNext(new Node<T>(data, curr->getNext()));
		Size++;
	}

	return true;
}

// elimina el primer elemento de la lista
template <class T>
void LinkedList<T>::deleteFirst(){
	if(!this->isEmpty()){
		Node<T> *curr = head;
		head = head->getNext();
		delete curr;
		Size--;
	}
}

// elimina el ultimo elemento de la lista
template <class T>
void LinkedList<T>::deleteLast(){
	if(Size <= 1){
		deleteFirst();
	}
	else{
		Node<T> *curr = head;
		while(curr->getNext()->getNext() != NULL){
			curr = curr->getNext();
		}
		delete curr->getNext();
		curr->setNext(NULL);
		Size--;
	}
}

// elimina el elemento en la posicion n de la lista
template <class T>
void LinkedList<T>::del(int pos){
	if(pos < Size){
		if(pos == 0){
			deleteFirst();
		}
		if(pos == Size-1){
			deleteLast();
		}
		if(pos >= 0 && pos < Size-1){
			Node<T> *curr = head;
			for(int i=1; i<pos; i++){
				curr = curr->getNext();
			}
			Node<T> *temp = curr->getNext();
			curr->setNext(temp->getNext());
			delete temp;
			Size--;
		}
	}
}

// elimina todos los elementos de la lista
template <class T>
int LinkedList<T>::deleteAll(){
	int cant = Size;
	deleteHelper();
	Size = 0;
	return cant;
}

// Auxiliar
// elimina todos los nodos de una lista
template <class T>
void LinkedList<T>::deleteHelper(){
	Node<T> *curr = head;
	while(!this->isEmpty()){
		head = head->getNext();
		delete curr;
		curr = head;
	}
}

// retorna el elemento que se encuentra en la posicion n de la lista
template <class T>
T LinkedList<T>::get(int pos){
	Node<T> *curr = head;
	for(int i=0; i<pos; i++){
		curr = curr->getNext();
	}

	return curr->getData();
}

// modifica el dato que contiene el elemento en la posicion n de la lista
template <class T>
T LinkedList<T>::set(T data, int pos){
	Node<T> *curr = head;
	for(int i=0; i<pos; i++){
		curr = curr->getNext();
	}

	T temp = curr->getData();
	curr->setData(data);

	return temp;
}

// intercambia los elementos que se encuentran en las posiciones n y m
template <class T>
bool LinkedList<T>::change(int pos1, int pos2){
	if(pos1 == pos2){
		return true;
	}
	if(pos1 >= 0 && pos1 < Size && pos2 >= 0 && pos2 < Size){
		Node<T> *curr1 = head;
		for(int i=0; i<pos1; i++){
			curr1 = curr1->getNext();
		}
		Node<T> *curr2 = head;
		for(int i=0; i<pos2; i++){
			curr2 = curr2->getNext();
		}

		T aux;
		aux = curr1->getData();
		curr1->setData(curr2->getData());
		curr2->setData(aux);
		
		return true;
	}
	else{
		return false;
	}
}

// verifica si la lista esta vacia
template <class T>
bool LinkedList<T>::isEmpty(){
	return (head==NULL);
}

// retorna el tamaño de la lista
template <class T>
int LinkedList<T>::getSize(){
	return Size;
}

// imprime el contenido de la lista
template <class T>
void LinkedList<T>::print(){

	Node<T> *curr = head;
	if(curr != NULL){
		for(int i = 0; i < Size; i++){
			std::cout << curr->getData() << " ";
			curr = curr->getNext();
		}
		std::cout << "\n";
	} else {
		std::cout << "Lista vacia\n";
	}
}

// invierte la lista
template <class T>
void LinkedList<T>::reverse(){
	if(Size > 1){
		for(int x=(Size-1); x>0; x--){
			for(int aux=x; aux>0; aux--){
				this->change(0, aux);
			}
		}
	}
}

// operador ==, verifica la igualdad entre dos listas
template <class T>
bool LinkedList<T>::operator==(LinkedList<T> _lista){

	bool x = true;

	if(Size == _lista.getSize()){
		for(int i=0; i<Size; i++){
			if(this->get(i) != _lista.get(i)){
				x = false;
			}
		}
		return x;
	} else {
		return false;
	}
}

// operador += para un dato, anexa el dato n al final de la lista
template <class T>
void LinkedList<T>::operator+=(T data){
	this->addLast(data);
}

// operador += para una lista, concatena las listas n y m
template <class T>
void LinkedList<T>::operator+=(LinkedList<T> _lista){
	int x = _lista.getSize();
	for(int i=0; i<x; i++){
		this->addLast(_lista.get(i));
	}
}

// constructor parametrizado de la lista
template <class T>
LinkedList<T>::LinkedList(LinkedList &LL){
	head = NULL;
	Size = 0;

	for(int i=0; i<LL.getSize(); i++){
		this->addLast(LL.get(i));
	}
}

#endif // NODE_H_

#ifndef NODE_H_
#define NODE_H_

template <class T>

// definicion de clase node a usar en LinkedList
class Node{
public:
	Node(T data);
	Node(T data, Node<T> *next);
	T getData();
	Node<T>* getNext();
	void setData(T data);
	void setNext(Node<T> *next);

private:
	T data;
	Node<T> *next;
};

// constructor de clase con dato n 
// (usado para construir nodos al final de la lista)
template <class T>
Node<T>::Node(T data){
	this->data=data;
	this->next=NULL;
}

// constructor de clase, con dato y apuntador 
// (usado para construir nodos que iran en una posicion n de la lista)
template <class T>
Node<T>::Node(T data, Node<T> *next){
	this->data=data;
	this->next=next;
}

// retorna el dato que contiene el nodo
template <class T>
T Node<T>::getData(){
	return data;
}

// retorna el apuntador al que apunta el nodo
template <class T>
Node<T>* Node<T>::getNext(){
	return next;
}

// cambia el dato interno del nodo por n
template <class T>
void Node<T>::setData(T data){
	this->data=data;
}

// cambia el apuntador interno del nodo por *next
template <class T>
void Node<T>::setNext(Node<T> *next){
	this->next=next;
}

#endif // NODE_H_

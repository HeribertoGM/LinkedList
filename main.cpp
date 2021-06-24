#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	cout << "1. Se declaran dos listas de string" << endl << endl;
	LinkedList<string> lista, lista2;

	cout << "2. addFirst [2,1] y addLast [3,4] a lista1" << endl;
	lista.addFirst("2");
	lista.addFirst("1");
	lista.addLast("3");
	lista.addLast("4");

	cout << "\tlista1: ";
	lista.print();
	cout << endl;

	cout << "3. addFirst [B,A] y addLast [C,D] a lista2" << endl;
	lista2.addFirst("B");
	lista2.addFirst("A");
	lista2.addLast("C");
	lista2.addLast("D");
	lista2.addLast("E");

	cout << "\tlista2: ";
	lista2.print();
	cout << endl;

	cout << "4. Se declara lista3 copia de lista1" << endl;
	LinkedList<string> lista3(lista);

	cout << "\tlista3: ";
	lista3.print();
	cout << endl;

	cout << "5. Verifica si lista1 y lista3 son iguales" << endl;	
	if(lista==lista3){
		cout << "\tSon iguales" << endl;
	} else {
		cout << "\tSon diferentes" << endl;
	}
	cout << endl;

	cout << "6. inversa a lista3" << endl;
	lista3.reverse();
	cout << "\tlista3: ";
	lista3.print();
	cout << endl;

	cout << "7. agrega [0] a lista3 con +=" << endl;
	lista3 += "0";
	cout << "\tlista3: ";
	lista3.print();
	cout << endl;

	cout << "8. concatena lista1 en lista3 con +=" << endl;
	lista3 += lista;
	cout << "\tlista3: ";
	lista3.print();
	cout << endl;

	cout << "9. agrega [0] a lista3 con add en posicion 5" << endl;
	lista3.add("0", 5);
	cout << "\tlista3: ";
	lista3.print();
	cout << endl;

	cout << "10. obtiene el tamaño de la lista2: " << endl;
	cout << "\tlista2: ";
	lista2.print();
	cout << "\ttamaño lista2: " << lista2.getSize() << endl;
	cout << endl;

	cout << "11. intercambia los elementos en las posiciones 1 y 2 en la lista2" << endl;
	lista2.change(1, 2);
	cout << "\tlista2: ";
	lista2.print();
	cout << endl;

	cout << "12. elimina el primer y ultimo elemento de la lista2" << endl;
	lista2.deleteFirst();
	lista2.deleteLast();
	cout << "\tlista2: ";
	lista2.print();
	cout << endl;

	cout << "13. cambia el dato del elemento en la posicion 1 de la lista2" << endl;
	lista2.set("X", 1);
	cout << "\tlista2: ";
	lista2.print();
	cout << endl;

	cout << "14. obtiene el elemento en la posicion 1 de la lista2" << endl;
	cout << "\telemento lista2: " << lista2.get(1) << endl << endl;

	cout << "15. elimina el elemento de la posicion 1 de la lista2" << endl;
	lista2.del(1);
	cout << "\tlista2: ";
	lista2.print();
	cout << endl;

	cout << "16. elimina el resto de los elementos de la lista2" << endl;
	lista2.deleteAll();
	cout << "\tlista2: ";
	lista2.print();
	cout << endl;

	cout << "17. Verifica si lista2 esta vacia" << endl;	
	if(lista2.isEmpty()){
		cout << "\tEsta vacia" << endl;
	} else {
		cout << "\tNo esta vacia" << endl;
	}
	cout << endl;
	
	return 0;
}

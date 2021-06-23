#include <iostream>
#include "LinkedList.h"

using namespace std;

int main() {
	LinkedList<string> miLista;
	LinkedList<string> miLista2;

	miLista.addFirst("2");
	miLista.addFirst("1");
	miLista.addLast("3");
	miLista.addLast("4");
	miLista.print();

	miLista2.addFirst("B");
	miLista2.addFirst("A");
	miLista2.addLast("C");
	miLista2.addLast("D");
	miLista2.print();

	//miLista+=miLista2;
	//miLista.print();
	//miLista2.print();

	miLista2.reverse();
	miLista2.print();

	LinkedList<string> miLista3(miLista2);
	miLista3.print();


	/*    cout << miLista.getSize() << endl;

	 miLista.deleteFirst();
	 miLista.print();
	 miLista.deleteLast();
	 miLista.print();
	 miLista.del(1);

	 //miLista.deleteAll();

	 miLista.print();

	 cout << miLista.get(0) << endl;

	 miLista.set("Caro", 0);
	 miLista.addLast("Nina");
	 miLista.addLast("Juan");

	 miLista.print();

	 miLista.Change(0, 2);
	 miLista.print();
	 */
	return 0;
}

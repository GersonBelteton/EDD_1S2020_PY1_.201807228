#include "ColaFicha.h"
#include <vector>;
#include <fstream>;
#include <string>;
void ColaFicha::encolar() {
	ColaFicha cf = ColaFicha();
	cf.enqueue('a', 2);
	cf.enqueue('b', 2);
	cf.enqueue('c', 2);
	cf.enqueue('d', 2);
	cf.enqueue('e', 2);
	cf.enqueue('f', 2);

	cf.mostrarCola();
}

ColaFicha::ColaFicha()
{
	primero = NULL;
	ultimo = NULL;
	size = 0;
}

bool ColaFicha::isEmpty()
{
	return primero == NULL;
}

void ColaFicha::enqueue(char letra, int puntaje)
{
	Ficha* nuevo = new Ficha(letra, puntaje);
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		ultimo = nuevo;

	}
	size++;
}

Ficha* ColaFicha::dequeue()
{
	if (isEmpty()) {
		cout << "cola de fichas vacia";
	}
	else {
		Ficha* aux = primero;
		primero = primero->getSiguiente();
		aux->setSiguiente(NULL);
		size--;
		return aux;
	}
}

void ColaFicha::mostrarCola()
{
	Ficha* aux = primero;

	while (aux != NULL) {

		cout << aux->getLetra() << aux->getPuntaje() << endl;
		aux = aux->getSiguiente();
	}
}

void ColaFicha::generarReporte()
{
	Ficha* aux = primero;
	int contador = 0;
	int contador2 = 0;
	ofstream archivo;
	string a;
	a = "";

	archivo.open("colaFicha.txt", ios::out);
	if (archivo.fail()) {
		cout << "no se pudo abrir";
		exit(1);
	}
	a = a + "digraph G {\n node[shape = box];";

	while (aux != NULL) {

		a = a + "nodo"+ to_string(contador) + "[label = \" " + aux->getLetra() + "\"];\n";
		contador++;
		aux = aux->getSiguiente();
	}

	

	for (int i = 0; i < size - 1; i++) {
		a = a + "nodo" + to_string(i+1) + "->nodo" + to_string(i) + ";\n";

	}
	a = a + "}";
	//cout << a;
	archivo << a;

	archivo.close();
	system("dot.exe -Tjpg colaFicha.txt -o colaFicha.jpg");
	system("colaFicha.jpg");
}


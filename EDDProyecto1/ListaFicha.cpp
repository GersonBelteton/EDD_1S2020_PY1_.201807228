#include "ListaFicha.h"
#include <vector>;
#include <fstream>;
#include <string>;
ListaFicha::ListaFicha()
{
	primero = NULL;
	ultimo = NULL;
	size = 0;
	id = 0;
}

bool ListaFicha::isEmpty()
{
	return primero == NULL;
}

int ListaFicha::Size()
{
	return size;
}

void ListaFicha::insertarInicio(char letra, int puntaje)
{
	
	Ficha* nuevo = new Ficha(letra, puntaje, id);
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {
		nuevo->setSiguiente(primero);
		primero->setAnterior(nuevo);
		primero = nuevo;
	}

	size++;
	id++;
}

Ficha* ListaFicha::getPrimero() {
	return primero;
}

void ListaFicha::insertarFinal(char letra, int puntaje)
{
	
	Ficha* nuevo = new Ficha(letra, puntaje, id);
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {
		ultimo->setSiguiente(nuevo);
		nuevo->setAnterior(ultimo);
		ultimo = nuevo;
		
	}
	size++;
	id++;
	
}

Ficha* ListaFicha::buscar(int id)
{
	if (isEmpty()) {
		cout << "lista vacia" << endl;

	}
	else {
		Ficha* aux = primero;

		while (aux != NULL) {
			
			if (aux->getId() == id) {
				return aux;
			}

			aux = aux->getSiguiente();
		}


	}

	return NULL;
}

void ListaFicha::eliminarInicio()
{
	if (isEmpty()) {
		cout << "lista vacia" << endl;
	}
	else {
		primero->getSiguiente()->setAnterior(NULL);
		primero = primero->getSiguiente();
		size--;
	}
}

void ListaFicha::eliminarFinal()
{
	if (isEmpty()) {
		cout << "Lista vacia" << endl;
	}
	else if (primero == ultimo) {
		primero = NULL;
		ultimo = NULL;
	}
	else {
		ultimo->getAnterior()->setSiguiente(NULL);
		ultimo = ultimo->getAnterior();
		size--;
	}

}

void ListaFicha::eliminar(int id)
{
	if (isEmpty()) {
		cout << "Lista vacia" << endl;
	}
	else {
		if (primero->getId() == id) {
			eliminarInicio();
		}
		else if (ultimo->getId() == id) {
			eliminarFinal();
		}
		else {
			Ficha* aux = buscar(id);
			aux->getAnterior()->setSiguiente(aux->getSiguiente());
			aux->getSiguiente()->setAnterior(aux->getAnterior());

		}
		size--;
	}
}

void ListaFicha::mostrarLista()
{
	if (isEmpty()) {
		cout << "Lista vacia" << endl;
	}
	else {
		Ficha* aux = primero;
		while (aux != NULL) {
			cout << aux->getId() << " " << aux->getLetra() << " " << aux->getPuntaje() << endl;
			aux = aux->getSiguiente();
		}
	}
}

void ListaFicha::generarReporte()
{
	Ficha* aux = primero;
	int contador = 0;
	ofstream archivo;
	string a;
	a = "";

	archivo.open("listaFicha.txt", ios::out);
	if (archivo.fail()) {
		cout << "no se pudo abrir";
		exit(1);
	}
	a = a + "digraph G {\n node[shape = box];";
	/*
	while (aux != NULL) {

		a = a + "nodo" + to_string(contador) + "[label = \" " + to_string(aux->getId())+". " + aux->getLetra() + "\"];\n";
		contador++;"
		aux = aux->getSiguiente();
	}*/

	while (aux != NULL) {
		a = a + "nodo" + to_string(aux->getId()) + "[label = \" " + to_string(aux->getId()) + ". " + aux->getLetra() + "\"];\n";
		
		if (aux->getSiguiente() != NULL) {
			a += "nodo" + to_string(aux->getId()) + "-> nodo" + to_string(aux->getSiguiente()->getId())+";\n";
		}

		if (aux->getAnterior() != NULL) {
			a += "nodo" + to_string(aux->getId()) + "-> nodo" + to_string(aux->getAnterior()->getId())+";\n";
		}
		aux = aux->getSiguiente();
	}

	/*
	for (int i = 0; i < size - 1; i++) {
		a = a + "nodo" + to_string(i + 1) + "->nodo" + to_string(i) + ";\n";

	}

	for (int i = 0; i < size - 1; i++) {
		a = a + "nodo" + to_string(i) + " ->nodo" + to_string(i + 1) + ";\n";
	}*/
	a = a + "}";
	//cout << a;
	archivo << a;

	archivo.close();
	system("dot.exe -Tjpg listaFicha.txt -o listaFicha.jpg");
	system("listaFicha.jpg");
}

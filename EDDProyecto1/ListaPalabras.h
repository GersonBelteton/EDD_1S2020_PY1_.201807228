#pragma once

#include "NodoPalabra.h";
#include <iostream>;
#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <windows.h>;
#include <string.h>;
#include <vector>;
#include <fstream>;
#include <string>
#include <string>

using namespace std;
class ListaPalabras
{

private:
/*	ListaPalabras();
	bool isEmpty();
	int Size();
	void insertarFinal(string );
	NodoPalabra* buscar(int );
	void eliminar(int );
	void eliminarPrimero();
	void eliminarUltimo();
	void mostrarLista();*/


	NodoPalabra* primero;
	NodoPalabra* ultimo;
	int size;
	int id;

public:

	ListaPalabras() {
		primero = NULL;
		ultimo = NULL;
		size = 0;
		id = 0;
	}


	bool isEmpty() {
		return primero == NULL;
	}

	int Size() {
		return size;
	}

	NodoPalabra* getPrimero() {
		return primero;
	}

	void insertarFinal(string palabra) {

		NodoPalabra* nuevo = new NodoPalabra(palabra, id);

		if (isEmpty()) {
			primero = nuevo;
			ultimo = nuevo;
			primero->setAnterior(ultimo);
			ultimo->setSiguiente(primero);
		}
		else {
			ultimo->setSiguiente(nuevo);
			nuevo->setAnterior(ultimo);
			nuevo->setSiguiente(primero);
			primero->setAnterior(nuevo);
			ultimo = nuevo;
		}
		size++;
		id++;
	}

	void generarReporte() {
		NodoPalabra* aux = primero;
		int contador = 0;
		ofstream archivo;
		string a;
		a = "";

		archivo.open("listaPalabra.txt", ios::out);
		if (archivo.fail()) {
			cout << "no se pudo abrir";
			exit(1);
		}
		a = a + "digraph G {\n node[shape = box];";


		do {
			
			a = a + "nodo" + to_string(contador) + "[label = \" " + aux->getPalabra() + "\"];\n";
			contador++;
			aux = aux->getSiguiente();
		} while (aux != primero);





		for (int i = 0; i < size - 1; i++) {
			a = a + "nodo" + to_string(i + 1) + "->nodo" + to_string(i) + ";\n";
			a = a + "nodo" + to_string(i) + "->nodo" + to_string(i+1) + ";\n";

		}
		
		a = a + "nodo" + to_string(size - 1) + "->nodo0 ;\n";
		a = a + "nodo0 ->nodo"+ to_string(size - 1) + " ;\n";
		
	
		a = a + "}";
		//cout << a;
		archivo << a;

		archivo.close();
		system("dot.exe -Tjpg listaPalabra.txt -o listaPalabra.jpg");
		system("listaPalabra.jpg");
	}

	NodoPalabra* buscar(int id) {

		NodoPalabra* aux = primero;
		if (isEmpty()) {
			cout << "lista vacia" << endl;
			return NULL;	
		}
		else {
			do {

				if (aux->getId() == id) {
					return aux;
				}

				aux = aux->getSiguiente();
			} while (aux != primero);

			cout << "elemento no encontrado" << endl;
			return NULL;
		}

	}

	void eliminar(int id) {

		if (isEmpty()) {
			cout << "lista vacia";
		}
		else {
			if (id == 0) {
				eliminarPrimero();
			}
			else if (id == size) {
				eliminarUltimo();
			}
			else {
				NodoPalabra* aux = buscar(id);
				aux->getSiguiente()->setAnterior(aux->getAnterior());
				aux->getAnterior()->setSiguiente(aux->getSiguiente());
			}

		
		}
	}

	void eliminarPrimero() {
		if (isEmpty()) {
			cout << "lista vacia" << endl;
		}
		else {
			
			primero->getSiguiente()->setAnterior(ultimo);
			primero->getAnterior()->setSiguiente(primero->getSiguiente());
			primero = ultimo->getSiguiente();
		}
	}

	void eliminarUltimo() {
		if (isEmpty()) {
			cout << "lista vacia" << endl;
		}
		else {

			ultimo->getSiguiente()->setAnterior(ultimo->getAnterior());
			ultimo->getAnterior()->setSiguiente(primero);
			ultimo = primero->getAnterior();
		}
	}

	void mostrarLista() {
		if (isEmpty()) {
			cout << "lista vacia" << endl;
		}
		else {
			NodoPalabra* aux = primero;
			do {

				cout << aux->getPalabra() << endl;

				aux = aux->getSiguiente();
			} while (aux != primero);
		}
	}
	 };


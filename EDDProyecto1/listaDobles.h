#pragma once
#include "NodoDobles.h";
#include <iostream>;
#include <string>;
#include <stdlib.h>;

class listaDobles
{

private:
	NodoDobles* primero;
	NodoDobles* ultimo;
	int size;

public:
	listaDobles() {
		primero = NULL;
		ultimo = NULL;
		size = 0;
	}

	bool isEmpty() {
		return primero == NULL;
	}


	void insertar(int x, int y) {


		NodoDobles* nuevo = new NodoDobles(x, y);
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

	NodoDobles* getPrimero() {
		return primero;
	}

	void buscar(int x, int y) {

	}

};


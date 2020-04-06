#pragma once

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
class NodoPalabra
{

private:
	string palabra;
	int id;
	NodoPalabra* siguiente;
	NodoPalabra* anterior;

public:

	NodoPalabra(string palabra_, int id_) {
		palabra = palabra_;
		id = id_;
	}

	string getPalabra() {
		return palabra;
	}

	int getId() {
		return id;
	}

	NodoPalabra* getSiguiente() {
		return siguiente;
	}

	NodoPalabra* getAnterior() {
		return anterior;
	}


	void setPalabra(string palabra_) {
		palabra = palabra_;
	}

	void setId(int id_) {
		id = id_;
	}

	void setSiguiente(NodoPalabra* siguiente_) {
		siguiente = siguiente_;
	}

	void setAnterior(NodoPalabra* anterior_) {
		anterior = anterior_;
	}



	

};


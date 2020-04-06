#pragma once
#include "NodoPuntaje.h";
class ListaPuntaje
{
private:
	NodoPuntaje* primero;
	NodoPuntaje* ultimo;
	int size;

public:

	ListaPuntaje();
	bool isEmpty();
	int Size();

	void insertarOrdenado(int puntaje);
	void mostrarLista();
	NodoPuntaje* getPrimero();
	void generarReporte();
};


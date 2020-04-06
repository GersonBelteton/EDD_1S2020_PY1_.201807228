#pragma once

#include "Ficha.h";

class ColaFicha
{
private:
	Ficha* primero;
	Ficha* ultimo;
	int size;

public:
	void encolar();
	ColaFicha();
	bool isEmpty();
	void enqueue(char letra, int puntaje);
	Ficha* dequeue();
	void mostrarCola();
	void generarReporte();

};


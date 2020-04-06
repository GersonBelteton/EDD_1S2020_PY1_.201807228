#pragma once
#include <iostream>;
#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <windows.h>;
#include <string.h> ;
#include "ListaPuntaje.h";

using namespace std;
class NodoJugador
{
private:
	string nombre;
	ListaPuntaje* puntajes;
	NodoJugador* izquierda;
	NodoJugador* derecha;

public:
	NodoJugador(string nombre_);
	string getNombre();
	NodoJugador* getIzquierda();
	NodoJugador* getDerecha();
	ListaPuntaje* getPuntajes();

	void setNombre(string nombre_);
	void setIzquierda(NodoJugador* izquierda_);
	void setDerecha(NodoJugador* derecha_);

};


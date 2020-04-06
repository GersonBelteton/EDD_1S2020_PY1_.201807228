#include "NodoJugador.h"

NodoJugador::NodoJugador(string nombre_)
{
	nombre = nombre_;
	puntajes = new ListaPuntaje();
}

string NodoJugador::getNombre()
{
	return nombre;
}

NodoJugador* NodoJugador::getIzquierda()
{
	return izquierda;
}

NodoJugador* NodoJugador::getDerecha()
{
	return derecha;
}

ListaPuntaje* NodoJugador::getPuntajes()
{
	return puntajes;
}

void NodoJugador::setNombre(string nombre_)
{
	nombre = nombre_;
}

void NodoJugador::setIzquierda(NodoJugador* izquierda_)
{
	izquierda = izquierda_;
}

void NodoJugador::setDerecha(NodoJugador* derecha_)
{
	derecha = derecha_;
}

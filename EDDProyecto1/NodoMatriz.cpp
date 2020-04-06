#include "NodoMatriz.h"

NodoMatriz::NodoMatriz(int x_, int y_ , int puntaje_, string letra_)
{
	x = x_;
	y = y_;
	puntaje = puntaje_;
	letra = letra_;
}

string NodoMatriz::getLetra()
{
	return letra;
}

int NodoMatriz::getPuntaje()
{
	return puntaje;
}

int NodoMatriz::getX()
{
	return x;
}

int NodoMatriz::getY()
{
	return y;
}

string NodoMatriz::getIdx()
{
	if (x < 0) {
		return "n" + to_string(x * -1);
	}
	else {
		return to_string(x);
	}
	
}

string NodoMatriz::getIdy()
{
	if (y < 0) {
		return "n" + to_string(y * -1);
	}
	else {
		return to_string(y);
	}
}

NodoMatriz* NodoMatriz::getSiguiente()
{
	return siguiente;
}

NodoMatriz* NodoMatriz::getAnterior()
{
	return anterior;
}

NodoMatriz* NodoMatriz::getArriba()
{
	return arriba;
}

NodoMatriz* NodoMatriz::getAbajo()
{
	return abajo;
}

void NodoMatriz::setLetra(string letra_)
{
	letra = letra_;
}

void NodoMatriz::setPuntaje(int puntaje_)
{
	puntaje = puntaje_;
}

void NodoMatriz::setX(int x_)
{
	x = x_;
}

void NodoMatriz::setY(int y_)
{
	y = y_;
}

void NodoMatriz::setSiguiente(NodoMatriz* siguiente_)
{
	siguiente = siguiente_;
}

void NodoMatriz::setAnterior(NodoMatriz* anterior_)
{
	anterior = anterior_;
}

void NodoMatriz::setArriba(NodoMatriz* arriba_)
{
	arriba = arriba_;
}

void NodoMatriz::setAbajo(NodoMatriz* abajo_)
{
	abajo = abajo_;
}

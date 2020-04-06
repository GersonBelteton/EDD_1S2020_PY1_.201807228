#include "NodoPuntaje.h"

NodoPuntaje::NodoPuntaje(int puntaje_)
{
	puntaje = puntaje_;
}

int NodoPuntaje::getPuntaje()
{
	return puntaje;
}

NodoPuntaje* NodoPuntaje::getSiguiente()
{
	return siguiente;
}

void NodoPuntaje::setPuntaje(int puntaje_)
{
	puntaje = puntaje_;
}

void NodoPuntaje::setSiguiente(NodoPuntaje* siguiente_) {
	siguiente = siguiente_;
}

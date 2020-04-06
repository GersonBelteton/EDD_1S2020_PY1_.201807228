#pragma once
class NodoPuntaje
{

private:
	int puntaje;
	NodoPuntaje* siguiente;
public:
	NodoPuntaje(int puntaje_);

	int getPuntaje();
	NodoPuntaje* getSiguiente();

	void setPuntaje(int puntaje_);
	void setSiguiente(NodoPuntaje* siguiente_);
};


#pragma once
#include <string>;
#include <string>;

using namespace std;
class NodoMatriz
{
private:
	string letra;
	int puntaje;
	int x;
	int y;
	string idx;
	string idy;
	NodoMatriz* siguiente;
	NodoMatriz* anterior;
	NodoMatriz* arriba;
	NodoMatriz* abajo;

public:
	NodoMatriz(int x, int y, int puntaje, string letra);
	string getLetra();
	int getPuntaje();
	int getX();
	int getY();
	string getIdx();
	string getIdy();
	NodoMatriz* getSiguiente();
	NodoMatriz* getAnterior();
	NodoMatriz* getArriba();
	NodoMatriz* getAbajo();

	void setLetra(string letra_);
	void setPuntaje(int puntaje_);
	void setX(int x_);
	void setY(int y_);
	void setSiguiente(NodoMatriz* siguiente_);
	void setAnterior(NodoMatriz* anterior_);
	void setArriba(NodoMatriz* arriba_);
	void setAbajo(NodoMatriz* abajo_);


};


#pragma once
#include "NodoJugador.h";
class ArbolJugador
{

private:
	NodoJugador* raiz;
	ListaPuntaje* score;
	int contador ;
public:
	ArbolJugador();
	bool isEmpty();
	NodoJugador* getRaiz();
	NodoJugador* insertar(string nombre_, NodoJugador* n);
	int isMayor(string mayor, string menor);
	void inOrden(NodoJugador* n);
	void preOrden(NodoJugador* n);
	void posOrden(NodoJugador* n);
	string reporteArbol2(NodoJugador* n, string grafo, int contador);
	string reporteInorden(NodoJugador* n, string grafo, int contador);
	string reportePreorden(NodoJugador* n, string grafo, int contador);
	string reportePosorden(NodoJugador* n, string grafo, int contador);
	void reporte(string reporte);
	void reporteArbol();
	NodoJugador* buscar(string nombre);
	void scoreBoard();
};


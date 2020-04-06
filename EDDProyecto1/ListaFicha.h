#pragma once
#include "Ficha.h";
class ListaFicha
{
private:
	Ficha* primero;
	Ficha* ultimo;
	int size;
	int id;

public:
	ListaFicha();
	bool isEmpty();
	int Size();
	void insertarInicio(char letra, int puntaje);
	Ficha* getPrimero();
	void insertarFinal(char letra, int puntaje);
	Ficha* buscar(int id);
	void eliminarInicio();
	void eliminarFinal();
	void eliminar(int id);
	void mostrarLista();
	void generarReporte();


};


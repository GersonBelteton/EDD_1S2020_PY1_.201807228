#pragma once
#include "listaDobles.h";
class LecturaJSON
{
public:
	void CargarArchivo();
	ListaPalabras getDiccionario();
	listaDobles getDobles();
	listaDobles getTriples();
	int getDimension();


};


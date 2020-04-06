#include"listaDobles.h";
#include "ListaPalabras.h";
#include "LecturaJSON.h";
#include <string>;
#include "JSON.h";
#include <iostream>;
#include <fstream>;
#include <windows.h>;
#include <iostream>;
using json = nlohmann::json;
using namespace std;
static ListaPalabras lp = ListaPalabras();
static listaDobles dobles = listaDobles();
static listaDobles triples = listaDobles();
static int dimensionX;

void LecturaJSON::CargarArchivo()
{

	static int dimensionX;
	static int dimensionY;

	bool estado = true;
	do
	{
		string direccion = "";
		cout << "Escribir direccion de archivo: ";
		cin >> direccion;

		ifstream archivo;

		archivo.open(direccion, ios::in);

		if (!archivo.fail())
		{

			ifstream archivo(direccion);
			json js;
			archivo >> js;

			//TABLERO DIMENSION

			dimensionX = js.at("dimension");
			dimensionY = dimensionX;
			//DICCIONARIO
			for (int i = 0; i < js.at("diccionario").size(); i++)
			{
			
				lp.insertarFinal(js.at("diccionario")[i].at("palabra"));
			}

			//DOBLES
			for (int i = 0; i < js.at("casillas").at("dobles").size(); i++)
			{

				dobles.insertar(js.at("casillas").at("dobles")[i].at("x"), js.at("casillas").at("dobles")[i].at("y"));
			}

			//TRIPLE
			for (int i = 0; i < js.at("casillas").at("triples").size(); i++)
			{

				triples.insertar(js.at("casillas").at("dobles")[i].at("x"), js.at("casillas").at("dobles")[i].at("y"));
			}

		
			cout << "Archivo encontrado \n";
	
			break;
		}
		else {
			
			cout << "Archivo no encontrado \n";
			
			system("pause");
			system("cls");
		}
	} while (estado);
}

ListaPalabras LecturaJSON::getDiccionario() {
	return lp;
}

listaDobles LecturaJSON::getDobles() {
	return dobles;
}

listaDobles LecturaJSON::getTriples() {
	return triples;
}

int LecturaJSON::getDimension() {
	return dimensionX;
}

/*#include"listaDobles.h";
#include "ListaPalabras.h"
#include "LecturaJSON.h"
#include <string>
#include "JSON.h"
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iostream>
using json = nlohmann::json;
using namespace std;
static ListaPalabras lp = ListaPalabras();
static listaDobles dobles = listaDobles();
static listaDobles triples = listaDobles();
static int dimensionX;

void LecturaJSON::CargarArchivo()
{

	static int dimensionX;
	static int dimensionY;
	
	bool estado = true;
	do
	{
		string direccion = "";
		cout << "Escribir direccion de archivo: ";
		cin >> direccion;

		ifstream archivo;

		archivo.open(direccion, ios::in);

		if (!archivo.fail())
		{

			ifstream archivo(direccion);
			json js;
			archivo >> js;

			//TABLERO DIMENSION
			cout << js.at("dimension") << "\n";
			dimensionX = js.at("dimension");
			dimensionY = dimensionX;
			//DICCIONARIO
			for (int i = 0; i < js.at("diccionario").size(); i++)
			{
		
				lp.insertarFinal(js.at("diccionario")[x].at("palabra"));
			}

			//DOBLES
			for (int i = 0; i < js.at("casillas").at("dobles").size(); i++)

				
				dobles.insertar(js.at("casillas").at("dobles")[i].at("x"), js.at("casillas").at("dobles")[i].at("y"));
			}

			//TRIPLE
			for (int i = 0; i < js.at("casillas").at("triples").size(); i++)
			{
				triples.insertar(js.at("casillas").at("dobles")[i].at("x"), js.at("casillas").at("dobles")[i].at("y"));
			}

		
			cout << "Archivo encontrado \n";

			break;
		}
		else {

			cout << "Archivo no encontrado\n";

			system("cls");
		}
	} while (estado);
}

ListaPalabras LecturaJSON::getDiccionario() {
	return lp;
}

listaDobles LecturaJSON::getDobles() {
	return dobles;
}

listaDobles LecturaJSON::getTriples() {
	return triples;
}

int LecturaJSON::getDimension() {
	return dimensionX;
}
*/
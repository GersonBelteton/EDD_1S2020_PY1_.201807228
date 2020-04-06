#include "ListaPuntaje.h"
#include <iostream>;
#include <stdio.h>;
#include <stdlib.h>;
#include <conio.h>;
#include <windows.h>;
#include <string.h> ;
#include <vector>;
#include <fstream>;
#include <string>


using namespace std;
ListaPuntaje::ListaPuntaje()
{
	primero = NULL;
	ultimo = NULL;
	size = 0;
}

bool ListaPuntaje::isEmpty()
{
	return primero == NULL;
}

int ListaPuntaje::Size()
{
	return size;
}

void ListaPuntaje::insertarOrdenado(int puntaje)
{

	NodoPuntaje* nuevo = new NodoPuntaje(puntaje);
	NodoPuntaje* aux = primero;
	NodoPuntaje* temp = aux;
	if (isEmpty()) {
		primero = nuevo;
		ultimo = nuevo;
	}
	else {

		while (aux != NULL) {

			if (puntaje > primero->getPuntaje()) {
				nuevo->setSiguiente(primero);
				primero = nuevo;
				break;
			}
			else if (puntaje < ultimo->getPuntaje()) {
				ultimo->setSiguiente(nuevo);
				ultimo = nuevo;
				break;
			}
			else if (primero == ultimo && puntaje == primero->getPuntaje()) {
				ultimo->setSiguiente(nuevo);
				ultimo = nuevo;
				break;
			}

			else {

				
				if (puntaje < aux->getPuntaje()) {
					temp = aux;
					aux = aux->getSiguiente();
				}
				else {
				
						temp->setSiguiente(nuevo);
						nuevo->setSiguiente(aux);
			
						break;
					
				}
	
			}


		}


	}
}

void ListaPuntaje::mostrarLista()
{
	NodoPuntaje* aux = primero;

	if (isEmpty()) {
		cout << "lista vacia" << endl;
	}
	else {
		while (aux != NULL) {


			cout << aux->getPuntaje()<< " puntaje" << endl;
			aux = aux->getSiguiente();
		}
	}


}

NodoPuntaje* ListaPuntaje::getPrimero()
{
	return primero;
}

void ListaPuntaje::generarReporte()
{

	NodoPuntaje* aux = primero;
	

	int contador = 0;
	ofstream archivo;
	string a = "digraph G {\n node[shape = box];";

	archivo.open("listaPuntaje.txt", ios::out);

	if (archivo.fail()) {
		cout << "no se pudo abrir";
		exit(1);
	}

	while (aux != NULL) {

		a = a + "nodo" + to_string(contador) + "[label = \" " + to_string(aux->getPuntaje()) + "\"];\n";
		contador++;
		cout << "repitewhile"<<endl;
		aux = aux->getSiguiente();
	}

	for (int i = 0; i < contador-1; i++) {
		a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";
		cout << "repitefor" << endl;
	}

	a = a + "}";
	//cout << a;
	archivo << a;

	archivo.close();


	system("dot.exe -Tjpg listaPuntaje.txt -o listaPuntaje.jpg");
	system("listaPuntaje.jpg");
}





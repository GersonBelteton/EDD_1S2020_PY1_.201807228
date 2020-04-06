#include "Matriz.h";
#include <cstddef>;
#include <iostream>;
#include <string>;
#include <vector>;
#include <fstream>;

using namespace std;
Matriz::Matriz()
{
	raiz = new NodoMatriz(-1, -1, 0, "Raiz");
}


NodoMatriz* Matriz::buscarNodo(int x, int y) {

	NodoMatriz* aux = buscarFila(y);

	while (aux != NULL) {

		if (aux->getX() == x) {
			return aux;
		}
		aux = aux->getSiguiente();
	}

	return NULL;
}


void Matriz::eliminar(int x, int y) {

	NodoMatriz* aux = buscarNodo(x, y);

	if (aux->getSiguiente() != NULL && aux->getAbajo() != NULL) {
		aux->getAnterior()->setSiguiente(aux->getSiguiente());
		aux->getSiguiente()->setAnterior(aux->getAnterior());
		aux->getArriba()->setAbajo(aux->getAbajo());
		aux->getAbajo()->setArriba(aux->getArriba());
	}
	else if (aux->getSiguiente() == NULL && aux->getAbajo() != NULL) {
		aux->getAnterior()->setSiguiente(NULL);
		aux->getArriba()->setAbajo(aux->getAbajo());
		aux->getAbajo()->setArriba(aux->getArriba());
	}
	else if (aux->getSiguiente() != NULL && aux->getAbajo() == NULL) {
		aux->getArriba()->setAbajo(NULL);
		aux->getAnterior()->setSiguiente(aux->getSiguiente());
		aux->getSiguiente()->setAnterior(aux->getAnterior());
	}else{
		aux->getAnterior()->setSiguiente(NULL);
		aux->getArriba()->setAbajo(NULL);
	}

}
void Matriz::insertar(int x, int y ,int puntaje, string letra)
{

	NodoMatriz* fila = buscarFila(y);
	NodoMatriz* columna = buscarColumna(x);
	NodoMatriz* nuevo = new NodoMatriz(x, y, puntaje, letra);
	
	if (fila == NULL && columna == NULL) {
		//No hay fila, no hay columna

		//cout << "null null" << endl;
		fila = crearFila(y);
		columna = crearColumna(x);
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
	}
	else if (fila != NULL && columna == NULL) {
		// existe fila, no hay columna
		//cout << " no null null" << endl;
		columna = crearColumna(x);
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
		//cout << "hola";
	}
	else if (fila == NULL && columna != NULL) {
		//no hay fila, existe columna
		//cout << "null no null" << endl;
		fila = crearFila(y);
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
	}
	else if (fila != NULL && columna != NULL) {
		//existe fila, existe columna
		//cout << "no null no null" << endl;
		nuevo = insertarColumnaOrdenada(columna, nuevo);
		nuevo = insertarFilaOrdenada(fila, nuevo);
	}
}

NodoMatriz* Matriz::insertarFilaOrdenada(NodoMatriz* cabezaFila, NodoMatriz* nuevo)
{
	NodoMatriz* aux = cabezaFila;

	while (aux != NULL) {
		//cout << aux->getLetra() << " "<< aux->getX() << aux->getY()<<endl;
		if (aux->getX() == nuevo->getX()) {
			//sobrescribir
			aux->setX(nuevo->getX());
			aux->setLetra(nuevo->getLetra());
			aux->setPuntaje(nuevo->getPuntaje());
			return nuevo;

		}
		else if (aux->getX() > nuevo->getX()) {
			aux->getAnterior()->setSiguiente(nuevo);
			nuevo->setAnterior(aux->getAnterior());
			nuevo->setSiguiente(aux);
			aux->setAnterior(nuevo);
			return nuevo;
		}
		else if (aux->getSiguiente() == NULL) {
			aux->setSiguiente(nuevo);
			nuevo->setAnterior(aux);
			return nuevo;
		}
		else if (aux->getX() < nuevo->getX()) {
			aux = aux->getSiguiente();
		}
		


	}


	return nuevo;
}

NodoMatriz* Matriz::insertarColumnaOrdenada(NodoMatriz* cabezaColumna, NodoMatriz* nuevo)
{
	NodoMatriz* aux = cabezaColumna;

	while (aux != NULL) {
		//cout << aux->getLetra() << " " << aux->getX()<<aux->getY()<< endl;
		if (aux->getY() == nuevo->getY()) {
			//sobrescribir
			aux->setY(nuevo->getY());
			aux->setLetra(nuevo->getLetra());
			aux->setPuntaje(nuevo->getPuntaje());
			return nuevo;

		}
		else if (aux->getY() > nuevo->getY()) {
			aux->getArriba()->setAbajo(nuevo);
			nuevo->setArriba(aux->getArriba());
			nuevo->setAbajo(aux);
			aux->setArriba(nuevo);
			return nuevo;
		}
		else if (aux->getAbajo() == NULL) {
			aux->setAbajo(nuevo);
			nuevo->setArriba(aux);
			return nuevo;
		}
		else if (aux->getY() < nuevo->getY()) {
			aux = aux->getAbajo();
		}



	}
	return nuevo;
}

NodoMatriz* Matriz::buscarFila(int y)
{

	NodoMatriz* aux = raiz;

	while (aux != NULL) {
		if (aux->getY() == y) {
			return aux;
		}

		aux = aux->getAbajo();
	}
	return NULL;
}

NodoMatriz* Matriz::buscarColumna(int x)
{
	NodoMatriz* aux = raiz;

	while (aux != NULL) {
		if (aux->getX() == x) {
			return aux;
		}

		aux = aux->getSiguiente();
	}
	return NULL;
}

NodoMatriz* Matriz::crearColumna(int x)
{
	NodoMatriz* aux = raiz;
	NodoMatriz* columna = insertarFilaOrdenada(aux, new NodoMatriz(x, -1, 0, "c"+to_string(x)));

	return columna;

}

NodoMatriz* Matriz::crearFila(int y)
{
	NodoMatriz* aux = raiz;
	NodoMatriz* fila = insertarColumnaOrdenada(aux, new NodoMatriz(-1, y, 0, "f"+to_string(y)));

	return fila;
}

void Matriz::mostrarMatriz()
{
	NodoMatriz* aux = raiz;
	int contador = 0;

	while (aux != NULL) {
		while (aux != NULL) {

			cout << aux->getLetra() << " "<<aux->getX()<<aux->getY() ;
			aux = aux->getSiguiente();

		}

		cout << endl;
		aux = raiz;
		contador++;

		for (int i = 0; i < contador; i++) {
			aux = aux->getAbajo();
		}

	}

}

void Matriz::generarReporte()
{
	NodoMatriz* aux = raiz;
	int contador = 0;
	string idx = "";
	string idy = "";

	ofstream archivo;


	archivo.open("matriz.txt", ios::out);
	if (archivo.fail()) {
		cout << "no se pudo abrir";
		exit(1);
	}
	string matriz = "digraph G { \n  node [shape=box]\n ";
	matriz += "nodoINV[label = \"inv\" width = 1.5 style = invis];";
	while (aux != NULL) {
		while (aux != NULL) {

		
				matriz += "nodo" + aux->getIdx() + aux->getIdy() + "[label = \"" + aux->getLetra() + "\" width = 1.5 style = filled, fillcolor = lightskyblue];\n";
				

				if (aux->getSiguiente() != NULL) {
					
					if (aux->getAnterior() == NULL) {
						//matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodo" + aux->getSiguiente()->getIdx() + aux->getSiguiente()->getIdy() + "[constraint=false];\n";
					}
					else {
						//matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodo" + aux->getSiguiente()->getIdx() + aux->getSiguiente()->getIdy() + ";\n";
					}
					
			
				}
				
				if (aux->getAnterior() != NULL) {
			
					matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodo" + aux->getAnterior()->getIdx() + aux->getAnterior()->getIdy() + "[constraint=false, dir = both];\n";
				}
				
				if (aux->getArriba() != NULL) {
				//	matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodo" + aux->getArriba()->getIdx() + aux->getArriba()->getIdy()+ ";\n";
				}
				
				if (aux->getAbajo() != NULL) {
					
					matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodo" + aux->getAbajo()->getIdx() + aux->getAbajo()->getIdy() + "[dir = both];\n";
				}
			
			
			aux = aux->getSiguiente();
		}
		aux = raiz;
		contador++;
		for (int i = 0; i < contador; i++) {
			aux = aux->getAbajo();
		}
	}

	contador = 0;
	aux = raiz;
	/*while (aux != NULL) {

		if (aux->getAbajo() == NULL) {
			matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodoINV[style = invis];";
		}

		aux = aux->getAbajo();
	}
	*/

	while (aux != NULL) {
		while (aux != NULL) {
			if (aux->getAbajo() == NULL) {

				matriz += "nodoINV"+aux->getIdx()+"[label = \"inv\", width = 1.5, style = invis];\n";
				matriz += "nodo" + aux->getIdx() + aux->getIdy() + "-> nodoINV" + aux->getIdx()+"[style = invis];\n";
			}

			aux = aux->getAbajo();
		}
		aux = raiz;
		contador++;
		for (int i = 0; i < contador; i++) {
			aux = aux->getSiguiente();
		}
	}

	aux = raiz;
	while (aux != NULL) {

		if (aux->getAnterior() != NULL) {
			matriz += "nodoINV" + aux->getIdx() + "-> nodoINV" + aux->getAnterior()->getIdx() + "[style = invis, constraint = false, dir = both ];\n";
			
		}
		aux = aux->getSiguiente();
	}
	
	aux = raiz;
	contador = 0;
	while (aux != NULL) {
		matriz += "{ rank = same; ";
		while (aux != NULL) {

			matriz += "nodo"+aux->getIdx() + aux->getIdy()+";";
			aux = aux->getSiguiente();
		}

		matriz += "}\n";
		aux = raiz;
		contador++;
		for (int i = 0; i < contador; i++) {
			aux = aux->getAbajo();
		}
	}

	aux = raiz;
	matriz += "{ rank = same; ";
	while (aux != NULL) {
		matriz += "nodoINV" + aux->getIdx() + ";";
		aux = aux->getSiguiente();
	}
	matriz += "}\n";

	matriz += "}";

	//cout << matriz;
	archivo << matriz;

	archivo.close();
	system("dot.exe -Tjpg matriz.txt -o matriz.jpg");
	system("matriz.jpg");
}






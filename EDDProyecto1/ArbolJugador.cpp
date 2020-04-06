#include "ArbolJugador.h";
#include <vector>;
#include <fstream>;
#include <string>;

using namespace std;
ArbolJugador::ArbolJugador()
{
	raiz = NULL;
	score = new ListaPuntaje();
	contador = 0;
}

bool ArbolJugador::isEmpty()
{
	return raiz == NULL;
}

NodoJugador* ArbolJugador::getRaiz()
{
	return raiz;
}



NodoJugador* ArbolJugador::insertar(string nombre_, NodoJugador* n)
{

	if (n == NULL) {
		n = new NodoJugador(nombre_);
		if (isEmpty()) {
			raiz = n;
		}
		
		//cout << "null";
	}
	else if (isMayor(nombre_, n->getNombre()) == 1) {
		//cout << "derecha";
		n->setDerecha(insertar(nombre_, n->getDerecha()));
	}
	else if(isMayor(nombre_, n->getNombre())==-1){
		//cout << "izquierda";
		n->setIzquierda(insertar(nombre_, n->getIzquierda()));
	}
	else {
		// iguales 
		cout << "error, ya existe ese nombre"<<endl;
	}
	return n ;
}





int ArbolJugador::isMayor(string mayor, string menor)
{
	//0 iguales, 1 mayor, -1 menor
	
	int asciiMayor = 0;
	int asciiMenor = 0;
	int limite;
	
	if (mayor.length() <= menor.length()) {
		limite = mayor.length();
	}
	else {
		limite = menor.length();
	}
		
		for (int j = 0; j < limite; j++) {
			asciiMayor = mayor[j];
			asciiMenor = menor[j];

			if (asciiMayor > asciiMenor) {
				return 1;
			}
			else if (asciiMayor < asciiMenor) {
				return -1;
			}
			else {
				
			}
		}
	if (mayor.length() > menor.length()) {
		return 1;
	}
	else if(mayor.length() < menor.length()){
		return -1;
	}
	else {
		return 0;
	}
}

void ArbolJugador::inOrden(NodoJugador* n)
{
	if (n != NULL) {
		inOrden(n->getIzquierda());
		cout << n->getNombre() << endl;
		inOrden(n->getDerecha());
	}

}

void ArbolJugador::preOrden(NodoJugador* n)
{
	if (n != NULL) {
		cout << n->getNombre()<<endl;
		preOrden(n->getIzquierda());
		preOrden(n->getDerecha());
	}

}

void ArbolJugador::posOrden(NodoJugador* n)
{
	if (n != NULL) {
		posOrden(n->getIzquierda());
		posOrden(n->getDerecha());
		cout << n->getNombre() << endl;

	}
}

string ArbolJugador::reporteArbol2(NodoJugador* n, string grafo, int contador) {

	if (n != NULL) {
		cout << n->getNombre() << endl;	



		grafo = grafo + "nodo" + n->getNombre() + "[label = \" " + n->getNombre() + "\"];\n";

		if (n->getIzquierda() != NULL) {
			grafo = grafo + "nodo" + n->getIzquierda()->getNombre() + "[label = \" " + n->getIzquierda()->getNombre() + "\"];\n";
			grafo = grafo + "nodo" + n->getNombre() + "->nodo" + n->getIzquierda()->getNombre() + ";\n";
		}
		if (n->getDerecha() != NULL) {
			grafo = grafo + "nodo" + n->getDerecha()->getNombre() + "[label = \" " + n->getDerecha()->getNombre() + "\"];\n";
			grafo = grafo + "nodo" + n->getNombre() + "->nodo" + n->getDerecha()->getNombre() + ";\n";
		}



		grafo = reporteArbol2(n->getIzquierda(), grafo, contador);
		grafo = reporteArbol2(n->getDerecha(), grafo, contador);
	}

	return grafo;
}
string ArbolJugador::reporteInorden(NodoJugador* n, string grafo, int contador2) {

	if (n != NULL) {

		grafo = reporteInorden(n->getIzquierda(), grafo, contador);
		grafo = grafo + "nodo" + to_string(contador) + "[label = \" " + n->getNombre() + "\"];\n";
		contador++;
		cout << n->getNombre() << endl;
		grafo = reporteInorden(n->getDerecha(), grafo, contador);
	}
	return grafo;
}


string ArbolJugador::reportePreorden(NodoJugador* n, string grafo, int contador2) {

	if (n != NULL) {
		grafo = grafo + "nodo" + to_string(contador) + "[label = \" " + n->getNombre() + "\"];\n";
		contador++;
		cout << n->getNombre() << endl;
		grafo = reportePreorden(n->getIzquierda(), grafo, contador);
		grafo = reportePreorden(n->getDerecha(), grafo, contador);
	}
	return grafo;
}

string ArbolJugador::reportePosorden(NodoJugador* n, string grafo, int contador2) {

	if (n != NULL) {

		grafo = reportePosorden(n->getIzquierda(), grafo, contador);
		grafo = reportePosorden(n->getDerecha(), grafo, contador);
		grafo = grafo + "nodo" + to_string(contador) + "[label = \" " + n->getNombre() + "\"];\n";
		contador++;
		cout << n->getNombre() << endl;
	}
	return grafo;
}
void ArbolJugador::reporte(string rep) {

	NodoJugador* aux = raiz;

	
	ofstream archivo;
	string a = "digraph G {\n node[shape = box];";

	if (rep == "in") {
		archivo.open("reporteInorden.txt", ios::out);

		if (archivo.fail()) {
			cout << "no se pudo abrir";
			exit(1);
		}

		a = reporteInorden(raiz, a, contador);

		for (int i = 0; i < contador - 1; i++) {
			a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";
		}
		a = a + "}";

		cout << a;
		archivo << a;
		archivo.close();

		system("dot.exe -Tjpg reporteInorden.txt -o reporteInorden.jpg");
		system("reporteInorden.jpg");
	}
	else if (rep == "pre") {
		archivo.open("reportePreorden.txt", ios::out);

		if (archivo.fail()) {
			cout << "no se pudo abrir";
			exit(1);
		}

		a = reportePreorden(raiz, a, contador);

		for (int i = 0; i < contador - 1; i++) {
			a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";
		}
		a = a + "}";

		cout << a;
		archivo << a;
		archivo.close();

		system("dot.exe -Tjpg reportePreorden.txt -o reportePreorden.jpg");
		system("reportePreorden.jpg");
	}
	else if (rep == "pos") {
		archivo.open("reportePosorden.txt", ios::out);

		if (archivo.fail()) {
			cout << "no se pudo abrir";
			exit(1);
		}

		a = reportePosorden(raiz, a, contador);

		for (int i = 0; i < contador - 1; i++) {
			a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";
		}
		a = a + "}";

		cout << a;
		archivo << a;
		archivo.close();

		system("dot.exe -Tjpg reportePosorden.txt -o reportePosorden.jpg");
		system("reportePosorden.jpg");
	}

	contador = 0;

}

void ArbolJugador::reporteArbol()
{

	NodoJugador* aux = raiz;

	int contador = 0;
	ofstream archivo;
	string a = "digraph G {\n ";

	archivo.open("reporteArbol2.txt", ios::out);

	if (archivo.fail()) {
		cout << "no se pudo abrir";
		exit(1);
	}

	a = reporteArbol2(aux, a, 0);
	a = a + "}";
	
	cout << a;
	archivo << a;
	archivo.close();

	system("dot.exe -Tjpg reporteArbol2.txt -o reporteArbol2.jpg");
	system("reporteArbol2.jpg");
	/*
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
		aux = aux->getSiguiente();
	}

	for (int i = 0; i < contador-1; i++) {
		a = a + "nodo" + to_string(i) + "->nodo" + to_string(i + 1) + ";\n";

	}

	a = a + "}";
	//cout << a;
	archivo << a;

	archivo.close();


	system("dot.exe -Tjpg listaPuntaje.txt -o listaPuntaje.jpg");
	system("listaPuntaje.jpg");
	*/

}



NodoJugador* ArbolJugador::buscar(string nombre)
{
	if (isEmpty()) {
		cout << "Arbol de jugadores vacio";
	}
	else {
		NodoJugador* aux = raiz;

		while (aux != NULL) {
			if (nombre == aux->getNombre()) {
				return aux;
			}
			else {
				if (isMayor(nombre, aux->getNombre())==1) {
					aux = aux->getDerecha();
				}
				else if (isMayor(nombre, aux->getNombre()) == -1) {
					aux = aux->getIzquierda();
				}
			}
		


		}

	}


	return NULL;
}

void ArbolJugador::scoreBoard()
{
	
	score->insertarOrdenado(6);


}

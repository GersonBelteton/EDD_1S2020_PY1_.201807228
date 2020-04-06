#include <fstream>;
#include <iostream>;
#include "ColaFicha.h";
#include "ListaPalabras.h";
#include "ListaPuntaje.h";
#include "ListaFicha.h";
#include <windows.h>;
#include "ArbolJugador.h";
#include "Matriz.h";
#include <string>;
#include "LecturaJSON.h";
#include <stdlib.h>;
#include <time.h>;
using namespace std;

void leerArchivo();
void menu();
void menuJuego();
void llenarCola();
void agregarJugador();
void jugar();
void menuReportes();
bool buscarPalabra(string);
bool isDoble(int, int);
bool isTriple(int, int);

ListaPuntaje sc = ListaPuntaje();
LecturaJSON lj;
ColaFicha cf;
ArbolJugador aj;
int main()
{
	menu();

	system("pause");
}

void menu() {
	int opcion = 0;
	do {
		system("cls");
		cout << "1. Lectura de Archivo" << endl;
		cout << "2. Juego" << endl;
		cout << "3. Reportes " << endl;
		cout << "4. Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1:
			leerArchivo();
			menu();
			break;

		case 2:
			menuJuego();
			menu();
			break;

		case 3:
			menuReportes();
			menu();
			break;

		case 4:
			break;
		}

		//system("cls");
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4);
}
void leerArchivo() {

	lj.CargarArchivo();
	lj.getDiccionario().mostrarLista();
	_getch();
	
}

void menuJuego() {
	int opcion = 0;
	do {
		system("cls");
		cout << "1. Agruegar nuevo jugador" << endl;
		cout << "2. Iniciar juego" << endl;
		cout << "3. Regresar" << endl;

		cin >> opcion;

		switch (opcion) {
			case 1:
				agregarJugador();
				menuJuego();
				break;
			case 2:
				jugar();
				menuJuego();
				break;
			case 3:
				//menu();
				break;

		}
	} while (opcion != 1 && opcion != 2 && opcion != 3);



}

void menuReportes() {
	int opcion = 0;
	string nombre = "";
	do {
		system("cls");
		cout << "1. Diccionario" << endl;
		cout << "2. Arbol de jugadores" << endl;
		cout << "3. Jugadores pre-orden" << endl;
		cout << "4. Jugadores in-orden" << endl;
		cout << "5. Jugadores pos-orden" << endl;
		cout << "6. Cola de fichas" << endl;
		cout << "7. Puntaje por jugador" << endl;
		cout << "8. Score Board" << endl;
		cout << "9. Regresar" << endl;

		cin >> opcion;
		switch (opcion) {
			case 1:
				lj.getDiccionario().generarReporte();
				menuReportes();
				break;
			case 2:
				aj.reporteArbol();
				menuReportes();
				break;
			case 3:
				aj.reporte("pre");
				menuReportes();
				break;
			case 4:
				aj.reporte("in");
				menuReportes();
				break;
			case 5:
				aj.reporte("pos");
				menuReportes();
				break;
			case 6:
				cf.generarReporte();
				menuReportes();
				break;
			case 7:


				cout << "Escribe el nombre del jugador " << endl;
				aj.preOrden(aj.getRaiz());
				
				cin >> nombre;

				aj.buscar(nombre)->getPuntajes()->generarReporte();
				break;
			case 8:
				sc.generarReporte();
				break;
			case 9:
				break;
		}
	} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 4 && opcion != 5 && opcion != 6 && opcion != 7 && opcion != 8 && opcion != 9);


}

void llenarListaSC() {

}

void agregarJugador() {
	string nombre = "";
	cout << "Introduce el nombre del jugador" << endl;
	cin >> nombre;

	aj.insertar(nombre, aj.getRaiz());
	
	_getch();
}

void jugar() {
	string nombre = "";
	string palabra = "";
	int x = 0;
	int y = 0;
	int sumaPuntos = 0;
	int puntosJ1 = 0;
	int puntosJ2 = 0;
	int xIN = 0;
	int yIN = 0;
	bool repetir = false;
	bool finJuego = false;
	bool validado = false;
	bool primerFicha = true;
	llenarCola();
	///cf.mostrarCola();
	NodoJugador* j [2];
	do {
		for (int i = 0; i < 2; i++) {
			cout << "Seleccionar al jugador " + to_string(i+1) << endl;
			aj.preOrden(aj.getRaiz());
			cout << endl;
			cin >> nombre;
			j[i] = aj.buscar(nombre);
			if (j[i] == NULL) {
				"Jugador no encontrado";
				repetir = true;
				break;
			}
			else {
				repetir = false;
			}
		
		}

		
	} while (repetir);

	ListaFicha l1;
	ListaFicha l2;
	for (int i = 0; i < 7; i++) {
		Ficha* f = cf.dequeue();
		l1.insertarFinal(f->getLetra(), f->getPuntaje());
	}
	for (int i = 0; i < 7; i++) {
		Ficha* f = cf.dequeue();
		l2.insertarFinal(f->getLetra(), f->getPuntaje());
	}

	cout << "se ha repartido 7 fichas a cada jugador" << endl;
	_getch();
	Matriz m;
	Ficha* f;
	string s = "";
	int opcion = 0;
	int selectJ = 0;
	int ficha = 0;

	do {

		validado = false;
		system("cls");
		
		primerFicha = true;
		
		do {
			cout << "Turno de " << j[selectJ]->getNombre() << endl;
			cout << "Puntos de " << j[0]->getNombre() << ": " << puntosJ1<< endl;
			cout << "Puntos de " << j[1]->getNombre() << ": " << puntosJ2 << endl;
			cout << "------------------------------------------------------------------------------------------"<<endl;
			cout << "1. jugar" << endl;
			cout << "2. validar" << endl;
			cout << "3. Cambiar fichas" << endl;
			cout << "4. Reportes" << endl;
			cout << "5. terminar juego" << endl;
			cin >> opcion;
			palabra = "";
			switch (opcion) {
			case 1:


				if (selectJ == 0) {
					l1.generarReporte();
				}
				else {
					l2.generarReporte();
				}

				do {
					cout << "seleccionar ficha" << endl;
					cin >> ficha;
					if (selectJ == 0) {
						f = l1.buscar(ficha);
						l1.eliminar(ficha);
					}
					else {
						f = l2.buscar(ficha);
						l2.eliminar(ficha);

					}
				} while (f == NULL);


				cout << "coordenada x: " << endl;
				cin >> x;
				cout << "coordenada y: " << endl;
				cin >> y;

				if (primerFicha) {
					xIN = x;
					yIN = y;
					primerFicha = false;
				}
				s += f->getLetra();
				m.insertar(x, y, f->getPuntaje(), s);
				s = "";

				//system("taskill/F/IM matriz.jpg");
				m.generarReporte();

				break;

			case 2:


				if (x == xIN) {
					//vertical
					NodoMatriz* temp = m.buscarNodo(xIN, yIN);
					NodoMatriz* inicio = NULL;
					while (temp != NULL) {
						if (temp->getArriba()->getY() > -1) {
							if (temp->getArriba()->getY() == temp->getY() - 1) {
								temp = temp->getArriba();
							}
							else {
								inicio = temp;
								break;
							}
						}
						else {
							inicio = temp;
							break;
						}
						inicio = temp;
					}

					while (temp != NULL) {
						palabra += temp->getLetra();
						if (temp->getAbajo() == NULL) {
							break;
						}
						if (temp->getAbajo()->getY() != temp->getY() + 1) {
							break;
						}

						temp = temp->getAbajo();
					}

					if (buscarPalabra(palabra)) {
						cout << "palabra valida" << endl;

						while (inicio != NULL) {
							if (isDoble(inicio->getX(), inicio->getY())) {
								inicio->setPuntaje(inicio->getPuntaje() * 2);
							}
							else if (isTriple(inicio->getX(), inicio->getY())) {
								inicio->setPuntaje(inicio->getPuntaje() * 3);
							}
							sumaPuntos += inicio->getPuntaje();
							if (inicio->getAbajo() != NULL) {
								if (inicio->getAbajo()->getY() != inicio->getY() + 1) {
									break;
								}
							}
							else {
								break;
							}

							inicio = inicio->getAbajo();
						}

						if (selectJ == 0) {
							puntosJ1 += sumaPuntos;
							sumaPuntos = 0;
						}
						else {
							puntosJ2 += sumaPuntos;
							sumaPuntos = 0;
						}

					}
					else {
						cout << "palabra no encontrada" << endl;

						for (int i = yIN; i <= y; i++) {
							m.eliminar(xIN, i);
						}
					}

					_getch();

				}
				else if (y == yIN) {
					//horizontal

					NodoMatriz* temp = m.buscarNodo(xIN, yIN);
					NodoMatriz* inicio = NULL;
					while (temp != NULL) {
						if (temp->getAnterior()->getX() > -1) {
							if (temp->getAnterior()->getX() == temp->getX() - 1) {
								temp = temp->getAnterior();
							}
							else {
								inicio = temp;
								break;
							}
						}
						else {
							inicio = temp;
							break;
						}
						inicio = temp;
					}

					while (temp != NULL) {
						palabra += temp->getLetra();
						if (temp->getSiguiente() == NULL) {
							break;
						}
						if (temp->getSiguiente()->getX() != temp->getX() + 1) {
							break;
						}

						temp = temp->getSiguiente();
					}
					cout << palabra << endl;
					if (buscarPalabra(palabra)) {

						cout << "palabra valida" << endl;

						while (inicio != NULL) {
							if (isDoble(inicio->getX(), inicio->getY())) {
								inicio->setPuntaje(inicio->getPuntaje() * 2);
							}
							else if (isTriple(inicio->getX(), inicio->getY())) {
								inicio->setPuntaje(inicio->getPuntaje() * 3);
							}
							sumaPuntos += inicio->getPuntaje();
							if (inicio->getSiguiente() != NULL) {
								if (inicio->getSiguiente()->getX() != inicio->getX() + 1) {
									break;
								}
							}
							else {
								break;
							}

							inicio = inicio->getSiguiente();
						}

						if (selectJ == 0) {

							puntosJ1 += sumaPuntos;
							sumaPuntos = 0;
						}
						else {
							puntosJ2 += sumaPuntos;
							sumaPuntos = 0;
						}
					}
					else {
						cout << "palabra no encontrada" << endl;

						for (int i = xIN; i <= x; i++) {
							m.eliminar(i, yIN);
						}

					}

					_getch();
				}



				validado = true;
				if (selectJ == 0) {
					selectJ = 1;
				}
				else {
					selectJ = 0;
				}
				break;
			case 3:
				if (selectJ == 0) {
					Ficha* aux = l1.getPrimero();
					while (aux != NULL) {
						cf.enqueue(aux->getLetra(), aux->getPuntaje());
						//l1.eliminar(aux->getId());
						aux = aux->getSiguiente();
					}

					while (!l1.isEmpty()) {
						l1.eliminarFinal();
					}

					for (int i = 0; i < 7; i++) {
						Ficha* f = cf.dequeue();
						l1.insertarFinal(f->getLetra(), f->getPuntaje());
					}
				}
				else {
					Ficha* aux = l2.getPrimero();
					while (aux != NULL) {
						cf.enqueue(aux->getLetra(), aux->getPuntaje());
						//l2.eliminar(aux->getId());
						aux = aux->getSiguiente();
					}

					while (!l2.isEmpty()) {
						l2.eliminarFinal();
					}
					for (int i = 0; i < 7; i++) {
						Ficha* f = cf.dequeue();
						l2.insertarFinal(f->getLetra(), f->getPuntaje());
					}
				}



				break;
			case 4:

				menuReportes();


				break;
			case 5:
				aj.buscar(j[0]->getNombre())->getPuntajes()->insertarOrdenado(puntosJ1);
				//	j[0]->getPuntajes()->insertarOrdenado(puntosJ1);
				sc.insertarOrdenado(aj.buscar(j[0]->getNombre())->getPuntajes()->getPrimero()->getPuntaje());

				aj.buscar(j[1]->getNombre())->getPuntajes()->insertarOrdenado(puntosJ2);
				//j[1]->getPuntajes()->insertarOrdenado(puntosJ2);
				sc.insertarOrdenado(aj.buscar(j[1]->getNombre())->getPuntajes()->getPrimero()->getPuntaje());

				if (puntosJ1 > puntosJ2) {
					cout << "Ha ganado " + j[0]->getNombre() << endl;

				}
				else if (puntosJ2 > puntosJ1) {
					cout << "Ha ganado " + j[1]->getNombre() << endl;
				}
				else {
					cout << "Empate" << endl;
				}
				_getch();
				finJuego = true;
				validado = true;
				break;
			}

			system("cls");
		} while (!validado);
		
	} while (!finJuego);











}

bool buscarPalabra(string palabra) {

	NodoPalabra* aux = lj.getDiccionario().getPrimero();


		do {
			if (aux->getPalabra() == palabra) {
				return true;
			}

			aux = aux->getSiguiente();
		} while (aux != lj.getDiccionario().getPrimero());

	

	return false;
}

bool isDoble(int x, int y) {
	NodoDobles* aux = lj.getDobles().getPrimero();

	while (aux != NULL) {

		if (aux->getX() == x && aux->getY() == y) {
			return true;
		}
		aux = aux->getSiguiente();
	}

	return false;
}
bool isTriple(int x, int y) {
	NodoDobles* aux = lj.getTriples().getPrimero();

	while (aux != NULL) {

		if (aux->getX() == x && aux->getY() == y) {
			return true;
		}
		aux = aux->getSiguiente();
	}

	return false;
}

void llenarCola() {
	
	int num = 0;
	srand(time(NULL));
	num = rand();
	int contadorA = 7;
	int contador[25];

	for (int i = 0; i < 25; i++) {
		if (i == 0 || i == 1) {
			contador[i] = 12;//a, e
		}
		else if (i == 2) {
			contador[i] = 9;// o
		}
		else if (i == 3 || i == 4) {
			contador[i] = 6;//i, s
		}
		else if (i == 5 || i == 7 || i == 8 || i == 10) {
			contador[i] = 5;//n, r, u, d
		}
		else if (i == 6 || i == 9 || i == 12) {
			contador[i] = 4;//l, t, c
		}
		else if (i == 11 || i == 13 || i == 14 || i == 15 || i == 16) {
			contador[i] = 2;//g, b, m, p, h
		}
		else if (i == 17 || i == 18 || i == 19 || i == 20 || i == 21 || i == 22 || i == 23 || i == 24) {
			contador[i] = 1;//f, v, y, q, j, ñ, x, z
		}
			
		 
	}
	cf.enqueue('h', 3);
	cf.enqueue('o', 3);
	cf.enqueue('l', 3);
	cf.enqueue('a', 3);
	cf.enqueue('h', 3);
	cf.enqueue('o', 3);
	cf.enqueue('l', 3);
	cf.enqueue('a', 3);
	cf.enqueue('h', 3);
	cf.enqueue('o', 3);
	cf.enqueue('l', 3);
	cf.enqueue('a', 3);
	for (int i = 0; i < 95; i++) {
		num = rand() % 25;

		switch (num) {
			case 0:
				if (contador[0] > 0) {
					cf.enqueue('a', 1);
					contador[0]--;
				}
				else {
					i--;
				}
				
				break;
			case 1:
				if (contador[1] > 0) {
					cf.enqueue('e', 1);
					contador[1]--;
				}
				else {
					i--;
				}
				break;
			case 2:
				if (contador[2] > 0) {
					cf.enqueue('o', 1);
					contador[2]--;
				}
				else {
					i--;
				}
				break;
			case 3:
				if (contador[3] > 0) {
					cf.enqueue('i', 1);
					contador[3]--;
				}
				else {
					i--;
				}
				break;
			case 4:
				if (contador[4] > 0) {
					cf.enqueue('s', 1);
					contador[4]--;
				}
				else {
					i--;
				}
				break;
			case 5:
				if (contador[5] > 0) {
					cf.enqueue('n', 1);
					contador[5]--;
				}
				else {
					i--;
				}
				break;
			case 6:
				if (contador[6] > 0) {
					cf.enqueue('l', 1);
					contador[6]--;
				}
				else {
					i--;
				}
				break;
			case 7:
				if (contador[7] > 0) {
					cf.enqueue('r', 1);
					contador[7]--;
				}
				else {
					i--;
				}
				break;
			case 8:
				if (contador[8] > 0) {
					cf.enqueue('u', 1);
					contador[8]--;
				}
				else {
					i--;
				}
				break;
			case 9:
				if (contador[9] > 0) {
					cf.enqueue('t', 1);
					contador[9]--;
				}
				else {
					i--;
				}
				break;
			case 10:
				if (contador[10] > 0) {
					cf.enqueue('d', 2);
					contador[10]--;
				}
				else {
					i--;
				}
				break;
			case 11:
				if (contador[11] > 0) {
					cf.enqueue('g', 2);
					contador[11]--;
				}
				else {
					i--;
				}
				break;
			case 12:
				if (contador[12] > 0) {
					cf.enqueue('c', 3);
					contador[12]--;
				}
				else {
					i--;
				}
				break;
			case 13:
				if (contador[13] > 0) {
					cf.enqueue('b', 3);
					contador[13]--;
				}
				else {
					i--;
				}
				break;
			case 14:
				if (contador[14] > 0) {
					cf.enqueue('m', 3);
					contador[14]--;
				}
				else {
					i--;
				}
				break;
			case 15:
				if (contador[15] > 0) {
					cf.enqueue('p', 3);
					contador[15]--;
				}
				else {
					i--;
				}
				break;
			case 16:
				if (contador[16] > 0) {
					cf.enqueue('h', 4);
					contador[16]--;
				}
				else {
					i--;
				}
				break;
			case 17:
				if (contador[17] > 0) {
					cf.enqueue('f', 4);
					contador[17]--;
				}
				else {
					i--;
				}
				break;
			case 18:
				if (contador[18] > 0) {
					cf.enqueue('v', 4);
					contador[18]--;
				}
				else {
					i--;
				}
				break;
			case 19:
				if (contador[19] > 0) {
					cf.enqueue('y', 4);
					contador[19]--;
				}
				else {
					i--;
				}
				break;
			case 20:
				if (contador[20] > 0) {
					cf.enqueue('q', 5);
					contador[20]--;
				}
				else {
					i--;
				}
				break;
			case 21:
				if (contador[21] > 0) {
					cf.enqueue('j', 8);
					contador[21]--;
				}
				else {
					i--;
				}
				break;
			case 22:
				if (contador[22] > 0) {
					cf.enqueue('ñ', 8);
					contador[22]--;
				}
				else {
					i--;
				}
				break;
			case 23:
				if (contador[23] > 0) {
					cf.enqueue('x', 8);
					contador[23]--;
				}
				else {
					i--;
				}
				break;
			case 24:
				if (contador[24] > 0) {
					cf.enqueue('z', 10);
					contador[24]--;
				}
				else {
					i--;
				}
				break;



		}




	}

}



	



/*std::cout << "Hello World!\n";

	json j3;


	cout << "----------------------- Matriz-----------------------------"<<endl<<endl;


	Matriz m = Matriz();

	/*m.insertar(0, 0, 1, "Y");
	m.insertar(0, 5, 1, "A");
	m.insertar(1, 5, 1, "Z");
	m.insertar(6, 10, 4, "M");
	m.insertar(7, 10, 3, "k");
	m.insertar(8, 11, 4, "n");
	//m.insertar(20, 30, 7, "M");
	m.insertar(7, 0, 5, "S");
	m.insertar(6, 30, 4, "g");
	m.insertar(20, 11, 4, "e");
//	m.insertar(20, 5, 4, "j");
	//m.insertar(20, 9, 3, "d");
	//m.insertar(3, 40, 3, "h");
	m.insertar(0, 10, 3, "j");
	m.mostrarMatriz();
	m.generarReporte();
	

int x = 0;
int y = 0;
string let = "";

do {
	cout << "coordenada x: ";
	cin >> x;
	cout << endl;
	cout << "coordenada y: ";
	cin >> y;
	cout << endl;
	cout << "letra: ";
	cin >> let;


	m.insertar(x, y, 1, let);
	m.generarReporte();

} while (let != "*");





ColaFicha cf = ColaFicha();

cf.enqueue('a', 9);
cf.enqueue('b', 9);
cf.enqueue('c', 9);
cf.enqueue('d', 9);

cf.mostrarCola();
//cf.generarReporte();

ListaFicha lf = ListaFicha();

lf.insertarFinal('a', 5);
lf.insertarFinal('b', 6);
lf.insertarFinal('a', 5);
lf.insertarFinal('b', 6);
lf.mostrarLista();
//lf.generarReporte();


ListaPalabras lp = ListaPalabras();

lp.insertarFinal("hola");
lp.insertarFinal("adios");


lp.mostrarLista();
//	lp.generarReporte();


ArbolJugador aj = ArbolJugador();
ListaPuntaje sc = ListaPuntaje();
aj.insertar("luis", aj.getRaiz());
aj.insertar("mario", aj.getRaiz());
aj.insertar("juan", aj.getRaiz());
aj.insertar("jorge", aj.getRaiz());
aj.insertar("raul", aj.getRaiz());
aj.insertar("alejandro", aj.getRaiz());
aj.insertar("felipe", aj.getRaiz());
aj.insertar("enrique", aj.getRaiz());
aj.insertar("manuel", aj.getRaiz());
aj.insertar("pablo", aj.getRaiz());
aj.insertar("pedro", aj.getRaiz());

//aj.reporteArbol();
///aj.reporte("in");

aj.preOrden(aj.getRaiz());

aj.buscar("luis")->getPuntajes()->insertarOrdenado(3);
aj.buscar("luis")->getPuntajes()->insertarOrdenado(6);
aj.buscar("luis")->getPuntajes()->insertarOrdenado(4);
aj.buscar("luis")->getPuntajes()->insertarOrdenado(8);
sc.insertarOrdenado(aj.buscar("luis")->getPuntajes()->getPrimero()->getPuntaje());
//aj.buscar("luis")->getPuntajes()->generarReporte();

aj.buscar("juan")->getPuntajes()->insertarOrdenado(3);
aj.buscar("juan")->getPuntajes()->insertarOrdenado(4);
aj.buscar("juan")->getPuntajes()->insertarOrdenado(1);
aj.buscar("juan")->getPuntajes()->insertarOrdenado(8);
aj.buscar("juan")->getPuntajes()->insertarOrdenado(9);
sc.insertarOrdenado(aj.buscar("juan")->getPuntajes()->getPrimero()->getPuntaje());

aj.buscar("pedro")->getPuntajes()->insertarOrdenado(3);
sc.insertarOrdenado(aj.buscar("pedro")->getPuntajes()->getPrimero()->getPuntaje());

//sc.generarReporte();

//scoreBoard.insertarOrdenado(lpun2.getPrimero()->getPuntaje());

//scoreBoard.insertarOrdenado(lpun3.getPrimero()->getPuntaje());

//scoreBoard.generarReporte();
//	aj.reportePuntaje("pedro");
	//aj.reportePuntaje("luis");*/


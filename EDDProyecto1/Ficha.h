#pragma once
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

using namespace std;
class Ficha
{

	
private:
	char letra;
	int puntaje;
	int id;
	Ficha* siguiente;
	Ficha* anterior;


public:
	 Ficha(char letra_, int puntaje_, int id_) {
		letra = letra_;
		puntaje = puntaje_;
		id = id_;
	}

	 Ficha(char letra_, int puntaje_) {
		 letra = letra_;
		 puntaje = puntaje_;
	 }

	 char getLetra() {
		 return letra;
	 }

	 int getPuntaje() {
		 return puntaje;
	 }

	 int getId() {
		 return id;
	 }

	 Ficha* getSiguiente() {
		 return siguiente;
	 }

	 Ficha* getAnterior() {
		 return anterior;
	 }


	 void setLetra(char letra_) {
		 letra = letra_;
	 }

	 void setPuntaje(int puntaje_) {
		 puntaje = puntaje_;
	 }

	 void setaId(int id_) {
		  id = id_;
	 }

	 void setSiguiente(Ficha* siguiente_) {
		 siguiente = siguiente_;
	 }

	 void setAnterior(Ficha* anterior_) {
		 anterior = anterior_;
	 }

	



};


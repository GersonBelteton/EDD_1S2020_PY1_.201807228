#pragma once
class NodoDobles
{

private:
	int x;
	int y;

	NodoDobles* siguiente;

public:

	NodoDobles(int x_, int y_) {
		x = x_;
		y = y_;
	}

	int getX() {
		return x;
	}

	int getY() {
		return y;
	}

	NodoDobles* getSiguiente() {
		return siguiente;
	}

	void setX(int x_) {
		x = x_;
	}

	void setY(int y_) {
		y = y_;
	}

	void setSiguiente(NodoDobles* siguiente_) {
		siguiente = siguiente_;
	}

};


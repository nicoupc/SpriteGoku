#pragma once
using namespace System;
using namespace System::Drawing;

ref class CEnemigo {
protected:
	int x, y;
	int ancho, alto;
	int indiceX = 0;
	int indiceY = 2; // Comenzamos hacia la derecha
	int pasos = 0;
	int direccion = 0; // 0: derecha, 1: izquierda
	int escalaAncho = 64;
	int escalaAlto = 96;
	Bitmap^ sprite;

public:
	CEnemigo(String^ ruta, int px, int py) {
		sprite = gcnew Bitmap(ruta);
		ancho = sprite->Width / 4;
		alto = sprite->Height / 4;
		x = px;
		y = py;
	}

	virtual void mover() {} // método virtual, pero NO puro

	void dibujar(Graphics^ g) {
		Rectangle origen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle destino = Rectangle(x, y, escalaAncho, escalaAlto);
		g->DrawImage(sprite, destino, origen, GraphicsUnit::Pixel);
		g->DrawRectangle(gcnew Pen(Color::Red), obtenerRectangulo());

	}

	Rectangle obtenerRectangulo() {
		return Rectangle(x + 15, y + 15, (ancho * 2) - 30, (alto * 2) - 30);
	}
};

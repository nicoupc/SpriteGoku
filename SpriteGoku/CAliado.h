#pragma once

using namespace System;
using namespace System::Drawing;

ref class CAliado {
protected:
	int x, y;
	int ancho, alto;
	int escalaAncho = 64;
	int escalaAlto = 96;
	int indiceX = 0;
	int indiceY = 0;
	Bitmap^ sprite;
	bool visible = true;
	bool enReaparicion = false;
	bool enParpadeo = false;

	int contadorReaparicion = 0;
	int tiempoEspera = 200;     // 10 segundos si el timer es de 16 ms
	int tiempoParpadeo = 10;    // 1 segundo de parpadeo

public:
	CAliado(String^ ruta, int px, int py) {
		sprite = gcnew Bitmap(ruta);
		ancho = sprite->Width / 4;
		alto = sprite->Height / 4;
		x = px;
		y = py;
	}

	virtual void mover() {
		if (enReaparicion) {
			contadorReaparicion++;
			visible = (contadorReaparicion / 3) % 2 == 0;

			if (contadorReaparicion >= tiempoEspera) {
				enReaparicion = false;
				visible = true;
				contadorReaparicion = 0;
			}
			return;
		}
	}
	virtual void aplicarEfecto(int% vidas) = 0; // cada aliado define su efecto

	virtual void dibujar(Graphics^ g) {
		if (!visible) return;

		Rectangle origen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle destino = Rectangle(x, y, escalaAncho, escalaAlto);
		g->DrawImage(sprite, destino, origen, GraphicsUnit::Pixel);

		// Para depurar colisión
		//g->DrawRectangle(gcnew Pen(Color::Red), obtenerRectangulo());
	}

	virtual Rectangle obtenerRectangulo() {
		return Rectangle(x + 15, y + 15, escalaAncho - 30, escalaAlto - 30);
	}

	void desaparecer() {
		enReaparicion = true;
		enParpadeo = false;
		visible = false;
		contadorReaparicion = 0;
	}

	void reaparecerEn(int nuevaX, int nuevaY) {
		x = nuevaX;
		y = nuevaY;
		visible = true;
		indiceX = 0;
	}

	bool estaVisible() {
		return !enReaparicion || enParpadeo;
	}

	bool colisionaCon(Rectangle jugador) {
		if (!visible) return false;
		return obtenerRectangulo().IntersectsWith(jugador);
	}

	void reposicionar(int anchoMapa, int altoMapa) {
		Random^ rnd = gcnew Random(Environment::TickCount + x + y);
		x = rnd->Next(100, anchoMapa - 100);
		y = rnd->Next(100, altoMapa - 100);
	}
};

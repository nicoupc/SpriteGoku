#pragma once

using namespace System;
using namespace System::Drawing;

ref class CRecurso {
protected:
	int x, y;
	int ancho, alto;
	int escala = 48;
	Bitmap^ sprite;
	bool visible;
	bool enReaparicion = false;
	bool enParpadeo = false;
	int contadorReaparicion = 0;
	int tiempoEspera = 100;     // 10 segundos (si el timer es de 16 ms)
	int tiempoParpadeo = 10;    // 1 segundo de parpadeo

public:
	CRecurso(String^ rutaImagen, int px, int py) {
		sprite = gcnew Bitmap(rutaImagen);
		ancho = sprite->Width;
		alto = sprite->Height;
		x = px;
		y = py;
		visible = true;
	}

	virtual void dibujar(Graphics^ g) {
		if (!visible) return;

		Rectangle destino = Rectangle(x, y, escala, escala);
		g->DrawImage(sprite, destino);
		//g->DrawRectangle(gcnew Pen(Color::Red), obtenerRectangulo());
	}

	virtual Rectangle obtenerRectangulo() {
		return Rectangle(x + 5, y + 5, escala - 10, escala - 10);
	}

	bool colisionaCon(Rectangle jugador) {
		return visible && obtenerRectangulo().IntersectsWith(jugador);
	}

	void desaparecer() {
		enReaparicion = true;
		enParpadeo = false;
		visible = false;
		contadorReaparicion = 0;
	}

	bool estaVisible() {
		return !enReaparicion || enParpadeo;
	}

	Point getPosicion() {
		return Point(x, y);
	}

	void reposicionar(int anchoMapa, int altoMapa) {
		Random^ rnd = gcnew Random(Environment::TickCount + x + y);
		x = rnd->Next(100, anchoMapa - 100);
		y = rnd->Next(100, altoMapa - 100);
	}

	void mover() {
		if (enReaparicion) {
			contadorReaparicion++;

			if (!enParpadeo && contadorReaparicion >= tiempoEspera) {
				reposicionar(900, 650); // ajustá según el tamaño de tu mapa
				enParpadeo = true;
				contadorReaparicion = 0;
			}

			if (enParpadeo) {
				visible = (contadorReaparicion / 3) % 2 == 0;

				if (contadorReaparicion >= tiempoParpadeo) {
					enReaparicion = false;
					enParpadeo = false;
					visible = true;
					contadorReaparicion = 0;
				}
			}
		}
	}
};

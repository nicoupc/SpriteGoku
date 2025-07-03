#pragma once

#include <cstdlib> // para rand

using namespace System;
using namespace System::Drawing;

public enum class EstadoEnemigo { Activo, Eliminado, Reapareciendo };

ref class CEnemigo {
private:
	int x, y;
	int ancho, alto;
	int escalaAncho = 64;
	int escalaAlto = 96;

	int direccion; // 0: derecha, 1: izquierda, 2: arriba, 3: abajo
	int pasosRestantes;
	int velocidad;
	int tiempoReaparicion;
	int contadorReaparicion;
	bool visible;

	Bitmap^ sprite;
	EstadoEnemigo estado;

public:
	CEnemigo(String^ ruta, int px, int py, int _velocidad) {
		sprite = gcnew Bitmap(ruta);
		ancho = sprite->Width / 4;
		alto = sprite->Height / 4;
		x = px;
		y = py;
		velocidad = _velocidad;
		direccion = rand() % 4;
		pasosRestantes = 4;
		estado = EstadoEnemigo::Activo;
		tiempoReaparicion = 60; // frames
		contadorReaparicion = 0;
		visible = true;
	}

	void mover(int jugadorX, int jugadorY) {
		if (estado == EstadoEnemigo::Eliminado) {
			contadorReaparicion++;
			if (contadorReaparicion >= tiempoReaparicion) {
				estado = EstadoEnemigo::Reapareciendo;
				contadorReaparicion = 0;
			}
			return;
		}

		if (estado == EstadoEnemigo::Reapareciendo) {
			contadorReaparicion++;
			visible = (contadorReaparicion / 10) % 2 == 0;
			if (contadorReaparicion >= 40) {
				estado = EstadoEnemigo::Activo;
				visible = true;
				contadorReaparicion = 0;
			}
			return;
		}

		// Perseguir si está cerca
		int dx = jugadorX - x;
		int dy = jugadorY - y;
		int distancia = Math::Abs(dx) + Math::Abs(dy);

		if (distancia < 150) {
			if (Math::Abs(dx) > Math::Abs(dy)) {
				direccion = (dx > 0) ? 0 : 1;
			}
			else {
				direccion = (dy > 0) ? 3 : 2;
			}
		}

		// Movimiento por pasos
		if (pasosRestantes == 0) {
			direccion = rand() % 4;
			pasosRestantes = 4;
		}

		switch (direccion) {
		case 0: x += velocidad; break;
		case 1: x -= velocidad; break;
		case 2: y -= velocidad; break;
		case 3: y += velocidad; break;
		}

		pasosRestantes--;
	}

	void dibujar(Graphics^ g) {
		if (!visible) return;

		int indiceY;

		switch (direccion) {
		case 0: indiceY = 2; break; // Derecha -> fila 2
		case 1: indiceY = 1; break; // Izquierda -> fila 1
		case 2: indiceY = 3; break; // Arriba -> fila 3
		case 3: indiceY = 0; break; // Abajo -> fila 0
		default: indiceY = 0; break;
		}

		static int animacion = 0;
		animacion = (animacion + 1) % 4;
		int indiceX = animacion;

		Rectangle origen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle destino = Rectangle(x, y, escalaAncho, escalaAlto);
		g->DrawImage(sprite, destino, origen, GraphicsUnit::Pixel);
	}

	Rectangle obtenerRectangulo() {
		return Rectangle(x + 10, y + 10, escalaAncho - 20, escalaAlto - 20);
	}

	void eliminar() {
		estado = EstadoEnemigo::Eliminado;
		contadorReaparicion = 0;
		visible = false;
	}

	EstadoEnemigo getEstado() {
		return estado;
	}
};

#pragma once

#include "CAliado.h"

ref class CAliadoVida : public CAliado {
private:
	int pasos = 0;
	int direccion = 0; // 0: derecha, 1: izquierda

public:
	CAliadoVida(String^ ruta, int px, int py)
		: CAliado(ruta, px, py) {
		indiceY = 2; // Comienza mirando a la derecha
	}

	virtual void mover() override {
		if (!visible) return;

		// Movimiento horizontal suave
		if (direccion == 0) x += 5;
		else x -= 5;

		pasos++;
		indiceX = (indiceX + 1) % 4;

		if (pasos >= 30) {
			pasos = 0;
			direccion = (direccion == 0) ? 1 : 0;
			indiceY = (direccion == 0) ? 2 : 1; // derecha o izquierda
		}
	}

	virtual void aplicarEfecto(int% vidas) override {
		vidas++;
		desaparecer(); // desaparece tras usarse
	}
};

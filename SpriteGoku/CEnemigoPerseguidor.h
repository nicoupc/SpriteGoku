#pragma once
#include "CEnemigo.h"

ref class CEnemigoPerseguidor : public CEnemigo {
private:
	int velocidad;

public:
	CEnemigoPerseguidor(String^ ruta, int x, int y, int vel)
		: CEnemigo(ruta, x, y) // llamada al constructor base
	{
		velocidad = vel;
	}

	void moverHacia(int jugadorX, int jugadorY) {
		int dx = jugadorX - x;
		int dy = jugadorY - y;
		int tolerancia = velocidad;

		if (Math::Abs(dx) <= tolerancia && Math::Abs(dy) <= tolerancia)
			return;

		bool movidoX = false;
		bool movidoY = false;

		if (Math::Abs(dx) > tolerancia) {
			if (Math::Abs(dx) >= Math::Abs(dy)) { // Prioriza eje horizontal si es dominante
				if (dx > 0) {
					x += velocidad;
					indiceY = 2; // derecha
				}
				else {
					x -= velocidad;
					indiceY = 1; // izquierda
				}
				movidoX = true;
			}
		}

		if (Math::Abs(dy) > tolerancia) {
			if (!movidoX || Math::Abs(dy) > Math::Abs(dx)) { // Solo si no se movió en X o Y es mayor
				if (dy > 0) {
					y += velocidad;
					indiceY = 0; // abajo
				}
				else {
					y -= velocidad;
					indiceY = 3; // arriba
				}
				movidoY = true;
			}
		}

		// Si ambos se movieron (diagonal real), ajustamos solo la animación vertical
		if (movidoX && movidoY) {
			if (dy > 0) indiceY = 0; // abajo
			else        indiceY = 3; // arriba
		}

		indiceX = (indiceX + 1) % 4;
	}

	virtual void mover() override {}
};

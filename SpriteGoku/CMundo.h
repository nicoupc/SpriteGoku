#pragma once

#include "CEnemigo.h"
#include "CEnemigoPatrullaSI.h"
#include "CEnemigoPatrullaSD.h"
#include "CEnemigoPerseguidor.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class CMundo {
private:
	Bitmap^ fondo;
	List<CEnemigo^>^ enemigos;
	CEnemigoPerseguidor^ perseguidor;

public:
	CMundo(String^ rutaFondo) {
		fondo = gcnew Bitmap(rutaFondo);
		enemigos = gcnew List<CEnemigo^>();
	}

	void dibujar(Graphics^ g, int ancho, int alto) {
		g->DrawImage(fondo, Rectangle(0, 0, ancho, alto));

		for each (CEnemigo ^ e in enemigos) {
			e->mover();
			e->dibujar(g);
		}

		if (perseguidor != nullptr) {
			perseguidor->dibujar(g);
		}
	}

	void agregarPatrullaSI(String^ ruta, int x, int y, int subirAltura, int irDerecha, int velocidad) {
		enemigos->Add(gcnew CEnemigoPatrullaSI(ruta, x, y, subirAltura, irDerecha, velocidad));
	}

	void agregarPatrullaSD(String^ ruta, int x, int y, int alto, int ancho, int vel) {
		enemigos->Add(gcnew CEnemigoPatrullaSD(ruta, x, y, alto, ancho, vel));
	}

	void agregarPerseguidor(String^ ruta, int x, int y, int vel) {
		perseguidor = gcnew CEnemigoPerseguidor(ruta, x, y, vel);
	}

	void moverPerseguidor(int jugadorX, int jugadorY) {
		if (perseguidor != nullptr) {
			perseguidor->moverHacia(jugadorX, jugadorY);
		}
	}
};

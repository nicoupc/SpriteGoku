#pragma once

#include "CEnemigo.h"
#include "CEnemigoPatrulla.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class CMundo {
private:
    Bitmap^ fondo;
    List<CEnemigo^>^ enemigos;

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
    }

    /*void agregarEnemigo(String^ ruta, int x, int y) {
        enemigos->Add(gcnew CEnemigo(ruta, x, y));
    }*/

	void agregarPatrulla(String^ ruta, int x, int y, int subirAltura, int irDerecha, int velocidad) {
		enemigos->Add(gcnew CEnemigoPatrulla(ruta, x, y, subirAltura, irDerecha, velocidad));
    }
};

#pragma once
using namespace System;
using namespace System::Drawing;

ref class CMundo {
private:
    Bitmap^ fondo;

public:
    CMundo(String^ rutaFondo) {
        fondo = gcnew Bitmap(rutaFondo);
    }

    void dibujar(Graphics^ g, int ancho, int alto) {
        g->DrawImage(fondo, Rectangle(0, 0, ancho, alto));
    }
};

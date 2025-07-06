#pragma once

using namespace System;
using namespace System::Drawing;

ref class CDisparo {
private:
    int x, y;
    int dx, dy;
    int velocidad = 20;
    Bitmap^ sprite;
    int ancho, alto;
    int escalaAncho = 30;
    int escalaAlto = 30;

public:
    CDisparo(String^ ruta, int px, int py, Direcciones direccion) {
        sprite = gcnew Bitmap(ruta);
        ancho = sprite->Width;
        alto = sprite->Height;
        x = px;
        y = py;

        dx = dy = 0;
        switch (direccion) {
        case Direcciones::Arriba: dy = -velocidad; break;
        case Direcciones::Abajo: dy = velocidad; break;
        case Direcciones::Izquierda: dx = -velocidad; break;
        case Direcciones::Derecha: dx = velocidad; break;
        default: dx = 0; dy = 0; break;
        }
    }

    void mover() {
        x += dx;
        y += dy;
    }

    void dibujar(Graphics^ g) {
        Rectangle destino = Rectangle(x, y, escalaAncho, escalaAlto);
        g->DrawImage(sprite, destino);
        //g->DrawRectangle(Pens::Red, obtenerRectangulo());
    }

    Rectangle obtenerRectangulo() {
        return Rectangle(x, y, escalaAncho, escalaAlto);
    }

    bool estaFueraPantalla(int anchoPantalla, int altoPantalla) {
        return x < 0 || x > anchoPantalla || y < 0 || y > altoPantalla;
    }
};

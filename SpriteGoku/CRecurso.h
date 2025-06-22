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

public:
    CRecurso (String^ rutaImagen, int px, int py) {
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
        g->DrawRectangle(gcnew Pen(Color::Red), obtenerRectangulo());
    }

    virtual Rectangle obtenerRectangulo() {
        return Rectangle(x + 5, y + 5, escala - 10, escala - 10);
    }

    bool colisionaCon(Rectangle jugador) {
        return visible && obtenerRectangulo().IntersectsWith(jugador);
    }

    void desaparecer() {
        visible = false;
    }

    bool estaVisible() {
        return visible;
    }

    Point getPosicion() {
        return Point(x, y);
    }
};

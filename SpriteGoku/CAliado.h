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

public:
    CAliado(String^ ruta, int px, int py) {
        sprite = gcnew Bitmap(ruta);
        ancho = sprite->Width / 4;
        alto = sprite->Height / 4;
        x = px;
        y = py;
    }

    virtual void mover() = 0; // cada aliado define su propio movimiento
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
        visible = false;
    }

    void reaparecerEn(int nuevaX, int nuevaY) {
        x = nuevaX;
        y = nuevaY;
        visible = true;
        indiceX = 0;
    }

    bool estaVisible() {
        return visible;
    }

    bool colisionaCon(Rectangle jugador) {
        if (!visible) return false;
        return obtenerRectangulo().IntersectsWith(jugador);
    }
};

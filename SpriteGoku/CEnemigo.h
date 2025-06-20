#pragma once
using namespace System;
using namespace System::Drawing;

ref class CEnemigo {
private:
    int x, y;
    int ancho = 32; // un frame de 128px / 4
    int alto = 48;  // un frame de 192px / 4
    int indiceX = 0;
    int indiceY = 2; // Comenzamos hacia la derecha
    int pasos = 0;
    int direccion = 0; // 0: derecha, 1: izquierda
    Bitmap^ sprite;

public:
    CEnemigo(String^ ruta, int px, int py) {
        sprite = gcnew Bitmap(ruta);
        x = px;
        y = py;
    }

    void mover() {
        if (direccion == 0) {
            x += 4;
            indiceY = 2; // derecha
        }
        else {
            x -= 4;
            indiceY = 1; // izquierda
        }

        indiceX = (indiceX + 1) % 4;
        pasos++;

        if (pasos >= 20) {
            pasos = 0;
            direccion = (direccion + 1) % 2;
        }
    }

    void dibujar(Graphics^ g) {
        Rectangle origen = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
        Rectangle destino = Rectangle(x, y, ancho * 2, alto * 2);
        g->DrawImage(sprite, destino, origen, GraphicsUnit::Pixel);
    }
};

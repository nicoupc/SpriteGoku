#pragma once
using namespace System;
using namespace System::Drawing;

ref class CEnemigo {
private:
    int x, y;
	int ancho, alto;
    int indiceX = 0;
    int indiceY = 2; // Comenzamos hacia la derecha
    int pasos = 0;
    int direccion = 0; // 0: derecha, 1: izquierda
    int escalaAncho = 64;
    int escalaAlto = 96;
    Bitmap^ sprite;

public:
    CEnemigo(String^ ruta, int px, int py) {
        sprite = gcnew Bitmap(ruta);
        ancho = sprite->Width / 4;
        alto = sprite->Height / 4;
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
        Rectangle destino = Rectangle(x, y, escalaAncho, escalaAlto);
        g->DrawImage(sprite, destino, origen, GraphicsUnit::Pixel);
    }
};

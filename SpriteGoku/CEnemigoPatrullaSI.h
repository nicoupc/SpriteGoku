#pragma once
#include "CEnemigo.h"

ref class CEnemigoPatrullaSI : public CEnemigo {
private:
    int estado = 0;
    int distancia = 0;
    int maxY;
    int maxX;
    int inicioX, inicioY;
	int velocidad;

public:
    CEnemigoPatrullaSI(String^ ruta, int px, int py, int alto, int largo, int vel)
        : CEnemigo(ruta, px, py)
    {
        inicioX = px;
        inicioY = py;
        maxY = alto;
        maxX = largo;
        velocidad = vel;
    }

    virtual void mover() override {
        switch (estado) {
        case 0: // mover a la derecha
			x += velocidad;
            indiceY = 2;
            if (++distancia >= maxX) {
                distancia = 0;
                estado = 1;
            }
            break;
        case 1: // subir
			y -= velocidad;
            indiceY = 3;
            if (++distancia >= maxY) {
                distancia = 0;
                estado = 2;
            }
            break;
        case 2: // volver al punto original de y
			y += velocidad;
            indiceY = 0;
            if (y >= inicioY) {
                y = inicioY;
                estado = 3;
            }
            break;
        case 3: // mover a la izquierda
			x -= velocidad;
            indiceY = 1;
            if (++distancia >= maxX) {
                distancia = 0;
                estado = 0;
            }
            break;
        }

        indiceX = (indiceX + 1) % 4;
    }
};

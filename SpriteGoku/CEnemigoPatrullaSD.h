#pragma once
#include "CEnemigo.h"

ref class CEnemigoPatrullaSD : public CEnemigo {
private:
    int estado = 0;
    int distancia = 0;
    int maxY, maxX;
    int inicioX, inicioY;
    int velocidad;

public:
    CEnemigoPatrullaSD(String^ ruta, int px, int py, int alto, int ancho, int vel)
        : CEnemigo(ruta, px, py)
    {
        inicioX = px;
        inicioY = py;
        maxY = alto;       // cuánto baja
        maxX = ancho;      // cuánto avanza/retrocede horizontal
        velocidad = vel;
    }

    virtual void mover() override {
        switch (estado) {
        case 0: // Baja
            y += velocidad;
            indiceY = 0;
            if (++distancia >= maxY) {
                distancia = 0;
                estado = 1;
            }
            break;

        case 1: // Moverse a la derecha
            x += velocidad;
            indiceY = 2;
            if (++distancia >= maxX) {
                distancia = 0;
                estado = 2;
            }
            break;

        case 2: // Moverse a la izquierda
            x -= velocidad;
            indiceY = 1;
            if (++distancia >= maxX) {
                distancia = 0;
                estado = 3;
            }
            break;

        case 3: // Subir hasta volver a inicioY
            y -= velocidad;
            indiceY = 3;
            if (y <= inicioY) {
                y = inicioY;
                estado = 0;
            }
            break;
        }

        indiceX = (indiceX + 1) % 4;
    }
};

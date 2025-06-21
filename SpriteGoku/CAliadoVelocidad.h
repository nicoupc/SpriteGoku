#pragma once
#include "CAliado.h"

ref class CAliadoVelocidad : public CAliado {
private:
    int pasos = 0;
    int direccion = 0; // 0: derecha, 1: izquierda

public:
    CAliadoVelocidad(String^ ruta, int px, int py)
        : CAliado(ruta, px, py) {
        indiceY = 2; // Comienza mirando a la derecha
    }

    virtual void mover() override {
        if (!visible) return;

        // Movimiento suave de lado a lado
        if (direccion == 0) x += 3;
        else x -= 3;

        pasos++;
        indiceX = (indiceX + 1) % 4;

        if (pasos >= 30) {
            pasos = 0;
            direccion = 1 - direccion;
            indiceY = direccion == 0 ? 2 : 1; // Mirar derecha o izquierda
        }
    }

    virtual void aplicarEfecto(int% vidas) override {
        // No afecta vidas: el efecto será manejado externamente
        desaparecer(); // desaparece tras tocarlo
    }
};

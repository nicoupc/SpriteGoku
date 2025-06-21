#pragma once
#include "CAliado.h"

ref class CAliadoEscudo : public CAliado {
private:
    int pasos = 0;
    int direccion = 0; // 0: derecha, 1: izquierda

public:
    CAliadoEscudo(String^ ruta, int px, int py)
        : CAliado(ruta, px, py) {
        indiceY = 2;
    }

    virtual void mover() override {
        if (!visible) return;

        if (direccion == 0) x += 3;
        else x -= 3;

        pasos++;
        indiceX = (indiceX + 1) % 4;

        if (pasos >= 30) {
            pasos = 0;
            direccion = (direccion == 0) ? 1 : 0;
            indiceY = (direccion == 0) ? 2 : 1;
        }
    }

    virtual void aplicarEfecto(int% vidas) override {
        // No afecta vidas, activa escudo
        desaparecer();
    }
};

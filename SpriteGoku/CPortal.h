#pragma once
using namespace System;
using namespace System::Drawing;

public ref class CPortal {
private:
    int x, y;
    int ancho, alto;
    int frameActual;
    int totalFrames;
    int contadorAnimacion;
    int delayAnimacion;
    bool activo;
    Bitmap^ sprite;

public:
    CPortal(int x, int y, Bitmap^ sprite) {
        this->x = x;
        this->y = y;
        this->ancho = 150;
        this->alto = 100;
        this->frameActual = 0;
        this->totalFrames = 5;
        this->contadorAnimacion = 0;
        this->delayAnimacion = 1;
        this->activo = false;
        this->sprite = sprite;
    }

    void actualizar(Rectangle rectJugador) {
        Rectangle zonaActivacion = Rectangle(x - 80, y - 60, ancho + 160, alto + 120);
        activo = rectJugador.IntersectsWith(zonaActivacion);

        if (activo) {
            contadorAnimacion++;
            if (contadorAnimacion >= delayAnimacion) {
                frameActual++;
                if (frameActual >= totalFrames) frameActual = 1; // Cicla entre 1 y 4
                contadorAnimacion = 0;
            }
        }
        else {
            frameActual = 0; // Vuelve a la plataforma gris
        }
    }

    void dibujar(Graphics^ g) {
        int altoFrame = sprite->Height / totalFrames;
        Rectangle src = Rectangle(0, frameActual * altoFrame, sprite->Width, altoFrame);
        Rectangle destino = Rectangle(x, y, ancho, alto);
        g->DrawImage(sprite, destino, src, GraphicsUnit::Pixel);

        // Borde rojo para depuración
        //g->DrawRectangle(gcnew Pen(Color::Red, 2), destino);
    }

    Rectangle obtenerRectangulo() {
        return Rectangle(x, y, ancho, alto);
    }

    bool jugadorPuedeViajar(Rectangle rectJugador) {
        Rectangle zonaCentral = Rectangle(x + ancho / 4, y, ancho / 2, alto);
        return activo && zonaCentral.IntersectsWith(rectJugador);
    }
};

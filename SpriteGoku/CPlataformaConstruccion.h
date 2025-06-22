#pragma once
#include "CEspacioConstruible.h"

using namespace System::Collections::Generic;

ref class CPlataformaConstruccion {
private:
    int x, y;
    Bitmap^ imagenPlataforma;
    Bitmap^ imagenConstruida;
    List<CEspacioConstruible^>^ espacios;
    bool construida;

public:
    CPlataformaConstruccion(int px, int py, String^ rutaPlataforma, String^ rutaConstruida) {
        x = px;
        y = py;
        imagenPlataforma = gcnew Bitmap(rutaPlataforma);
        imagenConstruida = gcnew Bitmap(rutaConstruida);
        espacios = gcnew List<CEspacioConstruible^>();
        construida = false;
    }

    void agregarEspacio(CEspacioConstruible^ espacio) {
        espacios->Add(espacio);
    }

    void dibujar(Graphics^ g) {
        // Dibujar espacios primero (debajo de la plataforma)
        for each (CEspacioConstruible ^ espacio in espacios) {
            espacio->dibujar(g);
        }

        // Dibujar la plataforma
        g->DrawImage(imagenPlataforma, x, y);

        // Dibujar la construcción final solo si está completa
        if (construida) {
            int anchoObjeto = 80;
            int altoObjeto = 80;

            // Centrar horizontalmente encima de la plataforma
            //int cx = x + (imagenPlataforma->Width - anchoObjeto) / 2;
            int cx = x;
            //int cy = y - altoObjeto + 10; // Ajuste vertical opcional
            int cy = y;

            Rectangle destino(cx, cy, anchoObjeto, altoObjeto);
            g->DrawImage(imagenConstruida, destino);
        }
    }

    void verificarConstruccion() {
        for each (CEspacioConstruible ^ espacio in espacios) {
            if (!espacio->estaLleno())
                return;
        }
        construida = true;
    }

    List<CEspacioConstruible^>^ obtenerEspacios() {
        return espacios;
    }

    bool estaConstruida() {
        return construida;
    }

    Rectangle obtenerZonaConstruida() {
        return Rectangle(x + 10, y - 60, 50, 50); // para colisiones futuras, opcional
    }
};

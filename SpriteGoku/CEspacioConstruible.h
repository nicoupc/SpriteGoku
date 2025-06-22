#pragma once
using namespace System;
using namespace System::Drawing;

// Tipos de recurso posibles (puede ser humano o tecnológico)
public enum class TipoDeRecurso {
    Robotica = 0,
    InteligenciaArtificial = 1,
    BigData = 2,
    EnergiaSostenible = 3,
    Empatia = 4,
    Etica = 5,
    Creatividad = 6,
    TrabajoEnEquipo = 7
};

ref class CEspacioConstruible {
private:
    int x, y;
    int ancho = 32;
    int alto = 32;
    bool lleno;
    TipoDeRecurso tipo;
    Bitmap^ imagenGris;
    Bitmap^ imagenColor;

public:
    // Constructor: recibe la imagen vacía y el tipo de recurso que requiere
    CEspacioConstruible(int px, int py, TipoDeRecurso tipo, String^ rutaGris, String^ rutaColor) {
        x = px;
        y = py;
        this->tipo = tipo;
        lleno = false;
        imagenGris = gcnew Bitmap(rutaGris);
        imagenColor = gcnew Bitmap(rutaColor);
    }

    void dibujar(Graphics^ g) {
        Rectangle destino = Rectangle(x, y, ancho, alto);

        // Elegir imagen y borde según el estado
        Bitmap^ mostrar = lleno ? imagenColor : imagenGris;
        Pen^ borde = lleno ? gcnew Pen(Color::Yellow, 2.0f) : gcnew Pen(Color::Black, 2.0f);

        g->DrawImage(mostrar, destino);
        g->DrawRectangle(borde, destino);
    }

    Rectangle obtenerRect() {
        return Rectangle(x + 4, y + 4, ancho - 8, alto - 8); // colisión más justa
    }

    TipoDeRecurso obtenerTipo() {
        return tipo;
    }

    bool estaLleno() {
        return lleno;
    }

    void rellenar() {
        lleno = true;
    }

    Point getPosicion() {
        return Point(x, y);
    }
};

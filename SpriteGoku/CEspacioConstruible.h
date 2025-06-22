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
    Bitmap^ imagen;
    Bitmap^ imagenRellena;

public:
    // Constructor: recibe la imagen vacía y el tipo de recurso que requiere
    CEspacioConstruible(int px, int py, TipoDeRecurso tipo, String^ rutaImagenVacia, String^ rutaImagenRellena) {
        x = px;
        y = py;
        this->tipo = tipo;
        lleno = false;
        imagen = gcnew Bitmap(rutaImagenVacia);
        imagenRellena = gcnew Bitmap(rutaImagenRellena);
    }

    void dibujar(Graphics^ g) {
        Rectangle destino = Rectangle(x, y, ancho, alto);
        Bitmap^ mostrar = lleno ? imagenRellena : imagen;
        g->DrawImage(mostrar, destino);
		g->DrawRectangle(Pens::Red, destino); // dibujar borde para visibilidad
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

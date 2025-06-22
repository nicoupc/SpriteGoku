#pragma once
#include "CRecurso.h"

public enum class TipoHabilidadHumana {
    Empatia,
    Etica,
    Creatividad,
    TrabajoEnEquipo
};

ref class CRecursoHumano : public CRecurso {
private:
    TipoHabilidadHumana tipo;

public:
    CRecursoHumano(String^ rutaImagen, int px, int py, TipoHabilidadHumana tipo)
        : CRecurso(rutaImagen, px, py) {
        this->tipo = tipo;
    }

    TipoHabilidadHumana obtenerTipo() {
        return tipo;
    }
};

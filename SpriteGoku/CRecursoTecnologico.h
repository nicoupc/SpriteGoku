#pragma once
#include "CRecurso.h"

public enum class TipoRecursoTecnologico {
    Robotica,
    InteligenciaArtificial,
    BigData,
    EnergiaSostenible
};

ref class CRecursoTecnologico : public CRecurso {
private:
    TipoRecursoTecnologico tipo;

public:
    CRecursoTecnologico(String^ rutaImagen, int px, int py, TipoRecursoTecnologico tipo)
        : CRecurso(rutaImagen, px, py) {
        this->tipo = tipo;
    }

    TipoRecursoTecnologico obtenerTipo() {
        return tipo;
    }
};

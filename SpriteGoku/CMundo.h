#pragma once

#include "CEnemigo.h"
#include "CEnemigoPatrullaSI.h"
#include "CEnemigoPatrullaSD.h"
#include "CEnemigoPerseguidor.h"
#include "CAliado.h"
#include "CAliadoVida.h"
#include "CAliadoEscudo.h"
#include "CAliadoVelocidad.h"
#include "CRecursoTecnologico.h"
#include "CRecursoHumano.h"
#include "CPlataformaConstruccion.h"

using namespace System;
using namespace System::Drawing;
using namespace System::Collections::Generic;

ref class CMundo {
protected:
	Bitmap^ fondo;
	List<CEnemigo^>^ enemigos;
	CEnemigoPerseguidor^ perseguidor;

public:
	List<CAliado^>^ aliados;
	List<CRecursoTecnologico^>^ recursosTecnologicos;
	List<CRecursoHumano^>^ recursosHumanos;
	List<CPlataformaConstruccion^>^ plataformasConstruccion;

public:
	CMundo(String^ rutaFondo) {
		fondo = gcnew Bitmap(rutaFondo);
		enemigos = gcnew List<CEnemigo^>();

		aliados = gcnew List<CAliado^>();

		// Solo crear aliados en mundo 0 y 1
		if (rutaFondo->Contains("Mundo1") || rutaFondo->Contains("Mundo2")) {
			CAliado^ aliado1 = gcnew CAliadoVida("Sakura.png", 350, 60);
			aliados->Add(aliado1);
			CAliado^ aliado2 = gcnew CAliadoEscudo("Vegeta.png", 30, 300);
			aliados->Add(aliado2);
			CAliado^ aliado3 = gcnew CAliadoVelocidad("Sangohan.png", 830, 300);
			aliados->Add(aliado3);
		}

		recursosTecnologicos = gcnew List<CRecursoTecnologico^>();

		if (rutaFondo->Contains("Mundo1")) {
			CRecursoTecnologico^ recurso1 = gcnew CRecursoTecnologico("Robotica.png", 300, 300, TipoRecursoTecnologico::Robotica);
			recursosTecnologicos->Add(recurso1);
			CRecursoTecnologico^ recurso2 = gcnew CRecursoTecnologico("InteligenciaArtificial.png", 350, 300, TipoRecursoTecnologico::InteligenciaArtificial);
			recursosTecnologicos->Add(recurso2);
			CRecursoTecnologico^ recurso3 = gcnew CRecursoTecnologico("BigData.png", 400, 300, TipoRecursoTecnologico::BigData);
			recursosTecnologicos->Add(recurso3);
			CRecursoTecnologico^ recurso4 = gcnew CRecursoTecnologico("Panel.png", 450, 300, TipoRecursoTecnologico::EnergiaSostenible);
			recursosTecnologicos->Add(recurso4);
			CRecursoTecnologico^ recurso5 = gcnew CRecursoTecnologico("Robotica.png", 500, 300, TipoRecursoTecnologico::Robotica);
			recursosTecnologicos->Add(recurso5);
			CRecursoTecnologico^ recurso6 = gcnew CRecursoTecnologico("InteligenciaArtificial.png", 550, 300, TipoRecursoTecnologico::InteligenciaArtificial);
			recursosTecnologicos->Add(recurso6);
			CRecursoTecnologico^ recurso7 = gcnew CRecursoTecnologico("BigData.png", 600, 300, TipoRecursoTecnologico::BigData);
			recursosTecnologicos->Add(recurso7);
			CRecursoTecnologico^ recurso8 = gcnew CRecursoTecnologico("Panel.png", 650, 300, TipoRecursoTecnologico::EnergiaSostenible);
			recursosTecnologicos->Add(recurso8);
			CRecursoTecnologico^ recurso9 = gcnew CRecursoTecnologico("Robotica.png", 700, 300, TipoRecursoTecnologico::Robotica);
			recursosTecnologicos->Add(recurso9);
			CRecursoTecnologico^ recurso10 = gcnew CRecursoTecnologico("InteligenciaArtificial.png", 750, 300, TipoRecursoTecnologico::InteligenciaArtificial);
			recursosTecnologicos->Add(recurso10);
			CRecursoTecnologico^ recurso11 = gcnew CRecursoTecnologico("BigData.png", 800, 300, TipoRecursoTecnologico::BigData);
			recursosTecnologicos->Add(recurso11);
			CRecursoTecnologico^ recurso12 = gcnew CRecursoTecnologico("Panel.png", 850, 300, TipoRecursoTecnologico::EnergiaSostenible);
			recursosTecnologicos->Add(recurso12);
		}

		recursosHumanos = gcnew List<CRecursoHumano^>();

		if (rutaFondo->Contains("Mundo2")) {
			CRecursoHumano^ recurso1 = gcnew CRecursoHumano("Empatia.png", 300, 300, TipoHabilidadHumana::Empatia);
			recursosHumanos->Add(recurso1);
			CRecursoHumano^ recurso2 = gcnew CRecursoHumano("Etica.png", 350, 300, TipoHabilidadHumana::Etica);
			recursosHumanos->Add(recurso2);
			CRecursoHumano^ recurso3 = gcnew CRecursoHumano("Creatividad.png", 400, 300, TipoHabilidadHumana::Creatividad);
			recursosHumanos->Add(recurso3);
			CRecursoHumano^ recurso4 = gcnew CRecursoHumano("TrabajoEnEquipo.png", 450, 300, TipoHabilidadHumana::TrabajoEnEquipo);
			recursosHumanos->Add(recurso4);
			CRecursoHumano^ recurso5 = gcnew CRecursoHumano("Empatia.png", 500, 300, TipoHabilidadHumana::Empatia);
			recursosHumanos->Add(recurso5);
			CRecursoHumano^ recurso6 = gcnew CRecursoHumano("Etica.png", 550, 300, TipoHabilidadHumana::Etica);
			recursosHumanos->Add(recurso6);
			CRecursoHumano^ recurso7 = gcnew CRecursoHumano("Creatividad.png", 600, 300, TipoHabilidadHumana::Creatividad);
			recursosHumanos->Add(recurso7);
			CRecursoHumano^ recurso8 = gcnew CRecursoHumano("TrabajoEnEquipo.png", 650, 300, TipoHabilidadHumana::TrabajoEnEquipo);
			recursosHumanos->Add(recurso8);
			CRecursoHumano^ recurso9 = gcnew CRecursoHumano("Empatia.png", 700, 300, TipoHabilidadHumana::Empatia);
			recursosHumanos->Add(recurso9);
			CRecursoHumano^ recurso10 = gcnew CRecursoHumano("Etica.png", 750, 300, TipoHabilidadHumana::Etica);
			recursosHumanos->Add(recurso10);
			CRecursoHumano^ recurso11 = gcnew CRecursoHumano("Creatividad.png", 800, 300, TipoHabilidadHumana::Creatividad);
			recursosHumanos->Add(recurso11);
			CRecursoHumano^ recurso12 = gcnew CRecursoHumano("TrabajoEnEquipo.png", 850, 300, TipoHabilidadHumana::TrabajoEnEquipo);
			recursosHumanos->Add(recurso12);
		}

		plataformasConstruccion = gcnew List<CPlataformaConstruccion^>();

		if (rutaFondo->Contains("Mundo3")) {
			plataformasConstruccion = gcnew List<CPlataformaConstruccion^>();

			CPlataformaConstruccion^ plataforma = gcnew CPlataformaConstruccion(
				250, 400, "Platform220.png", "Robot.png"
			);

			// Coordenadas iniciales centradas para 5 cuadros de 32px + espaciado
			int inicioX = 260;  // podés ajustar este valor horizontal
			int yEspacios = 600;
			int separacion = 40;

			plataforma->agregarEspacio(gcnew CEspacioConstruible(inicioX + 0 * separacion, yEspacios, TipoDeRecurso::Robotica, "Robotica_Gris.png", "Robotica.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(inicioX + 1 * separacion, yEspacios, TipoDeRecurso::InteligenciaArtificial, "InteligenciaArtificial_Gris.png", "InteligenciaArtificial.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(inicioX + 2 * separacion, yEspacios, TipoDeRecurso::Creatividad, "Creatividad_Gris.png", "Creatividad.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(inicioX + 3 * separacion, yEspacios, TipoDeRecurso::Empatia, "Empatia_Gris.png", "Empatia.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(inicioX + 4 * separacion, yEspacios, TipoDeRecurso::Etica, "Etica_Gris.png", "Etica.png"));

			plataformasConstruccion->Add(plataforma);

			// PLATAFORMA 2 — CENTRO DE SALUD TECNOLÓGICO
			CPlataformaConstruccion^ plataforma2 = gcnew CPlataformaConstruccion(
				610, 400, "Platform220.png", "Hospital.png"
			);

			int inicioX2 = 620;
			int yEspacios2 = 600;
			int separacion2 = 40;

			plataforma2->agregarEspacio(gcnew CEspacioConstruible(inicioX2 + 0 * separacion2, yEspacios2, TipoDeRecurso::BigData, "BigData_Gris.png", "BigData.png"));
			plataforma2->agregarEspacio(gcnew CEspacioConstruible(inicioX2 + 1 * separacion2, yEspacios2, TipoDeRecurso::Empatia, "Empatia_Gris.png", "Empatia.png"));
			plataforma2->agregarEspacio(gcnew CEspacioConstruible(inicioX2 + 2 * separacion2, yEspacios2, TipoDeRecurso::TrabajoEnEquipo, "TrabajoEnEquipo_Gris.png", "TrabajoEnEquipo.png"));
			plataforma2->agregarEspacio(gcnew CEspacioConstruible(inicioX2 + 3 * separacion2, yEspacios2, TipoDeRecurso::InteligenciaArtificial, "InteligenciaArtificial_Gris.png", "InteligenciaArtificial.png"));
			plataforma2->agregarEspacio(gcnew CEspacioConstruible(inicioX2 + 4 * separacion2, yEspacios2, TipoDeRecurso::Etica, "Etica_Gris.png", "Etica.png"));

			plataformasConstruccion->Add(plataforma2);

			// PLATAFORMA 3 — CENTRO DE INVESTIGACIÓN
			CPlataformaConstruccion^ plataforma3 = gcnew CPlataformaConstruccion(
				250, 100, "Platform220.png", "CentroInvestigacion.png"
			);

			int inicioX3 = 260;
			int yEspacios3 = 300;
			int separacion3 = 40;

			plataforma3->agregarEspacio(gcnew CEspacioConstruible(inicioX3 + 0 * separacion3, yEspacios3, TipoDeRecurso::BigData, "BigData_Gris.png", "BigData.png"));
			plataforma3->agregarEspacio(gcnew CEspacioConstruible(inicioX3 + 1 * separacion3, yEspacios3, TipoDeRecurso::InteligenciaArtificial, "InteligenciaArtificial_Gris.png", "InteligenciaArtificial.png"));
			plataforma3->agregarEspacio(gcnew CEspacioConstruible(inicioX3 + 2 * separacion3, yEspacios3, TipoDeRecurso::EnergiaSostenible, "Panel_Gris.png", "Panel.png"));
			plataforma3->agregarEspacio(gcnew CEspacioConstruible(inicioX3 + 3 * separacion3, yEspacios3, TipoDeRecurso::Creatividad, "Creatividad_Gris.png", "Creatividad.png"));
			plataforma3->agregarEspacio(gcnew CEspacioConstruible(inicioX3 + 4 * separacion3, yEspacios3, TipoDeRecurso::Empatia, "Empatia_Gris.png", "Empatia.png"));

			plataformasConstruccion->Add(plataforma3);

			// PLATAFORMA 4 — CENTRO DE ENERGÍA HUMANO-TECNOLOGICO
			CPlataformaConstruccion^ plataforma4 = gcnew CPlataformaConstruccion(
				610, 100, "Platform220.png", "CentroEnergia.png"
			);

			int inicioX4 = 620;
			int yEspacios4 = 300;
			int separacion4 = 40;

			plataforma4->agregarEspacio(gcnew CEspacioConstruible(inicioX4 + 0 * separacion4, yEspacios4, TipoDeRecurso::EnergiaSostenible, "Panel_Gris.png", "Panel.png"));
			plataforma4->agregarEspacio(gcnew CEspacioConstruible(inicioX4 + 1 * separacion4, yEspacios4, TipoDeRecurso::Robotica, "Robotica_Gris.png", "Robotica.png"));
			plataforma4->agregarEspacio(gcnew CEspacioConstruible(inicioX4 + 2 * separacion4, yEspacios4, TipoDeRecurso::Creatividad, "Creatividad_Gris.png", "Creatividad.png"));
			plataforma4->agregarEspacio(gcnew CEspacioConstruible(inicioX4 + 3 * separacion4, yEspacios4, TipoDeRecurso::Etica, "Etica_Gris.png", "Etica.png"));
			plataforma4->agregarEspacio(gcnew CEspacioConstruible(inicioX4 + 4 * separacion4, yEspacios4, TipoDeRecurso::TrabajoEnEquipo, "TrabajoEnEquipo_Gris.png", "TrabajoEnEquipo.png"));

			plataformasConstruccion->Add(plataforma4);
		}
	}

	void dibujar(Graphics^ g, int ancho, int alto) {
		g->DrawImage(fondo, Rectangle(0, 0, ancho, alto));

		for each(CEnemigo ^ e in enemigos) {
			e->mover();
			e->dibujar(g);
		}

		if (perseguidor != nullptr) {
			perseguidor->dibujar(g);
		}

		for each(CAliado ^ a in aliados) {
			a->mover();
			a->dibujar(g);
		}

		for each(CRecursoTecnologico ^ r in recursosTecnologicos) {
			r->dibujar(g);
		}

		for each(CRecursoHumano ^ r in recursosHumanos) {
			r->dibujar(g);
		}

		if (plataformasConstruccion != nullptr) {
			for each(CPlataformaConstruccion ^ p in plataformasConstruccion)
				p->dibujar(g);
		}
	}

	void agregarPatrullaSI(String^ ruta, int x, int y, int subirAltura, int irDerecha, int velocidad) {
		enemigos->Add(gcnew CEnemigoPatrullaSI(ruta, x, y, subirAltura, irDerecha, velocidad));
	}

	void agregarPatrullaSD(String^ ruta, int x, int y, int alto, int ancho, int vel) {
		enemigos->Add(gcnew CEnemigoPatrullaSD(ruta, x, y, alto, ancho, vel));
	}

	void agregarPerseguidor(String^ ruta, int x, int y, int vel) {
		perseguidor = gcnew CEnemigoPerseguidor(ruta, x, y, vel);
	}

	void moverPerseguidor(int jugadorX, int jugadorY) {
		if (perseguidor != nullptr) {
			perseguidor->moverHacia(jugadorX, jugadorY);
		}
	}

	bool detectarColision(Rectangle jugadorRect) {
		for each(CEnemigo ^ e in enemigos) {
			if (jugadorRect.IntersectsWith(e->obtenerRectangulo())) {
				return true;
			}
		}

		// También verificar con el perseguidor
		if (perseguidor != nullptr && jugadorRect.IntersectsWith(perseguidor->obtenerRectangulo())) {
			return true;
		}

		return false;
	}
};

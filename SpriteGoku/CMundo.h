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
			CRecursoTecnologico^ recurso1 = gcnew CRecursoTecnologico("Robotica.png", 0, 0, TipoRecursoTecnologico::Robotica);
			recursosTecnologicos->Add(recurso1);

			CRecursoTecnologico^ recurso2 = gcnew CRecursoTecnologico("IA.png", 800, 0, TipoRecursoTecnologico::InteligenciaArtificial);
			recursosTecnologicos->Add(recurso2);

			CRecursoTecnologico^ recurso3 = gcnew CRecursoTecnologico("BigData.png", 300, 240, TipoRecursoTecnologico::BigData);
			recursosTecnologicos->Add(recurso3);

			CRecursoTecnologico^ recurso4 = gcnew CRecursoTecnologico("Panel.png", 600, 0, TipoRecursoTecnologico::EnergiaSostenible);
			recursosTecnologicos->Add(recurso4);
		}

		recursosHumanos = gcnew List<CRecursoHumano^>();

		if (rutaFondo->Contains("Mundo2")) {
			CRecursoHumano^ recurso1 = gcnew CRecursoHumano("Empatia.png", 100, 100, TipoHabilidadHumana::Empatia);
			recursosHumanos->Add(recurso1);
			CRecursoHumano^ recurso2 = gcnew CRecursoHumano("Etica.png", 200, 200, TipoHabilidadHumana::Etica);
			recursosHumanos->Add(recurso2);
			CRecursoHumano^ recurso3 = gcnew CRecursoHumano("Creatividad.png", 300, 300, TipoHabilidadHumana::Creatividad);
			recursosHumanos->Add(recurso3);
			CRecursoHumano^ recurso4 = gcnew CRecursoHumano("Equipo.png", 400, 400, TipoHabilidadHumana::TrabajoEnEquipo);
			recursosHumanos->Add(recurso4);
		}

		plataformasConstruccion = gcnew List<CPlataformaConstruccion^>();

		if (rutaFondo->Contains("Mundo3")) {
			plataformasConstruccion = gcnew List<CPlataformaConstruccion^>();

			CPlataformaConstruccion^ plataforma = gcnew CPlataformaConstruccion(
				300, 470, "Platform.png", "Robot.png"
			);

			// Coordenadas iniciales centradas para 5 cuadros de 32px + espaciado
			int inicioX = 260;  // podés ajustar este valor horizontal
			int yEspacios = 550;
			int separacion = 40;

			plataforma->agregarEspacio(gcnew CEspacioConstruible(
				inicioX + 0 * separacion, yEspacios, TipoDeRecurso::Robotica, "RecuadroVacio.png", "RecuadroLleno.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(
				inicioX + 1 * separacion, yEspacios, TipoDeRecurso::InteligenciaArtificial, "RecuadroVacio.png", "RecuadroLleno.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(
				inicioX + 2 * separacion, yEspacios, TipoDeRecurso::Creatividad, "RecuadroVacio.png", "RecuadroLleno.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(
				inicioX + 3 * separacion, yEspacios, TipoDeRecurso::Empatia, "RecuadroVacio.png", "RecuadroLleno.png"));
			plataforma->agregarEspacio(gcnew CEspacioConstruible(
				inicioX + 4 * separacion, yEspacios, TipoDeRecurso::Etica, "RecuadroVacio.png", "RecuadroLleno.png"));

			plataformasConstruccion->Add(plataforma);
		}
	}

	void dibujar(Graphics^ g, int ancho, int alto) {
		g->DrawImage(fondo, Rectangle(0, 0, ancho, alto));

		for each (CEnemigo ^ e in enemigos) {
			e->mover();
			e->dibujar(g);
		}

		if (perseguidor != nullptr) {
			perseguidor->dibujar(g);
		}

		for each (CAliado ^ a in aliados) {
			a->mover();
			a->dibujar(g);
		}

		for each (CRecursoTecnologico ^ r in recursosTecnologicos) {
			r->dibujar(g);
		}

		for each (CRecursoHumano ^ r in recursosHumanos) {
			r->dibujar(g);
		}

		if (plataformasConstruccion != nullptr) {
			for each (CPlataformaConstruccion ^ p in plataformasConstruccion)
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
		for each (CEnemigo ^ e in enemigos) {
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

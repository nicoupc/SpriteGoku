#pragma once

#include "CEnemigo.h"
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
public:
	Bitmap^ fondo;
	List<CEnemigo^>^ enemigos;

public:
	List<CAliado^>^ aliados;
	List<CRecurso^>^ recursos;
	List<CPlataformaConstruccion^>^ plataformasConstruccion;

public:
	CMundo(String^ rutaFondo) {
		fondo = gcnew Bitmap(rutaFondo);
		enemigos = gcnew List<CEnemigo^>();
		aliados = gcnew List<CAliado^>();
		recursos = gcnew List<CRecurso^>();
		plataformasConstruccion = gcnew List<CPlataformaConstruccion^>();

		// Solo crear aliados en mundo 0 y 1
		if (rutaFondo->Contains("Mundo1") || rutaFondo->Contains("Mundo2")) {
			CAliado^ aliado1 = gcnew CAliadoVida("Sakura.png", 350, 60);
			aliados->Add(aliado1);
			CAliado^ aliado2 = gcnew CAliadoEscudo("Vegeta.png", 30, 300);
			aliados->Add(aliado2);
			CAliado^ aliado3 = gcnew CAliadoVelocidad("Sangohan.png", 830, 300);
			aliados->Add(aliado3);
		}

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

	void generarEnemigos(int cantidad, int mundo) {
		enemigos->Clear(); // Limpiar enemigos anteriores

		for (int i = 0; i < cantidad; i++) {
			// Elegir sprite según mundo y repetir si hay más enemigos que sprites
			int spriteIndex = (i % 5) + 1;
			String^ rutaSprite = "Enemigo" + mundo.ToString() + "_" + spriteIndex.ToString() + ".png";

			// Posición aleatoria según mundo
			int x, y;
			Random^ rnd = gcnew Random(Environment::TickCount + i * 100);

			if (mundo == 1) {
				x = rnd->Next(100, 500); // más a la izquierda
			}
			else if (mundo == 2) {
				x = rnd->Next(400, 800); // más a la derecha
			}

			y = rnd->Next(100, 500);

			// Crear enemigo con velocidad base 4
			CEnemigo^ enemigo = gcnew CEnemigo(rutaSprite, x, y, 10);
			enemigos->Add(enemigo);
		}
	}

	void generarAliados(int cantidad, int mundo) {
		aliados->Clear();

		for (int i = 0; i < cantidad; i++) {
			int tipo = i % 3;
			CAliado^ aliado;

			// Posición según mundo
			int x, y;
			Random^ rnd = gcnew Random(Environment::TickCount + i * 100);

			if (mundo == 1) {
				// Mundo 1: arriba, izquierda, abajo
				array<Point>^ zonas = gcnew array<Point>{
					Point(rnd->Next(100, 800), rnd->Next(100, 150)),   // arriba
						Point(rnd->Next(100, 200), rnd->Next(200, 500)),   // izquierda
						Point(rnd->Next(100, 800), rnd->Next(500, 600))    // abajo
				};
				Point p = zonas[i % 3];
				x = p.X; y = p.Y;
			}
			else if (mundo == 2) {
				// Mundo 2: arriba, derecha, abajo
				array<Point>^ zonas = gcnew array<Point>{
					Point(rnd->Next(100, 800), rnd->Next(100, 150)),   // arriba
						Point(rnd->Next(700, 850), rnd->Next(200, 500)),   // derecha
						Point(rnd->Next(100, 800), rnd->Next(500, 600))    // abajo
				};
				Point p = zonas[i % 3];
				x = p.X; y = p.Y;
			}
			else {
				x = rnd->Next(100, 800);
				y = rnd->Next(100, 600);
			}

			switch (tipo) {
			case 0: aliado = gcnew CAliadoVida("Sakura.png", x, y); break;
			case 1: aliado = gcnew CAliadoEscudo("Vegeta.png", x, y); break;
			case 2: aliado = gcnew CAliadoVelocidad("Sangohan.png", x, y); break;
			}

			aliados->Add(aliado);
		}
	}

	void generarRecursos(int cantidad, int mundo) {
		recursos->Clear();
		Random^ rnd = gcnew Random();

		if (mundo == 1) {
			// Recursos tecnológicos
			array<String^>^ rutas = {
				"Robotica.png", "InteligenciaArtificial.png",
				"BigData.png", "EnergiaSostenible.png"
			};

			for (int i = 0; i < cantidad; i++) {
				int tipo = i % 4;
				int x = rnd->Next(100, 800);
				int y = rnd->Next(100, 600);

				CRecursoTecnologico^ r = gcnew CRecursoTecnologico(rutas[tipo], x, y, (TipoRecursoTecnologico)tipo);
				recursos->Add(r);
			}
		}
		else if (mundo == 2) {
			// Recursos humanos
			array<String^>^ rutas = {
				"Empatia.png", "Etica.png",
				"Creatividad.png", "TrabajoEnEquipo.png"
			};

			for (int i = 0; i < cantidad; i++) {
				int tipo = i % 4;
				int x = rnd->Next(100, 800);
				int y = rnd->Next(100, 600);

				CRecursoHumano^ r = gcnew CRecursoHumano(rutas[tipo], x, y, (TipoHabilidadHumana)tipo);
				recursos->Add(r);
			}
		}
	}

	void dibujar(Graphics^ g, int ancho, int alto, CJugador^ jugador) {
		g->DrawImage(fondo, Rectangle(0, 0, ancho, alto));

		for each (CEnemigo ^ e in enemigos) {
			e->mover(jugador->getX(), jugador->getY());
			e->dibujar(g);
		}

		for each (CAliado ^ a in aliados) {
			a->mover();
			a->dibujar(g);
		}

		for each (CRecurso ^ r in recursos) {
			r->mover();
			r->dibujar(g);
		}

		if (plataformasConstruccion != nullptr) {
			for each (CPlataformaConstruccion ^ p in plataformasConstruccion)
				p->dibujar(g);
		}
	}

	bool detectarColision(Rectangle jugadorRect) {
		for each (CEnemigo ^ e in enemigos) {
			if (jugadorRect.IntersectsWith(e->obtenerRectangulo())) {
				return true;
			}
		}

		return false;
	}
};

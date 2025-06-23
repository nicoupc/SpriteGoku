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
	int alphaConstruccion; // transparencia inicial
	bool eliminada;

public:
	CPlataformaConstruccion(int px, int py, String^ rutaPlataforma, String^ rutaConstruida) {
		x = px;
		y = py;
		imagenPlataforma = gcnew Bitmap(rutaPlataforma);
		imagenConstruida = gcnew Bitmap(rutaConstruida);
		espacios = gcnew List<CEspacioConstruible^>();
		construida = false;
		alphaConstruccion = 0;
		eliminada = false;
	}

	void agregarEspacio(CEspacioConstruible^ espacio) {
		espacios->Add(espacio);
	}

	void dibujar(Graphics^ g) {
		// Dibujar espacios primero (debajo de la plataforma)
		for each (CEspacioConstruible ^ espacio in espacios) {
			espacio->dibujar(g);
		}

		// Dibujar la plataforma base con transparencia usando su tamaño real
		if (!eliminada) {
			float alpha = construida ? (1.0f - alphaConstruccion / 255.0f) : 1.0f;

			System::Drawing::Imaging::ColorMatrix^ cmPlataforma = gcnew System::Drawing::Imaging::ColorMatrix();
			cmPlataforma->Matrix33 = alpha;

			System::Drawing::Imaging::ImageAttributes^ iaPlataforma = gcnew System::Drawing::Imaging::ImageAttributes();
			iaPlataforma->SetColorMatrix(cmPlataforma);

			int ancho = imagenPlataforma->Width;
			int alto = imagenPlataforma->Height;
			Rectangle destino = Rectangle(x, y, ancho, alto);

			g->DrawImage(imagenPlataforma, destino, 0, 0, ancho, alto, GraphicsUnit::Pixel, iaPlataforma);
		}

		// Dibujar la construcción final solo si está completa
		if (construida) {

			// Incrementar alpha para hacerla visible gradualmente
			if (alphaConstruccion < 255) {
				alphaConstruccion += 10; // velocidad del fade-in
			}

			if (alphaConstruccion >= 255) {
				eliminada = true; // marca para eliminar
			}

			int anchoObjeto = 250;
			int altoObjeto = 250;

			// Centrar horizontalmente encima de la plataforma
			//int cx = x + (imagenPlataforma->Width - anchoObjeto) / 2;
			int cx = x - 15;
			//int cy = y - altoObjeto + 10; // Ajuste vertical opcional
			int cy = y - 50;

			Rectangle destino(cx, cy, anchoObjeto, altoObjeto);

			// Crear transparencia
			System::Drawing::Imaging::ColorMatrix^ cm = gcnew System::Drawing::Imaging::ColorMatrix();
			cm->Matrix33 = alphaConstruccion / 255.0f;

			System::Drawing::Imaging::ImageAttributes^ ia = gcnew System::Drawing::Imaging::ImageAttributes();
			ia->SetColorMatrix(cm, System::Drawing::Imaging::ColorMatrixFlag::Default, System::Drawing::Imaging::ColorAdjustType::Bitmap);

			g->DrawImage(imagenConstruida, destino, 0, 0, imagenConstruida->Width, imagenConstruida->Height, GraphicsUnit::Pixel, ia);
		}
	}

	void verificarConstruccion() {
		for each (CEspacioConstruible ^ espacio in espacios)
			if (!espacio->estaLleno())
				return;

		if (!construida) {
			construida = true;
			alphaConstruccion = 0; // inicia desde transparente
		}
	}

	List<CEspacioConstruible^>^ obtenerEspacios() {
		return espacios;
	}

	bool estaConstruida() {
		return construida;
	}

	bool estaEliminada() {
		return eliminada;
	}

	Rectangle obtenerZonaConstruida() {
		return Rectangle(x + 10, y - 60, 50, 50); // para colisiones futuras, opcional
	}
};

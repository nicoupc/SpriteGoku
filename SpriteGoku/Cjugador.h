#pragma once

using namespace System::Drawing;

enum Direcciones
{
	Ninguna, Abajo, Arriba, Izquierda, Derecha
};

class CJugador
{
	int x, y, dx, dy;
	int ancho, alto;
	int indiceX, indiceY;
	Direcciones ultimaTecla;

public:
	CJugador();
	~CJugador();

	Direcciones direccion;

	CJugador(int x, int y)
	{
		this->x = x;
		this->y = y;
		dx = 0;
		dy = 0;
		ancho = 25; // Ancho del sprite
		alto = 39; // Alto del sprite
		indiceX = 0; // Índice de animación en X
		indiceY = 0; // Índice de animación en Y
		direccion = Ninguna;
		ultimaTecla = Abajo;
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp)
	{
		// Dibujar el sprite del jugador en la posición actual
		Rectangle posicion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 2, alto * 2);
		buffer->Graphics->DrawImage(bmp, aumentoPersonaje, posicion, GraphicsUnit::Pixel);

		x += dx;
		y += dy;
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp)
	{
		switch (direccion)
		{
		case Direcciones::Arriba:
			indiceX = 2;
			if (indiceY >= 0 && indiceY < 2)
			{
				indiceY++;
			}
			else
			{
				indiceY = 0;
			}
			dy = -10;
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Direcciones::Abajo:
			indiceX = 0;
			if (indiceY >= 0 && indiceY < 2)
			{
				indiceY++;
			}
			else
			{
				indiceY = 0;
			}
			dy = 10;
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Direcciones::Izquierda:
			indiceX = 1;
			if (indiceY >= 0 && indiceY < 2)
			{
				indiceY++;
			}
			else
			{
				indiceY = 0;
			}
			dy = 0;
			dx = -10;
			ultimaTecla = Izquierda;
			break;

		case Direcciones::Derecha:
			indiceX = 3;
			if (indiceY >= 0 && indiceY < 2)
			{
				indiceY++;
			}
			else
			{
				indiceY = 0;
			}
			dy = 0;
			dx = 10;
			ultimaTecla = Derecha;
			break;

		case Direcciones::Ninguna:
			// Si no se mueve, resetea la animación
			if (ultimaTecla == Arriba)
			{
				indiceX = 2;
				indiceY = 0;
			}
			else if (ultimaTecla == Abajo)
			{
				indiceX = 0;
				indiceY = 0;
			}
			else if (ultimaTecla == Izquierda)
			{
				indiceX = 1;
				indiceY = 0;
			}
			else if (ultimaTecla == Derecha)
			{
				indiceX = 3;
				indiceY = 0;
			}
			dy = 0;
			dx = 0;
			break;
		}
		dibujar(buffer, bmp);
	}
};

#pragma once

using namespace System::Drawing;

enum Direcciones
{
	Ninguna, Abajo, Izquierda, Derecha, Arriba
};

ref class CJugador
{
	int x, y, dx, dy;
	int ancho, alto;
	int indiceX, indiceY;
	Direcciones ultimaTecla;
	int tiempoInvulnerabilidad = 0;
	float factorVelocidad = 1.0f;

public:
	Direcciones direccion;

	CJugador(int x, int y)
	{
		this->x = x;
		this->y = y;
		dx = 0;
		dy = 0;
		ancho = 32;
		alto = 48;
		indiceX = 0; // Índice de animación en X
		indiceY = 0; // Índice de animación en Y
		direccion = Ninguna;
		ultimaTecla = Abajo;
	}

	void dibujar(BufferedGraphics^ buffer, Bitmap^ bmp, bool invulnerable) {
		Rectangle posicion = Rectangle(indiceX * ancho, indiceY * alto, ancho, alto);
		Rectangle aumentoPersonaje = Rectangle(x, y, ancho * 2, alto * 2);

		// Si no está invulnerable o toca renderizar (parpadeo), dibujar al jugador
		if (!invulnerable || (invulnerable && tiempoInvulnerabilidad % 4 < 2))
		{
			buffer->Graphics->DrawImage(bmp, aumentoPersonaje, posicion, GraphicsUnit::Pixel);
		}

		// Dibuja el cuadrado rojo si querés seguir visualizando colisión
		buffer->Graphics->DrawRectangle(gcnew Pen(Color::Red, 2), obtenerRectangulo());

		x += dx;
		y += dy;
	}

	void setTiempoInvulnerabilidad(int valor) {
		tiempoInvulnerabilidad = valor;
	}

	int getX() { return x; }
	int getY() { return y; }

	void activarVelocidad(float factor) {
		factorVelocidad = factor;
	}

	void restaurarVelocidad() {
		factorVelocidad = 1.0f;
	}


	Rectangle obtenerRectangulo() {
		return Rectangle(x + 10, y + 25, ancho * 2 - 25, alto * 2 - 30);
	}

	void mover(BufferedGraphics^ buffer, Bitmap^ bmp)
	{
		switch (direccion)
		{
		case Abajo:
			indiceY = 0;
			indiceX = (indiceX + 1) % 4;
			dy = static_cast<int>(15 * factorVelocidad);
			dx = 0;
			ultimaTecla = Abajo;
			break;

		case Izquierda:
			indiceY = 1;
			indiceX = (indiceX + 1) % 4;
			dy = 0;
			dx = -static_cast<int>(15 * factorVelocidad);
			ultimaTecla = Izquierda;
			break;

		case Derecha:
			indiceY = 2;
			indiceX = (indiceX + 1) % 4;
			dy = 0;
			dx = static_cast<int>(15 * factorVelocidad);
			ultimaTecla = Derecha;
			break;

		case Arriba:
			indiceY = 3;
			indiceX = (indiceX + 1) % 4;
			dy = -static_cast<int>(15 * factorVelocidad);
			dx = 0;
			ultimaTecla = Arriba;
			break;

		case Direcciones::Ninguna:
			indiceX = 0;
			dx = 0;
			dy = 0;
			indiceY = static_cast<int>(ultimaTecla) - 1; // mantener mirada en la última dirección
			break;
		}

		// Limitar el movimiento del jugador a los bordes arriba y abajo de la pantalla
		if (y < 0) y = 0; // Limite superior
		if (y + alto * 2 > buffer->Graphics->VisibleClipBounds.Height)
		{
			y = buffer->Graphics->VisibleClipBounds.Height - alto * 2; // Limite inferior
		}
		if (x < 0) x = 0; // Limite izquierdo
		if (x + ancho * 2 > buffer->Graphics->VisibleClipBounds.Width)
		{
			x = buffer->Graphics->VisibleClipBounds.Width - ancho * 2; // Limite derecho
		}
	}
};

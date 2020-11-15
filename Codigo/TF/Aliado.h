#pragma once
#include "Personaje.h"
#include <ctime>
class Aliado : public Personaje
{
	bool asociado;

public:
	Aliado(short x, short y, short ancho, short alto) :Personaje(x, y, ancho, alto) {
		this->subimgx = 11;
		this->subimgy = 4;
		asociado = false;
		srand(time(0));
	}

	bool getAsociado() {
		return this->asociado;
	}

	/*void setJugador(CJugador* oJugador) {
		this->oJugador = oJugador;
	}*/

	void setAsociado(bool asociado) {
		this->asociado = asociado;
	}

	void dibujar(Graphics^ g, Bitmap^ aliado)override {
		this->cdi = Rectangle(area_dibujo.X + ancho / 4 - 1, area_dibujo.Y + alto / 2, ancho / 4, alto / 4);
		this->cdd = Rectangle(area_dibujo.X + ancho / 2, area_dibujo.Y + alto / 2, ancho / 4 + 1, alto / 4);
		this->cda = Rectangle(area_dibujo.X + ancho / 3 + 2, area_dibujo.Y + alto / 3, ancho / 4, alto / 4 + 1);
		this->cdab = Rectangle(area_dibujo.X + ancho / 3 + 2, area_dibujo.Y + alto / 2 + 5, ancho / 4, alto / 2);
		g->DrawImage(aliado, area_dibujo, calcular_recorte(aliado), GraphicsUnit::Pixel);
	}

	void mover(Point nuevaPosicion ,int** escenario) {
		int v = 5;
		int resultadoAleatorio;


		if (dyab)iy = 0;
		if (dxi)iy = 1;
		if (dxd)iy = 2;
		if (dya)iy = 3;

		if (nuevaPosicion.X > area_dibujo.X) {
			dxd = nuevaPosicion.X- area_dibujo.X;
			dxi = 0;
		}
		else if (area_dibujo.X > nuevaPosicion.X) {
			dxi = nuevaPosicion.X-area_dibujo.X;
			dxd = 0;
		}
		else {
			dxi = 0;
			dxd = 0;
		}

		if (nuevaPosicion.Y > area_dibujo.Y) {
			dya = 0;
			dyab = nuevaPosicion.Y - area_dibujo.Y;
		}
		else if (area_dibujo.Y > nuevaPosicion.Y) {
			dya = nuevaPosicion.Y - area_dibujo.Y;
			dyab = 0;
		}
		else {
			dya = 0;
			dyab = 0;
		}


		/*if (dyab == 0 && dya == 0 && dxd == 0 && dxi == 0) {
			switch (rand() % 4) {
			case 0: dxi = -v; break;
			case 1:	dxd = v; break;
			case 2: dya = -v; break;
			case 3: dyab = v; break;
			}
		}
		else if (dyab == 0 && dya == 0 && dxd == 0)
			dxi = -v;
		else if (dyab == 0 && dya == 0 && dxi == 0)
			dxd = v;
		else if (dyab == 0 && dxi == 0 && dxd == 0)
			dya = -v;
		else if (dya == 0 && dxi == 0 && dxd == 0)
			dyab = v;*/

		/*if (asociado)
		{
			int diferenciaPosX = posJugador.X - area_dibujo.X;
			int diferenciaPosY = posJugador.Y - area_dibujo.Y;

			if (diferenciaPosX < 0)
			{
				if (posJugador.Width + 10 >= abs(diferenciaPosX))
				{
					dxi = 0;
					dxd = 0;
				}
				else {
					resultadoAleatorio = rand() % (abs(diferenciaPosX) - posJugador.Width - 10);
					if (resultadoAleatorio < 0)
						dxi = resultadoAleatorio;
					else
						dxd = resultadoAleatorio;
				}
			}
			else {
				if (ancho + 10 >= abs(diferenciaPosX))
				{
					dxi = 0;
					dxd = 0;
				}
				else {
					dxd = rand() % (abs(diferenciaPosX) - ancho - 10);
				}
			}

			if (diferenciaPosY < 0)
			{
				if (posJugador.Height + 10 >= abs(diferenciaPosY))
				{
					dya = 0;
					dyab = 0;
				}
				else {
					resultadoAleatorio = rand() % (abs(diferenciaPosY) - posJugador.Height - 10);
					if (resultadoAleatorio < 0)
						dya = resultadoAleatorio;
					else
						dyab = resultadoAleatorio;
				}
			}
			else {
				if (alto + 10 >= abs(diferenciaPosY))
				{
					dya = 0;
					dyab = 0;
				}
				else {
					dyab = rand() % (abs(diferenciaPosY) - alto - 10);
				}
			}

		}*/

		/*if (dxi > 0) {
			iy = 1;
			if (ix >= 0 && ix < 3) {
				ix++;
			}
			else
				ix = 0;
		}
		else if (dxd > 0) {
			iy = 2;
			if (ix >= 0 && ix < 3) {
				ix++;
			}
			else
				ix = 0;
		}
		else if (dya > 0) {
			iy = 3;
			if (ix >= 0 && ix < 3) {
				ix++;
			}
			else
				ix = 0;
		}
		else if (dyab > 0) {
			iy = 0;
			//indicex++;
			//indicex %= 4;
			if (ix >= 0 && ix < 3) {
				ix++;
			}
			else
				ix = 0;
		}
		else {
			ix = 0;
		}*/

		validar_mov(escenario);

		area_dibujo.X += dxi + dxd;
		area_dibujo.Y += dya + dyab;

		ix = ix + 1;
		if (ix == subimgx)
			ix = 0;
	}

	void mover(int** escenario)override {
		int v = 3;


		if (dyab)iy = 0;
		if (dxi)iy = 1;
		if (dxd)iy = 2;
		if (dya)iy = 3;

		if (dyab == 0 && dya == 0 && dxd == 0 && dxi == 0) {
			switch (rand() % 4) {
			case 0: dxi = -v; break;
			case 1:	dxd = v; break;
			case 2: dya = -v; break;
			case 3: dyab = v; break;
			}
		}
		else if (dyab == 0 && dya == 0 && dxd == 0)
			dxi = -v;
		else if (dyab == 0 && dya == 0 && dxi == 0)
			dxd = v;
		else if (dyab == 0 && dxi == 0 && dxd == 0)
			dya = -v;
		else if (dya == 0 && dxi == 0 && dxd == 0)
			dyab = v;

		validar_mov(escenario);

		area_dibujo.X += dxi + dxd;
		area_dibujo.Y += dya + dyab;

		ix = ix + 1;
		if (ix == subimgx)
			ix = 0;
	}
};


#pragma once
#include "Personaje.h"
class Corrupt: public Personaje
{
public:
	Corrupt(short x, short y, short ancho, short alto) :Personaje(x, y, ancho, alto)
	{
		this->subimgx = 8;
		this->subimgy = 4;
		//dxd = 3;
	}

	void dibujar(Graphics^ g, Bitmap^ corrupt)override {
		this->cdi = Rectangle(area_dibujo.X + ancho / 4 - 1, area_dibujo.Y + alto / 2, ancho / 4, alto / 4);
		this->cdd = Rectangle(area_dibujo.X + ancho / 2, area_dibujo.Y + alto / 2, ancho / 4 + 1, alto / 4);
		this->cda = Rectangle(area_dibujo.X + ancho / 3 + 2, area_dibujo.Y + alto / 3, ancho / 4, alto / 4 + 1);
		this->cdab = Rectangle(area_dibujo.X + ancho / 3 + 2, area_dibujo.Y + alto / 2 + 5, ancho / 4, alto / 2);
		g->DrawImage(corrupt, area_dibujo, calcular_recorte(corrupt),GraphicsUnit::Pixel);
	}

	void mover(int** escenario)override {
		int v = 3;
		

		if (dyab)iy = 0;
		if (dxi)iy =1;
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
		else if (dyab == 0 && dya == 0 && dxd ==0 ) dxi = -v;
		else if (dyab == 0 && dya == 0 && dxi == 0) dxd = v;
		else if (dyab == 0 && dxi == 0 && dxd == 0) dya = -v;
		else if (dya == 0 && dxi == 0 && dxd == 0) dyab = v;
       
		validar_mov(escenario);
		
		area_dibujo.X += dxi + dxd;
		area_dibujo.Y += dya + dyab;

		ix = ix + 1;
		if (ix == subimgx)
			ix = 0;
	}
};


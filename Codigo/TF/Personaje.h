#pragma once
#define FILAS 27
#define COLUMNAS 51
#include <iostream>
using namespace System::Drawing;
using namespace System;
class Personaje
{
protected:
	short ix, iy, dxi, dxd, dya,dyab;
	short x, y;
	short ancho, alto;
	short subimgx, subimgy;
	Rectangle area_dibujo;
	Rectangle cdi; //cuadro de izquierda
	Rectangle cdd; //cuadro de derecha
	Rectangle cda; //cuadro de arriba
	Rectangle cdab; //cuadro de abajo

	
public:
	Personaje(short x,short y,short ancho,short alto):
		x(x),y(y),ancho(ancho),alto(alto),dxd(0),dya(0),dxi(0),dyab(0),ix(0),iy(0)
	{
		area_dibujo = Rectangle(this->x, this->y, this->ancho, this->alto);
	}

	Rectangle getPosicion() {
		return area_dibujo;

	}

	virtual void dibujar(Graphics^ g, Bitmap^ personaje){
		
	}
	virtual void mover(int** escenario){}
protected:
	Rectangle calcular_recorte(Bitmap^ principal) {
		short ancho = principal->Width / subimgx;
		short alto = principal->Height / subimgy;
		short x = ix * ancho;
		short y = iy * alto;
		return Rectangle(x, y, ancho, alto);
	}

	void validar_mov(int** escenario)
	{
		short X = 0;
		short Y = 0;

		for (int i = 0; i < FILAS; i++)
		{
			X = 0;
			for (int j = 0; j < COLUMNAS; j++)
			{
				Rectangle c = Rectangle(X, Y, 30, 30);
				if (escenario[i][j] == 1)
				{
					if (cdi.IntersectsWith(c))
					{
						dxi = 0;
					}
					if (cdd.IntersectsWith(c))
					{
						dxd = 0;
					}
					if (cda.IntersectsWith(c))
					{
						dya = 0;
					}
					if (cdab.IntersectsWith(c))
					{
						dyab = 0;
					}

				}
				X += 30;
			}
			Y += 30;
		}
	}
};


#pragma once
#include <iostream>
#include <time.h>
#include <vector>

using namespace std;
using namespace System;
using namespace System::Drawing;
using namespace System::Windows::Forms;

class Entidad
{
protected:
	int x, y;
	int dx, dy;
	int ancho, alto;

	int IDx;
public:
	Entidad()
	{
		x = y = 0;
		dx = dy = 0;
		ancho = alto = 0;
		IDx = 0;
	}

	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	int GetDX()
	{
		return dx;
	}
	int GetDY()
	{
		return dy;
	}
	int GetAncho()
	{
		return ancho;
	}
	int GetAlto()
	{
		return alto;
	}
	int GetIDx()
	{
		return IDx;
	}

	void SetX(int value)
	{
		x = value;
	}
	void SetY(int value)
	{
		y = value;
	}
	void SetDX(int value)
	{
		dx = value;
	}
	void SetDY(int value)
	{
		dy = value;
	}
	void SetAncho(int value)
	{
		ancho = value;
	}
	void SetAlto(int value)
	{
		alto = value;
	}

	Rectangle Area()
	{
		return Rectangle(x, y, ancho, alto);
	}
	Rectangle NextArea()
	{
		return Rectangle(x + dx, y + dy, ancho, alto);
	}

	Rectangle HitBox()
	{
		double alfa = 0.5; // 0 -> 1
		int ancho = this->ancho * alfa;
		int alto = this->alto * alfa;
		return Rectangle(x + ancho / 2, y + alto / 2, ancho, alto);
	}

	virtual void Mover(Graphics^ g)
	{
		x += dx;
		y += dy;
	}
	virtual void Mostrar(Graphics^ g, Bitmap^ img)
	{
		g->FillRectangle(Brushes::Black, x, y, ancho, alto);
	}
};
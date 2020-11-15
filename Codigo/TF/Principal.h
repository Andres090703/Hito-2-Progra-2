#pragma once
#include "Personaje.h"
#include <queue>

using namespace std;

class Principal :public Personaje
{
	int maximoAsociados;
	int numeroAsociados;
	queue<pair<int, int>>* movimientos;

public:
	Principal(short x, short y, short ancho, short alto) :Personaje(x, y, ancho, alto) {
		this->subimgx = 12;
		this->subimgy = 4;
		this->maximoAsociados = 2;
		this->numeroAsociados = 0;
		movimientos = new queue<pair<int, int>>;
	}

	queue<pair<int,int>>* getMovimientos() {
		return movimientos;
	}


	int getMaximoAsociados() {
		return maximoAsociados;
	}
	void setMaximoAsociados(int maximoAsociados) {
		this->maximoAsociados = maximoAsociados;
	}

	int getNumeroAsociados() {
		return numeroAsociados;
	}
	void setNumeroAsociados(int numeroAsociados) {
		this->numeroAsociados = numeroAsociados;
	}

	void dibujar(Graphics^ g, Bitmap^ principal)override {
		this->cdi = Rectangle(area_dibujo.X + ancho / 4 - 1, area_dibujo.Y + alto / 2, ancho / 4, alto / 4);
		this->cdd = Rectangle(area_dibujo.X + ancho / 2, area_dibujo.Y + alto / 2, ancho / 4 + 1, alto / 4);
		this->cda = Rectangle(area_dibujo.X + ancho / 3 + 2, area_dibujo.Y + alto / 3, ancho / 4, alto / 4 + 1);
		this->cdab = Rectangle(area_dibujo.X + ancho / 3 + 2, area_dibujo.Y + alto / 2 + 5, ancho / 4, alto / 2);
		g->DrawImage(principal,area_dibujo,calcular_recorte(principal),GraphicsUnit::Pixel);
		
	}
	void parar() { ix = 0; dxi = 0; dya = 0; dxd = 0; dyab = 0; }

		void mover(int i, int**escenario) {

				this->iy = i;
				switch (iy)
				{
				case 0: dyab=5;   break; //abajo
				case 1: dxi=-5; break; //izquierda
				case 2: dxd=5;  break; //derecha
				case 3: dya=-5; break; //arriba

				}

				validar_mov(escenario);
				
				area_dibujo.X += dxi + dxd;
				area_dibujo.Y += dya + dyab;

				pair<int, int> miPair = make_pair(area_dibujo.X, area_dibujo.Y);

				movimientos->push(miPair);

				++this->ix;
				if (ix == 12)
					ix = 0;
		
		}

		void volver_transparente(Bitmap^ principal) {
			Color color=principal->GetPixel(0, 0);
			principal->MakeTransparent(color);
		}

	
};


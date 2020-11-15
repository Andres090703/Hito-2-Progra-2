#pragma once
#include<iostream>
#include <time.h>
using namespace std;
using namespace System;
using namespace System::Drawing;
#define FILAS 27
#define COLUMNAS 51

class CEscenario
{
private:
	int** escenario;
public:
	CEscenario() {
		escenario = new int* [FILAS];
		for (int i = 0; i < FILAS; i++)
			this->escenario[i] = new int[COLUMNAS];
	}

	~CEscenario() {
		for (int i = 0; i < FILAS; i++)
			delete this->escenario[i];
		delete[] this->escenario;
	}

	void Crear_Matriz() {

		srand(time(NULL));

		for (int f = 0; f < FILAS; f++)
		{
			
			for (int c = 0; c < COLUMNAS; c++)
			{
				int v = rand() % 4;
				if (f == 0 || f == FILAS - 1 || c == 0 || c == COLUMNAS - 1)
					escenario[f][c] = 1;
				else
				{
					if (f % 2 != 0 && c % 2 != 0)
					{
						escenario[f][c] = 0;
					}
					else
						if(f%2==0 && c%2==0)
					{
						escenario[f][c] = 1;

						if (v == 0) escenario[f][c + 1] = 1;

						if (v == 1) escenario[f][c - 1] = 1;

						if (v == 2) escenario[f + 1][c] = 1;

						if (v == 3) escenario[f - 1][c] = 1;
					}
						else
							if(escenario[f][c]!=0 && escenario[f][c]!=1)
							escenario[f][c] = 0;

					
				}

			}
		}
	}


	void pintar_suelo(Graphics^ g, Bitmap^ base){
		short x, y;
		x = y = 0;
		for (int i = 0; i < FILAS; i++)
		{
			x = 0;
			for (int j = 0; j < COLUMNAS; j++)
			{
				if (escenario[i][j] == 0)
					g->DrawImage(base, x, y, 30, 30);
				x += 30;
			}
			y += 30;
	    }
	}

	void pintar_pared(Graphics^ g, Bitmap^ pared) {
		short x, y;
		x = y = 0;
		for (int i = 0; i < FILAS; i++)
		{
			x = 0;
			for (int j = 0; j < COLUMNAS; j++)
			{
				if (escenario[i][j] == 1)
					g->DrawImage(pared, x, y, 30, 30);
				x += 30;
			}
			y += 30;
		}
	}

	int** get_escenario() { return escenario; }
};


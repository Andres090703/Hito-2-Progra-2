#pragma once
#include "CEscenario.h"
#include "Principal.h"
#include "Corrupt.h"
#include "asesino.h"
#include "Aliado.h"
ref class CJuego
{
	Bitmap^ corrupt;
	Bitmap^ suelo;
	Bitmap^ pared;
	Bitmap^ prota;
	Bitmap^ asesin;
	Bitmap^ aliad;
	CEscenario* escenario;
	Principal* principal;
	Corrupt* corrupto;
	Asesino* asesino;
	Aliado* aliado;

public:
	CJuego() { this->escenario = new CEscenario(); 
	this->principal = new Principal(25,5,40,50);
	this->corrupto = new Corrupt(25,5,40, 50);
	this->asesino = new Asesino(25, 5, 40, 50);
	this->aliado = new Aliado(25,5,40,50);
	this->pared = gcnew Bitmap("Imagenes\\Pared.png");
	this->suelo = gcnew Bitmap("Imagenes\\Suelo.png");
	this->prota = gcnew Bitmap("Imagenes\\Principal.png");
	this->corrupt = gcnew Bitmap("Imagenes\\Corrupt.png");
	this->asesin = gcnew Bitmap("Imagenes\\Asassin.png");
	this->aliad = gcnew Bitmap("Imagenes\\Aliado.png");

	}
	~CJuego() { delete this->escenario, suelo, pared,corrupt, prota, principal, corrupto; }

	void cambiar_escenario() { this->escenario->Crear_Matriz(); }
	

	void dibujar(Graphics^g) {
	    this->escenario->pintar_suelo(g, this->suelo);
		this->escenario->pintar_pared(g, this->pared);

	}

	void parar() { principal->parar(); }

	void detectarColisionAliado() {
		//Rectangle posJugador = Rectangle(x, y, ancho, alto);

		if (principal->getPosicion().IntersectsWith(aliado->getPosicion()))
		{
			if (principal->getNumeroAsociados() <= principal->getMaximoAsociados()) {
				if (!aliado->getAsociado())
				{
					aliado->setAsociado(true);
					principal->setNumeroAsociados(principal->getNumeroAsociados() + 1);
				}
			}
		}
	}

	void dibujar_prota(Graphics^ g) {

		this->principal->dibujar(g, this->prota);
		this->corrupto->dibujar(g, this->corrupt);
		this->asesino->dibujar(g,this->asesin);
		this->aliado->dibujar(g, this->aliad);
	}

	void mover_prota(int i) { 
		principal->mover(i,escenario->get_escenario()); 
		detectarColisionAliado();
	}
	void mover_corrupt() {
		corrupto->mover(escenario->get_escenario());
	}
	void mover_asesino() {
		asesino->mover(escenario->get_escenario());
	}
	void mover_aliado() {
		int qsize = this->principal->getMovimientos()->size();
		if (qsize > 10) {
			
			aliado->mover(Point(this->principal->getMovimientos()->front().first, this->principal->getMovimientos()->front().second), escenario->get_escenario());
			this->principal->getMovimientos()->pop();
		}
			
	}

	void volver_prota_transparente() { principal->volver_transparente(prota); }
};


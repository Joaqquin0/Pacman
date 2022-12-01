#pragma once
#include"Pacman.h"
#include"Enemigos.h"
#include"Puntos.h"
#include"Boost.h"

using namespace std;

class Controlador
{
private:

	vector<Boost*>* arrB;
	//Boost* boost;
	vector<Enmigo*>* arrE;
	vector<Puntos*>* arrP;
	Pacmans* pacman;
	int puntoss;

public:
	Controlador(Bitmap^ bmppac, Bitmap^ bmpboost, int vidas) {

		arrE = new vector<Enmigo*>();
		arrP = new vector<Puntos*>();
		arrB = new vector<Boost*>();

		pacman = new Pacmans(bmppac->Width / 14, bmppac->Height / 4, vidas);

		//boost = new Boost(bmpboost->Width / 4, bmpboost->Height);
				//boost

		for (int i = 0; i < 5; i++)
		{
			arrB->push_back(new Boost(bmpboost->Width / 4, bmpboost->Height));
		}

		puntoss = 0;



	}
	~Controlador(){}

	void agregarenemigo(Bitmap^ bmppac){
	
		for (short i = 1; i < 8; ++i)
		{
			arrE->push_back(new Enmigo(bmppac->Width / 14, bmppac->Height / 4));
		}
	}

	void agregarPuntos(Bitmap^ bmpPunto) {


		for (short i = 1; i < 15; ++i)
		{
			arrP->push_back(new Puntos(bmpPunto->Width, bmpPunto->Height));
		}

	}

	void dibujartodo(Graphics^ gr, Bitmap^ bmppac,Bitmap^ bmpbonus, Bitmap^ bmpPunto) {

		for (int i = 0; i < arrE->size(); i++)
		{
			arrE->at(i)->dibujar(gr, bmppac);
		}

		for (int i = 0; i < arrP->size(); i++)
		{
			arrP->at(i)->dibujars(gr, bmpPunto);
		}

		for (int i = 0; i < arrB->size(); i++)
		{
			arrB->at(i)->dibujarss(gr,bmpbonus);
		}

		pacman->dibujar(gr, bmppac);

	}

	void movertodo(Graphics^ gr) {

		for (int i = 0; i < arrE->size(); i++)
		{
			arrE->at(i)->mover(gr);
		}


	}

	Pacmans* getpacman() { return pacman; }

	void colision(){
	
	
	//pacman con fantasmas

		for (int i = 0; i < arrE->size(); i++)
		{
			if (pacman->getRectangle().IntersectsWith(arrE->at(i)->getRectangle()))
			{
				
				pacman->setx(500);
				pacman->sety(20);
				pacman->perdervidas();
				
			}
		}
	
	
	// puntos con pacman

		for (int i = 0; i < arrP->size(); i++)
		{
			if (pacman->getRectangle().IntersectsWith(arrP->at(i)->getRectangles()))
			{
				puntoss++;
				arrP->at(i)->setvisible(false);
				
			}
		}
	//Bonus pacman

		for (int  i = 0; i < arrB->size(); i++)
		{
			if (pacman->getRectangle().IntersectsWith(arrB->at(i)->getRectangles()))
			{
				pacman->boost();
				arrB->at(i)->setvisible(false);
			}
		}



		
	//borrar del arreglo 

		for (int i = 0; i < arrP->size(); i++)
		{
			if (!arrP->at(i)->getvisible())
			{
				
				arrP->erase(arrP->begin() + i);
			}
		}

		for (int i = 0; i < arrB->size(); i++)
		{
			if (!arrB->at(i)->getvisible())
			{

				arrB->erase(arrB->begin() + i);
			}
		}
	
	}

	int getpuntos() { return this->puntoss; }

	int getganar() {

		return arrP->size();

	}
};


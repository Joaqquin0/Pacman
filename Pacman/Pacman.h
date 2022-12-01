#pragma once
#include"Entidad.h"

class Pacmans:public Entidad
{
private:

	int vidas;

public:
	Pacmans(int W, int H, int vidas){
		
		this->W = W;
		this->H = H;
		x = 500;	
		y = 50;
		dx = dy = 20;
		this->vidas = vidas;
		indiceW = 10;
		indiceH = 0;
		

	}
	~Pacmans(){}

	void mover(Graphics^ gr, char Tecla) {

		switch (Tecla)
		{
		case 'A':

			if (x + dx > 0) {

				x -= dx;
				indiceH = 2;

			}

			break;

		case 'D':

			if (x + W + dx < gr->VisibleClipBounds.Width) {

				x += dx;
				indiceH = 0;
	

			}
			break;

		case 'W':

			if (y > 0) {

				y -= dy;
				indiceH = 3;
			
			}

			break;

		case 'S':

			if (y + H + dy < 790) {

				y += dy;
				indiceH = 1;
			

			}
			break;

		}


		indiceW++;
		if (indiceW > 11)
		{
			indiceW = 10;
		}


	}




	void boost() { dx=dy += 5; }

	int gethp() { return vidas; }
	void perdervidas() { vidas--; }


};


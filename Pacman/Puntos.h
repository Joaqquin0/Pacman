#pragma once
#include"Entidad.h"

class Puntos:public Entidad
{
private:

	int radio;

public:
	Puntos(int W, int H) {
		Random m, n;
		this->W = W;
		this->H = H;
		x = 4 + rand() % 621;
		y = 10 + rand()% 518;

		radio = 5;
	}
	~Puntos(){}

	void dibujars(Graphics^ gr, Bitmap^ bmp) {

		bmp->MakeTransparent(bmp->GetPixel(1, 1)); // transparencia
		gr->DrawImage(bmp, x, y, W * 1, H * 1); //
	}

	Rectangle getRectangles() { //para colision

		return Rectangle(x, y, W * 1, H *1 );

	}

};


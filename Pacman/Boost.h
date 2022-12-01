#pragma once
#include"Entidad.h"

class Boost:public Entidad
{
private:


public:
	Boost(int W, int H) {

		this->W = W;
		this->H = H;

		x = 2 + rand() % (500);
		y = 2 + rand() % (400);

		indiceW = 0 + rand() % (4);

	}
	~Boost(){}

	void dibujarss(Graphics^ gr, Bitmap^ bmp) {
		//porcion del sprite a mostrar
		Rectangle porcionSprite = Rectangle(indiceW * W, indiceH * H, W, H);
		//porsicon donde se mostrara el sprote , modificar tamano
		bmp->MakeTransparent(bmp->GetPixel(1, 1)); // transparencia
		Rectangle zoom = Rectangle(x, y, W * 0.8, H * 0.8); //multiplicar w y h para cambiar tamano
		//dibujar
		gr->DrawImage(bmp, zoom, porcionSprite, GraphicsUnit::Pixel);

	}

	Rectangle getRectangles() { //para colision

		return Rectangle(x, y, W * 0.8, H * 0.8);

	}

};


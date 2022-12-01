#pragma once
#include"Entidad.h"

class Enmigo: public Entidad
{
private:

	int id;

public:
	Enmigo(int W, int H) {

		this->W = W;
		this->H = H;
		Random r;
		Random h, j;

		x = 6 + rand() % 621; //muy importante usar randl para que aparescan los puntos y enemos en cualquier lugar
		y = 10 +rand() %  518;

		dx = dy = j.Next(6,10);

		indiceH = 0;
		indiceW = 0;

		id = 1+rand()%3;

	}
	~Enmigo(){}

	void mover(Graphics^ gr) {

		switch (id)
		{
		case 1:

			if (x + dx<0 || x + dx + W>gr->VisibleClipBounds.Width)
			{
				dx *= -1;
			}if (dy > 0)
			{
				indiceH = 0;

			}
			else
			{
				indiceH = 1;
			}
			x += dx;

			if (y + dy<0 || y + dy + H>gr->VisibleClipBounds.Height)
			{
				dy *= -1;
			}if (dy > 0)
			{
				indiceH = 1;

			}
			else
			{
				indiceH = 3;
			}
			y += dy;

			indiceW++;
			if (indiceW > 1) {

				indiceW = 0;
			}

			break;
		case 2:

			indiceW = 2;
			if (x + dx<0 || x + dx + W>gr->VisibleClipBounds.Width)
			{
				dx *= -1;
			}if (dy > 0)
			{
				indiceH = 0;

			}
			else
			{
				indiceH = 2;
			}
			x += dx;

			if (y + dy<0 || y + dy + H>gr->VisibleClipBounds.Height)
			{
				dy *= -1;
			}if (dy > 0)
			{
				indiceH = 1;

			}
			else
			{
				indiceH = 3;
			}
			y += dy;

			indiceW++;
			if (indiceW > 3) {

				indiceW = 2;
			}
			break;
		case 3: 

			indiceW = 7;
			if (x + dx<0 || x + dx + W>gr->VisibleClipBounds.Width)
			{
				dx *= -1;
			}if (dy > 0)
			{
				indiceH = 0;

			}
			else
			{
				indiceH = 2;
			}
			x += dx;

			if (y + dy<0 || y + dy + H>gr->VisibleClipBounds.Height)
			{
				dy *= -1;
			}if (dy > 0)
			{
				indiceH = 1;

			}
			else
			{
				indiceH = 3;
			}
			y += dy;

			indiceW++;
			if (indiceW > 8) {

				indiceW = 7;
			}
			break;

		default:
			break;
		}



	}



};


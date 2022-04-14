#include "Patrat.h"

Patrat::Patrat()
{
	this->x = 0;
	this->y = 0;
	this->latura = 0;
	this->aria = 0;
	this->perimetru = 0;
	this->diagonala = 0.0;
}

Patrat::Patrat(float l, float x, float y)
{
	this->x = x;
	this->y = y;
	this->latura = l;
	this->perimetru = 4 * l;
	this->aria = l * l;
	this->diagonala = l * sqrt(2);
}

Patrat::~Patrat()
{
}

float Patrat::getX()
{
	return this->x;
}

float Patrat::getY()
{
	return this->y;
}

float Patrat::getLatura()
{
	return this->latura;
}

float Patrat::getAria()
{
	return this->aria;
}

float Patrat::getPerimetru()
{
	return this->perimetru;
}

float Patrat::getDiagonala()
{
	return this->diagonala;
}

void Patrat::setLatura(float l)
{
	this->latura = l;
	this->y = x + l;
	this->perimetru = 4 * l;
	this->aria = l * l;
	this->diagonala = l * sqrt(2);
}

void Patrat::setAria(float a)
{
	this->aria = a;
	this->latura = a / this->latura;
	this->y = this->x + this->latura;
	this->diagonala = this->latura * sqrt(2);
	this->perimetru = this->latura * 4;
}

void Patrat::setPerimetru(float p)
{
	this->perimetru = p;
	this->latura = this->perimetru / 4;
	this->y = this->x + this->latura;
	this->aria = this->latura * this->latura;
	this->diagonala = this->latura * sqrt(2);
}

void Patrat::setDiagonala(float d)
{
	this->diagonala = d;
	this->latura = this->diagonala / sqrt(2);
	this->y = this->x + this->latura;
	this->aria = this->latura * this->latura;
	this->perimetru = this->latura * 4;
}

Patrat& Patrat::operator+(const Patrat& other)
{
	if (this->x > other.x)
		this->x = other.x;
	if (this->y < other.y)
		this->y = other.y;

	this->setLatura(this->latura + other.latura);

	return *this;
}

bool Patrat::operator==(const Patrat& other) const
{
	return this->latura == other.latura;
}

bool Patrat::operator>(const Patrat& other) const
{
	return this->latura > other.latura;
}

bool Patrat::inCerculGeometric()
{
	return this->x > 0 && this->y > 0;
}

Patrat maxim(map<int, Patrat> patrate, unsigned int nrPatrate)
{
	Patrat maxim = Patrat();
	map<int, Patrat>::iterator itr;

	for (itr = patrate.begin(); itr != patrate.end(); ++itr)
	{
		if (itr->second > maxim)
			maxim = itr->second;
	}
	return maxim;
}

int secventaEgale(map<int, Patrat> patrate, unsigned int nrPatrate)
{
	unsigned int lungimeSecventa = 1, lungimeMaximaSecventa = lungimeSecventa;
	Patrat patratCurent = patrate[0];
	map<int, Patrat>::iterator itr;

	for (itr = patrate.begin(); itr != patrate.end(); ++itr)
	{
		if (itr->second == patratCurent) {
			lungimeSecventa++;
			patratCurent = itr->second;
		}
		else {
			if (lungimeSecventa > lungimeMaximaSecventa)
				lungimeMaximaSecventa = lungimeSecventa;
			patratCurent = itr->second;
			lungimeSecventa = 1;
		}
	}
	return lungimeMaximaSecventa;
}

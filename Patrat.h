#pragma once
#include <iostream>
#include <map>
using namespace std;

class Patrat {
public:
	Patrat();
	Patrat(float l, float x, float y);

	~Patrat();

	// Getters
	float getX();
	float getY();
	float getLatura();
	float getAria();
	float getPerimetru();
	float getDiagonala();

	// Setters

	void setLatura(float l);
	void setAria(float a);
	void setPerimetru(float p);
	void setDiagonala(float d);

	// Operators

	Patrat& operator+(const Patrat& other);
	bool operator==(const Patrat& other) const;
	bool operator>(const Patrat& other) const;

	// Cercul Geometric Cadran I

	bool inCerculGeometric();

private:
	float x, y;
	float latura;
	float aria;
	float perimetru;
	float diagonala;
};

Patrat maxim(map<int, Patrat> patrate, unsigned int nrPatrate);
int secventaEgale(map<int, Patrat>, unsigned int nrPatrate);
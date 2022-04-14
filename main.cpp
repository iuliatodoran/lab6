#include <iostream>
#include "Patrat.h"
#include "PatratTest.h"
#include <iterator>
#include <map>
using namespace std;

int main() {
	PatratTest::runAllTests();
	Patrat p1 = Patrat(1, 0, 0), p2 = Patrat(2, -1, -3), p3 = Patrat(3, 1, 2), p4 = Patrat(4, -1, 2);

	map<int, Patrat> patrate;
	
	patrate.insert(pair<int, Patrat>(1, p1));
	patrate.insert(pair<int, Patrat>(2, p2));
	patrate.insert(pair<int, Patrat>(3, p3));
	patrate.insert(pair<int, Patrat>(4, p4));

	map<int, Patrat>::iterator itr;

	// Afisare informatii
	for (itr = patrate.begin(); itr != patrate.end(); ++itr)
	{
		cout << "Coordonate: (" << itr->second.getX() << ", " << itr->second.getY() << ") \m";
		cout << "Latura: " << itr->second.getLatura() << '\n';
		cout << "Perimetru: " << itr->second.getPerimetru() << '\n';
		cout << "Diagonala: " << itr->second.getDiagonala() << '\n';
		cout << "Aria: " << itr->second.getAria() << '\n';
	}
	// Afisare cel mai mare patrat
	Patrat patratMax = maxim(patrate, 4);
	cout << "Cel mai mare patrat are latura: " << patratMax.getLatura() << '\n';

	// Afisare cele care se afla in primul cadran din Cercul Geometric
	for (int i = 0; i < 4; i++)
	{
		if (patrate[i].inCerculGeometric())
			cout << "Patratul " << i + 1 << " se afla in primul cadran al cercului geometric." << '\n';
	}

	// Identificare cea mai lunga secventa de patrate egale
	cout << "Cea mai lunga secventa de patrate egale are lungimea de: " << secventaEgale(patrate, 4) << '\n';

	return 0;
}
#include "PatratTest.h"

void PatratTest::runAllTests()
{
	creationTest();
	gettersSettersTests();
	operatorTest();
}

int PatratTest::creationTest()
{
	Patrat patrat = Patrat();

	assert(patrat.getLatura() == 0);
	assert(patrat.getPerimetru() == 0);
	assert(patrat.getAria() == 0);
	assert(patrat.getDiagonala() == 0.0);

	return 0;
}

int PatratTest::gettersSettersTests()
{
	Patrat patrat = Patrat();

	assert(patrat.getLatura() == 0);
	assert(patrat.getPerimetru() == 0);
	assert(patrat.getAria() == 0);
	assert(patrat.getDiagonala() == 0.0);

	patrat.setLatura(2);
	assert(patrat.getAria() == 4.0);
	assert(patrat.getPerimetru() == 2.0 * 4);

	patrat.setAria(4);
	assert(patrat.getLatura() == 2.0);
	assert(patrat.getPerimetru() == 2.0 * 4);

	return 0;
}

int PatratTest::operatorTest()
{
	Patrat p1 = Patrat(2, 0, 0), p2 = Patrat(2, 0, 0);
	Patrat p3 = p1 + p2;

	assert(p3.getLatura() == 4.0);
	assert(p3.getPerimetru() == 4.0 * 4);
	assert(p3.getAria() == 4.0 * 4.0);

	map<int, Patrat> patrate;

	Patrat p4 = Patrat(4, 0, 0), p5 = Patrat(6, 0, 0);

	patrate.insert(pair<int, Patrat>(1, p1));
	patrate.insert(pair<int, Patrat>(2, p2));
	patrate.insert(pair<int, Patrat>(3, p3));
	patrate.insert(pair<int, Patrat>(4, p4));
	patrate.insert(pair<int, Patrat>(5, p5));

	assert(maxim(patrate, 5).getLatura() == 6);
	assert(secventaEgale(patrate, 5) == 2);

	return 0;
}

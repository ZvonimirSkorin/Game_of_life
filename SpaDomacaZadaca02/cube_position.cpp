#include "cube_position.h"

void cube_position::add(sf::RectangleShape rec, sf::RectangleShape okvir, bool nextStanje)
{
	this->rec = rec;
	this->okvir = okvir;
	this->nextStanje = nextStanje;

}

sf::RectangleShape cube_position::send()
{

	return rec;
}

sf::RectangleShape cube_position::sendOkvir()
{
	return okvir;
}

bool cube_position::zivoNezivo()
{
	return stanje;
}

void cube_position::promjenaStanja()
{
	stanje = nextStanje;
	if (stanje) {
		okvir.setFillColor(sf::Color::Green);
	}
	else {
		stanje = false; okvir.setFillColor(sf::Color::Black);
	}
}

void cube_position::set(bool is)
{
	if (is) {
		nextStanje = true;
	}
	else { nextStanje = false; }
}


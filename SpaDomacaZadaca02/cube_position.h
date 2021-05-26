#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
class cube_position
{
private:
	sf::RectangleShape rec;
	sf::RectangleShape okvir;
	bool stanje;
	bool nextStanje = false;

public:
	void add(sf::RectangleShape rec, sf::RectangleShape okvir, bool stanje);
	sf::RectangleShape send();
	sf::RectangleShape sendOkvir();
	bool zivoNezivo();
	void promjenaStanja();
	void set(bool is);

};


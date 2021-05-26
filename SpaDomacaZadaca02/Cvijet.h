#pragma once
#include<SFML/Graphics.hpp>
#include<vector>
#include<chrono>
#include "cube_position.h"
using namespace std;
using namespace sf;
class Cvijet
{
public:
	Cvijet(sf::RenderWindow* window);
	bool draw();
	int draw_manual();
	int counter = 0;

private:
	sf::RenderWindow* window;
	std::vector<vector<cube_position>> vec;
	chrono::high_resolution_clock sat;
	chrono::high_resolution_clock::time_point t_point = sat.now();
	chrono::high_resolution_clock::time_point t_point_second;
};




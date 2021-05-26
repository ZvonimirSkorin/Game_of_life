#include "Cvijet.h"
#include<string>
#include<sstream>
#include<algorithm>
#include<ctime>
#include<random>
#include<iostream>
using namespace std;
using namespace sf;

bool randomStanje() {

	return rand() % 4 == 1;
}

void draw_net(vector<vector<cube_position>>& polje) {
	vector<cube_position>pom;
	sf::RectangleShape rectangle2(sf::Vector2f(9, 9));
	cube_position cb;
	for (int i = 0; i < 80; i++) {
		bool stanje;
		for (int j = 0; j < 60; j++) {
			bool rand = randomStanje();
			sf::RectangleShape rectangle(sf::Vector2f(10, 10));
			Transform tran;
			rectangle.setFillColor(sf::Color::Blue);
			rectangle.setPosition(10 * i, 10 * j);
			if (rand)		rectangle2.setFillColor(sf::Color::Green);
			else			rectangle2.setFillColor(sf::Color::Black);
			rectangle2.setPosition(10 * i, 10 * j);

			cb.add(rectangle, rectangle2, randomStanje());
			pom.push_back(cb);
		}

		polje.push_back(pom);
		pom.clear();
	}
}

void kalkuliraj(std::vector<vector<cube_position>>& vec, int counter) {
	for (int i = 0; i < 80; i++) {
		for (int j = 0; j < 60; j++) {
			if (!counter) {
				vec[i][j].promjenaStanja();
			}
			int brojac = 0;
			if (i - 1 > -1 && j - 1 > -1) { if (vec[i - 1][j - 1].zivoNezivo())brojac++; }
			if (i > -1 && j - 1 > -1) { if (vec[i][j - 1].zivoNezivo()) brojac++; }
			if (i + 1 < 80 && j - 1 > -1) { if (vec[i + 1][j - 1].zivoNezivo())brojac++; }
			if (i + 1 < 80) { if (vec[i + 1][j].zivoNezivo())brojac++; }
			if (i + 1 < 80 && j + 1 < 60) { if (vec[i + 1][j + 1].zivoNezivo())brojac++; }
			if (j + 1 < 60) { if (vec[i][j + 1].zivoNezivo())brojac++; }
			if (i - 1 > -1 && j + 1 < 60) { if (vec[i - 1][j + 1].zivoNezivo())brojac++; }
			if (i - 1 > -1) { if (vec[i - 1][j].zivoNezivo())brojac++; }

			if (brojac == 3) {
				vec[i][j].set(true);
			}
			else if (brojac < 2 || brojac>3) {
				vec[i][j].set(false);
			}

		}
	}

}

Cvijet::Cvijet(sf::RenderWindow* window)
{
	srand(time(nullptr));

	this->window = window;
	draw_net(vec);
}

bool Cvijet::draw()
{

	bool flag = false;
	bool flagSw = false;
	t_point_second = sat.now();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{
		flag = false;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{
		flag = true;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		window->close();
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		flagSw=true;
		return flagSw;
	}
	else
		if (chrono::duration_cast<chrono::seconds>(t_point_second - t_point).count() > 2) {

			t_point = sat.now();
			flag = true;
		}
	if (flag) {
		kalkuliraj(vec, counter);
	}
	for (int i = 0; i < 80; i++) {


		{
			for (int j = 0; j < 60; j++) {

				window->draw(vec[i][j].send());
				window->draw(vec[i][j].sendOkvir());
			}
		}


	}
	return flagSw;
}

int Cvijet::draw_manual()
{
	int a;
	cout << "Exit-0 // Next step-1 // switch mode-2 "<<endl;
	std::cin >> a;
	if (a == 1) {
		kalkuliraj(vec, counter);

		for (int i = 0; i < 80; i++) {



			for (int j = 0; j < 60; j++) {

				window->draw(vec[i][j].send());
				window->draw(vec[i][j].sendOkvir());
			}

		}

	}
	return a;
}


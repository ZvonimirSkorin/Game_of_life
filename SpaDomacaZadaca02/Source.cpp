#include <SFML/Graphics.hpp>
#include "Cvijet.h"
#include<fstream>
#include<chrono>
#include<iostream>


int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Game of life");
	window.setFramerateLimit(60);
	Cvijet go(&window);
	Cvijet game_of_life(&window);
	cout << "Odaberite mode (automatic, manual)-(0,1)"<<endl;
	bool a;
	cin >> a;
	poc:
	if (a) {
		while (window.isOpen())
		{
			bool flag = false;
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			int fl=game_of_life.draw_manual();
			if(fl==0)
			{
				
					window.close();
			}
			else if (fl == 2) {
				a = 0;
				goto poc;
			}
			window.display();

		}
	}
	else {
		bool flagSw = false;
		cout << "Arrow left-stop" << endl << "Arrow right-ubrzaj" << endl << "Arrow up-end"<<endl << "Arrow down-switch to manual";
		while (window.isOpen())
		{
			bool flag = false;
			sf::Event event;

			while (window.pollEvent(event))
			{
				if (event.type == sf::Event::Closed)
					window.close();
			}

			window.clear();
			flagSw=game_of_life.draw();
			if (flagSw) { a = 1; goto poc; }
			window.display();

		}
	}
	cout << endl << "Thank you for playing!";
	return 0;
}
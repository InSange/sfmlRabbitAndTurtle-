#include <SFML/Graphics.hpp>
#include "animal.h"
#include "turtle.h"
#include "rabbit.h"
#include <iostream>
#include <Windows.h>
#include <ctime>

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(1500, 720), "Rabbit and Turtle");
	
	srand(time(nullptr));

	int num;
	int count = 0;

	/*Turtle* turtle = new Turtle(500, 5);
	Rabbit rabbit(100, 20);*/

	Animal *turtle = new Turtle(500, 5);
	Rabbit *rabbit = new Rabbit(100, 20);
	


	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
			/*if (turtle.goal()) {
				cout << "°ÅºÏÀÌ ½Â!!!" << endl;
				window.close();
			}
			else if (rabbit.goal()) {
				cout << "Åä³¢ ½Â!!!" << endl;
				window.close();
			}
			else if (rabbit.goal() && turtle.goal()) {
				cout << "¹«½ÂºÎ!" << endl;
				window.close();
			}*/
		}

		window.clear();
		if (count > 0) {
			count--;
			rabbit->sleep(window);
		}
		else if (count == 0) {
			num = rand() % 6;
			count = num;
			rabbit->draw(window);
		}
		
		turtle->draw(window);

		window.display();
		if (turtle->goal()) {
			cout << "°ÅºÏÀÌ ½Â!!!" << endl;
			Sleep(10000000000000000);
		}
		else if (rabbit->goal()) {
			cout << "Åä³¢ ½Â!!!" << endl;
			Sleep(10000000000000000);
		}
		else if (rabbit->goal() && turtle->goal()) {
			cout << "¹«½ÂºÎ!" << endl;
		}
		Sleep(10);
	}
	delete turtle;
	delete rabbit;
}
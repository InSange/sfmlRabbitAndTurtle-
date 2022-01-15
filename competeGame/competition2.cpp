#include <SFML/Graphics.hpp>
#include "animal.h"
#include "turtle.h"
#include "rabbit.h"
#include <iostream>
#include <Windows.h>
#include <ctime>
#include <vector>

using namespace sf;
using namespace std;

int main() {
	RenderWindow window(VideoMode(1500, 1000), "Rabbit and Turtle");

	srand(time(nullptr));

	int num;
	int count = 0;

	/*Turtle* turtle = new Turtle(500, 5);
	Rabbit rabbit(100, 20);*/

	/*Animal *turtle = new Turtle(500, 5);
	Rabbit *rabbit = new Rabbit(100, 20);*/

	int Rn = rand() % 3 + 1; // Åä³¢¼ö
	int Tn = rand() % 3 + 1; // °ÅºÏÀÌ¼ö

	cout << Rn << " " << Tn << endl;

	vector<int> wincount(Rn+Tn);

	//vector<Animal> p(Rn+Tn);
	vector<Animal*> p;

	vector<int> ::iterator it;
	vector<Animal*> ::iterator An;

	for (int i = 0; i < Rn; i++) {
		int Rs = rand() % 30 + 10;
		Animal *r = new Rabbit(i * 216, Rs);
		p.push_back(r);
	}

	for (int i = Rn; i < Rn + Tn; i++) {
		int Ts = rand() % 10 + 5;
		Animal *t = new Turtle((216 * Rn) + ((i-Rn) * 225), Ts);
		p.push_back(t);
	}

	for (int i = 0; i < Rn + Tn; i++) {
		p[i]->test();
	}

	/*for (An = p.begin(); An != p.end(); An++) {
		cout << *An << endl;
	}*/

	while (window.isOpen())
	{
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed)
				window.close();
		}

		window.clear();
		int cho1 = 0;
		for (An = p.begin(); An != p.end(); An++) {
			if (cho1 < Rn) {
				if (count > 0) {
					count--;
					(*An)->sleep(window);
				}
				else if (count == 0) {
					num = rand() % 6;
					count = num;
					if (wincount[cho1] == 0) {
						(*An)->draw(window);
					}
					else {
						(*An)->setSpeed(0);
						(*An)->draw(window);
					}
				}
			}
			else {
				//p[i]->draw(window);
				if (wincount[cho1] == 0) {
					(*An)->draw(window);
				}
				else {
					(*An)->setSpeed(0);
					(*An)->draw(window);
				}
			}
			cho1++;
		}

		window.display();
		int cho2 = 0;
		for (An = p.begin(); An != p.end(); An++) {
			int check = 0;
			if (cho2 < Rn) {
				if ((*An)->goal()) {
					cout << cho2+1 <<"¹øÂ° Åä³¢ µµÂø!!!" << endl;
					//Sleep(10000000000000000);
					check++;
					wincount[cho2]=check;
				}
			}
			else {
				if ((*An)->goal()) {
					cout << cho2+1-Rn <<"¹øÂ° °ÅºÏÀÌ µµÂø!!!" << endl;
					//Sleep(10000000000000000);
					check++;
					wincount[cho2] = check;
				}
			}
			cho2++;
		}
		int cho3 = 0;
		for (it = wincount.begin(); it != wincount.end(); it++) {
			if (*it > 0) {
				//cout << wincount[i] << endl;
				if (cho3 < Rn) {
					cout << cho3 + 1 << "¹øÂ° Åä³¢ ½Â" << endl;
					Sleep(10000000000000000);
				}
				else {
					cout << cho3 + 1-Rn << "¹øÂ° °ÅºÏÀÌ ½Â" << endl;
					Sleep(10000000000000000);
				}
			}
			cho3++;
		}
		Sleep(100);
	}
	
	for (An = p.begin(); An != p.end(); An++) {
		delete[] *An;
		An = p.erase(An);
	}
	p.clear();
}

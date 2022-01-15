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

	int Animalnum = rand() % 6 + 1;	//µøπ∞ºˆ

	vector<int> wincount(Animalnum);

	vector<Animal*> p;

	vector<int> ::iterator it;
	vector<Animal*> ::iterator An;

	map<int, string> RT;
	RT.insert(make_pair(0, "background"));
	RT.insert(make_pair(1, "Rabbit"));
	RT.insert(make_pair(2, "Turtle"));
	map<int, string>::iterator RTmap;
	/*multimap<string, string>image;
	image.insert(pair<string, string>("Rabbit", "images//≈‰≥¢.png"));
	image.insert(pair<string, string>("Rabbit", "images//zzz.jpg"));
	image.insert(pair<string, string>("Turtle", "images//∞≈∫œ¿Ã.jpg"));
*/
	map<string, string>image;
	image.insert(pair<string, string>("Rabbit", "images//≈‰≥¢.png"));
	image.insert(pair<string, string>("Rabbitzzz", "images//zzz.jpg"));
	image.insert(pair<string, string>("Turtle", "images//∞≈∫œ¿Ã.jpg"));
	
	int width = 0;
	for (int i = 0; i < Animalnum; i++) {
		int n = rand() % 2 + 1;
		cout << n << endl;
		if (RT.find(n)->second == "Rabbit") {
			int Rs = rand() % 30 + 10;
			width = width + 216;
			Animal *r = new Rabbit(width, Rs);
			p.push_back(r);
		}
		else if (RT.find(n)->second == "Turtle") {
			int Ts = rand() % 10 + 5;
			width = width + 225;
			Animal *t = new Turtle(width, Ts);
			p.push_back(t);
		}
	}

	for (auto& an : p) {
		an->test();
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
			if ((*An)->getStatus() == "Rabbit") {
				if (count > 0) {
					count--;
					(*An)->setText(image.find("Rabbitzzz")->second);
					(*An)->sleep(window);
				}
				else if (count == 0) {
					num = rand() % 6;
					count = num;
					if (wincount[cho1] == 0) {
						(*An)->setText(image.find("Rabbit")->second);
						(*An)->draw(window);
					}
					else {
						(*An)->setText(image.find("Rabbit")->second);
						(*An)->setSpeed(0);
						(*An)->draw(window);
					}
				}
			}
			else {
				//p[i]->draw(window);
				if (wincount[cho1] == 0) {
					(*An)->setText(image.find("Turtle")->second);
					(*An)->draw(window);
				}
				else {
					(*An)->setText(image.find("Turtle")->second);
					(*An)->setSpeed(0);
					(*An)->draw(window);
				}
			}
			cho1++;
		}

		window.display();
		int NumRabbit = 0;
		int NumTurtle = 0;
		for (An = p.begin(); An != p.end(); An++) {
			int check = 0;
			if ((*An)->getStatus() == "Rabbit") {
				if ((*An)->goal()) {
					cout << NumRabbit +1 << "π¯¬∞ ≈‰≥¢ µµ¬¯!!!" << endl;
					//Sleep(10000000000000000);
					check++;
					wincount[NumRabbit+NumTurtle] = check;
				}
				NumRabbit++;
			}
			else {
				if ((*An)->goal()) {
					cout << NumTurtle + 1 << "π¯¬∞ ∞≈∫œ¿Ã µµ¬¯!!!" << endl;
					//Sleep(10000000000000000);
					check++;
					wincount[NumRabbit+NumTurtle] = check;
				}
				NumTurtle++;
			}
		}
		int cho3 = 0;
		for (it = wincount.begin(); it != wincount.end(); it++) {
			if (*it > 0) {
				//cout << wincount[i] << endl;
				if (p[cho3]->getStatus()=="Rabbit") {
					cout << cho3 + 1 << "π¯¬∞ ≈‰≥¢ Ω¬" << endl;
					Sleep(10000000000000000);
				}
				else {
					cout << cho3 + 1 << "π¯¬∞ ∞≈∫œ¿Ã Ω¬" << endl;
					Sleep(10000000000000000);
				}
			}
			cho3++;
		}
		Sleep(100);
	}

	for (An = p.begin(); An != p.end(); An++) {
		delete[] * An;
		An = p.erase(An);
	}
	p.clear();
}

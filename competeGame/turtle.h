#ifndef _TURTLE_H_
#define _TURTLE_H_
#include "animal.h"
#include<SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Turtle:public Animal {
	Texture t;
	Sprite turtle;
public:
	Turtle(double y, double speed);
	bool goal();
	void move();
	void draw(RenderWindow &window);
	string sound();
	void setText(string t);
	string getStatus() {
		return status;
	}
	~Turtle() {
		cout << "turtle ¼Ò¸ê ¿Ï·á" << endl;
	}
};

#endif
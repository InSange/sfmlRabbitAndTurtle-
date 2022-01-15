#ifndef _RABBIT_H_
#define _RABBIT_H_
#include "animal.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

class Rabbit :public Animal {
	Texture t;
	Sprite rabbit;
	Texture z;
	Sprite zzz;
public:
	Rabbit(double y, double speed);
	bool goal();
	void move();
	void draw(RenderWindow &window);
	string sound();
	void sleep(RenderWindow&window);
	void setText(string t);
	string getStatus() {
		return status;
	}
	~Rabbit() {
		cout << "rabbit ¼Ò¸ê ¿Ï·á" << endl;
	}
};

#endif
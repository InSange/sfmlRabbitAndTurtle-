#ifndef _ANIMAL_H_
#define _ANIMAL_H_
#include <string>
#include <iostream>
#include<SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Animal{
protected:
	double x, y;
	double speed;
	string status;
public:
	Animal(double y, double speed);
	virtual bool goal();
	virtual void move();
	virtual void draw(RenderWindow&window);
	virtual string sound();
	virtual void sleep(RenderWindow &window);
	void setSpeed(double speed);
	virtual void setText(string t) {
		cout << "�ؽ�Ʈ ����" << endl;
	}
	virtual string getStatus() {
		return status;
	}
	~Animal() {
		cout << "animal �Ҹ� �Ϸ�" << endl;
	}

	void test() {
		cout << "x : " << x << " y : " << y << " speed : " << speed << endl;
	}
};

#endif
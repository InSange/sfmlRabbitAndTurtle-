#include "animal.h"

Animal::Animal(double y=0, double speed=0)
{
	this->y = y;
	this->speed = speed;
	cout << "animal ���� �Ϸ�" << endl;
}

void Animal::move()
{
	cout << sound() << endl;
}

string Animal::sound() {
	return "������";
}

void Animal::draw(RenderWindow&window) {
	cout << "�׸���!! " << endl;
}

bool Animal::goal() {
	if (x >= 1000) {
		return true;
	}
	return false;
}

void Animal::sleep(RenderWindow &window) {
	cout << "������" << endl;
}

void Animal::setSpeed(double speed=0) {
	this->speed = speed;
}
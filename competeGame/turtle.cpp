#include "turtle.h"

Turtle::Turtle(double y=0, double speed=0) : Animal(y, speed)
{
	x = 0;
	turtle.setPosition(x, this->y);
	status = "Turtle";
	cout << "°ÅºÏÀÌ »ý¼º ¿Ï·á" << endl;
}

void Turtle::setText(string texture)
{
	t.loadFromFile(texture);
	turtle.setTexture(t);
}

bool Turtle::goal()
{
	if (x >= 1000) {
		return true;
	}
	return false;
}

void Turtle::move()
{
	x = x + speed;
	if (x > 1000) x = 1000;
	turtle.setPosition(x, y);
	cout << sound()<< endl;
}

void Turtle::draw(RenderWindow &window) {
	move();
	window.draw(turtle);
}

string Turtle::sound() {
	return "¾û±Ý¾û±Ý";
}
#include "rabbit.h"

Rabbit::Rabbit(double y=0, double speed=0) : Animal(y, speed)
{
	x = 0;
	rabbit.setPosition(x, this->y);
	status = "Rabbit";
	cout << "配尝 积己 肯丰" << endl;
}

bool Rabbit::goal()
{
	if (x >= 1000) {
		return true;
	}
	return false;
}

void Rabbit::move()
{
	x = x + speed;
	if (x > 1000) x = 1000;
	rabbit.setPosition(x, y);
	cout << sound() << endl;
}

void Rabbit::draw(RenderWindow & window)
{
	move();
	window.draw(rabbit);
}

string Rabbit::sound()
{
	return "脖面脖面";
}
void Rabbit::setText(string texture) {
	t.loadFromFile(texture);
	rabbit.setTexture(t);
}

void Rabbit::sleep(RenderWindow &window) 
{
	/*z.loadFromFile("images//zzz.jpg");
	zzz.setTexture(z);*/
	cout << "zzz" << endl;
	rabbit.setPosition(x, y);
	window.draw(rabbit);
}
//#include <SFML/Graphics.hpp>
//#include <iostream>
//#include <ctime>
//#include <windows.h>
//#include <string.h>
//
//using namespace std;
//using namespace sf;
//
//int main() {
//	RenderWindow window(VideoMode(720, 960), "LUNAR LANDER");
//	window.setFramerateLimit(60);
//
//	Texture t1;
//	Sprite lander;
//	t1.loadFromFile("images//�䳢.png");
//	lander.setTexture(t1);
//	lander.setPosition(0, 100);
//
//	Texture t2;
//	Sprite lander2;
//	t2.loadFromFile("images//�ź���.jpg");
//	lander2.setTexture(t2);
//	lander2.setPosition(0, 500);
//
//	window.draw(lander);
//	window.draw(lander2);
//
//	Text text;
//	Font font;
//
//	if (!font.loadFromFile("DXMSubtitlesM-KSCpc-EUC-H.ttf")) {
//		cout << "��Ʈ ������ ������ �� ����!" << endl;
//	}
//
//	text.setFont(font);
//
//	string status = "turtle";
//
//	while (window.isOpen())
//	{
//		Event e;
//		while (window.pollEvent(e)) {
//			if (e.type == Event::Closed)
//				window.close();
//		}
//		Sleep(1000);
//		/*if (Keyboard::isKeyPressed(Keyboard::Left))
//			lander.move(-10.0, 0.0);
//		if (Keyboard::isKeyPressed(Keyboard::Right))
//			lander.move(10.0, 0.0);
//		if (Keyboard::isKeyPressed(Keyboard::Up))
//			lander.move(0, -10.0);
//		if (Keyboard::isKeyPressed(Keyboard::Down))
//			lander.move(0, 10.0);*/
//		lander.move(20, 0.0);
//		lander2.move(5.0,0);
//
//		window.clear();
//		text.setString(status);
//		text.setCharacterSize(20);
//		text.setPosition(0, 0);
//		window.draw(text);
//		window.draw(lander);
//		window.draw(lander2);
//		window.display();
//	}
//	
//	/*srand(time(nullptr));
//	while (1) {
//		cout << rand() << endl;
//		cout << "1�ʸ��� ����" << endl;
//		Sleep(1000);
//	}*/
//}
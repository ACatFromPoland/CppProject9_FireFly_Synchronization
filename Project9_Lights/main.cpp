#include <SFML/Graphics.hpp>
#include "Vectors.h"
#include "buttonInput.h"

#define WINDOWX 150
#define WINDOWY 150

#define getrandom(min,max) ((rand()%(int)(((max) + 1) -(min))) + (min))


class Insect{
public:
	Vector2 position = Vector2(getrandom(15, WINDOWX - 15), getrandom(15, WINDOWY - 15));

	sf::Color color;
	//sf::RectangleShape rect;
	sf::CircleShape rect;

	Vector2 dims = Vector2(3.f, 2.f);
	Insect() {
		rect.setFillColor(sf::Color::Black);
		//rect.setSize(dims.asSF());
		rect.setRadius(dims.x);
		rect.setPosition(position.asSF());
	}


	float timeToflash = (float)getrandom(10, 80);
	float flashLength = 0.2f;
	float sight = 55.f;

	bool flashing = false;


	void Update(float deltatime, Insect *insectArray, int nMax) {
		for (int i = 0; i < nMax; i++) {
			if (position.distanceTo(insectArray[i].position) < sight) {
				if (insectArray[i].timeToflash > timeToflash) {
					timeToflash += 0.0025f;
				}
				else {
					timeToflash -= 0.0025f;
				}
			}
		}
		if (!flashing) {
			if (timeToflash > 0.f) {
				timeToflash -= 30.f * deltatime;
			}
			else {
				flashing = true;
				timeToflash = 60.f;
				// Set color Yellow
				rect.setFillColor(sf::Color::Yellow);
			}
		}
		else {
			if (flashLength > 0.f) {
				flashLength -= 1.f * deltatime;
			}
			else {
				flashing = false;
				flashLength = 0.2f;
				// Set color Black
				rect.setFillColor(sf::Color(20, 20, 20));
			}
		}
	}
};

void updateScreen(Insect *insectArray, int nMax, sf::RenderWindow &window, float deltatime) {
	for (int i = 0; i < nMax; i++) {
		Insect &obj = insectArray[i];
		obj.Update(deltatime, insectArray, nMax);
		window.draw(obj.rect);
	}
}

void renderScreen(Insect *insectArray, int nMax, sf::RenderWindow &window) { // This is doing nothing right now...
	for (int i = 0; i < nMax; i++) {
		window.draw(insectArray[i].rect);
	}
} 


int main()
{
	sf::Clock clock;

	sf::RenderWindow window(sf::VideoMode(WINDOWX, WINDOWY), "Sky Lights", sf::Style::Close);

	//newPressMouse spacekey = newPressMouse(sf::Mouse::Left);
	newPressKey spacekey = newPressKey(sf::Keyboard::Space);

	const int insectAmount = 9;
	Insect insectArray[insectAmount];

	sf::Event event;
	while (window.isOpen()) {
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed)
				window.close();
		}
		float deltatime = clock.restart().asSeconds();

		window.clear(sf::Color::Black);
		//
		if (spacekey.isPressed()) {
			for (int i = 0; i < insectAmount; i++) {
				insectArray[i].timeToflash = (float)getrandom(0, 60);
			}
		}

		updateScreen(insectArray, insectAmount, window, deltatime);
		//
		window.display();

	}
	return 0;
}
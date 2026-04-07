#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>

struct planet{
        sf::CircleShape body;
        sf::Vector2f position;
        sf::Vector2f velocity;
        sf::Vector2f accel;
};

float mag(sf::Vector2f v){
	return sqrt(v.x*v.x+v.y*v.y);
}

int main(){
	sf::RenderWindow window1(sf::VideoMode(1980,1080),"3 Body PRobmen");
	int n=3;
	struct planet array[n];

	array[0].position=sf::Vector2f(820,700);
	array[1].position=sf::Vector2f(1200,700);
	array[2].position=sf::Vector2f(900,400);

	sf::RectangleShape fade(sf::Vector2f(1980,1080));
	fade.setFillColor(sf::Color(0,0,0,5));

	for(int i=0;i<n;i++){
		array[i].body.setRadius(15.f);
		(array[i].body).setPosition(array[i].position);
		array[i].velocity=sf::Vector2f(0,0);
	}


	sf::Event event1;
	sf::Clock clock;
	sf::Time wait = sf::milliseconds(1.66);
	float r;
	while(window1.isOpen()){

		while(window1.pollEvent(event1)){

			switch(event1.type){
				case sf::Event::Closed:
					window1.close();
					break;
				default:
					break;
			}
		}

		if(clock.getElapsedTime()>wait){
			window1.clear();

			for(int i=0;i<n;i++){
				window1.draw(array[i].body);
			}

			for(int i=0;i<n;i++){
				array[i].accel=sf::Vector2f(0,0);

				for(int j=0;j<n;j++){
					if(i==j){
						continue;
					}
					r=mag(array[j].position-array[i].position);
					array[i].accel+=(array[j].position-array[i].position)*(float)(300000/(std::pow(r,3)+300000));
				}
			}
			for(int i=0;i<n;i++){
				array[i].velocity+=array[i].accel*(float)0.00166;
				array[i].position+=array[i].velocity*(float)0.00166;
				array[i].body.setPosition(array[i].position);
		}

		window1.display();
	}
	}
	return 0;
}


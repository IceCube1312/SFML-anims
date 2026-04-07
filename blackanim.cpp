#include <iostream>
#include <SFML/Graphics.hpp>
#include <cmath>
#include <random>
#include <vector>
#include <numbers>

struct balls{
	sf::CircleShape ball;
	sf::Vector2f position;
	sf::Vector2f velocity;
	sf::Vector2f accel;
};

float mag(sf::Vector2f v){
	return sqrt(v.x*v.x+v.y*v.y);
}

sf::Vector2f polar(float r, float theta){
	sf::Vector2f v;
	v.x=r*cos(theta);
	v.y=r*sin(theta);
	return v;
}

int main(){
	float pi=(float)M_PI;
	sf::RenderWindow window1(sf::VideoMode(1980,1080),"ITS A BLACK HOLE");
	sf::View view1(sf::FloatRect(0,0,1980,1080));
	view1.setCenter(0,0);
	window1.setView(view1);

	int n=5000;
	float r,theta;
	srand(time(0));

	std::vector<struct balls> array(n);

	for(int i=0;i<n;i++){
		r=(rand()%1200)+50;
		theta=(float)((float)rand()/RAND_MAX)*2*M_PI;
		float v=sqrt(500000000/r);
		array[i].ball.setRadius(3.f);
		if(i%2==0){
	        	array[i].ball.setFillColor(sf::Color(91,10,190,170));
		}
		if(i%2==1){
		        array[i].ball.setFillColor(sf::Color(190,10,90,170));
		}
		array[i].ball.setOrigin(1.5,1.5);
		array[i].position=polar(r,theta);
		array[i].ball.setPosition(array[i].position);
		array[i].velocity=polar(v,theta+((pi)/2));
	}


	sf::CircleShape centre(36.F);
	centre.setOutlineColor(sf::Color(90,19,190));
	centre.setFillColor(sf::Color(36,00,63));
	centre.setOutlineThickness(4.f);
	centre.setOrigin(15.f,15.f);
	centre.setPosition(sf::Vector2f(-20,-20));
//	sf::CircleShape test(10.f);
//
        sf::RectangleShape fade (sf::Vector2f(1980,1080));
	fade.setFillColor(sf::Color(0,0,0,10));
	fade.setOrigin(sf::Vector2f(0,0));
	fade.setPosition(window1.mapPixelToCoords(sf::Vector2i(0,0)));
	sf::Event event1;

	sf::Clock clock;

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
		if(clock.getElapsedTime()>sf::seconds(0.0001666)){
			window1.draw(fade);
			window1.draw(centre);
			for(int i=0;i<n;i++){
				r=mag(sf::Vector2f(0,0)-array[i].position);
				array[i].accel=(sf::Vector2f(0,0)-array[i].position)*(float)(500000000/(r*r*r));
				array[i].velocity+=array[i].accel*(float)0.0001666;
				array[i].position+=array[i].velocity*(float)0.0001666;
				array[i].ball.setPosition(array[i].position);
				window1.draw(array[i].ball);
				clock.restart();
		}
		}

		window1.display();

	}
	return 0;
}


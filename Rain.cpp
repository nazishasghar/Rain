#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <vector>
class Rain {
	public:
	float x, y, yspeed;
	Rain() {
		this->x = rand();
		this->y = 0.0f;
		this->yspeed = 15.4f;
	}
	sf::RectangleShape Drops() {
		sf::RectangleShape drops(sf::Vector2f(2.0f,25.0f));
		drops.setFillColor(sf::Color::Magenta);
		drops.setPosition(x, y);
		return drops;
	}
	float move() {
		
		this->y += yspeed;
		return y;
	}
};
int main() {
	bool isRaining = true;
	Rain *rain = new Rain();
	std::vector<std::shared_ptr<Rain>> rainvec;
	sf::RenderWindow window(sf::VideoMode(800, 600), "RainbyNazish");
	
	window.setFramerateLimit(60);
	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
	
		window.clear(sf::Color::White);
		while(rand()%20)
		{
			auto o = std::make_shared<Rain>(Rain());
			rainvec.emplace_back(o);
			
		} 
			
		for (auto o : rainvec)
		{
			o->move();
			window.draw(o->Drops());
		}
		window.display();
	}


}
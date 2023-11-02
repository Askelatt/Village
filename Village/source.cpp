#include "Entity.h"


int main()
{
    Entity mainCh(1, "Hero", sf::Vector2f(16.f, 16.f), sf::Vector2f(100.f, 250.f), "..\\mystic_woods_free_2.1\\sprites\\characters\\player.png", 4);
    sf::RenderWindow window(sf::VideoMode(1218, 643), "SFML works!");
    
    sf::Texture back;
    back.loadFromFile("..\\MagicMarket\\backgr1.png");
    sf::Sprite backspr;
    backspr.setTexture(back);

 
    sf::Clock clock;
    window.setFramerateLimit(60);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        sf::Time elapsedTime = clock.restart();
      

        window.clear();
        window.draw(backspr);
        mainCh.render(window);
        mainCh.updateAnimation(elapsedTime.asSeconds());
        window.display();
    }

    return 0;
}
#include<iostream>
#include"Game.hh"

//{  }
int main() 
{  
    
    //sf::RenderWindow* window{new sf::RenderWindow(sf::VideoMode(800 , 800), "Game1")};
    //sf::Event* event{new sf::Event()};

    /*sf::RectangleShape* rectangleshep{new sf::RectangleShape(sf::Vector2f(100, 100))};
    rectangleshep->setPosition(sf::Vector2f(200, 50));
    rectangleshep->setFillColor(sf::Color::Red);
    rectangleshep->setOutlineThickness(5);
    rectangleshep->setOutlineColor(sf::Color::Green);*/

    //main loop

   Game* game{new Game()};
   game->Initialize();
   
   delete game;

    return EXIT_SUCCESS;
}
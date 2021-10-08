#include"Game.hh"
#include"Constants.hh"
#include"Rectangle.hh"
#include<InputSystem.hh>
#include<iostream>

Rectangle* rectangle{new Rectangle(100, 100, 200, 100, sf::Color::Red)};
sf::Clock* gameClock{new sf::Clock()};
float deltaTime{};
sf::Texture* texture1{new sf::Texture()};
sf::Sprite* sprite1{new sf::Sprite()};


Game::Game()
{
    window = new sf::RenderWindow(sf::VideoMode(WINDOW_WIDTH , WINDOW_HEIGHT), GAME_NAME);
    event = new sf::Event();
}

void Game::Start()
{
    texture1->loadFromFile("assets/tiles3.png");
    if(texture1 != nullptr) std::cout<<"ok";
    sprite1->setTexture(*texture1);
    sprite1->setTextureRect(sf::IntRect(0 * 16, 5 * 16, 16, 16));
    sprite1->setPosition(100, 25);
    sprite1->setColor(sf::Color::White);
    sprite1->scale(4.f, 4.f);
    
}

Game::~Game()
{
    
}

void Game::Initialize()
{  
    Start();
    MainLoop();
}

void Game::Update()

{     
    deltaTime = gameClock->getElapsedTime().asSeconds();
    gameClock->restart();
    //std::cout<< "elapsed time: " << gameClock->getElapsedTime().asMilliseconds() << std::endl;

}

void Game::MainLoop()
{
    while (window->isOpen())
    {
        while (window->pollEvent(*event))
        {
            if(event->type == sf::Event::Closed)
            {  
                window->close();
            }
        }
        Input();
        Update();
        Render();
    }
    Destroy();
}

void Game::Render()

{  
    window->clear(sf::Color::Black);
    Draw();
    window->display();
}

void Game::Draw()
{
    window->draw(*rectangle->GetShape());
    window->draw(*sprite1);
}

void Game::Input()

{  
    rectangle->GetShape()->move(sf::Vector2f(InputSystem::Axis().x * deltaTime * 600.f, InputSystem::Axis().y * deltaTime * 600.f));
}

void Game::Destroy()
{   
    delete window;
    delete event;
}
#include "Rectangle.hh"

Rectangle::Rectangle(int w, int h, int x, int y, sf::Color color)
{
    rectangleshape = new sf::RectangleShape(sf::Vector2f(w, h));
    rectangleshape->setPosition(sf::Vector2f(x, y));
    rectangleshape->setFillColor(color);
}

Rectangle::~Rectangle()
{
}

sf::RectangleShape* Rectangle::GetShape() const
{
    return rectangleshape;
}
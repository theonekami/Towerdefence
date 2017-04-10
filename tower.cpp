#include <iostream>
#include <sstream>
using namespace std;
#include <SFML/Graphics.hpp>
using namespace sf;
#include "tower.h"

tower::tower()
{
    type=0;
    range.setRadius(32*3);
    range.setFillColor(Color::Transparent);
    range.setOrigin(32*3,32*3);
    body.setOrigin(32,32);
    in_hand=false;
}

tower::~tower()
{

}

void tower::tower_place(RenderWindow &w)
{
    w.draw(body);
}
bool tower::tower_hand(RenderWindow &w, Texture ta)
{
    t=ta;
    body.setTexture(t);
    Vector2i mo=Mouse::getPosition(w);
    Event e;
    if (w.waitEvent(e)&& (e.type==Event::MouseButtonPressed && e.mouseButton.button==Mouse::Left))
    {
        in_hand=true;
        w.draw(body);
        return false;
        range.setFillColor(Color::Transparent);
       // w.setMouseCursorVisible(true);
    }
    else
    {
        in_hand=false;
        pos.x=mo.x;
        pos.y=mo.y;
        body.setPosition(pos);
        range.setPosition(pos);
        w.draw(range);
        w.draw(body);
        range.setFillColor(Color(48,119,43,100));
        return true;
    }

}

#include <iostream>
using namespace std;

#include <SFML/Graphics.hpp>
using namespace sf;

#include "Creep.h"

enum dir{STOP=0,RIGHT,LEFT,UP,DOWN};
dir d;

Creep::Creep(int a[])
{
    hp=10;
    speed=0.7;
    body.setFillColor(Color::Red);
    body.setSize(Vector2f(32,32));
    pos.y=3*32;
    path=a;
    body.setPosition(pos);

}

Creep::~Creep()
{
    //dtor
}

void Creep::Draw(RenderWindow &w)
{
    body.setPosition(pos);
    w.draw(body);
}

void Creep::update(float t)
{
    time+=t;
    if (time>=speed&&path!=nullptr)
    {
        time-=speed;
        path++;
        switch(*path)
        {
            case LEFT:
                    pos.x-=32;
                    break;

            case RIGHT:
                    pos.x+=32;
                    break;

            case UP:
                    pos.y-=32;
                    break;

            case DOWN:
                    pos.y+=32;
                    break;

            case STOP:
                    path=nullptr;
                    break;
        }
    }
}

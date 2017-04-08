#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>

using namespace std;

#include "include/Creep.h"

#include "tower.h"

//enum dir{STOP=0,RIGHT,LEFT,UP,DOWN};


int path[]={1,1,1,1,1,1,1,4,4,4,4,4,4,1,1,1,1,1,1,4,4,4,4,1,1,1,1,1,1,1,0};

RenderWindow w(VideoMode(800,664),"Td!!");


bool call;
int no=0;
tower ta[50];

bool addtower(Texture &t)
{
    bool y=ta[no].tower_hand(w,t);
    if(!y)
    {
        no++;
        w.setMouseCursorVisible(true);
    }

    return y;
}

void drawtowers(Texture &t)
{
    for(int j=0;j<no;j++)
    ta[j].tower_place(w,t);
}

int main()
{
    Texture m;
    m.loadFromFile("maps/map1.png");

    Sprite bg;
    bg.setTexture(m);

    Creep c(path);
    Clock d;
    float t=0;

    RectangleShape menu(Vector2f(800,64));
    menu.setFillColor(Color::Magenta);
    menu.setPosition(0,600);

    Texture to;
    to.loadFromFile("towers/archer.png");

    Sprite s;
    s.setTexture(to);
    s.setPosition(Vector2f(0,600));

    Sprite x;
    x.setOrigin(32,32);


    while(w.isOpen())
    {
        t=d.restart().asSeconds();
        Vector2i mo=Mouse::getPosition(w);
        Event e;
        while (w.pollEvent(e))
        {
            if (e.type==Event::Closed)
            {
                w.close();
            }
            if(!call)
            {

                    if (e.type==Event::MouseButtonPressed && e.mouseButton.button==Mouse::Left )
                {
                    if (mo.y>=600&&mo.x<=64)
                    {
                        call=true;
                        w.setMouseCursorVisible(false);
                    }
                // else
                    //{
                    //   w.setMouseCursorVisible(true);
                    //  call=false;
                // }

                }
            }

        }
        w.clear(Color::Black);
        w.draw(bg);
        w.draw(menu);
        w.draw(s);
        if(call)
        {
            call=addtower(to);
        }
        drawtowers(to);
        cout<<no<<endl;
        c.Draw(w);
        c.update(t);
        t=0;
        w.display();
    }

    return 0;
}

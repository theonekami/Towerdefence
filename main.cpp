#include <SFML/Graphics.hpp>
using namespace sf;

#include <iostream>
#include <sstream>

using namespace std;

#include "include/Creep.h"

#include "tower.h"

//enum dir{STOP=0,RIGHT,LEFT,UP,DOWN};

//FIX THE TOWER PROBLEM!!SOMEHOW PLEAse!!!


int path[]={1,1,1,1,1,1,1,4,4,4,4,4,4,1,1,1,1,1,1,4,4,4,4,1,1,1,1,1,1,1,0};

RenderWindow w(VideoMode(800,664),"Td!!");


bool call=false;
int no=0;
tower ta[50];
Clock game_time;

bool addtower(int t)
{
    Texture to;
    stringstream scr;
    string y;
    switch(t)
    {
    case 1:
        y="arrow";
        break;
    case 2:
        y="magic";
        break;
    default:
        return false;
    }
    scr<<"towers/"<<y<<".png";
    to.loadFromFile(scr.str());
    bool x=ta[no].tower_hand(w,to);
    //cout<<x<<endl;
    if(!x)
    {
        no++;
        w.setMouseCursorVisible(true);
    }

    return x;
}


void drawtowers()
{
    for(int j=0;j<no;j++)
    ta[j].tower_place(w);
}

void call_creep(Creep &c)
{
    float t=0;
    t=game_time.restart().asSeconds();
    c.update(t,w);
 //   c.Draw(w);
}

int main()
{
    Texture m;
    m.loadFromFile("maps/map1.png");

    Sprite bg;
    bg.setTexture(m);

    Creep c(path);

    RectangleShape menu(Vector2f(800,64));
    menu.setFillColor(Color::Magenta);
    menu.setPosition(0,600);

    Texture to;
    stringstream scr;
    string y="arrow";
    scr<<"towers/"<<y<<".png";
    to.loadFromFile(scr.str());

    Sprite s;
    s.setTexture(to);
    s.setPosition(Vector2f(0,600));

    int x=0;

    while(w.isOpen())
    {

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
                    if (mo.y>=600)
                    {
                        if(mo.x<=64)
                            x=1;
                        else if(mo.x<=64*2)
                            x=2;
                        else
                            x=0;
                        call=true;
                        w.setMouseCursorVisible(false);
                    }

                }
            }

        }
        w.clear(Color::Black);
        w.draw(bg);
        w.draw(menu);
        w.draw(s);
        drawtowers();
        call_creep(c);
        if(call)
        {
            call=addtower(x);
        }


        //t=0;

        w.display();
    }

    return 0;
}

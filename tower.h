#ifndef TOWER_H
#define TOWER_H

#include <SFML/Graphics.hpp>
using namespace sf;

class tower
{
    CircleShape range;
    int type;
    Sprite body;
    Vector2f pos;
    bool in_hand;
    Texture t;

    public:
        tower();
        virtual ~tower();
        void tower_place(RenderWindow &w);
        bool tower_hand(RenderWindow &w,Texture t);

    protected:

};

#endif // TOWER_H

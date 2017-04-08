#ifndef CREEP_H
#define CREEP_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Creep
{
    int hp;
    float speed;
    float time;
    RectangleShape body;
    int *path;

    public:
        Vector2f pos;

    public:
        Creep(int a[]);
        virtual ~Creep();
        void Draw(RenderWindow &w);
        void update(float t);
};

#endif // CREEP_H

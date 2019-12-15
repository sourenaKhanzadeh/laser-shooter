#ifndef ENEMY_H
#define ENEMY_H

#include "gameObject.h"
#include "ammo.h"


class Enemy: public GameObject{
private:
    Vector2 size;
    Ammo **ammo;
    float health;
    int dmg=1;

    void draw();
    void move();
    void control();
    bool destroy();

    void clamp();
    void clamp(Ammo **ammo);
    void fire();

public:
    Enemy(sf::RenderWindow *window, float x, float y, Vector2 size=Vector2(E_WIDTH, E_HEIGHT));
    ~Enemy();

    float getHealth(){return health;}
    void damage(float dmg);
    bool isDestroyed(){return destroy();}

};

void onCollision(Ammo *obj1, Enemy *obj2);

#endif

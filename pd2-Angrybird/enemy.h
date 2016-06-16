#ifndef ENEMY_H
#define ENEMY_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define ENEMY_DENSITY 10.0f
#define ENEMY_FRICTION 0.2f
#define ENEMY_RESTITUTION 0.5f

class Enemy:public GameItem
{
public:
    Enemy(float x,float y,float radius,QTimer *timer ,QPixmap pixmap,b2World *world,QGraphicsScene *scene);
//    void BeginContact(b2Contact *contact, QGraphicsScene *scene);
//    virtual void collide();
};

#endif // ENEMY_H

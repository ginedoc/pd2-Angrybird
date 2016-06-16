#ifndef BARRIER_H
#define BARRIER_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>

#define BARRIER_DENSITY 5.0f
#define BARRIER_FRICTION 0.2f
#define BARRIER_RESTITUTION 0.3f


#define BIRD 0
#define ENEMY 1
#define LAND 2
#define BARRIER 3

class Barrier:public GameItem
{
public:
    Barrier(float x, float y, float length, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene, bool v_or_h);
//    virtual void collide();
};

#endif // BARRIER_H

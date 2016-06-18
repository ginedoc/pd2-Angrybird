#ifndef WALL_H
#define WALL_H

#include <gameitem.h>

class WALL:public GameItem
{
public:
    WALL(float x, float y, float length, QTimer *timer, b2World *world, QGraphicsScene *scene);
};

#endif // WALL_H

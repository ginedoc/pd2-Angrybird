#ifndef RED_BIRD_H
#define RED_BIRD_H

#include "bird.h"
#include <gameitem.h>

class Red_Bird:
        public Bird,public GameItem
{
public:
    Red_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Sskill();
};

#endif // RED_BIRD_H

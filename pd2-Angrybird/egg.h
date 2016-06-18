#ifndef EGG_H
#define EGG_H

#include <bird.h>
#include <gameitem.h>
class Egg:
   public GameItem,public Bird
{
public:
    Egg(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
};

#endif // EGG_H

#ifndef YELLOW_BIRD_H
#define YELLOW_BIRD_H

#include <bird.h>
#include <gameitem.h>
#include <QDebug>

class Yellow_Bird:
        public Bird,public GameItem
{
public:
    Yellow_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
//    virtual void Sskill();

};

#endif // YELLOW_BIRD_H

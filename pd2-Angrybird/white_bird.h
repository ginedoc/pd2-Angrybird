#ifndef WHITE_BIRD_H
#define WHITE_BIRD_H

#include <gameitem.h>
#include <bird.h>

#include <QTime>
#include <QCoreApplication>

class White_Bird:
        public GameItem,public Bird
{
public:
    White_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Sskill();
};

#endif // WHITE_BIRD_H

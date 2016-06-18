#ifndef BLACK_BIRD_H
#define BLACK_BIRD_H

#include <QCoreApplication>
#include <QTime>


#include <gameitem.h>
#include <bird.h>

class Black_Bird:
        public GameItem,public Bird
{
public:
    Black_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    virtual void Sskill();
};

#endif // BLACK_BIRD_H

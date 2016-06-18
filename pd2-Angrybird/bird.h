#ifndef BIRD_H
#define BIRD_H

#include <gameitem.h>
#include <QPixmap>
#include <QGraphicsScene>
#include <QTimer>
#include <QTime>
#include <QCoreApplication>
#include <birdcontact.h>

#define BIRD_DENSITY 10.0f
#define BIRD_FRICTION 0.2f
#define BIRD_RESTITUTION 0.5f
#define BIRD 0

class Bird: public GameItem
{
public:
    Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene);
    void remove_bird(QGraphicsScene *scene, b2World *world);
    void setLinearVelocity(b2Vec2 velocity);
    void delay(int);
    virtual void Sskill()  = 0;
private:
    QPointF bird_pos();
};

#endif // BIRD_H

#include "red_bird.h"


Red_Bird::Red_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
    GameItem(world),Bird(bird_x,bird_y,radius,timer,pixmap,world,scene)
{

}

void Red_Bird::Sskill()
{
    qDebug() << "RED BIRD SKILL";
}

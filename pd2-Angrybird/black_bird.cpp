#include "black_bird.h"

Black_Bird::Black_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
    GameItem(world),Bird(bird_x,bird_y,radius,timer,pixmap,world,scene)
{

}


void Black_Bird::Sskill()
{
    GrowUp();
}


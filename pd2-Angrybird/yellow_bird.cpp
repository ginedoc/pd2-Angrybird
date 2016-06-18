#include <yellow_bird.h>


Yellow_Bird::Yellow_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
    GameItem(world),Bird(bird_x,bird_y,radius,timer,pixmap,world,scene)
{

}


void Yellow_Bird::Sskill()
{
    b2Vec2 v = getVelocity();
    setLinearVelocity(b2Vec2(5*v.x,5*v.y));
}

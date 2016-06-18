#include "white_bird.h"

White_Bird::White_Bird(float bird_x, float bird_y, float radius, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene):
    GameItem(world),Bird(bird_x,bird_y,radius,timer,pixmap,world,scene)
{

}

void White_Bird::Sskill()
{
    b2Vec2 v = getVelocity();
    for(int i=0;i<200;i++){
        setLinearVelocity(b2Vec2(0,-10));
        v = getVelocity();
    }
}

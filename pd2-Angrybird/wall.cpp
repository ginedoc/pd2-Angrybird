#include "wall.h"

WALL::WALL(float x, float y, float length, QTimer *timer, b2World *world, QGraphicsScene *scene):
    GameItem(world)
{

    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(length/30,length);
    g_body->CreateFixture(&bodyBox,9.0f);

    paint();
}

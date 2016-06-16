#include "sling.h"

Sling::Sling(b2World *world, QGraphicsScene *scene):
    GameItem(world),x(7.5),y(4.5),w(0.5),h(4)
{
    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    g_body->CreateFixture(&bodyBox,9.0f);


    paint();
}

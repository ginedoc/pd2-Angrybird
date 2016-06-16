#include "barrier.h"


Barrier::Barrier(float x, float y, float length, QTimer *timer, QPixmap pixmap, b2World *world, QGraphicsScene *scene,bool v_or_h):
    GameItem(world)
{

    // Set pixmap
    g_pixmap.setPixmap(pixmap);
    g_pixmap.setTransformOriginPoint(g_pixmap.boundingRect().width()/2,g_pixmap.boundingRect().height()/2);
    g_size = v_or_h?QSize(length/9,length):QSize(length,length/9) ;

    // Set Bounding type
    set_boundingType(BARRIER);

    // Create Body
    b2BodyDef bodydef;
    bodydef.type = b2_dynamicBody;
    bodydef.bullet = true;
    bodydef.position.Set(x,y);
    bodydef.userData = this;
    g_body = world->CreateBody(&bodydef);
    b2PolygonShape polygonshape;
    v_or_h? polygonshape.SetAsBox(length/18,length/2): polygonshape.SetAsBox(length/2,length/18);
    b2FixtureDef fixturedef;
    fixturedef.shape = &polygonshape;
    fixturedef.density = BARRIER_DENSITY;
    fixturedef.friction = BARRIER_FRICTION;
    fixturedef.restitution = BARRIER_RESTITUTION;
    g_body->SetAngularDamping(3);
    g_body->CreateFixture(&fixturedef);



    // Bound timer
    connect(timer, SIGNAL(timeout()), this,SLOT(paint()));

    scene->addItem(&g_pixmap);

}

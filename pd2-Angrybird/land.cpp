#include "land.h"

Land::Land(QPixmap pixmap, b2World *world, QGraphicsScene * scene):
    GameItem(world) ,x(20),y(4/2),w(40),h(4)
{

    // Set Pixmap
    g_pixmap.setPixmap(pixmap);
    g_size = QSize(w,h);

    // Set Bounding type
    set_boundingType(LAND);

    b2BodyDef bodyDef;
    bodyDef.userData = this;
    bodyDef.position.Set(x,y);
    g_body = world->CreateBody(&bodyDef);
    b2PolygonShape bodyBox;
    bodyBox.SetAsBox(w/2,h/2);
    g_body->CreateFixture(&bodyBox,9.0f);

    scene->addItem(&g_pixmap);
    paint();
}

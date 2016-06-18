#include "gameitem.h"

#define BIRD 0
#define ENEMY 1
#define LAND 2
#define BARRIER 3

GameItem::GameItem(b2World * world):
    g_body(NULL),g_world(world),
    bounding_type(-1)
{
}

GameItem::~GameItem()
{
    g_world->DestroyBody(g_body);
}
QSizeF GameItem::g_windowsize = QSizeF();
QSizeF GameItem::g_worldsize = QSizeF();

void GameItem::setGlobalSize(QSizeF worldsize, QSizeF windowsize)
{
    g_worldsize = worldsize;
    g_windowsize = windowsize;
}

void GameItem::set_boundingType(int type)
{
    bounding_type = type;
}

int GameItem::get_BoundingType()
{
    if(bounding_type == BIRD)       return BIRD;
    if(bounding_type == ENEMY)      return ENEMY;
    if(bounding_type == LAND)       return LAND;
    if(bounding_type == BARRIER)    return BARRIER;
}



void GameItem::collid_handle()
{
    deleteLater();
}


void GameItem::paint()
{
    b2Vec2 pos = g_body->GetPosition();
    //std::cout << g_body->GetAngle() << std::endl;
    QPointF mappedPoint;
    mappedPoint.setX(((pos.x-g_size.width()/2) * g_windowsize.width())/g_worldsize.width());
    mappedPoint.setY((1.0f - (pos.y+g_size.height()/2)/g_worldsize.height()) * g_windowsize.height());
    g_pixmap.setPos(mappedPoint);
    g_pixmap.resetTransform();
    g_pixmap.setRotation(-(g_body->GetAngle()*180/3.14159));
}



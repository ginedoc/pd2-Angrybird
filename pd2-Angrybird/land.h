#ifndef LAND_H
#define LAND_H

#include <gameitem.h>
#include <QGraphicsScene>

#define BIRD 0
#define ENEMY 1
#define LAND 2
#define BARRIER 3


class Land : public GameItem
{
public:
    Land(QPixmap pixmap, b2World *world, QGraphicsScene *scene);
//    virtual void collide();

private:
    float x;    // x length
    float y;    // y length
    float h;    // ground box height
    float w;    // ground box width

};
#endif // LAND_H

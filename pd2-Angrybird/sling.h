#ifndef SLING_H
#define SLING_H

#include <gameitem.h>

class Sling:public GameItem
{
public:
    Sling(b2World *world, QGraphicsScene *scene);
private:
    float x;    // x length
    float y;    // y length
    float h;    // Sling height
    float w;    // Sling width

};

#endif // SLING_H

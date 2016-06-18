#ifndef CONTACTLISTENER_H
#define CONTACTLISTENER_H

#include <Box2D/Box2D.h>
#include <QDebug>

#include <gameitem.h>
#include <bird.h>
#include <enemy.h>

class ContactListener:
        public b2ContactListener
{
public:
    void BeginContact(b2Contact *contact);
    void EndContact(b2Contact *contact);
private:
    int type;
    int type1, type2;
};

#endif // CONTACTLISTENER_H

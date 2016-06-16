#include "contactlistener.h"


#define BIRD 0
#define ENEMY 1
#define LAND 2
#define BARRIER 3


void ContactListener::BeginContact(b2Contact *contact)
{
    GameItem *obj1 = static_cast<GameItem*> (contact->GetFixtureA()->GetBody()->GetUserData());
    GameItem *obj2 = static_cast<GameItem*> (contact->GetFixtureB()->GetBody()->GetUserData());

    type1 = obj1->get_BoundingType();
    type2 = obj2->get_BoundingType();

    if((type1 == BIRD && type2 == ENEMY )||
       (type2 == BIRD && type1 == ENEMY ))
    {
        qDebug() << "bird & barrier";
        // remove enemy        
    }

    if((type1 == BIRD && type2 == LAND )||
       (type2 == BIRD && type1 == LAND ))
    {
        qDebug() << "bird & barrier";
    }

}

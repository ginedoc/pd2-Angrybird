#include "contactlistener.h"


#define BIRD 0
#define ENEMY 1
#define LAND 2
#define BARRIER 3

void ContactListener::BeginContact(b2Contact *contact)
{

}

void ContactListener::EndContact(b2Contact *contact)
{
    GameItem *obj1 = static_cast<GameItem*> (contact->GetFixtureA()->GetBody()->GetUserData());
    GameItem *obj2 = static_cast<GameItem*> (contact->GetFixtureB()->GetBody()->GetUserData());

    type1 = obj1->get_BoundingType();
    type2 = obj2->get_BoundingType();

    // Bird et Enemy
    if(type1 == BIRD && type2 == ENEMY){
        obj2->collid_handle();
    }
    if(type1 == ENEMY && type2 == BIRD){
        obj1->collid_handle();
    }
}


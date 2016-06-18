
#include "birdcontact.h"

#define BIRD 0
void birdcontact::EndContact(b2Contact *contact)
{

    static int count = 0;
    Bird *obj1 = static_cast<Bird*> (contact->GetFixtureA()->GetBody()->GetUserData());
    Bird *obj2 = static_cast<Bird*> (contact->GetFixtureB()->GetBody()->GetUserData());

    type1 = obj1->get_BoundingType();
    type2 = obj2->get_BoundingType();

    // Bird et Enemy
    if(type1 == BIRD || type2 == BIRD){
        count++;
        if(count == 3){

        }
    }


}

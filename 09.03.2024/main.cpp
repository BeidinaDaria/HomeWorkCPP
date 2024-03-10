#include "Builder.h"
#include "Singleton.h"

int main()
{
    HouseBuilder b;
    b.buildDoors(6);
    b.buildRooms(2);
    b.buildStatues(1);
    b.buildSwimPools(1);
    b.buildWindows(11);
    b.result().show();

    Database* s=Database::getInstance("Holly");
    s->show();
    Database* s1 = Database::getInstance("Mad");
    s1->show();
}
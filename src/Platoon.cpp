
#include "../include/Platoon.h"

/**
 * Class to create a platoon, a subsection of a company. 
*/
Platoon::Platoon(Soldier platoon_sgt){
    platoon_sgt = platoon_sgt;
}

Platoon::Platoon(string mos){
    Soldier psgt = Soldier("Sergeant First Class", mos, 0);
    platoon_sgt = psgt;
}

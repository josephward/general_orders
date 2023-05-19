#include <vector>
#include "Soldier.h"

#ifndef PLATOON_H
#define PLATOON_H
using namespace std;


/**
 * Class to create a platoon, a subsection of a company. 
*/

class Platoon {

    // Private
    Soldier platoon_sgt;

    public:
        // Constructor for Platoon
        Platoon(Soldier platoon_sgt);

        // General constructor for a platoon
        // Stands up a platoon from 'other army units' (generates them)
        Platoon(string mos);

};

#endif

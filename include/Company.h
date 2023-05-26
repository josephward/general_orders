#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>

#include "../include/name_list.h"
#include "../include/Soldier.h"

#ifndef COMPANY_H
#define COMPANY_H
using namespace std;


/**
 * Class to create the Company, the basic command structure of
 * the military
*/

class Company {
    
    // Private 
    string id;
    string name;
    int head_count;
    Soldier commander;

    public:
        // Default constructor to stand up a company
        Company(string id, string name, int head_count, Soldier commander);


        void standup_Platoon(Soldier platoon_leader);
};
#endif
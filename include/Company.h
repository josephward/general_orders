#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include "name_list.h"
#include "../include/Soldier.h"
#ifndef COMPANY_H
#define COMPANY_H
using namespace std;

/**
 * Class to create the Company, the basic command structure of
 * the military
*/
class Company {
    
    string id;
    string name;
    int head_count;
    Soldier commander;

    public:
        Company(string id, string name, int head_count, Soldier commander);
};
#endif
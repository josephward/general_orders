#include <string>
#include <vector>
#include "../include/name_list.h"
using namespace std;

#ifndef SOLDIER_H
#define SOLDIER_H

/**
 * Class Definition for Soldier.h
 * 
 * This class builds Soldier objects, which are the basic blocks of any unit.
*/

extern vector<string> officer_ranks;
extern vector<string> enlisted_ranks;
extern vector<string> school_options;
extern vector<string> award_options;

class Soldier {
    // Basic soldier information
    // This is information which should be tied to the soldier's basic identity in the military
    std::string name;
    std::string rank;
    int years_in_service;
    int years_in_grade;

    // Specific Soldier Information
    // Soldier information that shows their specific use/role in the military
    std::vector<std::string> awards;
    std::vector<std::string> schools;
    std::string mos;

    // Soldier Character Values
    // These values are going to be used in combat or effect how they interact 
    double morale;  
    int accuracy;

    public:
        // Standard constructor if you are picking everything out
        Soldier(std::string name, std::string rank, int years_in_service, 
        int years_in_grade, std::vector<std::string> awards, std::vector<std::string>schools, 
        std::string mos, double morale, int accuracy);

        // Default Constructor for Soldier Class
        // This constructor is temporarily being used to generate 1SGTs. 
        // Updates should have it focus on generating privates. 
        Soldier();        

        void srb();
        void increment_year();
};
#endif
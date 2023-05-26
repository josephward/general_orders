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
    double years_in_service;
    int years_in_grade;
    int number_of_deployments;

    // Soldier Character Values
    // These values are going to be used in combat or effect how they interact 
    double morale;  
    int accuracy;


    // Specific Soldier Information
    // Soldier information that shows their specific use/role in the military
    std::vector<std::string> awards;
    std::vector<std::string> schools;
    std::string mos;

    public:

        // Standard constructor if you are picking everything out
        Soldier(std::string name, std::string rank, double years_in_service, 
        int years_in_grade, int number_of_deployments, std::vector<std::string> awards, 
        std::vector<std::string>schools, std::string mos, double morale, int accuracy);

        // Default Constructor for Soldier Class
        // This constructor is temporarily being used to generate 1SGTs. 
        // Updates should have it focus on generating privates. 
        Soldier();

        Soldier(std::string rank, std::string mos, double years_in_grade=0);        

        std::vector<std::string> gen_awards(std::vector<std::string> options, std::vector<int> perc_chance, int deployments);
        void srb();
        void increment_year();

        // Getters
        std::string get_rank(){
            return rank;
        }
        std::string get_name(){
            return name;
        }
        
};
#endif
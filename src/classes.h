#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <iostream>
#include "name_list.h"

using namespace std;

// General Information

//Vector of officer ranks
vector<string> officer_ranks
{   "2nd Lieutenant", "1st Lieutenant", "Captain", "Major",
    "Lieutenant Colonel", "Colonel", "Brigadier General",
    "Major General", "Lieutenant General", "General"
};

//Vector of enlisted ranks
vector<string> enlisted_ranks
{
    "Private", "Private 2nd Class", "Private 1st Class",
    "Specialist", "Sergeant", "Staff Sergeant", 
    "Sergeant First Class", "Master Sergeant", "First Sergeant",
    "Sergeant Major", "Command Sergeant Major:"
};

//Vector of all possible schools
vector<string> school_options
{
    "BLC", "ALC", "Sergeant Major School", "Field Grade School"
    "Airborne", "Air Assault", "Sapper", "Pathfinder",
    "Sniper", "Selection", "Ranger", "Drill Sergeant"
};

//Vector of possible awards
vector<string> award_options
{
    "Medal of Honor", "Silver Star", "Bronze Star", "Purple Heart", 
    "Army Achievement Medal", "National Defense Service Medal",
    "Army Service Ribbon"
};

/**
 * Class to create soldiers that can be placed in Unit Structures
*/
class Soldier {
    //Basic soldier information
    string name;
    string rank;
    int years_in_service;
    int years_in_grade;

    //Specific Soldier Information
    vector<string> awards;
    vector<string> schools;
    string mos;

    //Soldier Character Values
    double morale;  
    int accuracy;

    public:
        Soldier(string name, string rank, int years_in_service, 
        int years_in_grade, vector<string> awards, vector<string>schools, 
        string mos, double morale, int accuracy);

        //Default Constructor for Soldier Class
        Soldier();

        void srb();
        void increment_year();
};



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
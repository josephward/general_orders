// This file holds the classes and class functions that make up 
// the units in the game.

#include <algorithm>
#include "/../include/classes.h"
using namespace std;


// General Classes

Soldier::Soldier(
    string name, string rank, int years_in_service, int years_in_grade, 
    vector<string> awards, vector<string>schools, string mos, double morale,
    int accuracy) 
{
    name = name;
    rank = rank;
    years_in_service = years_in_service;
    years_in_grade = years_in_grade;
    awards = awards;
    schools = schools;
    mos = mos;
    morale = morale;
    accuracy = accuracy;
}

// Default constructor for Soldier class
Soldier::Soldier()
{   
    // Generate random name
    srand(time(NULL));
    int x = rand() % soldier_first_names.size();
    int y = rand() % soldier_last_names.size();
    name = soldier_first_names[x] + " " + soldier_last_names[y];

    rank = "First Sergeant";
    years_in_service = 15 + rand() % 3;
    years_in_grade = rand() % 8;
    awards.insert(awards.end(), {"Army Service Ribbon", "Army Achievement Medal", "Purple Heart",
        "The Defense of Earth and Space Medal", "The Chinese Assault Badge", "Tawain Medal of Freedom"});
    
    //Select a random school
    int temp = school_options.size() - 4;
    int z = rand() % temp;
    schools.insert(schools.end(), {"BLC","ACL"});
    schools.push_back(school_options[z+4]);

    //Randomly select an mos
    string standard = "40";
    mos = "11B" + standard;

    morale = rand() % 20 + 80;
    accuracy = 65 + rand() % 35;

}

//Prints out the important information in a nice format
void Soldier::srb(){

    string spacer = "============================================\n";
    cout << spacer;
    cout << rank + " " + name << endl;
    cout << spacer;
    
    cout << "MOS: " << mos << endl;
    cout << "Accuracy: " << accuracy << endl;
    cout << "Morale: " << morale << endl;
    cout << spacer;
    

    // Sort the relevant vector
    compare comp;
    sort(awards.begin(), awards.end());         // Sort alphabetically
    sort(awards.being(), awards.end(), comp)    // Sort by size
    // Create Header Text
    string award_header = "Awards:\n";
    string award_str;
    // Loop to assemble the award string for printing
    for(int i = 0; i<awards.size(); i++){
        // Statement to ensure that string doesn't extend beyond spacer's length
        if (award_str.size() + awards[i].size() > spacer.size()){
            award_str += "\n";
        } 
        if (i == awards.size()-1){ 
            award_str += awards[i];
        }
        else{
            award_str += awards[i] + ", ";
        }
        
    }
    cout << award_header << award_str + "\n";

    cout << spacer;
    string school_str = "Schools:\n";
    for(int i = 0; i<schools.size(); i++){
        // Statement to ensure that string doesn't extend beyond
        // spacer's length
        if (school_str.size() + schools[i].size() > spacer.size()){
            school_str += "\n";
        }
        if (i == schools.size()-1){
            school_str += schools[i] + " ";
        }
        else {
            school_str += schools[i] + ", ";
        }
        
    }
    cout << school_str + "\n";
    cout << spacer;

}

// When a new year comes through, everyone will gain a year
// in the grade they're in and their time in service
void Soldier::increment_year(){
    years_in_service += 1;
    years_in_grade += 1;
}


// Structures Classes

/**
 * Class to create the Company, the basic command structure of
 * the military
*/
Company::Company(string id, string name, int head_count, Soldier commander)
{
    id = id;
    name = name;
    head_count = head_count;
    commander = commander;
}
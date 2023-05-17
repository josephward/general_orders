#include <algorithm>
#include <chrono>
#include <iostream>
#include "../include/Soldier.h"
using namespace std;

// Structure that custom sorts the vector<string> passed to 
// std::sort from smallest to largest
struct compare {
    inline bool operator()(const std::string& first,
        const std::string& second) const
        {
            return first.size() < second.size();
        }
};

// Vectors 

//Vector of officer ranks
vector<string> officer_ranks
{   "2nd Lieutenant", "1st Lieutenant", "Captain", "Major",
    "Lieutenant Colonel", "Colonel", "Brigadier General",
    "Major General", "Lieutenant General", "General"
};

//Vector of enlisted ranks
//Does not support Corperal
vector<string> enlisted_ranks
{   "Private", "Private 2nd Class", "Private 1st Class",
    "Specialist", "Sergeant", "Staff Sergeant", 
    "Sergeant First Class", "Master Sergeant", "First Sergeant",
    "Sergeant Major", "Command Sergeant Major:"
};

//Vector of all possible schools
vector<string> school_options
{   "BLC", "ALC", "Sergeant Major School", "Field Grade School"
    "Airborne", "Air Assault", "Sapper", "Pathfinder",
    "Sniper", "Selection", "Ranger", "Drill Sergeant"
};

//Vector of possible awards
vector<string> award_options
{
    "Medal of Honor", "Destinguished Service Cross", "Silver Star", "Bronze Star", "Purple Heart", 
    "Army Achievement Medal", "National Defense Service Medal", "Army Service Ribbon"
};

// General Classes

Soldier::Soldier(
    string name, string rank, int years_in_service, int years_in_grade, 
    int number_of_deployments, vector<string> awards, vector<string>schools, 
    string mos, double morale, int accuracy) 
{
    name = name;
    rank = rank;
    years_in_service = years_in_service;
    years_in_grade = years_in_grade;
    number_of_deployments = number_of_deployments;
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
    int x = rand() % soldier_first_names.size();
    int y = rand() % soldier_last_names.size();
    name = soldier_first_names[x] + " " + soldier_last_names[y];

    rank = "First Sergeant";
    years_in_service = 15 + rand() % 3;
    years_in_grade = rand() % 8;
    number_of_deployments = rand() % 3;
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

Soldier::Soldier(string r, string m, int yig){

    // Assign the given information
    rank = r;
    mos = m;
    years_in_grade = yig;

    // Generate random name
    int x = rand() % soldier_first_names.size();
    int y = rand() % soldier_last_names.size();
    name = soldier_first_names[x] + " " + soldier_last_names[y];

    // // Generate awards
    // awards.insert(awards.end(), {"Army Service Ribbon", "Army Achievement Medal", "Purple Heart",
    //     "The Defense of Earth and Space Medal", "The Chinese Assault Badge", "Tawain Medal of Freedom"});

    // //Select a random school
    // int temp = school_options.size() - 4;
    // int z = rand() % temp;
    // schools.insert(schools.end(), {"BLC","ACL"});
    // schools.push_back(school_options[z+4]);

    // Giant if statement to set up rank dependant attributes
    if (rank == "Private"){
        number_of_deployments = 0;
    }
    else if (rank == "Private 2nd Class" || rank == "Private 1st Class"){
        number_of_deployments = rand() % 2;
    }
    else if (rank == "Specialist" || rank == "Sergeant"){
        number_of_deployments = 1 + rand() % 2;
    }
    else if (rank == "Staff Sergeant" || rank == "Sergeant First Class"){
        number_of_deployments = 2 + rand() % 2;
    }
    else if (rank == "First Sergeant" || rank == "Master Sergeant" || 
                rank == "Sergeant Major" || rank == "Command Sergeant Major"){
        number_of_deployments = 3 + rand() % 2;
    }

    else if (rank == "2nd Lieutenant"){
        number_of_deployments = 0;
    }
    else if (rank == "1st Lieutenant" || rank == "Captain"){
        number_of_deployments = rand() % 2;
    }
    else if (rank == "Major" || rank == "Lieutenant Colonel"){
        number_of_deployments = 1 + rand() % 2;
    }
    else if (rank == "Colonel" || rank == "Brigadier General" ||
        rank == "Major General" || rank == "Lieutenant General",
        rank == "General"){
            number_of_deployments = 2 + rand() % 2;
    }
    // Catch if they try to input a bad rank
    else {
        throw invalid_argument("Invalid rank string passed to Soldier Constructor");
    }

    // Add attributes related to MOS

    // Add deployments for combat MOSes
    if (mos == "11B"){
        number_of_deployments += 1;
    }

    // Set up the rest of the soldier information
    years_in_service = 15 + rand() % 3;
    morale = rand() % 20 + 80;
    accuracy = 65 + rand() % 35;
  
};

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
    sort(awards.begin(), awards.end(), comp);    // Sort by size
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
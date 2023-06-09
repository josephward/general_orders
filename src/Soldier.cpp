#include <algorithm>
#include <chrono>
#include <iostream>
#include <stdexcept>
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
    "Sergeant Major", "Command Sergeant Major"
};

//Vector of all possible schools
vector<string> school_options
{
    "Airborne", "Air Assault", "Sapper", "Pathfinder",
    "Sniper", "Ranger", "Drill Sergeant"
};

//Vector of possible awards
vector<string> award_options
{
    "Medal of Honor", "Distinguished Service Cross", "Silver Star", "Bronze Star", "Purple Heart",
    "Army Achievement Medal", "National Defense Service Medal", "Army Service Ribbon"
};
//Percentage chance of getting the award, perc being 100.00 = 10000
//Certain medals have a 0 percent chance to get them
//because they follow difference criteria
vector<int> awards_perc_chance
{
        1,      5,      100,    500,    2000,   0,  0,  0
    //  Percent Chance
    //  0.01    0.05    1       5       20      0   0   0
};

//Vector of combat mos
vector<string> combat_mos
{
    "11B", "12B", "13B", "13F", "14J", "15U", "19D", "19K", "68W", "74D", "89D"
};

// General Classes

Soldier::Soldier(
    string name, string rank, double years_in_service, int years_in_grade,
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

Soldier::Soldier(){
    Soldier("First Sergeant", "11B", 0);
}

// General Constructor for the Soldier Class
// Takes in the rank, mos, and year in grade of the soldier and uses various functions to generate the rest of the information.
Soldier::Soldier(string r, string m, double yig){

    // Assign the given information
    rank = r;
    mos = m;
    years_in_grade = yig;

    // Generate random name
    int x = rand() % soldier_first_names.size();
    int y = rand() % soldier_last_names.size();
    name = soldier_first_names[x] + " " + soldier_last_names[y];

    // General Soldier Information
    morale = rand() % 20 + 80;
    accuracy = 65 + rand() % 35;
    number_of_deployments = 0;

    // Giant if statement to set up rank dependant attributes

    // Enlisted Ranks
    if (rank == "Private"){
        mos += "00";
        years_in_service = 0.5;
        number_of_deployments += 0;
    }
    else if (rank == "Private 2nd Class" || rank == "Private 1st Class"){
        mos += "10";
        years_in_service = 1;
        number_of_deployments += rand() % 2;
    }
    else if (rank == "Specialist"){
        mos += "20";
        years_in_service = 2;
        number_of_deployments += 1 + rand() % 2;
    }
    // else if (rank == "Corperal"){
    //     mos += "30";
    //     years_in_service = 2.25;
    //     number_of_deployments += 1 + rand() % 2;
    // }
    else if (rank == "Sergeant"){
        mos += "40";
        years_in_service = 3;
        number_of_deployments += 1 + rand() % 2;
    }
    else if (rank == "Staff Sergeant"){
        mos += "40";
        years_in_service = 7 + rand() % 2;
        number_of_deployments += 2 + rand() % 2;
    }
    else if (rank == "Sergeant First Class"){
        mos += "40";
        years_in_service = 8 + rand() % 2;
        number_of_deployments += 2 + rand() % 2;
    }
    else if (rank == "Master Sergeant"){
        mos += "50";
        years_in_service = 12 + rand() % 4;
        number_of_deployments += 3 + rand() % 2;
    }
    else if (rank == "First Sergeant"){
        mos += "5M";
        years_in_service = 12 + rand() % 4;
        number_of_deployments += 3 + rand() % 2;
    }
    else if (rank == "Sergeant Major"){
        mos += "5Z";
        years_in_service = 16 + rand() % 6;
        number_of_deployments += 3 + rand() % 2;
    }
    else if (rank == "Command Sergeant Major"){
        mos = "00Z"; //CSMs always have this specific code
        years_in_service = 16 + rand() % 6;
        number_of_deployments += 3 + rand() % 2;
    }

    // Officer Ranks
    else if (rank == "2nd Lieutenant"){
        years_in_service += 0;
        number_of_deployments += 0;
    }
    else if (rank == "1st Lieutenant"){
        years_in_service += 1.5;
        number_of_deployments += rand() % 2;
    }
    else if (rank == "Captain"){
        years_in_service += 3.5;
        number_of_deployments += rand() % 2;
    }
    else if (rank == "Major"){
        years_in_service += 6.5 + rand() % 2;
        number_of_deployments += 1 + rand() % 2;
    }
    else if (rank == "Lieutenant Colonel"){
        years_in_service += 9.5 + rand() % 2;
        number_of_deployments += 2 + rand() % 2;
    }
    else if (rank == "Brigadier General"){
        years_in_service += 10.5 + rand() % 4;
        number_of_deployments += 2 + rand() % 2;
    }
    else if (rank == "Major General"){
        years_in_service += 11.5 + rand() % 6;
        number_of_deployments += 2 + rand() % 2;
    }
    else if (rank == "Lieutenant General"){
        years_in_service += 12.5 + rand() % 8;
        number_of_deployments += 2 + rand() % 2;
    }
    else if (rank == "General"){
        years_in_service += 13.5 + rand() % 10;
        number_of_deployments += 2 + rand() % 2;
    }
    // Catch if they try to input a bad rank
    else {
        throw invalid_argument("Invalid rank string passed to Soldier Constructor");
    }

    // Add attributes based on MOS and schools

    // Add extra deployment for combat MOSes
    if (std::find(combat_mos.begin(), combat_mos.end(), mos) != combat_mos.end()){
        number_of_deployments += 1;
    }

    // Add awards based on deployment numbers
    awards = gen_awards(number_of_deployments);

    // Assign Schools based on years of service
    int rr = 0;
    int chance = 0;
    string series = string() + mos[0] + mos[1];
    bool officer = false;
    if (std::find(officer_ranks.begin(), officer_ranks.end(), rank) != officer_ranks.end()){
        officer = true;
    }

    // Ranger
    rr = rand() % 101;
    chance = 3;
    if (rr <= chance){
        schools.push_back(school_options[5]);
    }
    // Add extra deployments for Rangers
    if (std::find(schools.begin(), schools.end(), "Ranger") != schools.end()){
        number_of_deployments += 2;
    }

    // Drill Sergeant
    if (rank == "Sergeant First Class" || rank == "Master Sergeant" || rank == "First Sergeant" ||
        rank == "Sergeant Major" || rank == "Command Sergeant Major"){
            rr = rand() % 101;
            chance = 25; // 25% Percent Chance
            if (rr <= chance){
                schools.push_back(school_options[6]);
            }
    }

    // Airborne
    rr = rand() % 101;
    chance = 20;
    if (series == "11"){
        chance += 5;
    }
    if (years_in_service >= 7){
        chance += 5;
    }
    if (years_in_service >= 10){
        chance += 5;
    }
    if (std::find(schools.begin(), schools.end(), "Ranger") != schools.end()){
        chance += 25;
    }
    if (rr <= chance){
        schools.push_back(school_options[0]);
    }

    // Air Assault
    rr = rand() % 101;
    chance = 20;
    if (series == "11"){
        chance += 5;
    }
    if (years_in_service >= 7){
        chance += 5;
    }
    if (years_in_service >= 10){
        chance += 5;
    }
    if (std::find(schools.begin(), schools.end(), "Ranger") != schools.end()){
        chance += 25;
    }
    if (rr <= chance){
        schools.push_back(school_options[1]);
    }

    // Pathfinder
    if (std::find(schools.begin(), schools.end(), "Air Assault") != schools.end()){
        rr = rand() % 101;
        chance = 10;
        if (series == "11"){
        chance += 5;
        }
        if (std::find(schools.begin(), schools.end(), "Ranger") != schools.end()){
        chance += 25;
        }
        if (rr <= chance){
            schools.push_back(school_options[3]);
        }
    }

    // Sapper
    rr = rand() % 101;
    chance = 5;
    //If engineer increase chance of being Sapper
    if (series == "12"){
        chance += 10;
    }
    if (std::find(schools.begin(), schools.end(), "Ranger") != schools.end()){
        if (series == "12"){
            chance += 25;
        }
    }
    if (officer == true){
        chance = 0;
    }
    if (rr <= chance){
        schools.push_back(school_options[2]);
    }

    // Sniper
    rr = rand() % 101;
    chance = 5;
    if (std::find(schools.begin(), schools.end(), "Ranger") != schools.end()){
        chance += 25;
    }
    if (officer == true){
        chance = 0;
    }
    if (rr <= chance){
        schools.push_back(school_options[4]);
    }

};

//Method which generates awards for a new soldier
//TODO add a method which generates awards randomly during the combat portion
vector<string> Soldier::gen_awards(int deployments){

    // Setup the return vector
    vector<string> awards_list;

    // If there is an error exit the function and throw an error
    if (awards_perc_chance.size() != award_options.size()){
        throw invalid_argument("Passed Awards List and Percent Change Vectors do not have the same size.");
        return awards_list;
    }

    // All Soldiers get the Army Service Ribbon
    awards_list.push_back(award_options[7]);

    // If the soldier has been deployed, give them the
    // Army Achievement Medal and National Defense Service Medal
    if (deployments > 0){
        awards_list.push_back(award_options[5]);
        awards_list.push_back(award_options[6]);
    }

    //For each medal option, 'randomly' give it to them
    //Soldiers cannot get some combat medals unless they deploy
    if (deployments != 0){
        for (int i = 0; i < award_options.size(); i++){
        int chance = 10000 - awards_perc_chance[i];
        int r = rand() % 10001; // Selects a random number between 0.00 and 100.00
        if (r >= chance){
            awards_list.push_back(award_options[i]);
            }
        }
    }

    return awards_list;
}

// If the search function does not get to the end of the awards list (it found the award) then return true
bool Soldier::get_award(string search){
    if (std::find(awards.begin(), awards.end(), search) != awards.end()){
        return true;
    }
    return false;
}

bool Soldier::get_school(string search){
    if (std::find(schools.begin(), schools.end(), search) != schools.end()){
        return true;
    }
    return false;
}

//Prints out the important information in a nice format
void Soldier::srb(){

    string spacer = "============================================\n";
    cout << spacer;
    cout << rank + " " + name << endl;
    cout << spacer;

    cout << "Years of Service: " << years_in_service << endl;
    cout << "MOS: " << mos << endl;
    cout << "Number of Deployments: " << number_of_deployments << endl;
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

//Main file for the General Order Project.
#include <algorithm>
#include <iostream>
#include "../include/Company.h"
#include "../include/Soldier.h"
#include "../include/Platoon.h"

//Testing Includes
#include <thread>

using namespace std;

int headcount = 0;

vector<Soldier> genSquad(){
    vector<Soldier> ss;
    ss.push_back(Soldier("Staff Sergeant", "11B", 0));
    ss.push_back(Soldier("Sergeant", "11B", 0));
    ss.push_back(Soldier("Private 1st Class", "11B", 0));
    ss.push_back(Soldier("Private", "11B", 0));
    ss.push_back(Soldier("Private", "11B", 0));
    ss.push_back(Soldier("Sergeant", "11B", 0));
    ss.push_back(Soldier("Private 1st Class", "11B", 0));
    ss.push_back(Soldier("Private", "11B", 0));
    ss.push_back(Soldier("Private", "11B", 0));
    return ss;
}

vector<Soldier> genPlatoon(){
    vector<Soldier> sq1 = genSquad();
    vector<Soldier> sq2 = genSquad();
    vector<Soldier> sq3 = genSquad();
    vector<Soldier> sq4 = genSquad();

    vector<Soldier> pr;
    pr.push_back(Soldier("1st Lieutenant", "11B", 0));
    pr.push_back(Soldier("Sergeant First Class", "11B", 0));
    pr.insert(pr.end(), sq1.begin(), sq1.end());
    pr.insert(pr.end(), sq2.begin(), sq2.end());
    pr.insert(pr.end(), sq3.begin(), sq3.end());
    pr.insert(pr.end(), sq4.begin(), sq4.end());

    return pr;
}

vector<vector<Soldier>> genCompany(){
    
    vector<Soldier> hqplt;
    hqplt.push_back(Soldier("Captain", "11B", 0));
    hqplt.push_back(Soldier("First Sergeant", "11B", 0));
    hqplt.push_back(Soldier("1st Lieutenant", "11B", 0));
    vector<Soldier> temp = genPlatoon();
    hqplt.insert(hqplt.end(), temp.begin(), temp.end());

    vector<Soldier> plt1    = genPlatoon();
    vector<Soldier> plt2    = genPlatoon();
    vector<Soldier> plt3    = genPlatoon();

    vector<vector<Soldier>> company_roster{hqplt, plt1, plt2, plt3};

    return company_roster;
}

vector<vector<vector<Soldier>>> genBattalion(){
    vector<Soldier> hq;
    // hq.push_back(Soldier("Lieutenant Colonel", "11B", 0));
    // hq.push_back(Soldier("Command Sergeant Major", "11B", 0));
    // hq.push_back(Soldier("Major", "11B", 0)); //XO
    // hq.push_back(Soldier("Major", "11B", 0)); //S3
    // hq.push_back(Soldier("Captain", "11B", 0));
    // hq.push_back(Soldier("Captain", "11B", 0));
    // hq.push_back(Soldier("Captain", "11B", 0));
    // hq.push_back(Soldier("Captain", "11B", 0));
    // hq.push_back(Soldier("Captain", "11B", 0));
    // hq.push_back(Soldier("Master Sergeant", "11B", 0));
    // hq.push_back(Soldier("Master Sergeant", "11B", 0));
    // hq.push_back(Soldier("Master Sergeant", "11B", 0));
    // hq.push_back(Soldier("Master Sergeant", "11B", 0));
    // hq.push_back(Soldier("Master Sergeant", "11B", 0));
    // hq.push_back(Soldier("Master Sergeant", "11B", 0));

    vector<vector<Soldier>> aco;
    aco.push_back(hq);
    vector<vector<Soldier>> tco = genCompany();
    aco.insert(aco.end(), tco.begin(), tco.end());
    vector<vector<Soldier>> bco = genCompany();
    vector<vector<Soldier>> cco = genCompany();
    vector<vector<Soldier>> dco = genCompany();
    vector<vector<Soldier>> eco = genCompany();
    vector<vector<Soldier>> fco = genCompany();

    vector<vector<vector<Soldier>>> batroster{aco, bco, cco, dco, eco, fco};

    return batroster;
}

void rollcall(vector<vector<Soldier>> co){
    for (int i = 0; i < co[0].size(); i++){
        cout << co[0][i].get_rank() << " " << co[0][i].get_name() << endl;
        headcount += 1;
    }
    cout << endl;
    for (int i = 0; i < co[1].size(); i++){
        cout << co[1][i].get_rank() << " " << co[1][i].get_name() << endl;
        headcount += 1;
    }
    cout << endl;
    for (int i = 0; i < co[2].size(); i++){
        cout << co[2][i].get_rank() << " " << co[2][i].get_name() << endl;
        headcount += 1;
    }
    cout << endl;
    for (int i = 0; i < co[3].size(); i++){
        cout << co[3][i].get_rank() << " " << co[3][i].get_name() << endl;
        headcount += 1;
    }
    cout << endl << endl;
}

int main(){
    srand(time(0)); //This is needed, only do this once in main.

    // Soldier cap = Soldier("Captain", "11B", 0);
    // std::cout << cap.get_rank() << " " << cap.get_name() << endl;
    // Company c123 = Company("C123", "Screaming Eagles", 100, cap);

    // Platoon c123a = Platoon("42A");

    // vector<Soldier> roster;
    // for (int i = 0; i < 100; i++){
    //     int guess = rand() % 3;
    //     roster.push_back(Soldier(enlisted_ranks[guess], "11B", 0));
    // }

    // for (int i = 0; i < 10; i++){
    //     int rr = rand() % roster.size();
    //     std::cout << roster[rr].get_rank() << " " << roster[rr].get_name() << std::endl;
    // }

    vector<vector<vector<Soldier>>> roster = genBattalion();
    for (int i = 0; i < roster.size(); i++){
        rollcall(roster[i]);
    }

    cout << "Battalion Staff Count: " << headcount << endl;

    //vector<Soldier> roster 
}
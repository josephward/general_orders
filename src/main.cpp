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

vector<Soldier> genBattStaff(){

    vector<Soldier> hq;

    hq.push_back(Soldier("Lieutenant Colonel", "11B", 0)); //CO
    hq.push_back(Soldier("Command Sergeant Major", "11B", 0)); //CMS
    hq.push_back(Soldier("Major", "11B", 0)); //XO
    hq.push_back(Soldier("Captain", "11B", 0)); //Chaplain

    //S1
    hq.push_back(Soldier("Captain", "11B", 0));
    hq.push_back(Soldier("Sergeant First Class", "11B", 0));
    hq.push_back(Soldier("Sergeant", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));
    hq.push_back(Soldier("Sergeant", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));

    //S2
    hq.push_back(Soldier("Captain", "11B", 0));
    hq.push_back(Soldier("Sergeant First Class", "11B", 0));
    hq.push_back(Soldier("Specialist", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));

    //S3
    hq.push_back(Soldier("Major", "11B", 0));
    hq.push_back(Soldier("Master Sergeant", "11B", 0));
    hq.push_back(Soldier("Sergeant", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));
    hq.push_back(Soldier("Sergeant", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));
    hq.push_back(Soldier("Sergeant", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));

    //S4
    hq.push_back(Soldier("Captain", "11B", 0));
    hq.push_back(Soldier("Sergeant First Class", "11B", 0));
    hq.push_back(Soldier("Private 2nd Class", "11B", 0));
    hq.push_back(Soldier("Private 1st Class", "11B", 0));

    return hq;
}

vector<vector<vector<Soldier>>> genBattalion(){
    vector<Soldier> hq = genBattStaff();

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
    for (int j = 0; j < co.size(); j++){
        for (int i = 0; i < co[j].size(); i++){
        cout << co[j][i].get_rank() << " " << co[j][i].get_name() << endl;
        headcount += 1;
        }
        cout << endl;
    }

    cout << endl << endl;
}

int count_moh(vector<vector<Soldier>> co){
    int mcount = 0;
    for (int j = 0; j < co.size(); j++){
        for (int i = 0; i < co[j].size(); i++){
            bool flip = co[j][i].get_award("Army Achievement Medal");
            if (flip == true){
                mcount += 1;
            }
        }
        cout << endl;
    }
    return mcount;
}

int main(){
    srand(time(0)); //This is needed, only do this once in main.

    int sw = 0;
    vector<vector<vector<Soldier>>> roster;
    while (sw == 0){
        roster = genBattalion();
        sw = roster[0][0][0].get_school("Ranger");
    }
    int mcount = 0;
    for (int i = 0; i < roster.size(); i++){
        rollcall(roster[i]);
    }

    cout << "Battalion Staff Count: " << headcount << endl << endl;

    roster[0][0][0].srb();
}

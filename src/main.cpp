//Main file for the General Order Project.
#include <algorithm>
#include <iostream>
#include "../include/Company.h"
#include "../include/Soldier.h"

int main(){
    srand(time(0)); //This is needed, only do this once in main.


    Soldier top = Soldier();
    top.srb();

    Soldier pvt = Soldier("Private 1st Class", "25U");
    Soldier pvt2 = Soldier("Staff Sergeant", "14L");
    Soldier gen = Soldier("General", "11X");
    Soldier csm = Soldier("Command Sergeant Major", "11X");

    cout << "\n\n";
    pvt.srb();
    pvt2.srb();
    gen.srb();
    csm.srb();

}
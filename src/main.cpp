//Main file for the General Order Project.
#include <algorithm>
#include <iostream>
#include "../include/Company.h"
#include "../include/Soldier.h"

//Testing Includes
#include <thread>

int main(){
    srand(time(0)); //This is needed, only do this once in main.
    int count = 0;
    int moh = 0;
    int dc = 0;
    int ss = 0;
    int bs = 0;
    int ph = 0;
    int until = 10000;

    for(int i = 0; i < until; i++){
        int rr = rand() % enlisted_ranks.size();
        Soldier blue_f = Soldier(enlisted_ranks[rr], "11B");
        //blue_f.srb();
        count += 1;
        //cout << "Count: " << count << "\n\n";
        if (std::find(blue_f.awards.begin(), blue_f.awards.end(), "Medal of Honor") != blue_f.awards.end()){
            moh += 1;
        }
        if (std::find(blue_f.awards.begin(), blue_f.awards.end(), "Distinguished Service Cross") != blue_f.awards.end()){
            dc += 1;
        }
        if (std::find(blue_f.awards.begin(), blue_f.awards.end(), "Silver Star") != blue_f.awards.end()){
            ss += 1;
        }
        if (std::find(blue_f.awards.begin(), blue_f.awards.end(), "Bronze Star") != blue_f.awards.end()){
            bs += 1;
        }
        if (std::find(blue_f.awards.begin(), blue_f.awards.end(), "Purple Heart") != blue_f.awards.end()){
            ph += 1;
        }
    }

    cout << "\n\nMedal of Honor "               << moh<< " " << 100.0*moh/until <<
            "\nDistinguished Service Cross "    << dc << " " << 100.0*dc/until <<
            "\nSilver Star "                    << ss << " " << 100.0*ss/until <<
            "\nBronze Star "                    << bs << " " << 100.0*bs/until <<
            "\nPurple Heart "                   << ph << " " << 100.0*ph/until;

    // Soldier pvt = Soldier("Private 1st Class", "25U");
    // Soldier pvt2 = Soldier("Staff Sergeant", "14L");
    // Soldier gen = Soldier("General", "11X");
    // Soldier csm = Soldier("Command Sergeant Major", "00Z");
    // Soldier top = Soldier("First Sergeant", "11B");
    // Soldier com = Soldier("Captain", "11B");

    // cout << "\n\n";
    // pvt.srb();
    // pvt2.srb();
    // gen.srb();
    // csm.srb();
    // top.srb();
    // com.srb();

}
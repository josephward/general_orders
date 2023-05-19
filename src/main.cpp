//Main file for the General Order Project.
#include <algorithm>
#include <iostream>
#include "Company.h"
#include "Soldier.h"
#include "Platoon.h"

//Testing Includes
#include <thread>

int main(){
    srand(time(0)); //This is needed, only do this once in main.

    Soldier cap = Soldier("Captain", "11B", 0);
    Company c123 = Company("C123", "Screaming Eagles", 100, cap);

    Platoon c123a = Platoon("42A");

}
//Main file for the General Order Project.
#include <algorithm>
#include <iostream>
#include "classes.h"


void print_vect(vector<string> s){
    std::cout << "\n\nVector Size: " << s.size() << endl;
    for(int i = 0; i < s.size(); i++){
        std::cout << s[i] << endl;
    }
}

int main(){
    // cout << "\n";
    // string test = "Army Service Ribbon, Army Achievement Medal,";
    // string spacer = "============================================\n";
    // cout << "Test: " << test.size() << "\nSpacer: " << spacer.size() << "\n\n";
    
    Soldier top = Soldier();
    top.srb();

    // vector<string> test{"Foo", "Bar", "Malt", "Jule"};
    // print_vect(test);
    // std::cout << "\nSorting...\n";
    // compare comp;
    // std::sort(test.begin(), test.end());
    // std::sort(test.begin(), test.end(), comp);
    // print_vect(test);



}
#include <string>
#include <stdexcept>
#include "../include/Company.h"

/**
 * Class to create the Company, the basic command structure of
 * the military
*/
Company::Company(string id, string name, int head_count, Soldier commander)
{
    id = id;
    name = name;
    head_count = head_count;
    if (commander.get_rank() == officer_ranks[1] ||  commander.get_rank() == officer_ranks[2] 
        || commander.get_rank() == officer_ranks[3]){
            commander = commander;
    }
    else{
        throw invalid_argument("Commander has an incorrect rank for the assigned position.");
    }
}

void Company::standup_Platoon(Soldier leader){
    
}
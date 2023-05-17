#include <string>
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
    commander = commander;
}
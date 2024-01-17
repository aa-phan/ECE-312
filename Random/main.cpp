#include <iostream>
#include <stdlib.h>
#include <vector>
#include <string>
#include <stdio.h>

#include <unordered_map>
#include <time.h>

int main() {
    std::vector<std::string> names = {"aaron", "anna", "amy", "rachel", "elizabeth", "johnny", "diamond", "cyndi", "kalia"};

    while(names.size()>0){
        int c1 = srand(time(NULL))%names.size();
        int c2 = srand(time(NULL))%names.size();
        std::cout<<names.at(c1) + " - " + names.at(c2)<<std::endl;
        names.erase(names.begin()+c1); names.erase(names.begin()+c2);
    }

}

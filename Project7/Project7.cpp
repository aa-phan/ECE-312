/*
 * Copy the contents of header.txt (filled out) and paste here
 */
#include <stdio.h>
#include <iostream>
#include "UTString.h"
#include "Customer.h"
#include "CustomerDB.h"

void readString(UTString&);
void readNum(int&);

CustomerDB database;

int num_bottles = 0;
int num_rattles = 0;
int num_diapers = 0;

/* clear the inventory and reset the customer database to empty */
void reset(void) {
    database.clear();
    num_bottles = 0;
    num_rattles = 0;
    num_diapers = 0;
}

/*
 * selectInventItem is a convenience function that allows you
 * to obtain a pointer to the inventory record using the item type name
 * word must be "Bottles", "Diapers" or "Rattles"
 * for example the expression *selectInventItem("Bottles") returns the
 * current global variable for the number of bottls in the inventory
 */
int* selectInventItem(UTString word) {
    if (word == "Bottles") {
        return &num_bottles;
    } else if (word == "Diapers") {
        return &num_diapers;
    } else if (word == "Rattles") {
        return &num_rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * this overload of selectInventItem is similar to selectInventItem above, however
 * this overload takes a Customer as a second argument and selects the data member
 * of that Customer that matches "word". The function returns a pointer to one of the three data
 * members from the specified customer.
 */
int* selectInventItem(UTString word, Customer& cust) {
    if (word == "Bottles") {
        return &cust.bottles;
    } else if (word == "Diapers") {
        return &cust.diapers;
    } else if (word == "Rattles") {
        return &cust.rattles;
    }

    /* NOT REACHED */
    return 0;
}

/*
 * findMax searches through the CustomerDB "database" and returns the Customer
 * who has purchased the most items of the specified type.
 * type must be one of "Bottles", "Rattles" or "Diapers".
 *
 * Note: if two or more Customers are tied for having purchased the most of that item type
 * then findMax returns the first Customer in the CustomerDB who has purchased that maximal
 * quantity.
 *
 * Note: in the special case (invalid case) where there are zero Customers in the
 * CustomerDB, fundMax returns a null pointer (0)
 */
Customer* findMax(UTString type) {
    Customer* result = 0;
    int max = 0;
    for (int k = 0; k < database.size(); k += 1) {
        Customer& cust = database[k];
        int *p = selectInventItem(type, cust);
        if (*p > max) {
            max = *p;
            result = &cust;
        }
    }

    return result;
}

void processPurchase() {
    // not done, your effort goes here
    UTString name;
    UTString item;
    int quant = 0;
    readString(name);
    readString(item);
    readNum(quant);
    if(quant == 0) return; //useless purchase, do nothing
    if(*selectInventItem(item)>=quant){
        *selectInventItem(item)-=quant;     //remove amount from storage
        *selectInventItem(item, database[name])+=quant;     //add to selected user
    }
    else if(*selectInventItem(item)<quant)
        std::cout <<"Sorry "<<name.c_str()<<", we only have "<<*selectInventItem(item)<<" "<<item.c_str()<<std::endl;


}

void processSummarize() {
    // not done, your effort goes here
    std::cout<<"There are "<<num_bottles<<" Bottles, "<<num_diapers<<" Diapers and "<<num_rattles<<" Rattles in inventory"<<std::endl;
    std::cout<<"We have a total of "<<database.size()<<" different customers"<<std::endl;

    Customer* mostBottles = findMax("Bottles");
    Customer* mostDiapers = findMax("Diapers");
    Customer* mostRattles = findMax("Rattles");

    if(mostBottles == NULL)
        std::cout<<"No one has purchased any Bottles"<<std::endl;
    else if(mostBottles->bottles>0)
        std::cout<<mostBottles->name.c_str()<<" has purchased the most Bottles ("<<mostBottles->bottles<<")"<<std::endl;
    if(mostDiapers == NULL)
        std::cout<<"No one has purchased any Diapers"<<std::endl;
    else if(mostDiapers->diapers>0)
        std::cout<<mostDiapers->name.c_str()<<" has purchased the most Diapers ("<<mostDiapers->diapers<<")"<<std::endl;
    if( mostRattles == NULL)
        std::cout<<"No one has purchased any Rattles"<<std::endl;
    else if(mostRattles->rattles>0)
        std::cout<<mostRattles->name.c_str()<<" has purchased the most Rattles ("<<mostRattles->rattles<<")"<<std::endl;

}

void processInventory() {
    // not done, your effort goes here
    UTString item;
    int quant = 0;
    readString(item);
    readNum(quant);
    *selectInventItem(item)+=quant;     //add to store inventory
}

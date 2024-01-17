// CRM <Project4.cpp>
// EE 312 Project 4 submission by
// Aaron Phan
// atp2323
// Slip days used: <0>
// Fall 2023
// Copy-Paste the above lines at the top of your submitted files.


#include <stdio.h>
#include <assert.h>
#include "MyString.h"
#include "Invent.h"

#define MAX_CUSTOMERS 1000
Customer customers[MAX_CUSTOMERS];
int num_customers = 0;
Customer store;
int rattleFlag = 0;
int bottleFlag = 0;
int diaperFlag = 0;

/* you'll probably need several more global variables */
/* and of course, you have a few functions to write */

int indexMostRattles();     //index of customer with most rattles
int indexMostDiapers();     //index.. diapers
int indexMostBottles();     //index... bottles
int currentCustomerIndex(String* person);       //index of customer input
int isCurrent(String* person);                  //true if customer already exists in array

/* clear the inventory and reset the customer database to empty */
void reset(void) {
	/* your code here */
    store.bottles = 0; store.diapers = 0; store.rattles = 0;    //reset inventory items
    bottleFlag = 0; diaperFlag = 0; rattleFlag = 0;     //reset all flags

    int i = 1;
    while(i<=num_customers){
        customers[i].bottles = 0;
        customers[i].rattles = 0;
        customers[i].diapers = 0;
        customers[i].name.ptr[0] = 0;
        StringDestroy(&customers[i].name);
        i++;
    }

    num_customers = 0;      //reset num of customers
}

void processSummarize() {
    int bottleIndex = indexMostBottles();
    int rattleIndex = indexMostRattles();
    int diaperIndex = indexMostDiapers();
    printf("There are %d Bottles %d Diapers and %d Rattles in inventory\n", store.bottles, store.diapers, store.rattles);
    printf("we have had a total of %d different customers\n", num_customers);
    if(bottleFlag == 1){
        StringPrint(&customers[bottleIndex].name);
        printf(" has purchased the most Bottles (%d)\n", customers[bottleIndex].bottles);
    }
    else{
        printf("no one has purchased any Bottles\n");
    }
    if(diaperFlag == 1){
        StringPrint(&customers[diaperIndex].name);
        printf(" has purchased the most Diapers (%d)\n", customers[diaperIndex].diapers);
    }
    else{
        printf("no one has purchased any Diapers\n");
    }
    if(rattleFlag == 1){
        StringPrint(&customers[rattleIndex].name);
        printf(" has purchased the most Rattles (%d)\n", customers[rattleIndex].rattles);
    }
    else{
        printf("no one has purchased any Rattles\n");
    }
}

void processPurchase() {
    String name; String item;
    int quant = 0;
    readString(&name); readString(&item); readNum(&quant);
    if(quant <= 0){
        StringDestroy(&name);
        StringDestroy(&item);
        return;
    }
    else{
        if(item.ptr[0] == 'B'){
            if(store.bottles!=0 && store.bottles>=quant) {
                if (isCurrent(&name) == 0) {
                    num_customers++;
                    customers[num_customers].name = StringDup(&name);
                    customers[num_customers].bottles += quant;
                    store.bottles -= quant;
                    bottleFlag = 1;
                } else {
                    int index = currentCustomerIndex(&name);
                    customers[index].bottles += quant;
                    store.bottles -= quant;
                    bottleFlag = 1;
                }
            }
            else{
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d ", store.bottles);
                StringPrint(&item); printf("\n");
            }
        }
        if(item.ptr[0] == 'D'){
            if(store.diapers!=0 && store.diapers>=quant) {
                if (isCurrent(&name) == 0) {
                    num_customers++;
                    customers[num_customers].name = StringDup(&name);
                    customers[num_customers].diapers += quant;
                    store.diapers -= quant;
                    diaperFlag = 1;
                } else {
                    int index = currentCustomerIndex(&name);
                    customers[index].diapers += quant;
                    store.diapers -= quant;
                    diaperFlag = 1;
                }
            }
            else{
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d ", store.diapers);
                StringPrint(&item); printf("\n");
            }

            }
        if(item.ptr[0] == 'R'){
            if(store.rattles!=0 && store.rattles>=quant) {
                if (isCurrent(&name) == 0) {
                    num_customers++;
                    customers[num_customers].name = StringDup(&name);
                    customers[num_customers].rattles += quant;
                    store.rattles -= quant;
                    rattleFlag = 1;
                } else {
                    int index = currentCustomerIndex(&name);
                    customers[index].rattles += quant;
                    store.rattles -= quant;
                    rattleFlag = 1;
                }
            }
            else{
                printf("Sorry ");
                StringPrint(&name);
                printf(", we only have %d ", store.rattles);
                StringPrint(&item); printf("\n");
            }
        }
    }
    StringDestroy(&name);
    StringDestroy(&item);
}

void processInventory() {
    String item;
    int in;

    readString(&item);
    readNum(&in);

    if(item.ptr[0] == 'B'){
        store.bottles+=in;
    }
    if(item.ptr[0] == 'D'){
        store.diapers+=in;
    }
    if(item.ptr[0] == 'R'){
        store.rattles+=in;
    }
    StringDestroy(&item);
}

int indexMostRattles(){
    int index = 0;
    int currMax = 0;
    for(int i = 1; i<=num_customers;i++){
        if(customers[i].rattles>currMax){
            currMax = customers[i].rattles;
            index = i;
        }
    }
    return index;
}
int indexMostDiapers(){
    int index = 0;
    int currMax = 0;
    for(int i = 1; i<=num_customers;i++){
        if(customers[i].diapers>currMax){
            currMax = customers[i].diapers;
            index = i;
        }
    }
    return index;
}
int indexMostBottles(){
    int index = 0;
    int currMax = 0;
    for(int i = 1; i<=num_customers;i++){
        if(customers[i].bottles>currMax){
            currMax = customers[i].bottles;
            index = i;
        }
    }
    return index;
}
int currentCustomerIndex(String* person){
    int index = 1;
    for(int i=1;i<=num_customers;i++){
        if(StringIsEqualTo(&customers[i].name,person)) index = i;
    }
    return index;
}
int isCurrent(String* person){
    for(int i = 0; i<=num_customers;i++){
        if(StringIsEqualTo(&customers[i].name, person)) return true;
    }
    return false;
}
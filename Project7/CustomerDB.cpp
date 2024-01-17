// CRM in C++ <filename.cpp>
// EE 312 Project 7 submission by
// Aaron Phan
// atp2323
// Slip days used: <0>
// Fall 2023

#include <iostream>
#include <cassert>
#include "UTString.h"
#include "CustomerDB.h"

using namespace std;

const int default_capacity = 1;

Customer::Customer(UTString name) { // done, please do not edit
    this->bottles = 0;
    this->rattles = 0;
    this->diapers = 0;
    this->name = name;
}

CustomerDB::CustomerDB(void) { // done, please do not edit
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

int CustomerDB::size(void) { // done, please do not edit
    return this->length;
}

CustomerDB::~CustomerDB(void) { // done, please do not edit
    delete[] this->data;
}



void CustomerDB::clear(void) { // done, please do not edit
    delete[] this->data;
    this->capacity = default_capacity;
    this->data = new Customer[this->capacity];
    this->length = 0;
}

Customer& CustomerDB::operator[](int k) { // done, please do not edit
    assert(k >= 0 && k < this->length);
    return this->data[k];
}

Customer& CustomerDB::operator[](UTString name) { // not done, your effort goes here
    if(!(isMember(name))){
        if(this->capacity <= this->length){
            this->capacity*=2;
            Customer *bigBase = new Customer[this->capacity];
            for(int i = 0; i<this->length;i++){
                bigBase[i] = this->data[i];
            }
            delete[] this->data;
            this->data = bigBase;
        }
        Customer newCustomer(name);
        this->length++;
        this->data[this->length-1] = newCustomer;
        return this->data[this->length-1];
    }
    else{
        for(int i = 0; i<this->length;i++){
            if(this->data[i].name == name)
                return this->data[i];
        }
    }
}

bool CustomerDB::isMember(UTString name) { // not done, your effort goes here
    for(int i = 0; i<this->length; i++){
        if(this->data[i].name == name)
            return true;
    }
    return false;
}

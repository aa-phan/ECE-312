#include <list>
#include <unordered_map>
#include <sstream>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class VariableTracker
{

private:
    unordered_map<string, int> variables;

public:
    ~VariableTracker() { variables.clear(); }
    void print() {
        for (auto s : variables) {
            cout << "Variable " << s.first << ": " << s.second << endl;
        }
    }

    // You need to write at least two functions:
    /*

    1)  Add a new variable to the list of variables
            - you should be able to provide a value
    2)  Update a variable's existing value
            - if the variable doesn't exist, print some error
    
    Bonus: implement functionality to set one variable's value to another variable's value!

    */
    void var(string name, int value){
        unordered_map<string, int>::iterator found = variables.find(name);
        if(found == variables.end()) {
            variables.insert({name, value});
            return;
        }
        else return;
    }
    void set(string name, int value){
        unordered_map<string, int>::iterator exist = variables.find(name);
        if(exist!=variables.end()){
            variables.at(name) = value;
            return;
        }
        else cout<<"Error, variable does not exist. Use var keyword to create variable."<<endl;
    }
};


int main() {
    ifstream input;
    input.open("../example.txt");

    VariableTracker vt;

    string line;
    // print line by line
    while (getline(input, line)) {
        cout << line << endl;
        stringstream s(line);

        string operation, variable;
        int value;
        s >> operation >> variable >> value;
        if(operation == "set") vt.set(variable, value);
        if(operation == "var") vt.var(variable, value);

        // Your VT object should call functions here.
        // The possible operations are "set" and "var", where:
        // "set" assigns the following variable to the following value, and
        // "var" declares a new variable with a following value.

        /*
        
        Example:

        var abc 10
        var xyz 100
        set abc 5

        At the end of this, "abc" should be 5, and "xyz" should be 100.
        
        */

    }
    vt.print();
}
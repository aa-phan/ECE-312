//
// Created by Aaron on 11/23/2023.
//

#include "Project8.h"
map<string, int> vars;
vector<string> blip;

int operations(string op, int a, int b){
    if(op==">") return a>b;
    else if(op=="<") return a<b;
    else if(op==">=") return a>=b;
    else if(op=="<=") return a<=b;
    else if(op=="==") return a==b;
    else if(op=="!=") return a!=b;
    else if(op=="+") return a+b;
    else if(op=="-") return a-b;
    else if(op=="*") return a*b;
    else if(op=="/") return a/b;
    else if(op=="&&") return a&&b;
    else if(op=="||") return a||b;
    else if(op=="%") return a%b;
}
void initVar(){     //used to initialize the variable
    read_next_token();
    string v = next_token();
    blipGen();
    if(vars.find(v)!=vars.end())        //doesn't already exist
    {
        cout<<"variable "<<v.c_str()<<"incorrectly re-initialized"<<endl;
    }
    vars[v] = polishExp(blip);
    blip.clear();
}
void setVar(){      //used to set the variable
    read_next_token();
    string v = next_token();
    blipGen();
    if(vars.find(v)==vars.end()){
        cout<<"variable "<<v.c_str()<<" not declared"<<endl;
    }
    vars[v] = polishExp(blip);
    blip.clear();
}

void blipGen(){     //used to generate expressions (ie token == output)
    string s = "set";
    string v = "var";
    string t = "text";
    string o = "output";
    string check = peek_next_token();
    while(check != s && check!=t && check!= v && check != o && next_token_type!=END){
        read_next_token();
        if(next_token()=="//") skip_line();
        blip.push_back(next_token());
        check = peek_next_token();
    }
}
//should read tokens, if equal to a symbol then recursively call the function, performing the operation while recursively
//calling the function with said operation removed.
//ex. --542
// - is a symbol, dual recurse with position 0 removed. ie: polishExp(a) removed 0
//repeat for second
//next is 5 ,so return
//next is 4, return
//next is 2, return
//use the operations function to compute expressions
int polishExp(vector<string>& a){
    string front = a.front();       //take the first value
    if(!(vars.find(front)==vars.end())){       //if at the end, should be a number so just return
        a.erase(a.begin());
        return vars[front];
    }
    else if(front != ">" && front != "<" && front != ">=" && front != "<=" && front != "==" && front != "!=" &&
            front != "+" && front != "-" && front != "*" && front != "/" &&
            front != "%" && front != "&&" && front != "||"  && front != "!" && front!= "~"){
        a.erase(a.begin());
        return atoi(front.c_str());     //when reaching a number, convert it to an int to compute exp
    }
    else if(front == "~"){
        a.erase(a.begin());
        return polishExp(a)*-1;     //if negate, call the function to find the next value so it can be negated
    }
    else if(front != "!"){      //operations
        a.erase(a.begin());
        int x = polishExp(a);
        int y = polishExp(a);
        return operations(front, x, y);
    }
    else if(front=="!"){
        a.erase(a.begin());
        int i = polishExp(a);
        if(i!=0){
            return false;
        }
        else if(i==0) return true;
    }
}
void run(){
    string s = "set";
    string v = "var";
    string t = "text";
    string o = "output";
    while(next_token_type != END){

        if(next_token()=="//") skip_line();
        else if(next_token()==t){
            read_next_token();
            if(next_token()=="//") skip_line();
            cout<<next_token();
        }
        else if(next_token()==s) {
            setVar();
        }
        else if(next_token()==v) {
            initVar();
        }
        else if(next_token()==o){
            blipGen();
            cout<<polishExp(blip);
            blip.clear();
        }
        read_next_token();
    }
    vars.clear();
}

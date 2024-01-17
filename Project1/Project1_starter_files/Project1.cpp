// SuperStrings <Project1.cpp>
// EE 312 Project 1 submission by
// Aaron Phan
// atp2323
// Slip days used: <0>
// Fall 2023
// Copy-paste contents of this file at the top of every .c or .h file that you write or modify.


#include <stdio.h> // provides declarations for printf and putchar
#include <stdint.h> // provides declarations for int32_t uint32_t and the other (new) standard C types
/*
All of your code must be in this file. Please no #includes other than standard system headers (ie.., stdio.h, stdint.h)

You must write this function (printSuperStrings). Do not change the way the function is declared (i.e., it has
exactly two parameters, each parameter is a standard (mundane) C string (see Instruction).
*/
int wordPosition(char list[], int start){
    int i = start;
    while(list[i]!='\n' && list[i]!=' ' && list[i]!=0){
        i++;
    }
    return i-1;
}
int compareString(char targets[], char candidates[], int tar_star, int can_star, int tar_end, int can_end){
    //given the start and end of a target word, and the start and end of a candidate word, check the frequency of every
    //letter in the target word, and see if that letter appears the same number of times in the candidate word
    char a; int a_pos = tar_star; int b_pos=can_star;

    while(a_pos < tar_end+1){
        while(b_pos<can_end+1){
            if(targets[a_pos]==candidates[b_pos]){
                b_pos++;
                a_pos++;
            }

            else b_pos++;
        }
        if(a_pos>=tar_end+1) return 1;
        else return 0;
    }
    //return 1;
}
void printSuperStrings(char targets [], char candidates []) {
    //save index of first char of a word before next non-letter char
    //save index of last char of a word
    //use both indexes as pointers to compare with the target, which can also be remembered similarly
    //if superstring doesn't contain all chars of the current target string, restart a loop to find next word
    //should use a helper function to return the indexes

    //initialize start positions with 0 (obviously), and leave ends undeclared
    int target_start = 0; int candidate_start = 0;
    int target_end = wordPosition(targets, target_start);
    int candidate_end = wordPosition(candidates, candidate_start);
    int length = 0; while(targets[length]!='\0') length++;
    while(candidates[candidate_end+1]!='\0' && target_start<length) {
        target_end = wordPosition(targets, target_start);
        candidate_end = wordPosition(candidates, candidate_start);
        if (compareString(targets, candidates, target_start, candidate_start, target_end, candidate_end) == 1) {
            for (int i = candidate_start; i < candidate_end + 1; i++) {
                printf("%c", candidates[i]);
            }
            printf("\n");
            candidate_start = candidate_end + 2;
        }
        else if((compareString(targets, candidates, target_start, candidate_start, target_end, candidate_end) == 0) && candidates[candidate_end+1]!='\0'){
            candidate_start = candidate_end + 2;
        }
        else{
            target_start = target_end + 2; candidate_start = 0; candidate_end = 0;
        }
    }
}

/*
 * Copy the contents of header.txt (filled out) and paste here
 */
// String ADT <Project3.cpp>
// EE 312 Project 3 submission by
// Aaron Phan
// atp2323
// Slip days used: <0>
// Fall 2023
// Copy and paste this file at the top of all your submitted source code files.
// Do not turn this in by itself.
#include <assert.h>     //to provide assert()
#include <stdbool.h>    //to provide "bool" datatype (true or false)
#include <stdlib.h>     //dynamic allocation functions
#include <stdint.h>     //integer datatype with precise explicit width
#include <string.h>     //utility functions for string management
#include "UTString.h"

/*
 * Helper macro to find the signature of a UTString
 * Treat this like a function that takes a UTString*
 * Accesses a uint32_t from where the signature should be located
 */
#define CHECK(s) (*(uint32_t*) ((s)->string + (s)->length + 1))

/*
 * Checks if a UTString is valid or not.
 */
bool isOurs(const UTString* s) {
    if (CHECK(s) == SIGNATURE) { return true; }
    else { return false; }
}

/*
 * Allocate a utstring on the heap.
 * Initialize the string correctly by copying src.
 * Return a pointer to the UTString.
 */
UTString* utstrdup(const char* src) {
    //int size = 0; while(src[size]!=0)size++;
    int size = strlen(src);
    UTString* tempVal = (UTString*)malloc(sizeof(UTString)*1);
    tempVal->length = size;
    tempVal->capacity = size;
    tempVal->string = (char*)malloc(size+5);
    for(int i = 0; i<size +1; i++){
        tempVal->string[i] = src[i];
    }
    CHECK(tempVal) = SIGNATURE;
    return tempVal;
}

/*
 * Returns the length of s.
 *  s must be a valid UTString.
 */
uint32_t utstrlen(const UTString* s) {
    assert(isOurs(s));
    return s->length;
}

/*
 * Append the string suffix to the UTString s.
 *  s must be a valid UTString.
 * Do not allocate any additional storage: only append as many characters
 *  as will actually fit in s.
 * Update the length of s.
 * Return s with the above changes. */
UTString* utstrcat(UTString* s, const char* suffix) {
    assert(isOurs(s));
    int i = s->length;
    while(i<s->capacity && suffix[i-s->length]!=0){
        s->string[i] = suffix[i-s->length];
        i++;
    }
    s->length = i;
    s->string[i]=0;
    /*char* tempStr = s->string;
    int len = s->length;
    //while s index < capacity && suffix != 0, s->string[i] = suffix[j];
    //return s
    while (len < s->capacity && suffix[len - s->length] != 0) {
        tempStr[len] = suffix[len - s->length];
        len++;
    }
    s->length = len;        //set length of utstring to new len based on index
    tempStr[s->length]=0;       //set end of tempstr to null
    s->string = tempStr;  */      //copy tempstr over to original utstring
    CHECK(s) = SIGNATURE;       //add signature;
    return s;
}
/*
 * Copy src into dst.
 *  dst must be a valid UTString.
 *  src is an ordinary string.
 * Do not allocate any additional storage: only copy as many characters
 *  as will actually fit in dst.
 * Update the length of dst.
 * Return dst with the above changes.
 */
UTString* utstrcpy(UTString* dst, const char* src) {
    assert(isOurs(dst));
    int i = 0;
    while(src[i]!=0 && i<dst->capacity){
        dst->string[i] = src[i]; i++;
    }
    dst->length = i;
    if(dst->string[i]!=0){
        dst->string[i] = 0;
        i++;
    }
    CHECK(dst) = SIGNATURE;
    return dst;
}

/*
 * Free all memory associated with the given UTString.
 */
void utstrfree(UTString* self) {
    assert(isOurs(self));
    free(self->string);
    free(self);
}

/*
 * Make s have at least as much capacity as new_capacity.
 *  s must be a valid UTString.
 * If s has enough capacity already, do nothing.
 * If s does not have enough capacity, then allocate enough capacity,
 *  copy the old string and the null terminator, free the old string,
 *  and update all relevant metadata.
 * Return s with the above changes.
 */
UTString* utstrrealloc(UTString* s, uint32_t new_capacity) {
    assert(isOurs(s));
    if(new_capacity <= s->capacity){
        return s;
    }
    else{
        const char* tempStr = s->string;
        char* newStr = (char*)malloc(new_capacity+5);
        for(int i = 0; i<s->length;i++){
            newStr[i] = tempStr[i];
        }
        newStr[s->length] = 0;
        s->string = newStr;
        CHECK(s) = SIGNATURE;
        s->capacity = new_capacity;
        free((void*)tempStr);
        return s;
    }
}

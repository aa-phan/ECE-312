// Set <Project5.cpp>
// EE 312 Project 5 submission by
// Aaron Phan
// atp2323
// Slip days used: <0>
// Fall 2023
// Copy-Paste the above lines at the top of your submitted files.


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "Set.h"

/*
 * Several of the required functions have been written already
 * You may use these functions as-is or you may modify them in any way.
 * Please NOTE, you are responsible for ensuring that the functions work correctly in
 * your project solution. Just because the function works correctly in my solution does
 * NOT mean that the function will work correctly in yours.
 */

/*
 * Design NOTES:
 *
 * The design provided in this starter kit assumes
 * (1) empty sets will be represented with length == 0 and elements == nullptr (i.e., address 0)
 * (2) amortized doubling is not used, and capacity is ignored/unused. Functions should assume that
 * the amount of storage available in the elements[] array is equal to length
 */

/* done for you already */
void destroySet(Set* self) {
    free(self->elements);
}

/* done for you already */
void createEmptySet(Set* self) {
    self->len = 0;
    self->elements = nullptr;
}

/* done for you already */
void createSingletonSet(Set* self, int x) {
    self->elements = (int*) malloc(sizeof(int));
    self->elements[0] = x;
    self->len = 1;
}

/* done for you already */
void createCopySet(Set* self, const Set* other) {
    self->elements = (int*) malloc(other->len * sizeof(int));
    for (int k = 0; k < other->len; k += 1) {
        self->elements[k] = other->elements[k];
    }
    self->len = other->len;
}

/* done for you already */
void assignSet(Set* self, const Set* other) {
    if (self == other) { return; }

    destroySet(self);
    createCopySet(self, other);
}
bool isMemberSetRecur(const Set* self, int x, int low, int high){
    if(high < low) return false;
    int mid = (high + low) / 2;
    if(x == self->elements[mid]) return true;
    if(x > self->elements[mid]) return isMemberSetRecur(self, x, mid + 1, high);
    return isMemberSetRecur(self, x, low, mid - 1);
}
/* return true if x is an element of self */
bool isMemberSet(const Set* self, int x) {
    if(isEmptySet(self)) return false;
    if(isMemberSetRecur(self, x, 0, self->len)) return true;
    else return false;
}

/*
 * add x as a new member to this set.
 * If x is already a member, then self should not be changed
 * Be sure to restore the design invariant property that elements[] remains sorted
 * (yes, you can assume it is sorted when the function is called, that's what an invariant is all about)
 */
// 0 1; 2
void insertSet(Set* self, int x) {
    int* inSet = (int*)malloc(sizeof(int)*(4+(self->len)));
    if(isEmptySet(self)){
        inSet[0] = x;
        self->len++;
        free(self->elements);
        self->elements = inSet;
        return;
    }
    else{
        int count = 0;
        for(int i = 0; i<self->len;i++){
            if(self->elements[i] == x){
                free(inSet); return;
            }
            else if(self->elements[i] < x){
                inSet[i] = self->elements[i];
                count++;
                if(count == self->len){
                    inSet[self->len] = x;
                    self->len++;
                    free(self->elements);
                    break;
                }
            }
            else if(self->elements[i] > x){
                inSet[i] = x;
                int j = i + 1;
                for(i = i; i<self->len;i++){
                    inSet[j] = self->elements[i];
                    j++;
                }
                self->len++;
                free(self->elements);
                break;
            }
        }
        self->elements = inSet;
    }
}


/*
 * don't forget: it is OK to try to remove an element
 * that is NOT in the set.
 * If 'x' is not in the set 'self', then
 * removeSet should do nothing (it's not an error)
 * Otherwise, ('x' IS in the set), remove x. Be sure to update self->length
 * It is not necessary (nor recommended) to call malloc -- if removing an element means the
 * array on the heap is "too big", that's almost certainly OK, and reallocating a smaller array
 * is almost definitely NOT worth the trouble
 */
void removeSet(Set* self, int x) {
    if(isEmptySet(self)) return;
    if(!isMemberSet(self, x)) return;
    for(int i = 0; i<self->len;i++){
        if(self->elements[i]==x){
            int j = i + 1;
            for(i=i;i<self->len-1;i++){
                self->elements[i] = self->elements[j]; j++;
            }
            self->len--; break;
        }
    }
}

/* done for you already */
void displaySet(const Set* self) {
    int k;

    printf("{");

    if (self->len == 0) {
        printf("}");
    }
    else {
        for (k = 0; k < self->len; k += 1) {
            if (k < self->len - 1) {
                printf("%d,", self->elements[k]);
            } else {
                printf("%d}", self->elements[k]);
            }
        }
    }
}

/* return true if self and other have exactly the same elements */
bool isEqualToSet(const Set* self, const Set* other) {
    if(self->len != other->len) return false;
    for(int i = 0; i<self->len;i++){
        if(self->elements[i]!=other->elements[i]) return false;
    }
    return true;
}
//0 1 2 3 5 7  // 0 1 2 3 4 5
/* return true if every element of self is also an element of other */
bool isSubsetOf(const Set* self, const Set* other) {
    if(self->len == 0) return true;
    int j = 0; int i = 0;
    while(i<self->len){
        if(other->len<=j) return false;   //reached end of other array, not a subset
        if(self->elements[i] == other->elements[j]){
            i++; j++;
        }
        else{
            j++;
        }
    }
    return true; //reached end of self, self is a subset
}

/* done for you */
bool isEmptySet(const Set* self) {
    return self->len == 0;
}

/* remove all elements from self that are not also elements of other */
void intersectFromSet(Set* self, const Set* other) {
    if(self->len == 0) return;
    if(isEqualToSet(self, other)) return;
    int* inter = (int*)malloc(sizeof(int)*self->len);
    if(isEmptySet(other)){
        free(self->elements);
        self->elements = inter;
        self->len = 0;
        return;
    }
    int intIndex = 0; int iLen = 0; int i, j=0;
    for(i = 0; i<self->len;i++){
        if(j>=other->len)break;
        else{
            if(self->elements[i] == other->elements[j]){
                inter[intIndex]= self->elements[i];
                intIndex++; iLen++; j++;
            }
            else if(self->elements[i] > other->elements[j]){
                j++; i--;
            }
            else continue;
        }
    }
    free(self->elements);
    self->elements = inter;
    self->len = iLen;
}

/* remove all elements from self that are also elements of other */
void subtractFromSet(Set* self, const Set* other) {
    if(isEmptySet(self)|| isEmptySet(other)) return;
    int* sub = (int*)malloc(sizeof(int)*self->len);
    int sIndex = 0; int sLen = 0;

    int i = 0; int j = 0;
    while(i<self->len){
        if(j>=other->len){
            sub[sIndex] = self->elements[i];
            sIndex++; sLen++; i++;
        }
        else{
            if(self->elements[i] < other->elements[j]){
                sub[sIndex] = self->elements[i];
                sIndex++; sLen++; i++;
            }
            else if(self->elements[i] > other->elements[j]) j++;
            else{
                j++; i++;
            }
        }
    }
    free(self->elements);
    self->elements = sub;
    self->len = sLen;
}

/* add all elements of other to self (obviously, without creating duplicate elements) */
void unionInSet(Set* self, const Set* other) {
    if(isEmptySet(other)) return;
    int* unionSet = (int*)malloc(sizeof(int)*(self->len + other->len));
    int j = 0; int i = 0; int uIndex = 0; int uLen = 0;

    while(i<other->len){
        if(j<self->len){
            if(other->elements[i] == self->elements[j]){
                unionSet[uIndex] = other->elements[i];
                j++; uIndex++; uLen++; i++;
            }
            else if(other->elements[i] > self->elements[j]){
                unionSet[uIndex] = self->elements[j];
                j++; uIndex++; uLen++;
            }
            else{
                unionSet[uIndex] = other->elements[i];
                uIndex++; uLen++; i++;
            }
        }
        else if(j>=self->len){
            unionSet[uIndex]= other->elements[i];
            uIndex++; uLen++; i++;
        }
    }
    if(j<self->len){
        while(j<self->len){
            unionSet[uIndex]=self->elements[j];
            uIndex++; uLen++; j++;
        }
    }
    free(self->elements);
    self->elements = unionSet;
    self->len = uLen;
}

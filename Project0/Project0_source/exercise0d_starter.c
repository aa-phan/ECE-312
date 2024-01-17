#include <stdio.h>

void printMultTableInt(int n);
void printMultTableFrac(int n);

int main(void){

    // You can change this to test your code
    int size = 7;

    printMultTableInt(size);
    printMultTableFrac(size);

    return 0;

}

// Prints multiplication table of integers from 1 to n
void printMultTableInt(int n){

    // WRITE CODE FOR PART A HERE
    for(int i = 1; i<n+1;i++){
        printf("%d ",i);
        for(int j = i+i; j<(n+1)*i;j+=i){
            printf("%d ",j);
        }
        printf("\n");
    }
}

// Prints multiplication table for fractions from 1, 1/2, 1/3 to 1/n
void printMultTableFrac(int n){
    double a = 1.0;
    // WRITE CODE FOR PART B HERE
    for(double i = 1.0; a<n+1;i=1/a){
        printf("%.2f ", i);
        for(double j = 2; j<n+1;j++){
        printf("%.2f ", i/j);
        }
        printf("\n");
        a++;
    }
}

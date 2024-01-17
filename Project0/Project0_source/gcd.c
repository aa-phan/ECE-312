//
// Created by Aaron on 8/29/2023.
//
#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y){
    if(x == 0) return y;
    if(y == 0) return x;
    else{
        return gcd(y,x%y);
    }
}
int main()
{
    int a = 18;
    int b = 48;
    int c = gcd(a,b);
    printf("%d",c);
    return 0;
}

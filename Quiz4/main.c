#include <stdio.h>

int checkValidity(int a, int b, int c) {
    if (a <= 0 || b <= 0 || c <= 0 || a+b <= c || a+c <= b || b+c <= a) {
        printf("non-triangle");
    } else 
        printf("triangle");
}

int main() {
    int a, b, c;
    printf("enter a number: ");
    scanf("%d", &a);
    printf("enter a number: ");
    scanf("%d", &b);
    printf("enter a number: ");
    scanf("%d", &c);
    checkValidity(a, b, c);
    return 0;
}
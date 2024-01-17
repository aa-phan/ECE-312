#include <stdio.h>
#include <assert.h>

#define SIZE 26

int are_anagrams(char[], char[]);

int main() {
    printf("running test 'iceman' and 'cinema'...\n");
    char iceman[] = "iceman";
    char cinema[] = "cinema";

    assert(are_anagrams(iceman, cinema));
    printf("passed!\n");

    printf("running test 'raganam' and 'anagram'...\n");
    char raganam[] = "raganam";
    char anagram[] = "anagram";

    assert(are_anagrams(raganam, anagram));
    printf("passed!\n");
    
    printf("running test 'listen' and 'silent'...\n");
    char listen[] = "listen";
    char silent[] = "silent";

    assert(are_anagrams(listen, silent));
    printf("passed!\n");

    printf("running test 'mole' and 'meal'...\n");
    char mole[] = "mole";
    char meal[] = "meal";

    assert(!are_anagrams(mole, meal));
    printf("passed!\n");

    printf("running test 'happy' and 'sad'...\n");
    char happy[] = "happy";
    char sad[] = "sad";

    assert(!are_anagrams(happy, sad));
    printf("passed!\n");
}

int are_anagrams(char first_word[], char second_word[]) {
    /* your code goes here */
    int f1 = 0; int f2 = 0;
    for(int i = 0; first_word[i]!='\0';i++){
        f1+= (int)first_word[i];
    }
    for(int i = 0; second_word[i]!='\0';i++){
        f2+=(int)second_word[i];
    }
    if(f1==f2) return 1;
    else return 0;
}

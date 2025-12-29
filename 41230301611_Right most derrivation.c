#include <stdio.h>
#include <string.h>

void rightmostDerivation(char* input) {
    char str[100];
    strcpy(str, input);

    printf("Rightmost Derivations:\n");
    printf("Step 1: %s\n", str);

    int i, j, step = 2;

    for (i = strlen(str) - 1; i >= 0; i--) {

        if (str[i] == 'A') {

            str[i] = 'b';
            printf("Step %d: %s\n", step++, str);
        }
        else if (str[i] == 'B') {

            str[i] = 'c';
            printf("Step %d: %s\n", step++, str);
        }
    }
}

int main() {
    char input[] = "aAB";
    rightmostDerivation(input);
    return 0;
}


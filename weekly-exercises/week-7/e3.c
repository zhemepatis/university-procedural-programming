#include <stdio.h>
#include <stdio.h>

int getPositiveNumber(char *msg);

int main() {

    int num = getPositiveNumber("Enter a positive integer: ");
    printf("Result: %d", num);
    
    return 0;
}

int getPositiveNumber(char *msg) {
    int number = 0;

    int validInput = 0;
    while(!validInput) {
        printf("%s", msg);
        if(scanf("%d", &number) != 1 || getchar() != '\n') {
            char temp;
            scanf("%*[^\n]%c", &temp);

            printf("Error: incorrect input, please try again.\n");
            continue;
        }
        else if(number < 1) {
            printf("Error: integer is not positive.\n");
            continue;
        }

        validInput = 1;
    }

    return number;

}
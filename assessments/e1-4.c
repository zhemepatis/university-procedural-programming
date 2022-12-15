#include <stdio.h>
#include <limits.h>

int main()
{
    int maxValue = 0, minValue = INT_MAX;
    int total = 0;


    int i = 0;
    int x;
    for( printf("Valio!"); i <=3; scanf("%d", x)){
        printf("%d", i);
        i++;
    }

    while(maxValue % minValue != 0 || maxValue / minValue <= 1) {
        int num;
        printf("Enter a whole, non-negative number: ");

        if(scanf("%d", &num) == 1 && getchar() == '\n') {
            if((num <= 0) || (num >= INT_MAX)) {
                printf("The number exceeds the limits! The number must be in range of (0; %d)\n", INT_MAX-1);
                continue;
            }
    
            printf("Input is valid.\n");   

            total++;

            maxValue = (num >= maxValue) ? num : maxValue;
            minValue = (num <= minValue) ? num : minValue;
        }
        else {
            printf("Input is unvalid!\n");
            while(getchar() != '\n');
        }
    }

    printf("\nResults:\n");
    printf("The biggest value: %d\n", maxValue);
    printf("The smallest value: %d\n", minValue);
    printf("Set size: %d\n", total);

    return 0;
}
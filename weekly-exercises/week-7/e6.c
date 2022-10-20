#include <stdio.h>

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg);

int main() {
    int menuOptionNum = 3;
    char *menuOptions[10] = {"New Game", "Load Game", "Exit"};

    int selection = showMenu("DOOM", menuOptions, 3, "Enter number of option");
    printf("\nSelected option: %d", selection);

    return 0;
}

int showMenu(char *menuTitle, char *menuOptions[], int menuSize, char *inputMsg) {
    printf("%s\n", menuTitle);
    printf("***\n");

    for(int i = 0; i < menuSize; ++i)
        printf("%d. %s\n", i+1, menuOptions[i]);
    printf("***\n");

    int selection = 0;
    printf("%s: ", inputMsg);

    if(scanf("%d", &selection) != 1 || getchar() != '\n') {
        char temp;
        scanf("%*[^\n]%c", &temp);

        printf("Error: incorrect input, please try again.\n\n");
        selection = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    }
    else if(selection < 1 || selection > menuSize) {
        printf("Error: there is not such option in the menu.\n\n");
        selection = showMenu(menuTitle, menuOptions, menuSize, inputMsg);
    }
    
    return selection;
}
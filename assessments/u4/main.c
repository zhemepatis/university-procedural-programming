#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "list.h"

#define NUM_OF_OPTIONS 4

int main() { 
    element list;

    char *options[] = {"Load list elements", "Print list elements", "Insert element", "Exit application"};
    int option = -1;
    while(option != NUM_OF_OPTIONS) {
        option = menu("MENU", 4, options);

        switch (option) {
            case 1:
                if(loadElements(&list))
                    emptyList(&list);
                break;

            case 2:
                printf("List: ");
                printList(list);
                printf("\n");
                break;

            case 3:
                printf("To be continued\n");
                break;
        }
    }
    emptyList(&list);

    return 0;
}
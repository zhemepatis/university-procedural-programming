#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "lists.h"

#define NUM_OF_OPTIONS 4

int main() { 
    node_t *head = NULL;

    char *options[] = {"Load list elements", "Print list elements", "Insert element", "Exit application"};
    int option = -1;

    while(option != NUM_OF_OPTIONS) {
        option = menu("MENU", 4, options);

        switch (option) {
            case 1:
                // Chekcing if list contains some data
                // If it does, a warning is printed that the data will be deleted
                if(head != NULL) {
                    printf("WARNING: this option will delete all your current list data.\n");
                    char *options[] = {"Yes", "No"};

                    if(menu("Proceed?", 2, options) == 2)
                        break;

                    emptyList(&head);
                }

                // Getting name of the file where list data is stored
                printf("Enter file name that contains list elements: ");
                char filename[MAX_FILENAME_LENGTH];
                if(!getFilename(filename)) {
                    printErr("something went wrong while getting filename");
                    break;
                }

                // Opening the file
                FILE *in = openFile(filename, "r");
                if(in == NULL) {
                    printErr("unable locate the file");
                    break;
                }

                // Loading list, closing file
                loadList(in, &head);
                fclose(in);
                
                break;

            case 2:
                printList(head);
                break;

            case 3:
                int criterea, value;
                
                printf("Enter the value of the list element before which you want to insert the new element: ");
                if(!getInt(stdin, &criterea))
                    break;

                printf("Enter value of new element: ");
                if(!getInt(stdin, &value))
                    break;

                insertNode(&head, criterea, value);

                break;
        }
    }

    if(head != NULL)
        emptyList(&head);

    return 0;
}
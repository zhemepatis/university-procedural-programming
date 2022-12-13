#ifndef LIST_H
    #define LIST_H

    typedef struct element {
        int value;
        struct element *next;
    } element;

    void initElement(element *list, int value);
    void addElement(element *list, int value);
    int loadElements(element *list);
    void printList(element list);
    void emptyList(element *list);

#endif 
#ifndef LIST_H
    #define LIST_H

    struct node {
        int value;
        struct node *next;
    };
    typedef struct node node_t;

    node_t *createNode(int value);
    void addNode(node_t **head, node_t *node);
    void insertNode(node_t **node, int criterea, int value);
    int loadList(FILE *in, node_t **head);
    void emptyList(node_t **node);
    void printList(node_t *head);
    void convertList(node_t *head, int **arr, int *arrSize);


#endif 
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

struct node *createNode(int value) {
    
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    
    if (new_node != NULL) {

        new_node->value = value;
        new_node->next = NULL; 
    }
    
    return new_node;
}


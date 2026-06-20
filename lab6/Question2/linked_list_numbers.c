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

void appendNode(struct node **head, int value) {
    struct node *new_node = createNode(value);
    
    if (new_node == NULL) {
        printf("Error: Memory allocation failed for value %d\n", value);
        return;

    if (*head == NULL) {
      
        *head = new_node;
    } 
    else {
        
        struct node *current_node = *head;
        
       
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        
        
        current_node->next = new_node;
    }
}

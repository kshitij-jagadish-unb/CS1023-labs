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
    } 

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

void printList(const struct node *head) {
    const struct node *current_node = head;
    
    printf("List values: ");
    
    if (current_node == NULL) {
        printf("(empty)");
    }
    
    while (current_node != NULL) {
        printf("%d ", current_node->value);
        current_node = current_node->next; 
    }
    printf("\n");
}

size_t countNodes(const struct node *head) {
    size_t count = 0;
    const struct node *current_node = head;
    
    while (current_node != NULL) {
        count = count + 1;
        current_node = current_node->next;
    }
    
    return count;
}

int sumNodes(const struct node *head) {
    int sum = 0;
    const struct node *current_node = head;
    
    while (current_node != NULL) {
        sum = sum + current_node->value;
        current_node = current_node->next;
    }
    
    return sum;
}

int searchNode(const struct node *head, int target) {
    const struct node *current_node = head;
    
    while (current_node != NULL) {
        if (current_node->value == target) {
            return 1; 
        }
        else {
            current_node = current_node->next;
        }
    }
    
    return 0; 
}

void freeList(struct node *head) {
    struct node *current_node = head;
    struct node *next_node = NULL;
    
    while (current_node != NULL) {
        next_node = current_node->next;
        free(current_node);
        current_node = next_node;
    }
}


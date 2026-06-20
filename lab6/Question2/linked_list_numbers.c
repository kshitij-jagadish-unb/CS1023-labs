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

int main(void) {

    struct node *head = NULL; 
    
    int num_items = 0;
    int input_check = 0;

    printf("How many integers do you want to add to the list? ");
    input_check = scanf("%d", &num_items);

    if (input_check != 1) {

        printf("Error: You did not enter a valid number.\n");
        return 1;
    } 
    if (num_items <= 0) {

        printf("Notice: Creating an empty list.\n");
    }
    else {

        int index = 0;
        int user_value = 0;

        while (index < num_items) {

            printf("Enter integer %d: ", index + 1);
            scanf("%d", &user_value);
            
            appendNode(&head, user_value);
            
            index = index + 1;
        }
    }

    printf("\n--- Linked List Data ---\n");
    printList(head);

    printf("Total number of nodes: %zu\n", countNodes(head));
    printf("Sum of all values: %d\n", sumNodes(head));

    printf("\n--- Search ---\n");
    int search_target = 0;
    printf("Enter a value to search for: ");
    scanf("%d", &search_target);

    int found = searchNode(head, search_target);

    if (found == 1) {

        printf("Result: The value %d WAS found in the list.\n", search_target);
    } 
    else {
        
        printf("Result: The value %d was NOT found in the list.\n", search_target);
    }

    freeList(head);
    
    return 0;
}
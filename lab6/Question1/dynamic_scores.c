#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert(struct node **head, int data){
    // first we need to allocate memory for the new node
    // because we need to need to first create the container
    struct node *newNode = malloc(sizeof(struct node));
    
    // then we need to check if the memory allocation was successful
    // if the memory allocation was successful, we can proceed to insert the new node
    if (newNode != NULL) {
        newNode->data = data;
        newNode->next = NULL;
        // then we need to create two pointters to traverse the linked list
        struct node *prevNode = NULL;
        struct node *currentNode = *head;
        printf("Inserting %d into the linked list...\n", data);

        while (currentNode !=NULL && currentNode->data < newNode->data){
            prevNode = currentNode;
            currentNode = currentNode->next;
            // printing the current node and prev node
            if (prevNode != NULL) {
                printf("Current node: %d, Previous node: %d\n", currentNode != NULL ? currentNode->data : -1, prevNode->data);
            } else {
                printf("Current node: %d, Previous node: NULL\n", currentNode != NULL ? currentNode->data : -1);
            }
        }
        // just in case if we are inserting the first node at the begining of the linked list
        if (prevNode == NULL) {
            printf("Inserting %d at the beginning of the linked list.\n", data);
            newNode->next = *head;
            *head = newNode;
        } else {
            prevNode->next = newNode;  
            newNode->next = currentNode;
        }
    }
    else {
        printf("Memory allocation failed for new node with data: %d\n", data);
    }
}

void printLinkList(struct node *head){
    struct node *currentNode = head;

    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}


int main(void){

    struct node *head = NULL;
    int a[5] = {1,3,2,5,4};

    for (size_t i = 0; i < 5; i++) {
        // if we don't send the address of head, we will be passing the value of head which is NULL and we won't be able to modify the head pointer in the insert function
        insert(&head, a[i]);
        printLinkList(head);
    }

    printLinkList(head);
}


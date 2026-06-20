#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct contact {
    char name[50];
    char number[20];
    struct contact *next;
};

void clearInputBuffer() {

    int current_char = 0;

    while ((current_char = getchar()) != '\n' && current_char != EOF) {
        
    }
}

void removeNewline(char text_string[]) {

    size_t index = 0;

    while (text_string[index] != '\0') {

        if (text_string[index] == '\n') {
            text_string[index] = '\0'; 
        }
        index = index + 1;
    }
}

struct contact *createContact(const char name[], const char number[]) {

    struct contact *new_contact = (struct contact *)malloc(sizeof(struct contact));
    
    if (new_contact != NULL) {
        
        strcpy(new_contact->name, name);
        strcpy(new_contact->number, number);
        new_contact->next = NULL; 
    }
    
    return new_contact;
}

void addContact(struct contact **head, const char name[], const char number[]) {

    struct contact *new_contact = createContact(name, number);
    
    if (new_contact == NULL) {

        printf("Error: Memory allocation failed.\n");
        return;
    } 

    if (*head == NULL) {
      
        *head = new_contact;
    } 
    else {
        
        struct contact *current = *head;

        while (current->next != NULL) {

            current = current->next;
        }
        current->next = new_contact;
    }
    printf("Success: Contact added!\n");
}


void displayContacts(const struct contact *head) {

    const struct contact *current = head;
    
    printf("\n--- Contact List ---\n");
    if (current == NULL) {
        printf("(Your contact list is empty)\n");
    } 
    else {
        while (current != NULL) {
            printf("Name: %s | Phone: %s\n", current->name, current->number);
            current = current->next;
        }
    }
    printf("--------------------\n");
}

void findByName(const struct contact *head, const char name[]) {
    const struct contact *current = head;
    int found_count = 0;
    
    while (current != NULL) {
       
        if (strcmp(current->name, name) == 0) {
            printf("Found Match -> Name: %s | Phone: %s\n", current->name, current->number);
            found_count = found_count + 1;
        }
        current = current->next;
    }
    
    if (found_count == 0) {
        printf("Notice: No contact found with the name '%s'.\n", name);
    }
}

void findByNumber(const struct contact *head, const char number[]) {
    const struct contact *current = head;
    int found_count = 0;
    
    while (current != NULL) {
        if (strcmp(current->number, number) == 0) {
            printf("Found Match -> Name: %s | Phone: %s\n", current->name, current->number);
            found_count = found_count + 1;
        }
        current = current->next;
    }
    
    if (found_count == 0) {
        printf("Notice: No contact found with the number '%s'.\n", number);
    }
}

int updateNumber(struct contact *head, const char name[], const char newNumber[]) {
    struct contact *current = head;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            strcpy(current->number, newNumber); 
            return 1;
        }
        current = current->next;
    }
    
    return 0; 
}

int deleteByName(struct contact **head, const char name[]) {
    struct contact *current = *head;
    struct contact *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            
            if (previous == NULL) {
               
                *head = current->next; 
            } 
            else {
              
                previous->next = current->next; 
            }
            
            free(current); 
            return 1; 
        }
        
        
        previous = current;
        current = current->next;
    }
    
    return 0; // Not found
}


int deleteByNumber(struct contact **head, const char number[]) {
    struct contact *current = *head;
    struct contact *previous = NULL;
    
    while (current != NULL) {
        if (strcmp(current->number, number) == 0) {
            if (previous == NULL) {
                *head = current->next; 
            } 
            else {
                previous->next = current->next; 
            }
            
            free(current); 
            return 1; 
        }
        
        previous = current;
        current = current->next;
    }
    
    return 0; 
}

size_t countContacts(const struct contact *head) {
    size_t count = 0;
    const struct contact *current = head;
    
    while (current != NULL) {
        count = count + 1;
        current = current->next;
    }
    
    return count;
}

void freeContacts(struct contact *head) {
    struct contact *current = head;
    struct contact *next_node = NULL;
    
    while (current != NULL) {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}

int main(void) {
    struct contact *head = NULL;
    int choice = 0;
    
    char temp_name[50];
    char temp_number[20];
    
    while (choice != 9) {
        printf("\n=== Contact List Menu ===\n");
        printf("1. Add a new contact\n");
        printf("2. Display all contacts\n");
        printf("3. Search by name\n");
        printf("4. Search by phone number\n");
        printf("5. Update a phone number\n");
        printf("6. Delete contact by name\n");
        printf("7. Delete contact by phone number\n");
        printf("8. Count total contacts\n");
        printf("9. Exit\n");
        printf("Choose an option: ");
        
        scanf("%d", &choice);
        clearInputBuffer(); 
        
        if (choice == 1) {
            printf("Enter contact full name: ");
            fgets(temp_name, 50, stdin);
            removeNewline(temp_name);
            
            printf("Enter phone number: ");
            fgets(temp_number, 20, stdin);
            removeNewline(temp_number);
            
            addContact(&head, temp_name, temp_number);
        }
        else if (choice == 2) {
            displayContacts(head);
        }
        else if (choice == 3) {
            printf("Enter name to search: ");
            fgets(temp_name, 50, stdin);
            removeNewline(temp_name);
            
            findByName(head, temp_name);
        }
        else if (choice == 4) {
            printf("Enter phone number to search: ");
            fgets(temp_number, 20, stdin);
            removeNewline(temp_number);
            
            findByNumber(head, temp_number);
        }
        else if (choice == 5) {
            printf("Enter the name of the contact to update: ");
            fgets(temp_name, 50, stdin);
            removeNewline(temp_name);
            
            printf("Enter the new phone number: ");
            fgets(temp_number, 20, stdin);
            removeNewline(temp_number);
            
            int result = updateNumber(head, temp_name, temp_number);
            if (result == 1) {
                printf("Success: Phone number updated.\n");
            } else {
                printf("Error: Could not find a contact with that name.\n");
            }
        }
        else if (choice == 6) {
            printf("Enter the name of the contact to delete: ");
            fgets(temp_name, 50, stdin);
            removeNewline(temp_name);
            
            int result = deleteByName(&head, temp_name);
            if (result == 1) {
                printf("Success: Contact deleted.\n");
            } else {
                printf("Error: Could not find a contact with that name.\n");
            }
        }
        else if (choice == 7) {
            printf("Enter the phone number to delete: ");
            fgets(temp_number, 20, stdin);
            removeNewline(temp_number);
            
            int result = deleteByNumber(&head, temp_number);
            if (result == 1) {
                printf("Success: Contact deleted.\n");
            } else {
                printf("Error: Could not find a contact with that number.\n");
            }
        }
        else if (choice == 8) {
            size_t total = countContacts(head);
            printf("You have %zu contacts saved.\n", total);
        }
        else if (choice == 9) {
            printf("Exiting program. Cleaning up memory...\n");
            freeContacts(head);
        }
        else {
            printf("Invalid choice. Please select a number from 1 to 9.\n");
        }
    }
    
    return 0;
}
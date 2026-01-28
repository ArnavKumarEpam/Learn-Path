#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store contact details
typedef struct {
    char name[50];
    char phone[20];
} Contact;

// Function to add a contact
Contact* addContact(Contact* contacts_array, int* current_size, const Contact* new_contact) {
    Contact* temp;

    if (contacts_array == NULL) {
        // First contact
        temp = (Contact*)malloc(sizeof(Contact));
        if (temp == NULL) {
            printf("Memory allocation failed\n");
            return NULL;
        }
        temp[0] = *new_contact;
        *current_size = 1;
    } else {
        // Add more contacts
        temp = (Contact*)realloc(contacts_array, (*current_size + 1) * sizeof(Contact));
        if (temp == NULL) {
            printf("Reallocation failed\n");
            return contacts_array;
        }
        temp[*current_size] = *new_contact;
        (*current_size)++;
    }

    printf("Contact added successfully\n");
    return temp;
}

// Function to search contact by name
Contact* findContact(Contact* contacts, int current_size, char name[]) {
    for (int i = 0; i < current_size; i++) {
        if (strcmp(contacts[i].name, name) == 0) {
            return &contacts[i];
        }
    }
    return NULL;
}

// Function to display all contacts
void displayContacts(Contact* contacts, int size) {
    if (size == 0) {
        printf("No contacts available\n");
        return;
    }

    printf("\nContact List:\n");
    for (int i = 0; i < size; i++) {
        printf("%d. Name: %s\n", i + 1, contacts[i].name);
        printf("   Phone: %s\n", contacts[i].phone);
    }
}
void cleanupContacts(Contact** contacts_array, int* current_size){
    if(*contacts_array != NULL){
        free(*contacts_array);
        *contacts_array = NULL;
        *current_size = 0;
    }
    else{
        printf("No contacts to free.\n");
    }
}

// Main function
int main() {
    Contact* contacts = NULL;
    int count = 0;
    int choice;
    Contact temp;
    char searchName[50];

    while (1) {
        printf("\n1. Add Contact");
        printf("\n2. Display Contacts");
        printf("\n3. Search Contact");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);
        getchar(); // clear buffer

        if (choice == 1) {
            printf("Enter name: ");
            fgets(temp.name, 50, stdin);
            temp.name[strcspn(temp.name, "\n")] = '\0';

            printf("Enter phone: ");
            fgets(temp.phone, 20, stdin);
            temp.phone[strcspn(temp.phone, "\n")] = '\0';

            contacts = addContact(contacts, &count, &temp);
        }
        else if (choice == 2) {
            displayContacts(contacts, count);
        }
        else if (choice == 3) {
            printf("Enter name to search: ");
            fgets(searchName, 50, stdin);
            searchName[strcspn(searchName, "\n")] = '\0';

            Contact* found = findContact(contacts, count, searchName);
            if (found != NULL) {
                printf("Contact found\n");
                printf("Name: %s\n", found->name);
                printf("Phone: %s\n", found->phone);
            } else {
                printf("Contact not found\n");
            }
        }
        else if (choice == 4) {
            cleanupContacts(&contacts, &count);
            printf("Exiting program.\n");
            break;
        }
        else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}

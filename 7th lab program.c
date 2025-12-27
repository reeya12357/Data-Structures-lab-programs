#include <stdio.h>
#include <stdlib.h>

// Structure definition
struct node {
    int data;
    struct node *prev;
    struct node *next;
};

struct node *head = NULL;

// Create doubly linked list
void create(int n) {
    struct node *newnode, *temp;
    int data;

    for (int i = 0; i < n; i++) {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: ");
        scanf("%d", &data);

        newnode->data = data;
        newnode->prev = NULL;
        newnode->next = NULL;

        if (head == NULL) {
            head = newnode;
            temp = head;
        } else {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }
}

// Insert to the left of a given value
void insert_left(int value, int newdata) {
    struct node *temp = head;
    struct node *newnode;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = newdata;

    newnode->next = temp;
    newnode->prev = temp->prev;

    if (temp->prev != NULL)
        temp->prev->next = newnode;
    else
        head = newnode;

    temp->prev = newnode;
}

// Delete node with specific value
void delete_value(int value) {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    while (temp != NULL && temp->data != value)
        temp = temp->next;

    if (temp == NULL) {
        printf("Value not found\n");
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;
    else
        head = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
    printf("Node deleted successfully\n");
}

// Display the list
void display() {
    struct node *temp = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Doubly Linked List: ");
    while (temp != NULL) {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    int n, choice, value, newdata;
     printf("\n1. Create List");
     printf("\n2. Insert Left");
     printf("\n3. Delete Node");
     printf("\n4. Display");
     printf("\n5. Exit");

    while (1) {

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter number of nodes: ");
                scanf("%d", &n);
                create(n);
                break;

            case 2:
                printf("Enter value to insert left of: ");
                scanf("%d", &value);
                printf("Enter new data: ");
                scanf("%d", &newdata);
                insert_left(value, newdata);
                break;

            case 3:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                delete_value(value);
                break;

            case 4:
                display();
                break;

            case 5:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}

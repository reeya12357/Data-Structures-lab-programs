#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;               // data inside node is now info
    struct Node *next;
};

struct Node *start = NULL;  // head pointer renamed to start

// Insert at first
void insertFirst(int item) {
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->info = item;
    p->next = start;
    start = p;
}

// Insert at end
void insertEnd(int item) {
    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->info = item;
    p->next = NULL;

    if (start == NULL) {
        start = p;
        return;
    }

    struct Node *temp = start;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = p;
}

// Insert at any position
void insertAtPosition(int item, int pos) {
    if (pos == 1) {
        insertFirst(item);
        return;
    }

    struct Node *p = (struct Node*)malloc(sizeof(struct Node));
    p->info = item;

    struct Node *temp = start;
    for (int i = 1; i < pos - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Invalid position!\n");
        free(p);
        return;
    }

    p->next = temp->next;
    temp->next = p;
}

// Create list by inserting at end
void createList() {
    int n, item;
    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter item: ");
        scanf("%d", &item);
        insertEnd(item);
    }
}

// Display the linked list
void display() {
    struct Node *temp = start;

    if (temp == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    int choice, item, pos;
     printf("\n--- Menu ---\n");
        printf("1. Create Linked List\n");
        printf("2. Insert at First\n");
        printf("3. Insert at Position\n");
        printf("4. Insert at End\n");
        printf("5. Display List\n");
        printf("6. Exit\n");

    while (1) {
            printf("Enter your choice: ");
        scanf("%d", &choice);



        switch (choice) {
            case 1:
                createList();
                break;
            case 2:
                printf("Enter item: ");
                scanf("%d", &item);
                insertFirst(item);
                break;
            case 3:
                printf("Enter item: ");
                scanf("%d", &item);
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(item, pos);
                break;
            case 4:
                printf("Enter item: ");
                scanf("%d", &item);
                insertEnd(item);
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

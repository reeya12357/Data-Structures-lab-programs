#include <stdio.h>
#include <stdlib.h>


struct node {
    int data;
    struct node *next;
};

struct node *top = NULL;


struct node *front = NULL;
struct node *rear = NULL;


void push() {
    int x;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter element to push: ");
    scanf("%d", &x);
    p->data = x;
    p->next = top;
    top = p;
    printf("Element pushed into stack\n");
}

void pop() {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct node *temp = top;
    printf("Popped element: %d\n", temp->data);
    top = temp->next;
    free(temp);
}

void displayStack() {
    struct node *temp = top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        return;
    }
    printf("Stack elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}


void enqueue() {
    int x;
    struct node *p = (struct node *)malloc(sizeof(struct node));
    if (p == NULL) {
        printf("Memory not allocated\n");
        return;
    }
    printf("Enter element to insert: ");
    scanf("%d", &x);
    p->data = x;
    p->next = NULL;

    if (rear == NULL) {
        front = rear = p;
    } else {
        rear->next = p;
        rear = p;
    }
    printf("Element inserted into queue\n");
}


void dequeue() {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }
    struct node *temp = front;
    printf("Deleted element: %d\n", temp->data);
    front = front->next;
    if (front == NULL)
        rear = NULL;
    free(temp);
}


void displayQueue() {
    struct node *temp = front;
    if (temp == NULL) {
        printf("Queue is empty\n");
        return;
    }
    printf("Queue elements:\n");
    while (temp != NULL) {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}



int main() {
    int choice;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Stack Push\n");
        printf("2. Stack Pop\n");
        printf("3. Stack Display\n");
        printf("4. Queue Insert\n");
        printf("5. Queue Delete\n");
        printf("6. Queue Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: displayStack(); break;
            case 4: enqueue(); break;
            case 5: dequeue(); break;
            case 6: displayQueue(); break;
            case 7: exit(0);
            default: printf("Invalid choice\n");
        }
    }
}

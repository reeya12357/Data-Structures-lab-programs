#include <stdio.h>
#include <stdlib.h>

struct Node {
    int info;
    struct Node *next;
};

struct Node *start = NULL;

/* Create linked list */
void create() {
    int n, i, val;
    struct Node *p, *temp;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("Enter data: ");
        scanf("%d", &val);

        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->info = val;
        temp->next = NULL;

        if (start == NULL) {
            start = temp;
        } else {
            p = start;
            while (p->next != NULL)
                p = p->next;
            p->next = temp;
        }
    }
}

/* Delete first element */
void delete_first() {
    struct Node *p;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    p = start;
    start = start->next;
    free(p);
}

/* Delete specified element */
void delete_specified() {
    int key;
    struct Node *p, *q;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    printf("Enter element to delete: ");
    scanf("%d", &key);

    if (start->info == key) {
        p = start;
        start = start->next;
        free(p);
        return;
    }

    q = start;
    p = start->next;

    while (p != NULL && p->info != key) {
        q = p;
        p = p->next;
    }

    if (p == NULL) {
        printf("Element not found\n");
    } else {
        q->next = p->next;
        free(p);
    }
}

/* Delete last element */
void delete_last() {
    struct Node *p, *q;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    if (start->next == NULL) {
        free(start);
        start = NULL;
        return;
    }

    q = start;
    p = start->next;

    while (p->next != NULL) {
        q = p;
        p = p->next;
    }

    q->next = NULL;
    free(p);
}

/* Display list */
void display() {
    struct Node *p;

    if (start == NULL) {
        printf("List is empty\n");
        return;
    }

    p = start;
    printf("Linked List: ");
    while (p != NULL) {
        printf("%d -> ", p->info);
        p = p->next;
    }
    printf("NULL\n");
}

/* Main function */
int main() {
    int choice;


    printf("\n1.Create\n2.Delete First\n3.Delete Specified\n4.Delete Last\n5.Display\n6.Exit\n");

    while(1){
            printf("Enter choice: ");
            scanf("%d", &choice);

            switch (choice) {

                case 1: create(); break;
                case 2: delete_first(); break;
                case 3: delete_specified(); break;
                case 4: delete_last(); break;
                case 5: display(); break;
                case 6: exit(0);
                default: printf("Invalid choice\n");
        }
    }


}

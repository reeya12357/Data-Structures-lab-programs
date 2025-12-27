#include <stdio.h>
#include <stdlib.h>

#define MAX 20

int hashTable[MAX];
int m;

// Initialize hash table
void init() {
    for (int i = 0; i < m; i++)
        hashTable[i] = -1;
}

// Hash function
int hashFunction(int key) {
    return key % m;
}

// Insert using Linear Probing
void insert(int key) {
    int index = hashFunction(key);

    if (hashTable[index] == -1) {
        hashTable[index] = key;
    } else {
        // Collision occurred
        int i = (index + 1) % m;
        while (i != index) {
            if (hashTable[i] == -1) {
                hashTable[i] = key;
                return;
            }
            i = (i + 1) % m;
        }
        printf("Hash table is full. Cannot insert key %d\n", key);
    }
}

// Display hash table
void display() {
    printf("\nHash Table:\n");
    for (int i = 0; i < m; i++) {
        if (hashTable[i] != -1)
            printf("Address %d : %d\n", i, hashTable[i]);
        else
            printf("Address %d : Empty\n", i);
    }
}

// Main function
int main() {
    int n, key;

    printf("Enter size of hash table (m): ");
    scanf("%d", &m);

    init();

    printf("Enter number of employee records (N): ");
    scanf("%d", &n);

    printf("Enter %d employee keys (4-digit):\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &key);
        insert(key);
    }

    display();
    return 0;
}

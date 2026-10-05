#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 11
#define NUM_SONGS 8

// Given Song IDs
int songIDs[NUM_SONGS] = {105, 210, 315, 420, 525, 630, 735, 840};

// Hash Table structure using Linear Probing
int hashTable[TABLE_SIZE];

void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = -1; // -1 indicates empty slot
    }
}

// Division Method Hash Function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Display Hash Table State
void displayTable() {
    printf("\nIndex | Song ID\n");
    printf("---------------\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        if (hashTable[i] == -1)
            printf("  %2d  |  EMPTY\n", i);
        else
            printf("  %2d  |  %d\n", i, hashTable[i]);
    }
    printf("---------------\n");
}

// Insert with Linear Probing Collision Handling
void insertHashTable() {
    printf("=== INSERTION PROCESS USING DIVISION METHOD (m = %d) ===\n", TABLE_SIZE);
    for (int i = 0; i < NUM_SONGS; i++) {
        int key = songIDs[i];
        int index = hashFunction(key);
        int collisions = 0;

        printf("\nInserting Song ID %d:\n", key);
        printf(" -> Initial Hash Index: %d %% %d = %d\n", key, TABLE_SIZE, index);

        while (hashTable[index] != -1) {
            collisions++;
            printf(" -> Collision detected at index %d! Probing next index...\n", index);
            index = (index + 1) % TABLE_SIZE;
        }

        hashTable[index] = key;
        printf(" -> Inserted %d at index %d after %d collision(s).\n", key, index, collisions);
        displayTable();
    }
}

// Search in Hash Table
int hashSearch(int key, int *comparisons) {
    int index = hashFunction(key);
    int startIndex = index;
    *comparisons = 0;

    while (hashTable[index] != -1) {
        (*comparisons)++;
        if (hashTable[index] == key) {
            return index; // Found
        }
        index = (index + 1) % TABLE_SIZE;
        if (index == startIndex) break; // Traversed whole table
    }
    return -1; // Not found
}

// Linear Search on Array
int linearSearch(int key, int *comparisons) {
    *comparisons = 0;
    for (int i = 0; i < NUM_SONGS; i++) {
        (*comparisons)++;
        if (songIDs[i] == key) {
            return i; // Found
        }
    }
    return -1; // Not found
}

int main() {
    initHashTable();
    insertHashTable();

    // Test Search Functionality
    int searchKeys[] = {315, 840, 999}; // 315, 840 present; 999 absent
    int searchCount = 3;

    printf("\n=== SEARCH COMPARISON PERFORMANCE ===\n");
    for (int i = 0; i < searchCount; i++) {
        int key = searchKeys[i];
        int hComps = 0, lComps = 0;

        int hRes = hashSearch(key, &hComps);
        int lRes = linearSearch(key, &lComps);

        printf("\nSearching for Song ID: %d\n", key);
        printf("  - Linear Search: %s (Comparisons: %d)\n", (lRes != -1) ? "FOUND" : "NOT FOUND", lComps);
        printf("  - Hash Search:   %s (Comparisons: %d)\n", (hRes != -1) ? "FOUND" : "NOT FOUND", hComps);
    }

    return 0;
}

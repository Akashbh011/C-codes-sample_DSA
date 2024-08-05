#include <stdio.h>
#include <stdlib.h>

int hash(int x, int m) {
    // A simple hash function that maps x to an index in [0, m)
    return x % m;
}

int isSubset(int S[], int m, int T[], int n)
{
    // Create a hash table of size m
    int hashTable[m];

    for (int i = 0; i < m; i++) {
        hashTable[i] = -1;
    }

    // Insert elements of S into the hash table
    for (int i = 0; i < m; i++) {
        int index = hash(S[i], m);
        while (hashTable[index] != -1 && hashTable[index] != S[i]) {
            // Handle collisions by probing linearly
            index = (index + 1) % m;
        }
        hashTable[index] = S[i];
    }

    // Check if all elements of S are in T
    for (int i = 0; i < n; i++) {
        int index = hash(T[i], m);
        while (hashTable[index] != -1 && hashTable[index] != T[i]) {
            index = (index + 1) % m;
        }
        if (hashTable[index] == -1) {
            return 0;
        }
    }

    return 1;
}

int main()
{
    int m, n;
    printf("Enter the size of S set: ");
    scanf("%d", &m);
    printf("Enter the size of T set: ");
    scanf("%d", &n);
    int S[m];
    int T[n];
    printf("Enter the elements of S one by one: ");
    for (int i = 0; i < m; i++) {
        scanf("%d", &S[i]);
    }
    printf("Enter the elements of T one by one: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &T[i]);
    }

    if (isSubset(S, m, T, n)) {
        printf("S is a subset of T\n");
    } else{
    printf("S is not a subset of T \n");
    }
    return 0;
}

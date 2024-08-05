#include <stdio.h>
#include <stdlib.h>
#define m 5 // size of set S
#define n 10 // size of set T

// function to check if S is a subset of T
int isSubset(int S[], int T[]) {
    // create a hash table of size m
    int hash_table[m] = {0};
    for (int i = 0; i < m; i++) {
        int index = S[i] % m;
        hash_table[index] = S[i];
    }
    // check if each element of S is in T
    for (int i = 0; i < m; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (hash_table[i] == T[j]) {
                found = 1;
                break;
            }
        }
        if (found == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int S[m] = {1, 2, 3, 4, 5};
    int T[n] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    if (isSubset(S, T) == 1) {
        printf("S is a subset of T.\n");
    } else {
        printf("S is not a subset of T.\n");
    }
    return 0;
}

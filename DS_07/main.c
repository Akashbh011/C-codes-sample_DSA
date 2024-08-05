#include <stdio.h>
#include <stdlib.h>

int hash(int x, int m) {
    return x % m;
}

int isSubset(int S[], int m, int T[], int n)
{
    int hashTable[m];
    for (int i = 0; i < m; i++) {
        hashTable[i] = 0;
    }

    for (int i = 0; i < m; i++) {
        int index = hash(S[i], m);

        hashTable[index] = S[i];
    }
    for(int j=0; j<m; j++)
    {
        for (int i = 0; i < n; i++)
        {


            if (hashTable[j] == T[i])
            {
                hashTable[j]=1;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        if(hashTable[i]!=1){

        return 0;}

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

    int S[m], T[n];
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
    } else {
        printf("S is not a subset of T\n");
    }

    return 0;
}

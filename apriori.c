#include <stdio.h>
#include <stdlib.h>

#define MAX_ITEMS 10  // Maximum number of items in a transaction
#define MAX_TRANS 100 // Maximum number of transactions

// Function to check if a pair is in a transaction
int contains(int transaction[], int item1, int item2, int len) {
    int found1 = 0, found2 = 0;
    for (int i = 0; i < len; i++) {
        if (transaction[i] == item1) found1 = 1;
        if (transaction[i] == item2) found2 = 1;
    }
    return found1 && found2;
}

// Main function to find frequent 2-itemsets
int main() {
    int transactions[MAX_TRANS][MAX_ITEMS], numTrans, transLen[MAX_TRANS], numItems, minSupport = 2;
    int support[MAX_ITEMS][MAX_ITEMS] = {0};

    // Input number of transactions and items
    printf("Enter number of transactions: ");
    scanf("%d", &numTrans);

    printf("Enter number of unique items: ");
    scanf("%d", &numItems);

    // Input transactions
    for (int i = 0; i < numTrans; i++) {
        printf("Enter number of items in transaction %d: ", i + 1);
        scanf("%d", &transLen[i]);
        printf("Enter items in transaction %d: ", i + 1);
        for (int j = 0; j < transLen[i]; j++) {
            scanf("%d", &transactions[i][j]);
        }
    }

    // Calculate support for each pair of items
    for (int i = 0; i < numItems; i++) {
        for (int j = i + 1; j < numItems; j++) {
            for (int t = 0; t < numTrans; t++) {
                if (contains(transactions[t], i, j, transLen[t])) {
                    support[i][j]++;
                }
            }
        }
    }

    // Print frequent 2-itemsets
    printf("\nFrequent 2-itemsets with minimum support count of %d:\n", minSupport);
    for (int i = 0; i < numItems; i++) {
        for (int j = i + 1; j < numItems; j++) {
            if (support[i][j] >= minSupport) {
                printf("Itemset {%d, %d} with support count %d\n", i, j, support[i][j]);
            }
        }
    }

    return 0;
}
#include <stdio.h>
#include <math.h>

// Function to calculate the distance between two points
double distance(int point, int centroid) {
    return fabs(point - centroid);
}

int main() {
    int n, i, j, iterations;
    int data[20], c1, c2;
    int k1[20], k2[20];
    int size_k1, size_k2;
    double mean_k1, mean_k2, sum_k1, sum_k2;
    
    // Input the number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input the data points
    printf("Enter the data points:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &data[i]);
    }

    // Input the initial centroids
    printf("Enter the initial centroid C1: ");
    scanf("%d", &c1);
    printf("Enter the initial centroid C2: ");
    scanf("%d", &c2);

    iterations = 0;
    
    // K-means algorithm loop
    while (1) {
        size_k1 = size_k2 = 0;
        sum_k1 = sum_k2 = 0;

        // Assign each data point to the nearest centroid
        for (i = 0; i < n; i++) {
            if (distance(data[i], c1) < distance(data[i], c2)) {
                k1[size_k1++] = data[i];
            } else {
                k2[size_k2++] = data[i];
            }
        }

        // Calculate new means for k1 and k2
        for (i = 0; i < size_k1; i++) {
            sum_k1 += k1[i];
        }
        for (i = 0; i < size_k2; i++) {
            sum_k2 += k2[i];
        }

        mean_k1 = size_k1 == 0 ? c1 : sum_k1 / size_k1;
        mean_k2 = size_k2 == 0 ? c2 : sum_k2 / size_k2;

        // Print the current iteration details
        printf("Iteration %d:\n", iterations + 1);
        printf("Cluster 1 (C1=%d): ", c1);
        for (i = 0; i < size_k1; i++) {
            printf("%d ", k1[i]);
        }
        printf("\n");

        printf("Cluster 2 (C2=%d): ", c2);
        for (i = 0; i < size_k2; i++) {
            printf("%d ", k2[i]);
        }
        printf("\n\n");

        // Check if centroids have changed
        if (c1 == (int)mean_k1 && c2 == (int)mean_k2) {
            break;
        }

        c1 = (int)mean_k1;
        c2 = (int)mean_k2;

        iterations++;
    }

    // Output the final clusters and centroids
    printf("Final clusters after %d iterations:\n", iterations + 1);
    printf("Cluster 1 (C1=%d): ", c1);
    for (i = 0; i < size_k1; i++) {
        printf("%d ", k1[i]);
    }
    printf("\n");

    printf("Cluster 2 (C2=%d): ", c2);
    for (i = 0; i < size_k2; i++) {
        printf("%d ", k2[i]);
    }
    printf("\n");

    return 0;
}
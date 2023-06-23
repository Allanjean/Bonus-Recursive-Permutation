#include <stdio.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int arr[], int start, int end) {
    if (start == end) {
        // Base case: Print the permutation
        for (int i = 0; i <= end; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        // Recursive case: Generate permutations
        for (int i = start; i <= end; i++) {
            // Fix element at the start index
            swap(&arr[start], &arr[i]);

            // Generate permutations for the remaining elements
            permute(arr, start + 1, end);

            // Restore the array to its original state
            swap(&arr[start], &arr[i]);
        }
    }
}

int main() {
    int arr[] = {1, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Permutations:\n");
    permute(arr, 0, n - 1);

    return 0;
}
#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void heapify(int arr[], int n, int i) {
  int largest = i;
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  if (left < n && arr[left] > arr[largest])
    largest = left;

  if (right < n && arr[right] > arr[largest])
    largest = right;

  if (largest != i) {
    swap(&arr[i], &arr[largest]);
    heapify(arr, n, largest);
  }
}

void heapSort(int arr[], int n) {
  int i, j;

  /* Build Max Heap */
  for (i = n / 2 - 1; i >= 0; i--)
    heapify(arr, n, i);

  printf("Max Heap: ");
  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  printf("\n");

  /* Sorting */
  for (i = n - 1; i > 0; i--) {
    swap(&arr[0], &arr[i]);
    heapify(arr, i, 0);

    printf("After step %d: ", n - i);

    for (j = 0; j < n; j++)
      printf("%d ", arr[j]);

    printf("\n");
  }
}

int main() {
  int arr[] = {45, 72, 30, 90, 65, 50, 85};
  int n = 7;
  int i;

  heapSort(arr, n);

  printf("\nFinal Sorted Array: ");

  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
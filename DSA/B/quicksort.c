#include <stdio.h>

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

int partition(int arr[], int low, int high) {
  int pivot = arr[high];
  int i = low - 1;
  int j;

  for (j = low; j < high; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[high]);

  return i + 1;
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pivotIndex;

    pivotIndex = partition(arr, low, high);

    quickSort(arr, low, pivotIndex - 1);
    quickSort(arr, pivotIndex + 1, high);
  }
}

int main() {
  int arr[] = {45, 72, 30, 90, 65, 50, 85};
  int n = 7;
  int i;

  quickSort(arr, 0, n - 1);

  printf("Final Sorted Array: ");

  for (i = 0; i < n; i++)
    printf("%d ", arr[i]);

  return 0;
}
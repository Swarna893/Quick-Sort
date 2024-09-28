# Quick-Sort

// #include <stdio.h>

// void swap(int *a, int *b){
//   int temp = *a;
//   *a = *b;
//   *b = temp;
// }

// void Partition(int *arr, int left, int right){
//   int pivot,i,j;
//   pivot=arr[left];
//   i=left;
//   j=right+1;
//   while(i<j){
//     do{
//       i++;
//     }while(arr[i]<pivot);
//     do{
//       j--;
//     }while(arr[j]>pivot);
//     if(i<j){
//       swap(arr[i],arr[j]);
//     }
//   }
// }

// void QuickSort(int *arr, int left, int right){
//   int i,j,pivot;
//   if(left<right){
//     Partition(arr, left, right);
//     QuickSort(arr, left, j-1);
//     QuickSort(arr, j+1, right);
//   }
// }


// int main(void) {
//   int arr[] = {5,7,3,7,32,6,324,5};
//   QuickSort(arr, left, right);
// }

// C program for QuickSort
#include <stdio.h>

// Utility function to swap tp integers
void swap(int* p1, int* p2)
{
    int temp;
    temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int partition(int arr[], int low, int high)
{
    // choose the pivot
    int pivot = arr[high];

    // Index of smaller element and Indicate
    // the right position of pivot found so far
    int i = (low - 1);

    for (int j = low; j <= high; j++) {
        // If current element is smaller than the pivot
        if (arr[j] < pivot) {
            // Increment index of smaller element
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

// The Quicksort function Implement

void quickSort(int arr[], int low, int high)
{
    // when low is less than high
    if (low < high) {
        // pi is the partition return index of pivot

        int pi = partition(arr, low, high);

        // Recursion Call
        // smaller element than pivot goes left and
        // higher element goes right
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main()
{
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    // Function call
    quickSort(arr, 0, n - 1);

  // Print the sorted array
    printf("Sorted Array\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
// This Code is Contributed By Diwakar Jha

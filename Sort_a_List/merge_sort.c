#include <stdio.h>


void merge_sort(int i, int j, int a[], int aux[]) {
    if (j <= i) {
        return; 
    }
    int mid = (i + j) / 2;

    // left partition of array is a[i .. mid]
    // right partition of array is a[mid + 1 .. j]
    merge_sort(i, mid, a, aux);     // sort the left side recursively
    merge_sort(mid + 1, j, a, aux);     // sort the right side recursively

    int pointer_left = i;       // pointer_left points to the beginning of the left side
    int pointer_right = mid + 1;        // pointer_right points to the beginning of the right side
    int k;      // k is the loop counter

    // i to j loop to fill each element of the final merged array
    for (k = i; k <= j; k++) {
        if (pointer_left == mid + 1) {      // left pointer has reached the limit
            aux[k] = a[pointer_right];
            pointer_right++;
        } else if (pointer_right == j + 1) {        // right pointer has reached the limit
            aux[k] = a[pointer_left];
            pointer_left++;
        } else if (a[pointer_left] < a[pointer_right]) {        // pointer left points to smaller element
            aux[k] = a[pointer_left];
            pointer_left++;
        } else {        // pointer right points to smaller element
            aux[k] = a[pointer_right];
            pointer_right++;
        }
    }

    for (k = i; k <= j; k++) {      // copy the elements from aux[] to a[]
        a[k] = aux[k];
    }
}


int main() {
  int a[100], aux[100], n, i, d, swap;
 
  printf("Enter number of elements in the array:\n");
  scanf("%d", &n);
 
  printf("Enter %d integers:\n", n);
 
  for (i = 0; i < n; i++)
    scanf("%d", &a[i]);
 
  merge_sort(0, n - 1, a, aux);
 
  printf("Printing the sorted array:\n");
  for (i = 0; i < n; i++)
     printf("%d,", a[i]);
 
  return 0;
}

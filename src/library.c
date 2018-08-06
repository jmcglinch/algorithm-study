#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#include "library.h"

void merge_sort(int *arr, int n);

void merge(int *arr, const int *left, int left_num, const int *right, int right_num);

void bucket_sort(const int *arr, int n, int *out);

void bubble_sort(int *arr, int n);

void selection_sort(int *arr, int n);

void insertion_sort(int *arr, int n);

void heap_sort(int *arr, int n);

int bitwise_2n(int n);

int bitwise_2nplus1(int n);

void heapify(int * arr, int i, int n);

void quick_sort(int *arr, int low, int high);

int partition(int *arr, int low, int high);

int main()
{
    int i = 0;

    int merge[10] = {9, 3, 2, 5, 93, 2, 34, 12, 0, 3};

    merge_sort(merge, 10);

    printf("==merge sort==\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", merge[i]);
    }


    int in[10] = {9, 3, 2, 5, 93, 2, 34, 12, 0, 3};
    int out[93];
    memset(out, 0, 93*sizeof(int));
    bucket_sort(in, 10, out);

    printf("==bucket sort==\n");
    for (i = 0; i < 94; i++)
    {
        if (out[i] > 0)
        {
            while (out[i] > 0)
            {
                --out[i];
            }
        }
    }

    int bubble[10] = {9, 3, 2, 5, 93, 2, 34, 12, 0, 3};
    printf("==bubble sort==\n");
    bubble_sort(bubble, 10);
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", bubble[i]);
    }

    int selection[10] = { 9, 3, 2, 5, 93, 2, 34, 12, 0, 3};
    printf("==selection sort==\n");
    selection_sort(selection, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", selection[i]);
    }

    int insertion[10] = { 9, 3, 2, 5, 93, 2, 34, 12, 0, 3};

    printf("==insertion sort==\n");
    insertion_sort(insertion, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%d\n", insertion[i]);
    }

    int heap[10] = { 93, 3, 2, 5, 9, 2, 34, 12, 0, 3};

    printf("==heap sort==\n");
    heap_sort(heap, 10);

    for (i = 0; i < 10; i++)
    {
        printf("%d\t%d\t%d\t%d\n", i, heap[i], bitwise_2n(i), bitwise_2nplus1(i));
    }

    int quick[10] = { 93, 3, 2, 5, 9, 2, 34, 12, 0, 3};

    printf("==quick sort==\n");
    quick_sort(quick, 0, 10-1);

    for (i = 0; i < 10; i++)
    {
        printf("%d\t%d\n", i, quick[i]);
    }

    return 0;

}


void merge(int *arr, const int *left, int left_num, const int *right, int right_num)
{
    int i = 0, j = 0, k = 0;

    //whoever finishes first
    while (j < left_num && k < right_num)
    {
        if (left[j] < right[k]) {
            arr[i++] = left[j++];
        } else {
            arr[i++] = right[k++];
        }
    }

    //if didn't finish first get leftover
    while (j < left_num)
    {
        arr[i++] = left[j++];
    }

    //if didn't finish first get leftover
    while (k < right_num)
    {
        arr[i++] = right[k++];
    }

}

/**
 * Merge Sort O(n log n)
 * 1. Recursively divide the array to left and right
 * 2. When you have left and right 1 element each, then merge
 * 3. merge by left 1 check right 1, then left 1 check right 2 or left 2 check right 1, and so on
 * 4. Consume leftovers in left or right once left or right has been exhausted.
 * 5. Now the merged array is returned up the tree and process continues
 */
void merge_sort(int *arr, int n)
{
    int mid, i;
    if (n < 2) return;

    //calculate mid (e.g., 5/2=2)
    mid =  n / 2;

    //allocate memory for num of items times Fact struct size
    int *left = malloc(mid * sizeof(int));
    int *right = malloc((n - mid) * sizeof(int));

    //fill the left and right arrays
    for (i = 0; i < mid; i++) {
        left[i] = arr[i];
    }
    //move the index up to mid and limit to array length
    for (i = mid; i < n; i++) {
        //  e.g. (i = 2, mid = 2)
        // right[0] = arr[2]
        right[i-mid] = arr[i];
    }

    merge_sort(left, mid);
    merge_sort(right, (n - mid));
    merge(arr, left, mid, right, (n-mid));
    //free allocated memory from malloc because left and right not needed anymore
    free(left);
    free(right);

}




/**
 * Bucket Sort O(n^2)
 * 1. We must know the maximum value of array
 * 2. Define new array the size of max value
 * 3. Loop over original array and put incremented value to index of new array.
 *    The new array index is the loop index of the original array.
 *    Increment this value as a way to handle duplicates.
 * 4. When you print the new array, simply print the index for the number of times it was incremented.
 */
void bucket_sort(const int *arr, int n, int *out)
{

    int i;

    for (i = 0; i < n; i++)
    {
        out[arr[i]]++;
    }
}

/**
 * Bubble Sort O(n^2)
 * 1. Go through array and swap instances where preceding index is greater than index.
 * 2. Then, repeat for entire array length
 */
void bubble_sort(int *arr, int n)
{
    int i, j, tmp, m;

    for (i = 0; i < n; i++)
    {
        for (j = 1; j < n; j++)
        {
            if (arr[j - 1] > arr[j])
            {
                tmp = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = tmp;
                for (m = 0; m < n; m++)
                {
                    printf("%d ", arr[m]);
                }
                printf("\n");
            }

        }
    }
}

/**
 * Selection Sort O(n^2)
 * 1. Here we compare an incrementally min'd index against rest of values.
 * 2. Do an inline swap with min index if value is less than min index.
 * {3, 2, 1, 0}
 * {2, 3, 1, 0}
 * {1, 3, 2, 0}
 * {0, 3, 2, 1}
 * {0, 2, 3, 1}
 * {0, 1, 3, 2}
 * {0, 1, 2, 3}
 */
void selection_sort(int *arr, int n)
{

    int i, tmp, j, min, m;

    for (i = 0; i < n; i++)
    {
        //move min position up
        min = i;
        //compare min positioned element against rest of elements
        for (j = min + 1; j < n; j++)
        {
            //here we found a smaller element than the min positioned element, so we swap
            if (arr[j] < arr[min])
            {
                tmp = arr[min];
                arr[min] = arr[j];
                arr[j] = tmp;
                for (m = 0; m < n; m++)
                {
                    printf("%d ", arr[m]);
                }
                printf("\n");
            }

        }
    }
}

/**
 * Insertion Sort O(n^2)
 * Insert element into sorted list.
 * The inner loop grows with increment of outer loop such that inner loop is sorted part.
 * {3, 2, 1, 0}
 * 2 < 3
 * {2, 3, 1, 0}
 * 1 < 2
 * {1, 3, 2, 0}
 * 2 < 3
 * {1, 2, 3, 0}
 * 0 < 1
 * {0, 2, 3, 1}
 * {0, 1, 3, 2}
 * {0, 1, 2, 3}
 */
void insertion_sort(int *arr, int n)
{
    int i, j, tmp;

    //this is the unsorted part
    for (i = 1; i < n; i++)
    {
        //this is the sorted part
        for (j = 0; j < i; j++)
        {
            if (arr[i] < arr[j])
            {
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
        }
    }
}

/** Heap Sort (O n log n)
 * first we build a heap structure
 * then, recursively swap root note with current shrinking end position and rebuild the heap
 * (essentially the current root node is the next largest value)
 * at then end you will have a sorted array
 */
void heap_sort(int *arr, int n)
{
    int i, tmp;


    // build heap
    for (i = n/2; i >= 0; i--)
    {
        heapify(arr, i, n);
    }

    for (i = n - 1; i > 0; i--)
    {
        tmp = arr[0];
        arr[0] = arr[i];
        arr[i] = tmp;
        heapify(arr, 0, --n);
    }
}

void heapify(int *arr, int i, int n)
{
    int tmp;
    int left_index = bitwise_2n(i);
    int right_index = bitwise_2nplus1(i);
    int largest;

    if (left_index < n && arr[left_index] >  arr[i])
    {
        largest = left_index;
    } else {
        largest = i;
    }
    if (right_index < n && arr[right_index] > arr[largest])
    {
        largest = right_index;
    }
    if (largest != i)
    {
        tmp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = tmp;
    }
}

int bitwise_2n(int n)
{
    if (n == 0)
    {
        return 1;
    }
    return (n << 1);
}

int bitwise_2nplus1(int n)
{
    if (n == 0)
    {
        return bitwise_2n(0) + 1;
    }
    return -(~(bitwise_2n(n)));
}

/**
 * Quick Sort O(n log n)
 * 1. Arrange lower values below pivot and higher values above
 * 2. Recursively, repeat with subarrays (divided by pivot)
 */
void quick_sort(int *arr, int low, int high)
{
    //{ 93, 3, 2, 5, 9, 2, 34, 12, 0, 3}
    int p;
    //recursively, there is a shrinking high or increasing low
    if (low < high)
    {
        p = partition(arr, low, high);
        //recursively, high is a shrinking middle index
        quick_sort(arr, low, p-1);
        //recursively, low is an incrementing middle index
        quick_sort(arr, p+1, high);
    }
}

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];
    int i = low - 1;
    int j;
    int tmp;
    for (j = low; j < high; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
        }
    }
    //move pivot into middle
    //because everything below (i + 1) is less than pivot
    //but everything else is greater than purely by definition that it wasn't rearranged
    tmp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = tmp;
    return i + 1;
}
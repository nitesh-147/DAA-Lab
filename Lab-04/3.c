#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int randInt()
{
    time_t t;
    srand((unsigned)t * rand());
    return rand() % 1000;
}
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
void printArray(int arr[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
void analyse(int n)
{
    int *arr = malloc(n * sizeof(int));
    for (int i = 0; i < n; ++i)
    {
        int num = randInt();
        arr[i] = num;
    }
    int mx, mn, i;
    clock_t t;
    double rt, bt;
    t = clock();
    mx = arr[0];
    mn = arr[0];
    for (i = 1; i < n; i++)
    {
        if (arr[i] > mx)
            mx = arr[i];
        if (arr[i] < mn)
            mn = arr[i];
    }
    t = clock() - t;
    bt = ((double)t) / CLOCKS_PER_SEC;
    t = clock();
    quickSort(arr, 0, n - 1);
    t = clock() - t;
    rt = ((double)t) / CLOCKS_PER_SEC;
    printf("%d\t%5d\t%10f\t%10f", n / 5000, n, rt, bt);
}
int main()
{
    printf("S.No\tVal N\t Using DnC\t Using Brute Force\n");
    for (int i = 5000; i <= 50000; i += 5000)
    {
        analyse(i);
        printf("\n");
    }
}
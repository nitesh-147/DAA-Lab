#include <stdlib.h>
#include <stdio.h>
#include <time.h>
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {

        if (arr[j] > pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void sortDescending(int arr[], int low, int high)
{
    if (low < high)
    {

        int pi = partition(arr, low, high);

        sortDescending(arr, low, pi - 1);
        sortDescending(arr, pi + 1, high);
    }
}
void printArr(int arr[], int n)
{
    printf("[ ");
    for (int i = 0; i < n; ++i)
        printf("%d, ", arr[i]);
    printf("]\n");
}
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}
void buildHeap(int arr[], int n)
{

    int startIdx = (n / 2) - 1;

    for (int i = startIdx; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
}
void fillRandom(int arr[], int n)
{
    srand(0);
    for (int i = 0; i < n; i++)
        arr[i] = rand() % n;
}
void analyze()
{
    int arr[50000];
    printf("RANDOM\t");
    printf("\tASCENDING\t");
    printf("DESCENDING\n");
    for (int n = 5000; n <= 50000; n += 5000)
    {
        fillRandom(arr, n);

        clock_t t_random = clock();
        heapSort(arr, n);

        t_random = clock() - t_random;

        clock_t t_ascending = clock();
        heapSort(arr, n);

        t_ascending = clock() - t_ascending;

        sortDescending(arr, 0, n);
        // Start timer for descending sort
        clock_t t_descending = clock();
        heapSort(arr, n);
        // Stop timer for descending sort
        t_descending = clock() - t_descending;
        printf("%f\t%f\t%f\n", (double)t_random / CLOCKS_PER_SEC, (double)t_ascending / CLOCKS_PER_SEC, (double)t_descending / CLOCKS_PER_SEC);
    }
}
int heap_extract_max(int arr[], int n)
{
    if (n < 1)
        return -1;
    int max = arr[0];
    arr[0] = arr[n - 1];
    heapify(arr, n, 0);
    printArr(arr, n - 1);
    return max;
}
int main()
{
    clock_t t_asc;
    double tt_asc;
    int i, j, temp;
    int arr[100000];
    int n;
    int ch = 0;
    do
    {
        printf("\
0. Quit\n\
1. n Random numbers=>Array\n\
2. Display the Array\n\
3. Sort the Array in Ascending Order by using Max-Heap Sort\n\
technique\n\
4. Sort the Array in Descending Order by using any algorithm\n\
5. Time Complexity to sort ascending of random data\n\
6. Time Complexity to sort ascending of data already sorted in\n\
ascending order\n\
7. Time Complexity to sort ascending of data already sorted in\n\
descending order\n\
8. Time Complexity to sort ascending all Cases (Data Ascending,\n\
Data in Descending & Random Data) in Tabular form for\n\
values n=5000 to 50000, step=5000\n\
9. Extract largest element\n\
10. Replace value at a node with new value\n\
11. Insert a new element\n\
12. Delete an element\nInput Choice\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            printf("Number of elements?\n");
            scanf("%d", &n);
            fillRandom(arr, n);
            buildHeap(arr, n);
        }
        break;
        case 2:
            printArr(arr, n);
            break;
        case 3:
            heapSort(arr, n);
            printArr(arr, n);
            break;
        case 4:
            sortDescending(arr, 0, n);
            break;
        case 5:
        {
            fillRandom(arr, n);
            clock_t start = clock();
            heapSort(arr, n);
            printf("Time taken to sort random data = %f", (double)(clock() - start) / CLOCKS_PER_SEC);
        }
        break;
        case 6:
        {
            fillRandom(arr, n);
            heapSort(arr, n);

            clock_t start = clock();
            heapSort(arr, n);

            printf("Time taken to sort already sorted data is = %f", (double)(clock() - start) / CLOCKS_PER_SEC);
        }
        break;
        case 7:
        {
            sortDescending(arr, 0, n);

            clock_t start = clock();
            heapSort(arr, n);

            printf("Time taken to sort already descending data is = %f", (double)(clock() - start) / CLOCKS_PER_SEC);
        }
        break;
        case 8:
            analyze();
            break;
        case 9:
        {
            buildHeap(arr, n);
            int max = heap_extract_max(arr, n);
            printf("Max element is %d\n", max);
        }
        break;
        case 10:
        {
            int index;
            printf("Enter index of value to be changed\n");
            scanf("%d", &index);
            printf("Enter new value\n");
            int num;
            scanf("%d", &num);
            arr[index] = num;
            buildHeap(arr, n);
            printArr(arr, n);
        }
        break;
        case 11:
        {
            int num;
            printf("Enter number to be inserted\n");
            scanf("%d", &num);
            printf(";-;\n");
            arr[n + 1] = num;
            buildHeap(arr, n + 1);
            printArr(arr, n + 1);
        }
        break;
        case 12:
        {
            int index;
            printf("Enter index of element to delete\n");
            scanf("%d", &index);
            arr[index] = __INT32_MAX__ + 1;
            n--;
            buildHeap(arr, n);
            printArr(arr, n);
        }
        break;
        default:
            break;
        }
    } while (ch);
}
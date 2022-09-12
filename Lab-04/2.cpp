// 4.2 Write a program to sort a list of n elements using the merge sort method and determine
// the time required to sort the elements. Repeat the experiment for different values of n
// and different nature of data (random data, sorted data, reversely sorted data) in the list.
// n is the user input and n integers can be generated randomly. Finally plot a graph of the
// time taken versus n.

#include <bits/stdc++.h>
using namespace std;

void merge(int a[], int l, int m, int r)
{
    int i = l, j = m + 1, k = l;
    int b[r + 1];
    while (i <= m && j <= r)
    {
        if (a[i] < a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }
    while (i <= m)
    {

        b[k++] = a[i++];
    }
kjdsb    while (j <= r)
    {
        b[k++] = a[j++];
    }
    for (int i = l; i <= r; i++)
        a[i] = b[i];
}

void mergesort(int a[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergesort(a, l, m);
        mergesort(a, m + 1, r);
        merge(a, l, m, r);
    }
}

int main()
{

    for (int j = 10; j < 100000001; j *= 10)
    {
        int n;
        n = j;
        int a[n];
        srand(time(0));
        for (int i = 0; i < n; i++)
        {
            a[i] = rand() % 1000;
        }

        cout << endl
             << "For n= " << n << endl;

        cout << "Average case:\n";
        clock_t start = clock();
        mergesort(a, 0, n - 1);

        cout << "Time: " << (long double)(clock() - start) / CLOCKS_PER_SEC << endl;

        cout << "Best case:\n";

        start = clock();
        mergesort(a, 0, n - 1);

        cout << "Time: " << (long double)(clock() - start) / CLOCKS_PER_SEC << endl;

        for (int i = 0; i < n / 2; i++)
            swap(a[i], a[n - i - 1]);

        cout << "Worst case:\n";

        start = clock();
        mergesort(a, 0, n - 1);

        cout << "Time: " << (long double)(clock() - start) / CLOCKS_PER_SEC << endl;
    }

    return 0;
}
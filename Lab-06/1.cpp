#include <bits/stdc++.h>
using namespace std;

void create_array(int a[], int *n)
{
    cout << "Enter the size of array: ";
    int x;
    cin >> x;
    *n = x;
    for (int i = 0; i < *n; i++)
    {
        a[i] = rand() % 100;
    }
    cout << "\n Array is created of size " << *n << endl;
}

void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

void heapify(int a[], int i, int n)
{
    int mx = i;
    int l = 2 * i + 1, r = 2 * i + 2;

    if (l < n && a[l] > a[mx])
        mx = l;

    if (r < n && a[r] > a[mx])
        mx = r;

    if (mx != i)
    {
        swap(a[mx], a[i]);

        if (mx <= (n / 2 - 1))
            heapify(a, mx, n);
    }
}

void heapsort(int a[], int n)
{
    // int j=2;
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, n);
        // break;
    }
    for (int i = n - 1; i >= 1; i--)
    {
        swap(a[0], a[i]);
        heapify(a, 0, i);
    }
}
void sort_desc(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        bool flag = true;
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                swap(a[j], a[j + 1]);
                flag = false;
            }
        }
        if (flag)
            break;
    }
}
int main()
{
    int a[500000];
    int n = 500000;
    int c = 1;
    while (c != 0)
    {
        cout << "0. Quit \n1. n Random numbers=>Array \n2. Display the Array \n3. Sort the Array in Ascending Order by using Max-Heap Sort technique \n4. Sort the Array in Descending Order by using any algorithm \n5. Time Complexity to sort ascending of random data \n6. Time Complexity to sort ascending of data already sorted in ascending order \n7. Time Complexity to sort ascending of data already sorted in descending order \n8. Time Complexity to sort ascending all Cases (Data Ascending, Data in Descending & Random Data) in Tabular form for values n=5000 to 50000, step=5000 \n9. Extract largest element \n10. Replace value at a node with new value \n11. Insert a new element \n12. Delete an element \n";
        cout << "\n Enter your choice : ";
        cin >> c;
        switch (c)
        {
        case 0:
            return 0;
        case 1:
            create_array(a, &n);
            break;

        case 2:
            display(a, n);
            break;

        case 3:
            heapsort(a, n);
            break;

        case 4:
            sort_desc(a, n);
            break;

        case 5:
               
        }
    }
    return 0;
}
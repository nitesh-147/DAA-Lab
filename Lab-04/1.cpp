// binary search algorithm

#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = l + (r - l) / 2;

        if (arr[mid] == x)
            return mid;

        else if (arr[mid] > x)
            return binarySearch(arr, l, mid - 1, x);
        else
            return binarySearch(arr, mid + 1, r, x);
    }
    return -1;
}

int main()
{
    cout << "Name: Nitesh Kumar Mehta "
         << "Roll: 20051741" << endl;

    // int size;

    // cout << "Enter Size: ";
    // cin >> size;

    // for (int i = 0; i < size; i++)
    //     cout << array[i] << " ";
    // sort(array, array + size);
    // int x;
    // int x;
    // cin>>x;
    for (int i = 10; i <= 100000000; i *= 10)
    {
        int array[i];

        for (int j = 0; j < i; j++)
            array[j] = j;

        // sort(array, array + i);

        cout << "For Size= " << i << endl
             << endl;
        cout << "Best Case:" << endl;
        auto start_time = clock();
        cout << "Found at" << binarySearch(array, 0, i - 1, array[(i - 1) / 2]) << endl;
        auto end_time = clock();
        cout << "Time : " << (end_time - start_time) << endl
             << endl;

        cout << "Average Case:" << endl;
        int p = rand() % i;
        start_time = clock();
        cout << "Found at" << binarySearch(array, 0, i - 1, array[p]) << endl;
        end_time = clock();
        cout << "Time : " << end_time - start_time << endl
             << endl;

        cout << "Worst Case:" << endl;
        start_time = clock();
        cout << "Found at" << binarySearch(array, 0, i - 1, array[i - 1]) << endl;
        end_time = clock();
        cout << "Time : " << end_time - start_time << endl
             << endl;
    }
}
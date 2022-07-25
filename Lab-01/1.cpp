// 1.1 Write a program to store random numbers into an array of n integers and then find out
// the smallest and largest number stored in it. n is the user input.

#include <bits/stdc++.h>
using namespace std;

int mx(int a[], int n)
{
    int result = a[0];
    for (int i = 1; i < n; i++)
        result = max(result, a[i]);

    return result;
}

int mn(int a[], int n)
{
    int result = a[0];
    for (int i = 1; i < n; i++)
        result = min(result, a[i]);

    return result;
}

void print(int a[], int n)
{
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";

    cout << endl;
}

int main()
{
    time_t start, end;

    time(&start);
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100;
    }

    cout << "\nArray obtained from random numbers is: \n";
    print(a, n);

    cout << "\nMaximum number= " << mx(a, n) << endl;
    cout << "Minimum number= " << mn(a, n) << endl;
    cout << "Nitesh Kumar Mehta 20051741" << endl;
    time(&end);

    double time_taken = double(end - start);

    cout << "\n\n Time taken by the program : " << time_taken << " sec" << endl;
    return 0;
}
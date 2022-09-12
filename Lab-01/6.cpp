// 1.6 Write a program to find out the second smallest and second largest element stored in an
// array of n integers. n is the user input. The array takes input through random number
// generation within a given range. How many different ways you can solve this problem.
// Write your approaches & strategy for solving this problem.

#include <bits/stdc++.h>
using namespace std;

int second_largest(int a[], int n)
{
    sort(a, a + n);

    return a[n - 2];
}

int second_smallest(int a[], int n)
{
    sort(a, a + n);

    return a[1];
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

    cout << "\nsecond largest number= " << second_largest(a, n) << endl;
    cout << "second smallest number= " << second_smallest(a, n) << endl;
    cout << "Nitesh Kumar Mehta 20051741" << endl;
    time(&end);

    double time_taken = double(end - start);

    cout << "\n\n Time taken by the program : " << time_taken << " sec" << endl;
    return 0;
}
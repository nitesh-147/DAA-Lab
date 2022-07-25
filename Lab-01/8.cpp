// 1.8 Write a program to display an array of n integers (n>1), where at every index of the
// array should contain the product of all elements in the array except the element at the
// given index. Solve this problem by taking single loop and without an additional array.
// Input Array : 3 4 5 1 2
// Output Array :40 30 24 120 60

#include <bits/stdc++.h>
using namespace std;



void print(int a[],int n){
    for(int i=0;i<n;i++)
     cout<<a[i]<<" ";

     cout<<endl;
}

int main()
{
    time_t start,end;

    time(&start);
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n];
   srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = (rand() % 5)+1;
        
    }

    cout<<"\nArray obtained from random numbers is: \n";
    print(a,n);

long long int product=1;
 for (int i = 0; i < n; i++)
    {
        product*=a[i];
        
    }
     for (int i = 0; i < n; i++)
    {
        a[i] = product/a[i];
        
    }

    cout<<"Array of Product Of all elements except self: \n";
    print(a,n);
    
time(&end);

double time_taken=double(end-start);

cout<<"\n\n Time taken by the program : "<<time_taken<<" sec"<<endl;
    return 0;
}
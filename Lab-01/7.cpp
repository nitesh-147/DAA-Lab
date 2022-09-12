// 1.7 Write a program to swap pair of elements of an array of n integers from starting. If n is
// odd, then last number will be remain unchanged.

#include <bits/stdc++.h>
using namespace std;



void swap_pair(int a[], int n)
{
   for(int i=1;i<n;i+=2){
    swap(a[i],a[i-1]);
   }
}

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
        a[i] = rand() % 100;
        
    }

    cout<<"\nArray obtained from random numbers is: \n";
    print(a,n);

    cout << "\nAfter Swapping pair, the array becomes: " << endl;
    swap_pair(a,n);
    print(a,n);
    
     cout<<"Nitesh Kumar Mehta 20051741"<<endl;
time(&end);

double time_taken=(double)(end-start);

cout<<"\n\n Time taken by the program : "<<time_taken<<" sec"<<endl;
    return 0;
}
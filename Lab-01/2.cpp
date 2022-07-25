// 1.2 Write a program to store random numbers into an array of n integers, where the array
// must contains some duplicates. Do the following:
// a) Find out the total number of duplicate elements.
// b) Find out the most repeating element in the array.



#include <bits/stdc++.h>
using namespace std;

int duplicate(int a[], int n)
{
    sort(a,a+n);
    int result = 0;
    for (int i = 1; i < n; i++)
        {
            if(a[i]==a[i-1])
              result++;
        }

    return result;
}

int repeating(int a[], int n)
{
        sort(a,a+n);

    int result = a[0];
    int curr=1,max=1;
    for (int i = 1; i < n; i++)
        {
            if(a[i]==a[i-1])
            curr++;

            else{
                if(curr>max){
                    max=curr;
                    result=a[i-1];
                }
                curr=1;
            }
        }
        if(curr>max)
        result=a[n-1];

    return result;
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

    cout<<"\nArray: \n";
    print(a,n);

    cout << "\nMost repeating= " << repeating(a, n) << endl;
    cout << "\n\nDuplicate = " << duplicate(a, n) << endl;
     cout<<"Biraj Thakur 20052005"<<endl;
time(&end);

double time_taken=double(end-start);

cout<<"\n\n Time taken by the program : "<<time_taken<<" sec"<<endl;
    return 0;
}
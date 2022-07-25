// 1.3 Write a program to rearrange the elements of an array of n integers such that all even
// numbers are followed by all odd numbers. How many different ways you can solve this
// problem. Write your approaches & strategy for solving this problem.



#include <bits/stdc++.h>
using namespace std;

void reaarange(int a[],int n){
vector<int>odd,even;

for(int i=0;i<n;i++){
    if(a[i]%2==0)
    even.push_back(a[i]);

    else
    odd.push_back(a[i]);
}
int j=0;
for(int i=0;i<odd.size();i++)
a[j++]=odd[i];

for(int i=0;i<even.size();i++)
a[j++]=even[i];

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
reaarange(a,n);
    cout << "\nAfter rearranging: "<< endl;
    print(a,n);
     cout<<"Aashish Shah 20051974"<<endl;
time(&end);

double time_taken=double(end-start);

cout<<"\n\n Time taken by the program : "<<time_taken<<" sec"<<endl;
    return 0;
}
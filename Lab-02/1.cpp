// 2.1 Write a program to test whether a number n, entered through keyboard is prime or
// not by using different algorithms you know for atleast 10 inputs and note down the time
// complexity by step/frequency count method for each algorithm & for each input.
// Finally make a comparision of time complexities found for different inputs, plot an
// appropriate graph & decide which algothm is faster.

#include <bits/stdc++.h>
using namespace std;

bool isprime1(int n)
{
    if (n <= 1)
        return false;
    for(int i=2;i<n;i++){
        if(n%i==0)
        return false;
    }

    return true;
}

bool isprime2(int n)
{
    if (n <= 1)
        return false;
    for(int i=2;i<sqrt(n);i++){
        if(n%i==0)
        return false;
    }

    return true;
}
bool isprime3(int n)
{
    // Corner cases
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
 
    
    if (n % 2 == 0 || n % 3 == 0)
        return false;
 

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
 
    return true;
}
int prime(int a[], int n)
{
   int result=0;
   for(int i=0;i<n;i++){
    if(isprime3(a[i]))
      result++;
   }

    return result;
}

void print (int a[],int n){
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";

    }
    cout<<endl;
}

int main()
{
    clock_t start, end;
for(int s=100;s<=1000;s+=100){
    cout<<" For n="<<s<<endl;
    int n=s;
    start=clock();
    
    // cout << "Enter the size of array: ";
    // cin >> n;
    int a[n];
    srand(time(0));
    for (int i = 0; i < n; i++)
    {
        a[i] = rand() % 100+1;
    }

    // cout << "\nArray obtained from random numbers is: \n";
    // print(a, n);

    cout << "\nNo. of Prime= " <<prime(a, n) << endl;
    cout << "Nitesh Kumar Mehta 20051741" << endl;
    end=clock();

    double time_taken = double(end - start);

    cout << "\n\n Time taken by the program : "  << fixed
         << time_taken << setprecision(3)<< " sec" << endl;
}
    return 0;
}
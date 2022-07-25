// 1.4 Write a program that takes three variable (a, b, c) as separate parameters and rotates the
// values stored so that value a goes to be, b, b to c and c to a by using SWAP(x,y)
// function that swaps/exchanges the numbers x & y.

// 1.3 Write a program to rearrange the elements of an array of n integers such that all even
// numbers are followed by all odd numbers. How many different ways you can solve this
// problem. Write your approaches & strategy for solving this problem.



#include <bits/stdc++.h>
using namespace std;



int main()
{
    time_t start,end;

    time(&start);
    cout<<"Enter Three numbers: ";
    int a,b,c;cin>>a>>b>>c;
    cout<<"\nOriginally: \n";
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;

    swap(a,b);
    swap(b,c);

    cout<<"\nAfter Rotation: \n";
    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"c = "<<c<<endl;

     cout<<"Biraj Thakur 20052005"<<endl;
time(&end);

double time_taken=double(end-start);

cout<<"\n\n Time taken by the program : "<<time_taken<<" sec"<<endl;
    return 0;
}
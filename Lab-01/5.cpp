// 1.5 Let A be n*n square matrix array. WAP by using appropriate user defined functions for
// the following:
// a) Find the number of nonzero elements in A
// b) Find the sum of the elements above the leading diagonal.
// c) Display the elements below the minor diagonal.
// d) Find the product of the diagonal elements.


#include <bits/stdc++.h>
using namespace std;
// const int M=100;

int non_zero(int n,int *a){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(*((a+i*n)+j)!=0)
            ans++;
        }
    }
    return ans;
}
int sum_above_leading_diagonal(int n,int *a){
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i<j)
            ans+=*((a+i*n)+j);
        }
    }
    return ans;
}

void element_below_minor_diagonal(int n,int *a){
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i+j>=n)
            cout<<*((a+i*n)+j)<<" ";
        }
        cout<<endl;
    }
    
}

int product_diagonal(int n,int *a){
    int ans=1;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j || i+j==n-1)
              ans*=*((a+i*n)+j);
        }
        // cout<<endl;
    }
    return ans;
}

void print_2darray(int n,int *a){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            // if(i+j>=n)
            cout<<*((a+i*n)+j)<<" ";
        }
        cout<<endl;
    }
}

int main()
{
    time_t start,end;

    time(&start);
    int n;
    cout << "Enter the size of array: ";
    cin >> n;
    int a[n][n];
   srand(time(0));
    for (int i = 0; i < n; i++)
    {
        for(int j=0;j<n;j++)
        a[i][j] = rand() % 10;
        
    }

    cout<<"\n2D-Array obtained from random numbers is: \n";
    print_2darray(n,(int *)a);

   cout<<"\n No. of non zero elements= "<<non_zero(n,(int *)a)<<endl;
   cout<<"\n sum of elements above leading diagonal= "<<sum_above_leading_diagonal(n,(int *)a)<<endl;

   cout<<"\n elements below minor diagonal= "<<endl;
   element_below_minor_diagonal(n,(int *)a);

   cout<<"\n product of diagonal= "<<product_diagonal(n,(int *)a)<<endl;

time(&end);

double time_taken=double(end-start);

cout<<"\n\n Time taken by the program : "<<time_taken<<" sec"<<endl;
    return 0;
}
// #include <iostream>
// #include<time.h>

// using namespace std;

// void nonzero(int A[][3])
// {
//     for(int i=0; i<3; i++)
//     {
//         for(int j=0; j<3; j++)
//         {
//             if(A[i][j]!=0)
//             {
//               cout<<A[i][j]<<" ";
//             }
//         }
//     }
//     cout<<endl;
// }

// void sum(int A[][3])
// {
//     int sum=0;
//    for(int i=0; i<3; i++)
//     {
//         for(int j=i; j<3; j++)
//         {
//             sum+=A[i][j];
            
//         }
//     }    
//     cout<<sum<<endl;

// }

// void display(int A[][3])
// {
//     for(int i=2; i>=0; i--)
//     {
//         for(int j=i; j<3; j++)
//         {
//            cout<<A[i][j]<<" ";
//         }
//         cout<<endl;
//     }    
// }

// void product(int A[][3])
// {
//     int total=1;
//     for(int i=0; i<3; i++)
//     {
//         total*=A[i][i]*A[i][2-i];

//     }
//     cout<<total-A[3/2][3/2]<<endl;
// }

// int main()
// {
//     time_t start,end;
//     time(&start);
//     int A[3][3]={1,30,36,0,3,2,42,2,78};
//     nonzero(A);
//    sum(A);
//    display(A);
//     product(A);
//     cout<<"Nitesh Kumar Mehta 20051741"<<endl;
//     time(&end);

//     double t=double(end-start);
//     cout<<"Time taken= "<<t<<"sec"<<endl;
// }
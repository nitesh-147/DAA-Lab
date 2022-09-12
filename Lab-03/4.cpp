// Let A be an array of n integers a0,a1,... ,an-1 (negative integers are allowed), denoted, by
// A[i... j], the sub-array ai, ai+1,... ,aj for i≤j. Also let Si-j denote the sum ai + ai+1 +· · · + aj.
// Write a programby using an udf that must run in O(n2

// ) time to find out the maximum
// value of Si-j for all the pair i, j with 0 ≤ i ≤ j ≤ n-1. Call this maximum value S. Also
// obtains the maximum of these computed sums. Let j < i in the notation A[i... j] is also
// allowed. In this case, A[i... j] denotes the empty sub-array (that is, a sub-array that ends
// before it starts) with sum Si-j = 0. Indeed, if all the elements of A are negative, then one
// returns 0 as the maximum sub-array sum.
// a. For example, for the array A[]={1, 3, 7, 2, 1, 5, 1, 2, 4, 6, 3}.
// b. This maximum sum is S = S3-8 = 2+( 1)+5+( 1)+( 2)+4 = 7.
#include <bits/stdc++.h>
#include <stdlib.h>
#include<time.h>
int findMax(int arr[], int n) { int max = 0;
for(int i=0;i<n;++i){
int sum = 0;
for(int j=i;j<n;++j){
sum+=arr[j];
if(sum > max)
max = sum; } }return max; }
int main(){
    double total_time;
    clock_t start, end;
    int A[] = {1, 3, 7, 2, 1, 5, 1, 2, 4, 6, 3};
    int max = 0;
    int n = sizeof(A) / sizeof(int);
    start = clock();
    max = findMax(A, n);
    for(int i=0;i<n;i++)
    printf("%d ",A[i]);
    printf("\n");
    printf("Max subarray is %d\n", max);
    end = clock();
    total_time = ((double) (end - start)) / CLK_TCK;
    printf("\nTime taken : %f seconds\n", total_time);
    printf("\nNitesh Kumar Mehta \n Roll Number : 20051741\n");
}

// Range with maximum sum of elements was found using a brute force method with time complexity
// O [n2].
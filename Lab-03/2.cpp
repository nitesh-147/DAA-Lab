// Let A be a list of n (not necessarily distinct) integers. Write a program by using User
// Defined Function(UDF)s to test whether any item occurs more than ฀ n/2฀ times in A.
// a) UDF should take O(n2

// ) time and use no additional space.
// b) UDF should take O(n) time and use O(1) additional space.
#include <bits/stdc++.h>
#include <stdlib.h>
#include <time.h>

int findMajorityNormal(int nums[], int n)
{
    for (int i = 0; n && i <= n / 2; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (nums[j] == nums[i])
                count++;
        }
        if (count > n / 2)
            return nums[i];
    }
    return -1;
}
int findMajorityLinear(int nums[], int n)
{
    int m;
    int i = 0;
    for (int j = 0; j < n; j++)
    {
        if (i == 0)
            m = nums[j], i = 1;
        else
            (m == nums[j]) ? i++ : i--;
    }
    return m;
}
int main()
{
    printf("Enter the value of n : ");
    int n;
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n;i++)
        scanf("%d",&arr[i]);
    /*for (int i = 0; i < n;i++)
        arr[i] = rand() % 100;*/
    clock_t t = clock();
    printf("The major element is (O(n^2)): %d\n", findMajorityNormal(arr, n));
    t = clock() - t;
    printf("Time taken Normal method : %f\n", ((double)t) / CLOCKS_PER_SEC);
    t = clock();
    printf("The major element is (O(n)): %d\n", findMajorityLinear(arr, n));
    t = clock() - t;
    printf("Time taken Boyer-Moore method : %f\n", ((double)t) / CLOCKS_PER_SEC);
    printf("\nNitesh  \n Roll Number : 20051741\n");
}
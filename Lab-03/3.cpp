// 3.3 Write a program by using an user defined function for computing ฀ √n฀ for any
// positive integer n. Besides assignment and comparison, your algorithm may only use the
// four basic arithmetical operations.

#include <bits/stdc++.h>

using namespace std;

double sqrt(double n) {
    double l = 0, r = n / 2, ans = 0, m = 0;
    while (l <= r) {
        m = (l + r) / 2;
        if (m * m == n) {
            return m;
        } else if (m * m < n) {
            l = m + 1;
            ans = l;
        } else {
            r = m - 1;
            ans = r;
        }
    }
    return ans;
}

int main() {
    double n;
    clock_t start, end;
    start = clock();
    cout << "Enter the number: ";
    cin >> n;
    cout << "The square root of " << n << " is " << sqrt(n) << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time taken by the program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    printf("\nNitesh \n Roll Number : 20051741\n");
    return 0;
}
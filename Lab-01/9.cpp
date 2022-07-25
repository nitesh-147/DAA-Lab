// 1.9 Write a program using a function for computing ⌊√n⌋ for any positive integer. Besides
// assignment and comparison, your algorithm may only use the four basic arithmetic
// operations.
// Hints: In number theory, the integer square root (isqrt) of a positive integer n is the
// positive integer m which is the greatest integer less than or equal to the square root of n,
// isqrt(n)=⌊√n⌋

#include <bits/stdc++.h>
using namespace std;

int main()
{

    time_t start, end;

    time(&start);
    int n;
    cout << "Enter the positive num: ";
    cin >> n;
    int ans=1;
    while(ans*ans<=n){
        ans++;
    }

    cout<<endl<<"square root of "<<n<<" = "<<ans-1<<endl;
    cout << "Nitesh Kumar Mehta 20051741" << endl;
    time(&end);

    double time_taken = double(end - start);

    cout << "\n\n Time taken by the program : " << time_taken << " sec" << endl;
    return 0;
}
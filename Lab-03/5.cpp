// 3.5 Design a data structure to maintain a set S of n distinct integers that supports the
// following two operations:
// a) INSERT(x, S): insert integer x into S
// b) REMOVE-BOTTOM-HALF(S): remove the smallest ฀ n/2฀ integers from S.
// c) Write a program by using UDFs that give the worse-case time complexity of the
// two operations INSERT(x, S) in O(1) time and REMOVE-BOTTOM-HALF(S) in
// O(n) time.
#include <bits/stdc++.h>
using namespace std;

void Insert(set<int> &s, int x)
{
    s.insert(x);
}
void Remove_bottom_half(set<int> &s)
{
    int n = s.size();
    //

    int x = n;
    for (auto i : s)
    {
        n--;
        if (n <= s.size() / 2)
            s.erase(i);
    }
}
void print(set<int> s)
{
    for (auto i : s)
    {
        cout << i << " ";
    }
    cout << endl;
}
int main()
{
    set<int> s;

    int n = 1;
    while (n != 0)
    {
        cout << "Enter the choice: \n1: Insert in Set\n2:Remove bottom half\n3:Print set \n Enter 0 to exit" << endl;
        cin >> n;

        switch (n)
        {
        case 0:
            break;
        case 1:
            cout << "Enter the data ";
            int x;
            cin >> x;
            Insert(s, x);
            break;
        case 2:
            Remove_bottom_half(s);
            print(s);
            break;
        case 3:
            print(s);
            break;
        default:
            cout << "Enter Valid Option: " << endl;
        }
    }
    return 0;
}

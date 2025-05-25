#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        if (n == 2)
        {
            cout << 2 << endl;
            continue;
        }
        int smallest_miltiple = 2;
        for (int i = 3; i <= n; i++)
        {

            if (smallest_miltiple % i == 0)
            {
                smallest_miltiple =  smallest_miltiple;
            }
            else
            {
                for (int j = 2; j <= 40; j++)
                {
                    if (i % j == 0)
                    {
                        smallest_miltiple = smallest_miltiple * j;
                        break;
                    }
                }
            }
        }
        cout << smallest_miltiple << endl;
    }

    return 0;
}
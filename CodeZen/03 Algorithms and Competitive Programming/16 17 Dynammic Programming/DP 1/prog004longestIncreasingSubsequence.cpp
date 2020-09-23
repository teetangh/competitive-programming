#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;


// Iterative
// Time: O(n^2) | Space: O(n)
int lis(int *input, int n)
{
    int *output = new int[n];
    output[0] = 1;

    for (int i = 1; i < n; i++)
    {
        output[i] = 1;
        for (int j = i - 1; j >= 0; j--)
        {
            if (input[j] > input[i])
                continue;

            int possibleAns = output[j] + 1;
            if (possibleAns > output[i])
                output[i] = possibleAns;
        }
    }

    int best = 0;
    for (int i = 0; i < n; i++)
    {
        if (best < output[i])
            best = output[i];
    }

    delete[] output;
    return best;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    int *input = new int[n];
    for (int i = 0; i < n; i++)
        cin >> input[i];

    cout << lis(input, n) << endl;

    return 0;
}
// // Sample IO
// 7
// 4 3 9 7 6 8 20

// 4
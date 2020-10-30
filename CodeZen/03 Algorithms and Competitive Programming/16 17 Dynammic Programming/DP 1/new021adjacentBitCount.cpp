#include <iostream>
#include <iomanip>
#include <bits/stdc++.h>

using namespace std;

// Defines
#define MOD 1000000007
#define endl '\n'
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL)

// typedefs
typedef long long ll;
typedef long long int lli;

lli adjacent_bit_count(int n, int k, int first, vector<vector<vector<int>>> &dp)
{
    if (n <= 0 || k < 0)
        return 0;

    if (n == 1)
    {
        if (k == 0)
            return dp[n][k][first] = 1;
        else
            return dp[n][k][first] = 0;
    }

    if (dp[n][k][first] != -1)
        return dp[n][k][first];

    if (first == 0)
        return dp[n][k][first] = adjacent_bit_count(n - 1, k, 0, dp) + adjacent_bit_count(n - 1, k - 1, 1, dp);
    else
        return dp[n][k][first] = adjacent_bit_count(n - 1, k, 0, dp) + adjacent_bit_count(n - 1, k, 1, dp);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("xinput.txt", "r", stdin);
    freopen("xoutput.txt", "w", stdout);
#endif

    fastio;

    int test_cases;
    cin >> test_cases;

    vector<vector<vector<int>>> dp;
    dp.resize(101, vector<vector<int>>(101, vector<int>(2, -1)));

    while (test_cases--)
    {
        int serial, n, k;
        cin >> serial >> n >> k;
        cout << serial << " " << (adjacent_bit_count(n, k, 0, dp) % MOD + adjacent_bit_count(n, k, 1, dp) % MOD) % MOD << endl;
    }

    return 0;
}

// // Sample IO
// 10
// 1 5 2
// 2 20 8
// 3 30 17
// 4 40 24
// 5 50 37
// 6 60 52
// 7 70 59
// 8 80 73
// 9 90 84
// 10 100 90
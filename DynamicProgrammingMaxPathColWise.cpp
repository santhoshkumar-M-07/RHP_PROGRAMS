#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int n;
vector<vector<int>> mat;
vector<long long> dp;

long long solve(int col, int mask) {

    if (col == n)
        return 0;

    if (dp[mask] != -1)
        return dp[mask];

    long long ans = LLONG_MIN;

    for (int row = 0; row < n; row++) {

        if ((mask & (1 << row)) == 0) {

            ans = max(
                ans,
                (long long)mat[row][col] +
                solve(col + 1, mask | (1 << row))
            );
        }
    }

    return dp[mask] = ans;
}

int main() {

    cin >> n;

    mat.resize(n, vector<int>(n));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> mat[i][j];
        }
    }

    dp.assign(1 << n, -1);

    cout << solve(0, 0) << endl;

    return 0;
}
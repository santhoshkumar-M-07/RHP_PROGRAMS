#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<long long> getFSMax(vector<vector<long long>>& dp, int row, int c) {

    long long fmax = max(dp[row][0], dp[row][1]);
    long long smax = min(dp[row][0], dp[row][1]);

    for (int col = 2; col < c; col++) {

        if (dp[row][col] > fmax) {
            smax = fmax;
            fmax = dp[row][col];
        }
        else if (dp[row][col] > smax) {
            smax = dp[row][col];
        }
    }

    return {fmax, smax};
}

int main() {

    int r, c;
    cin >> r >> c;

    vector<vector<int>> grid(r, vector<int>(c));
    vector<vector<long long>> dp(r, vector<long long>(c));

    for (int row = 0; row < r; row++) {
        for (int col = 0; col < c; col++) {

            cin >> grid[row][col];

            if (row == 0) {
                dp[row][col] = grid[row][col];
            }
        }
    }

    for (int row = 1; row < r; row++) {

        vector<long long> fsmax = getFSMax(dp, row - 1, c);

        for (int col = 0; col < c; col++) {

            dp[row][col] = grid[row][col] +
                           (dp[row - 1][col] == fsmax[0]
                                ? fsmax[1]
                                : fsmax[0]);
        }
    }

    cout << getFSMax(dp, r - 1, c)[0] << endl;

    return 0;
}
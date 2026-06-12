#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> solve(vector<vector<int>>& ranges, int n, int k) {

        int MAX = 200000;

        vector<int> diff(MAX + 2, 0);

        for (int i = 0; i < n; i++) {
            int left = ranges[i][0];
            int right = ranges[i][1];

            diff[left]++;
            diff[right + 1]--;
        }

        vector<int> freq(MAX + 1, 0);

        for (int i = 1; i <= MAX; i++) {
            freq[i] = freq[i - 1] + diff[i];
        }

        vector<int> admissible(MAX + 1, 0);

        for (int i = 1; i <= MAX; i++) {
            if (freq[i] >= k) {
                admissible[i] = 1;
            }
        }

        vector<int> pref(MAX + 1, 0);

        for (int i = 1; i <= MAX; i++) {
            pref[i] = pref[i - 1] + admissible[i];
        }

        return pref;
    }
};

int main() {

    int n, k, q;
    cin >> n >> k >> q;

    vector<vector<int>> ranges(n, vector<int>(2));

    for (int i = 0; i < n; i++) {
        cin >> ranges[i][0] >> ranges[i][1];
    }

    Solution obj;
    vector<int> pref = obj.solve(ranges, n, k);

    while (q--) {
        int a, b;
        cin >> a >> b;

        cout << pref[b] - pref[a - 1] << '\n';
    }

    return 0;
}
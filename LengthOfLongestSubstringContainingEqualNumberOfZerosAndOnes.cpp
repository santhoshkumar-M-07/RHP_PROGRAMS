#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int findMaxLen(string str) {
    unordered_map<int, int> hm;
    hm[0] = -1;

    int maxLen = 0;
    int sum = 0;

    for (int i = 0; i < str.length(); i++) {
        sum += (str[i] == '1') ? 1 : -1;

        if (hm.find(sum) != hm.end()) {
            maxLen = max(maxLen, i - hm[sum]);
        } else {
            hm[sum] = i;
        }
    }

    return maxLen;
}

int main() {
    string str;
    cin >> str;

    cout << findMaxLen(str) << endl;

    return 0;
}
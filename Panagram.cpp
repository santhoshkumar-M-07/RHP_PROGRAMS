#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int flag = 0;

    for (char ch : s) {
        ch = tolower(ch);

        if (ch >= 'a' && ch <= 'z') {
            flag |= (1 << (ch - 'a'));
        }
    }

    if (flag == (1 << 26) - 1)
        cout << "The given string is pangram" << endl;
    else
        cout << "The given string is not pangram" << endl;

    return 0;
}
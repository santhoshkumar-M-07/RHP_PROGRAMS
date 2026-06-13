#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string s;

    cout << "Enter a string: ";
    getline(cin, s);

    int flagL = 0;
    int flagU = 0;

    for (char ch : s) {
        if (islower(ch)) {
            flagL |= (1 << (ch - 'a'));
        }
        else if (isupper(ch)) {
            flagU |= (1 << (ch - 'A'));
        }
    }

    int allLetters = (1 << 26) - 1;

    if (flagL == allLetters && flagU == allLetters) {
        cout << "The given string is a pangram (Both upper and lower case)" << endl;
    } else {
        cout << "The given string is not a pangram (Both upper and lower case)" << endl;
    }

    return 0;
}
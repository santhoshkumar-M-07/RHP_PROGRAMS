#include <iostream>
#include <string>
using namespace std;

class StringWithBitwiseShifting {
public:
    void Bitwise(const string& str) {
        int len = str.length();

        for (int i = 0; i < (1 << len); i++) {
            string combination = "";

            for (int j = 0; j < len; j++) {
                if ((i & (1 << j)) > 0) {
                    combination += str[j];
                }
            }

            cout << combination << endl;
        }
    }
};

int main() {
    string str;

    cout << "Enter a String: ";
    getline(cin, str);

    StringWithBitwiseShifting obj;
    obj.Bitwise(str);

    return 0;
}
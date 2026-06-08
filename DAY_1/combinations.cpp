#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    const auto len = str.length();

    for (int i = 1; i < (1 << len); i++) {

        string combination;

        for (int shift = 0; shift < len; shift++)
            if (i & (1 << shift))
                combination += str[shift];

        cout << combination << endl;
    }
    return 0;
}
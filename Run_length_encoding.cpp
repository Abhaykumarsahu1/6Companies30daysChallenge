#include <iostream>
using namespace std;

void countConsecutive(string s) {
    int count = 1;
    for (int i = 0; i < s.length(); i++) {
        int j = i + 1;
        while (s[i] == s[j]) {
            count++;
            j++;
        }
        cout << s[i] << count;
        count = 1;
        i = j - 1;
    }
}

int main() {
    string s = "aaaabbbcc";
    countConsecutive(s);
    cout << endl;
    return 0;
}

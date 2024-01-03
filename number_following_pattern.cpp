#include <iostream>
using namespace std;

class Solution {
public:
    string smallestNumber(string& pattern) {
        string ans = "";
        int itr = 1;
        for (int i = 0; i <= pattern.size(); i++) {
            if (i == pattern.size() || pattern[i] == 'I') {
                ans += to_string(itr);
                itr++;
            } else {
                int count = 0;
                while (i < pattern.size() && pattern[i] == 'D') {
                    count++;
                    i++;
                }
                for (int j = count; j >= 0; j--) {
                    ans += to_string(j + itr);
                }
                itr += count + 1;
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string pattern = "IDID"; // Replace with your pattern
    string smallestNum = solution.smallestNumber(pattern);
    cout << "The smallest number following pattern " << pattern << " is: " << smallestNum << endl;
    return 0;
}

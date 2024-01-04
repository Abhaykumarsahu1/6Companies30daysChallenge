#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int cal(string a, string b) {
        if (a[0] == b[0] && a[1] == b[1]) {
            string s1 = a.substr(2, 2);
            string s2 = b.substr(2, 2);

            int a1 = stoi(s1);
            int b1 = stoi(s2);
            return (abs(a1 - b1));
        } else {
            string s1 = a.substr(0, 2);
            string s2 = b.substr(0, 2);
            string s3 = a.substr(2, 2);
            string s4 = b.substr(2, 2);

            int a1 = stoi(s1);
            int b1 = stoi(s2);
            int a2 = stoi(s3);
            int b2 = stoi(s4);
            int co = 0;
            if (abs(a1 - b1) == 1) {
                if (a1 < b1) {
                    co += 60 - a2;
                    co += b2;
                } else {
                    co += 60 - b2;
                    co += a2;
                }
                return co;
            } else
                return INT_MAX;
        }
    }

    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        vector<string> ans;
        int n = access_times.size();
        sort(access_times.begin(), access_times.end());
        map<string, vector<string>> mp;
        for (int i = 0; i < n; i++) {
            mp[access_times[i][0]].push_back(access_times[i][1]);
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            string key = it->first;
            vector<string> vec = it->second;
            if (mp[key].size() < 3)
                continue;
            else {
                for (int e = 0; e < mp[key].size() - 2; e++) {
                    if (cal(mp[key][e], mp[key][e + 2]) <= 59) {
                        ans.push_back(key);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test data - Access times
    vector<vector<string>> access_times = {
        {"Employee1", "0901"},
        {"Employee2", "1002"},
        {"Employee1", "0915"},
        {"Employee1", "0940"},
     
    };

    vector<string> highAccessEmployees = solution.findHighAccessEmployees(access_times);

    // Displaying employees with high access
    cout << "Employees with high access: ";
    for (const string& employee : highAccessEmployees) {
        cout << employee << " ";
    }
    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        sort(envelopes.begin(), envelopes.end(), [](const vector<int>& a, const vector<int>& b) {
            if (a[0] == b[0]) {
                return b[1] < a[1];
            } else {
                return a[0] < b[0];
            }
        });

        vector<int> nums(envelopes.size());
        int j = 0;
        for (int i = 0; i < envelopes.size(); ++i) {
            nums[j] = envelopes[i][1];
            j++;
        }
        return lengthOfLIS(nums);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<int> al;
        for (int i = 0; i < nums.size(); ++i) {
            int index = binary(al, nums[i]);
            if (index == al.size()) {
                al.push_back(nums[i]);
            } else {
                al[index] = nums[i];
            }
        }
        return al.size();
    }

    int binary(vector<int>& al, int target) {
        int s = 0;
        int e = al.size();
        int result = al.size();
        while (s < e) {
            int mid = (s + e) / 2;
            if (al[mid] < target) {
                s = mid + 1;
            } else {
                e = mid;
                result = mid;
            }
        }
        return result;
    }
};

int main() {
    Solution solution;

    vector<vector<int>> envelopes = {{5, 4}, {6, 4}, {6, 7}, {2, 3}};
    int maxEnvelopes = solution.maxEnvelopes(envelopes);
    cout << "Maximum number of envelopes that can be nested: " << maxEnvelopes << endl;

    return 0;
}

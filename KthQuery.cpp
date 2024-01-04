#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define pr pair<string, int>

// compare class for priority queue
class comp {
public:
    bool operator()(const pr &a, const pr &b) const {
        if (a.first.size() == b.first.size()) {
            if (a.first == b.first) {
                return a.second < b.second;
            }
            return a.first < b.first;
        }
        return a.first.size() < b.first.size();
    }
};

class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;

        // iterating through all queries
        for (auto query : queries) {
            int k = query[0]; // fetching k
            int final_len = query[1]; // fetching required trimmed length

            priority_queue<pr, vector<pr>, comp> pq;
            for (int i = 0; i < nums.size(); i++) {
                string num = nums[i];
                string trimmed_num = num.substr(num.size() - final_len); // trimming the num using substr function, trimming will be from the leftmost
                pq.push({ trimmed_num, i }); // pushing the pair in the priority_queue
            }

            // getting the kth smallest value
            while (pq.size() > k) {
                pq.pop();
            }
            string kSmallestNum = pq.top().first; // fetching
            int idx = pq.top().second;

            // if a smaller index is present for the same value
            while (pq.size() > 0 && pq.top().first == kSmallestNum && pq.top().second < idx) {
                idx = pq.top().second;
                pq.pop();
            }

            // we got our answer for the query
            ans.push_back(idx);
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Test data - numbers and queries
    vector<string> numbers = {"123456", "789012", "345678", "901234"};
    vector<vector<int>> queries = {
        {2, 4},
        {1, 3},
        {3, 5}
        // Add more test queries as needed
    };

    vector<int> result = solution.smallestTrimmedNumbers(numbers, queries);

    // Displaying the result
    cout << "Indices of smallest trimmed numbers for each query: ";
    for (int idx : result) {
        cout << idx << " ";
    }
    cout << endl;

    return 0;
}

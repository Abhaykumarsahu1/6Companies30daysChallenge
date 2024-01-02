#include <iostream>
#include <vector>

using namespace std;

class Solution {
private:
    void helperFun(int index, int sum, int n, int k, vector<int> &output, vector<vector<int>> &ans) {
        // Base case 
        if (sum == n && k == 0) {
            ans.push_back(output);
            return;
        }
        // Edge case:
        if (sum > n || k < 0) {
            return;
        }

        for (int i = index; i <= 9; i++) {
            output.push_back(i); // Add current element to the temporary output vector
            helperFun(i + 1, sum + i, n, k - 1, output, ans);
            output.pop_back(); // Backtrack: Remove the last added element
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> output;

        helperFun(1, 0, n, k, output, ans);
        return ans;
    }
};

int main() {
    Solution sol;
    int k = 3;
    int n = 15;

    vector<vector<int>> result = sol.combinationSum3(k, n);

    // Displaying the result
    cout << "Combinations of " << k << " numbers from 1 to 9 that sum up to " << n << ":\n";
    for (const auto &combination : result) {
        cout << "[";
        for (int i = 0; i < combination.size(); ++i) {
            cout << combination[i];
            if (i != combination.size() - 1) {
                cout << ", ";
            }
        }
        cout << "]\n";
    }

    return 0;
}

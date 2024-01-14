#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int LCSubStr(vector<int>& X, vector<int>& Y, int n, int m){
   int LCSuff[n + 1][m + 1];
    int result = 0; 

    /* LCSuff[m+1][n+1] in
        bottom up fashion. */
    for (int i = 0; i <= n; i++){
        
        for (int j = 0; j <= m; j++){
            // The first row and first column
            // entries have no logical meaning,
            if (i == 0 || j == 0)
                LCSuff[i][j] = 0;
 
            else if (X[i - 1] == Y[j - 1]) {
                LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
                result = max(result, LCSuff[i][j]);
            }
            else
                LCSuff[i][j] = 0;
        }
    }
    return result;
}

    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        
        return LCSubStr(nums1,nums2,n,m);
    }
};

int main() {
    Solution solution;

    // Example usage
    vector<int> nums1 = {1, 2, 3, 2, 1};
    vector<int> nums2 = {3, 2, 1, 4, 7};
    int result = solution.findLength(nums1, nums2);

    cout << "Length of Longest Common Substring: " << result << endl;

    return 0;
}

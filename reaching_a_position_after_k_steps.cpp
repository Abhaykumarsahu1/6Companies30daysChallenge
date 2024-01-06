#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
    long long solve(int curr, int endPos, int k, vector<vector<int>>& dp){
        if(k == 0){
            return curr==endPos;
        }
        if(dp[999+curr][k] != -1){
            return dp[999+curr][k];
        }
        long long forw = solve(curr+1,endPos,k-1,dp);
        long long back = solve(curr-1,endPos,k-1,dp);
        return dp[999+curr][k] = (forw+back)%mod;
    }
public:
    int numberOfWays(int startPos, int endPos, int k) {
        vector<vector<int>> dp(3000,vector<int>(k+1,-1));
        return solve(startPos,endPos,k,dp)%mod;
    }
};

int main() {
    Solution solution;
    int startPos = 0;
    int endPos = 5;
    int k = 3;
    
    int result = solution.numberOfWays(startPos, endPos, k);
    
    cout << "Number of ways to reach endPos from startPos in exactly k steps: " << result << endl;
    
    return 0;
}

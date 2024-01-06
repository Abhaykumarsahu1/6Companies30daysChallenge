#include <iostream>
#include <vector>
using namespace std;

class Solution {
    int mod = 1e9 + 7;
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<long long> dp(n+1,0);
        long long numOfPeopleSharingSecret = 0;
        dp[1] = 1;

        for(int i = 2; i <= n; i++){
            long long numOfNewPeopleSharingSecret = dp[max(0,i-delay)];
            long long numOfPeopleForgettingSecret = dp[max(0,i-forget)];

            numOfPeopleSharingSecret = (numOfPeopleSharingSecret + numOfNewPeopleSharingSecret - numOfPeopleForgettingSecret + mod) % mod;
            dp[i] = numOfPeopleSharingSecret % mod;
        }   

        long long ans = 0;   
        for(int i = n - forget + 1; i <= n; i++){
            ans = (ans + dp[i]) % mod;
        }
        return ans % mod;
    }
};

int main() {
    int n = 10; // Define the value of n
    int delay = 2; // Define the delay value
    int forget = 3; // Define the forget value
    
    Solution solution;
    int peopleCount = solution.peopleAwareOfSecret(n, delay, forget);
    
    cout << "Number of people aware of the secret within the range: " << peopleCount << endl;

    return 0;
}

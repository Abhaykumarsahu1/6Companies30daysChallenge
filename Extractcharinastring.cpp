#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;
class Solution {
public:
    int solve(string& s, unordered_map<string, int>&mp, vector<int>&dp, int index)
    {
        if (index >= s.size()) return 0;
        if (dp[index] != -1) return dp[index];
        
        string currStr = "";
        int minExtra = s.size();
        for (int cutIdx = index; cutIdx < s.size(); cutIdx++)
        {
            currStr.push_back(s[cutIdx]);
        
            int currExtra = (mp.count(currStr))? 0 : currStr.size();
            int nextExtra = solve(s, mp, dp, cutIdx + 1);
            int totalExtra = currExtra + nextExtra;
            
            minExtra = min(minExtra, totalExtra);
        }
        return dp[index] = minExtra;
    }
    int minExtraChar(string s, vector<string>& dictionary) 
    {
        vector<int>dp(s.size(), -1);
        unordered_map<string, int>mp;
        for (string& word : dictionary) mp[word]++;
        
        int ans = solve(s, mp, dp, 0);
        return ans;
        
    }
};
int main(){
     Solution sol;
    
    // Example usage
    string inputString = "leetcode";
    vector<string> dictionary = {"leet", "code"};
    
    int result = sol.minExtraChar(inputString, dictionary);
    
    cout << "Minimum extra characters needed: " << result << endl;

    return 0;
    return 0;
}
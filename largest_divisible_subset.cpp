#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n=arr.size();
        vector<int>dp(n,1),hash(n);
        int li=0;
        int maxi=1;
        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int prev=0;prev<i;prev++){
                if(arr[i]%arr[prev]==0 && 1+dp[prev]>dp[i]){
                    dp[i]=1+dp[prev];
                    hash[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                li=i;
            }
        }
        vector<int>res(maxi);
        int i=1;
        res[0]=arr[li];
        while(hash[li]!=li){
            li=hash[li];
            res[i]=arr[li];
            i++;
        }
        // return hash;
        reverse(res.begin(),res.end());
        return res;
    }
};
int main() {
    Solution solution;
    
    // Example usage
    vector<int> arr = {1, 2, 4, 8};
    vector<int> result = solution.largestDivisibleSubset(arr);

    cout << "Largest Divisible Subset: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>> > pq;

        for(int i = 0; i < nums.size(); i++){
            pq.push({nums[i],i});
            if(pq.size() > k){
                pq.pop();
            }
        }

        priority_queue<pair<int,int> , vector<pair<int,int>>,greater<pair<int,int>> > temp;

        while(!pq.empty()){
            temp.push({pq.top().second,pq.top().first});
            pq.pop();
        }

        vector<int> ans;
        while(!temp.empty()){
            ans.push_back(temp.top().second);
            temp.pop();
        }

        return ans;
    }
};
int main(){
     Solution solution;

    // Example usage
    vector<int> nums = {4, 3, 1, 5, 2};
    int k = 3;

    vector<int> result = solution.maxSubsequence(nums, k);

    // Display the result
    cout << "The maximum subsequence of size " << k << " is: [";
    for (int i = 0; i < k; ++i) {
        cout << result[i];
        if (i < k - 1) {
            std::cout << ", ";
        }
    }
    cout << "]" <<endl;

    return 0;
}
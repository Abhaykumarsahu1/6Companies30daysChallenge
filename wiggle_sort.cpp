#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
    public:
     void wiggleSort(vector<int>& nums) {
        // Sort the array in descending order
            sort(nums.begin(),nums.end(),greater<int>());
            // Initialize pointers for the even and odd indices
            int low=0;
            int high =nums.size()/2;
            vector<int> ans;

            while (low<nums.size()/2 && high <nums.size())
            {
                // Alternately add elements from high and low indices
               ans.push_back(nums[high++]);
               ans.push_back(nums[low++]);
            }
             // If the size of nums is odd, there might be one element left after the above process
            while (high<nums.size())
            {
                ans.push_back(nums[high++]);
            }

            // Assign the sorted wiggle array back to the original nums array
            nums = ans;
            
            
     }
};
int main(){
    vector<int> nums={1,5,1,1,6,4};
    Solution s;
    s.wiggleSort(nums);
    for(auto num : nums){
        cout<<num<<" ";
    }
    return 0;
}
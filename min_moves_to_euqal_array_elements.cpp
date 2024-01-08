#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int result = 0, length = nums.size();
        sort(nums.begin(), nums.end());

        int median = nums[length / 2]; // Calculate the median

        for (int i = 0; i < length; i++) {
            result += abs(nums[i] - median); // Calculate absolute difference with the true median
        }

        return result;
    }
};

int main(){
    vector<int> nums ={1,10,2,9};
    Solution s;
    cout<<s.minMoves2(nums);
    return 0;
}
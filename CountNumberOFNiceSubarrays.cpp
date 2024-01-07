#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution{
    public: 
         int numberOfSubarrays(vector<int>& nums, int k) {
            int count =0;
            int oddcount=0;
            unordered_map<int,int> frequency;
            frequency[0]=1; //intialize it if in case there is a element at first index is even
            for (auto num : nums)
            {
                if (num%2!=0)
                {
                    oddcount++;
                }

                if (frequency.find(oddcount-k)!=frequency.end())
                {
                    count+=frequency[oddcount-k];

                }

                frequency[oddcount]++;
                
                
            }
            return count;

         }
};
int main(){
    vector<int> nums ={1,1,2,1,1};
    Solution s;
    cout<<"total number of nice subarrays are : "<<s.numberOfSubarrays(nums,3);
    return 0;
}
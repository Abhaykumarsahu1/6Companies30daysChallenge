#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int incremovableSubarrayCount(vector<int>& arr) {
        int n=arr.size();
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                vector<int>temp;
                for(int k=0;k<i;k++)
                {
                    temp.push_back(arr[k]);
                }
                for(int k=j+1;k<n;k++)
                {
                    temp.push_back(arr[k]);
                }
                int f=0;
                for(int x=1;x<temp.size();x++)
                {
                   if(temp[x]<=temp[x-1])
                   {
                       f=1;
                       break;
                   }
                }
                if(f==0)
                {
                    cnt++;
                }
            }
        }
    return cnt;
    }
};
int main(){
    vector<int> nums = {1,2,3,4};
    Solution s;
    cout<<"the number of subarrays will be: "<<s.incremovableSubarrayCount(nums);
    return 0;
}
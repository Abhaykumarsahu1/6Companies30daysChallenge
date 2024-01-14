#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        vector<int> v(121, 0);
        for(auto it: ages)
            v[it]++;
        int ans=0;
        for(int i=1; i<121; i++)
        {
            if(v[i]==0) continue;
            int tmp =0;
            for(int j=1; j<121; j++)
            {
                if(v[j]==0) continue;
                if(i==j)
                {
                    if(j>(i*0.5+7))
                        tmp+=(v[i]-1);
                }
                else
                {
                    bool flag= true;
                    if(j<=(i*0.5+7)) flag= false;
                    if(j>i) flag= false;
                    if(i<100 && j>100) flag= false;
                    if(flag)
                        tmp+=v[j];
                }
            }
            ans= ans + v[i]*tmp;
        }
        return ans;
    }
};

int main() {
    Solution solution;

    // Example usage
    std::vector<int> ages = {16, 16, 16};
    int result = solution.numFriendRequests(ages);

    std::cout << "Number of friend requests: " << result << std::endl;

    return 0;
}


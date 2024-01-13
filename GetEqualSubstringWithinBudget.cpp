#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#pragma GCC optimize("Ofast","inline","fast-math","unroll-loops","no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native","f16c")

static int fast_io = []() 
{ 
    std::ios::sync_with_stdio(false); 
    cin.tie(nullptr); 
    cout.tie(nullptr); 
    return 0; 
}();

#ifdef LOCAL
    freopen("input.txt", "r" , stdin);
    freopen("output.txt", "w", stdout);
#endif

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) 
    {
        //we need to maximize the length of the string (substring)
        //in t that can be changed to the corresponding substring
        //as in s while keeping the constraint in mind;

        //as the length of the s and t are equal 

        int ans_len = 0;

        int cost = 0;

        int start = 0;
        int end   = 0;

        //traversing on the string t and checking if the particular substring can be made equal
        
        while(end < (s.length()))
        {
            int diff = abs(t[end] - s[end]);

            while((start <= end) and (cost + diff) > maxCost)
            {
                cost = cost - abs(t[start] - s[start]);
                start++;
            }

            cost = cost + diff;
            ans_len = max(ans_len,(end - start + 1));
            end++;
        }
        return ans_len;
    }
};

int main() {
    // Example usage:
    Solution solution;
    string s = "abcd";
    string t = "bcdf";
    int maxCost = 3;
    int result = solution.equalSubstring(s, t, maxCost);
    cout << "Maximum length of equal substring: " << result << endl;

    return 0;
}

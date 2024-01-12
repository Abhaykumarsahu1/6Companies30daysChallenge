#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    static bool cmp(pair<char,int> &a, pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
            unordered_map<char,int> m; //initializing unordered map so as to store the occurence of characters in it by traversing the string
            for(int i=0;i<s.length();i++){
                m[s[i]]++;
            }

            vector<pair<char,int>> cnt; //intializing pair cnt for storing pairs of characters and there occurences.
            for(auto &p:m){
                cnt.push_back(p); //copying m in cnt
            }

            sort(cnt.begin(),cnt.end(),cmp); //sorting pairs in descending order using cmp function
             for (auto k: cnt){
            cout<<k.first<<" "<<k.second<<endl;
        }
        int k=0;
        for (auto m: cnt){
            for (int j=1;j<=m.second;j++){
                s[k++]=m.first;
            }
        }
        return s;

    }
};
int main(){
    Solution sol;
    string result = sol.frequencySort("tree");
    cout << result << endl;
    
    return 0;
}
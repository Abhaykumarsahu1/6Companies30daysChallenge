#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    void find(vector<int>& price, vector<vector<int>>& special, vector<int> &needs, int idx , int &mn_price , int Price){
        mn_price = min(mn_price,Price);
        if(idx==special.size()) return;
        int n = needs.size();
        find(price,special,needs,idx+1,mn_price,Price);
        vector<int> needs2 = needs;
        // new price calculation
        for(int i = 0; i<n; i++){
            if(needs2[i]<special[idx][i]) return;
            Price = Price - special[idx][i]*price[i];
            // update our needs
            needs2[i] = needs2[i]-special[idx][i];
        }
        Price+= special[idx][n];
        find(price,special,needs2,idx,mn_price,Price);
    }
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        int mn_price = 0;
        int n = price.size();
        for(int i = 0; i<n; i++){
            mn_price+= price[i]*needs[i];
        }
        map<vector<int>,int> mp;
        for(auto &v : special){
            vector<int> temp(v.begin(),v.end()-1);
            if(mp.find(temp)==mp.end()) mp[temp] = v[v.size()-1];
            else{
                if(v[v.size()-1]<mp[temp]){
                    mp[temp] = v[v.size()-1];
                }
            }
        }
        special.clear();
        for(auto &p : mp){
            vector<int> temp = p.first;
            temp.push_back(p.second);
            special.push_back(temp);
        }
        find(price,special,needs,0,mn_price,mn_price);
        return mn_price;
    }
};
int main(){
     Solution solution;

    // Example usage:
    vector<int> price = {2, 5, 3};
    vector<vector<int>> special = {{1, 1, 1, 0, 4}, {2, 2, 1, 1, 9}};
    vector<int> needs = {1, 2, 1};

    int result = solution.shoppingOffers(price, special, needs);

    cout << "Minimum price: " << result <<endl;
    return 0;
}
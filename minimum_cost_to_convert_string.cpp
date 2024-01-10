#include <iostream>
#include <vector>
#include <climits>

using namespace std;

#pragma GCC optimize("O3", "unroll-loops")
// Use Floyd Warshall's algorithm
class Solution {
public:
    vector<char> original, changed;
    vector<int> cost;
    int D[26][26];
    void FW(){
        fill(&D[0][0], &D[0][0]+26*26, INT_MAX); // Use C++ fill
        int sz=original.size();
        for (int i=0; i<sz; i++){
            int row=original[i]-'a';
            int col=changed[i]-'a';
            D[row][col]=min(D[row][col], cost[i]);
        }
        for (int i=0; i<26; i++) D[i][i]=0;

        for(int k=0; k<26; k++)
            for(int i=0; i<26; i++)
                for(int j=0; j<26; j++)
                    D[i][j]=min((long long)D[i][j], (long long)D[i][k]+D[k][j]);

    }
    long long minimumCost(string& source, string& target, vector<char>& original, vector<char>& changed, vector<int>& cost) 
    {
        this->original=original;
        this->changed=changed;
        this->cost=cost;
        FW();
        int n=source.size();
        long long ans=0;
        for(int i=0; i<n; i++){
            int row=source[i]-'a';
            int col=target[i]-'a';
            if (D[row][col]==INT_MAX) return -1;
            ans+=D[row][col];
        }
        return ans;
    }
};

int main() {
    // Example usage
    Solution solution;
    string source = "abc";
    string target = "def";
    vector<char> original = {'a', 'b', 'c'};
    vector<char> changed = {'d', 'e', 'f'};
    vector<int> cost = {1, 2, 3};

    long long result = solution.minimumCost(source, target, original, changed, cost);
    
    if(result == -1) {
        cout << "Transformation not possible" << endl;
    } else {
        cout << "Minimum cost of transformation: " << result << endl;
    }

    return 0;
}

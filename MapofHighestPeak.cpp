#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, -1, 0, 1};

    bool isSafe(vector<vector<int>>& isWater, int r, int c, vector<vector<int>>& heights){
        if (r < 0 || c < 0 || r == isWater.size() || c == isWater[0].size() || isWater[r][c] == 1 || heights[r][c] > 0){
            return false;
        }
        return true;
    }

    void bfs(vector<vector<int>>& isWater, vector<vector<int>>& heights, queue<pair<int, int>>& q){
        while (q.size() != 0){
            int size = q.size();
            while (size--){
                int i = q.front().first;
                int j = q.front().second;
                q.pop();

                int height = heights[i][j];

                for (int b = 0; b < 4; b++){
                    int nI = i + dx[b];
                    int nJ = j + dy[b];

                    if (isSafe(isWater, nI, nJ, heights)){
                        heights[nI][nJ] = height + 1;
                        q.push({nI, nJ});
                    }
                }
            }
        }
    }
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int m = isWater.size();
        int n = isWater[0].size();

        vector<vector<int>> heights(m, vector<int>(n, 0));
        queue<pair<int, int>> q;

        for (int i = 0; i < m; i++){
            for (int j = 0; j < n; j++){
                if (isWater[i][j] == 1){
                    q.push({i, j});
                }
            }
        }

        bfs(isWater, heights, q);

        return heights;
    }
};

int main() {
    vector<vector<int>> isWater = {
        {0, 1, 0},
        {0, 0, 1},
        {1, 0, 0}
    };

    Solution obj;
    vector<vector<int>> result = obj.highestPeak(isWater);

    cout << "Highest Peak Grid: " << endl;
    for (const auto& row : result) {
        for (int height : row) {
            cout << height << " ";
        }
        cout << endl;
    }

    return 0;
}

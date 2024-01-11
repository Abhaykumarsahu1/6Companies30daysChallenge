#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int dist[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dist[i][j] = i == j ? 0 : 10001;
            }
        }
        for (auto &e : edges) {
            dist[e[0]][e[1]] = dist[e[1]][e[0]] = e[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
        int res = -1, resCount = INT_MAX;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (dist[i][j] <= distanceThreshold) {
                    count++;
                }
            }
            if (count <= resCount) {
                resCount = count;
                res = i;
            }
        }
        return res;
    }
};
int main() {
    Solution solution;
    int n = 5;
    vector<vector<int>> edges = {{0, 2, 4}, {0, 4, 2}, {1, 3, 1}, {2, 3, 3}, {2, 4, 3}, {3, 4, 1}};
    int distanceThreshold = 7;

    int result = solution.findTheCity(n, edges, distanceThreshold);

    cout << "The city with the minimum number of reachable cities: " << result <<endl;

    return 0;
}
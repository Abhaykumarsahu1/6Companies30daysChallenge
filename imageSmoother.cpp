#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        cout.tie(0);
        // code
        int m = img.size(), n = img[0].size();
        vector<vector<int>> result(m, vector<int>(n));
        
        for (int r = 0; r < m; r++) 
        {
            for (int c = 0; c < n; c++) 
            {
                int sum = 0, count = 0;

                // Iterate over the 3x3 neighborhood
                for (int dr = -1; dr <= 1; dr++) 
                {
                    for (int dc = -1; dc <= 1; dc++) 
                    {
                        int nr = r + dr;
                        int nc = c + dc;

                        // Check if the neighbor is within bounds
                        if ((nr >= 0) && (nr < m) && (nc >= 0) && (nc < n)) 
                        {
                            sum += img[nr][nc];
                            count++;
                        }
                    }
                }

                // Calculate the average and update the result matrix
                result[r][c] = (sum / count);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // Example input image matrix
    vector<vector<int>> image = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    // Applying image smoothing
    vector<vector<int>> smoothedImage = solution.imageSmoother(image);

    // Displaying the smoothed image matrix
    for (const auto& row : smoothedImage) {
        for (int pixel : row) {
            cout << pixel << " ";
        }
        cout << endl;
    }

    return 0;
}

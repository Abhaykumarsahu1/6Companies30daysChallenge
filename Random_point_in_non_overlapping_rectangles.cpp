#include <iostream>
#include<vector>
#include <cstdlib> // for rand()
#include <ctime> // for seeding rand()
using namespace std;
class Solution {
public:
    vector<vector<int>> rects;
    
    Solution(vector<vector<int>> rects) : rects(rects) {
    }
    
    vector<int> pick() {
        int sum_area = 0;
        vector<int> selected;
        
        /* Step 1 - select a random rectangle considering the area of it. */
        for (auto r : rects) {
            /*
             * What we need to be aware of here is that the input may contain
             * lines that are not rectangles. For example, [1, 2, 1, 5], [3, 2, 3, -2].
             * 
             * So, we work around it by adding +1 here. It does not affect
             * the final result of reservoir sampling.
             */
            int area = (r[2] - r[0] + 1) * (r[3] - r[1] + 1);
            sum_area += area;
            
            if (rand() % sum_area < area)
                selected = r;
        }
        
        /* Step 2 - select a random (x, y) coordinate within the selected rectangle. */
        int x = rand() % (selected[2] - selected[0] + 1) + selected[0];
        int y = rand() % (selected[3] - selected[1] + 1) + selected[1];
        
        return { x, y };
    }
};
int main(){
     vector<vector<int>> rectangles = {{1, 2, 5, 5}, {3, 3, 8, 10}, {11, 11, 15, 20}};
    
    Solution solution(rectangles);
    
    // Seed the random number generator with current time
    srand(time(0));
    
    // Generate 5 random points
    for (int i = 0; i < 5; ++i) {
        vector<int> point = solution.pick();
        cout << "Random Point " << i+1 << ": (" << point[0] << ", " << point[1] << ")" << endl;
    }
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
int n,m;
int i=0,j=0; //start with first row and first column
    Solution(int m, int n) {
        this->n=n;
        this->m=m;
    }
    
    vector<int> flip() {
        int I=i, J=j;
         if(j + 1 < n) j++; // will iterate over columns 
        else if(i + 1 < m){ // will switch to next row and first col
            i++;
            j = 0;
        }
        else i = 0,j = 0; // will point back to first row and col
        // work as reset and continue to cycle again
        return {I,J};
    }
    
    void reset() {
        
    }
};
int main() {
    int rows = 3;
    int cols = 4;

    Solution obj(rows, cols);

    // Flip through the grid
    for (int i = 0; i < rows * cols; ++i) {
        vector<int> indices = obj.flip();
        cout << "Flipped position: (" << indices[0] << ", " << indices[1] << ")" << endl;
    }

    return 0;
}

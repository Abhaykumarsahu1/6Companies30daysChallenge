#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int amountOfTime(TreeNode* root, int start) {
        std::unordered_map<int, std::unordered_set<int>> map;
        convert(root, 0, map);
        std::queue<int> q;
        q.push(start);
        int minute = 0;
        std::unordered_set<int> visited;
        visited.insert(start);

        while (!q.empty()) {
            int levelSize = q.size();
            while (levelSize > 0) {
                int current = q.front();
                q.pop();

                for (int num : map[current]) {
                    if (visited.find(num) == visited.end()) {
                        visited.insert(num);
                        q.push(num);
                    }
                }
                levelSize--;
            }
            minute++;
        }
        return minute - 1;
    }

    void convert(TreeNode* current, int parent, std::unordered_map<int, std::unordered_set<int>>& map) {
        if (current == nullptr) {
            return;
        } 
        if (map.find(current->val) == map.end()) {
            map[current->val] = std::unordered_set<int>();
        }
        std::unordered_set<int>& adjacentList = map[current->val];
        if (parent != 0) {
            adjacentList.insert(parent);
        } 
        if (current->left != nullptr) {
            adjacentList.insert(current->left->val);
        } 
        if (current->right != nullptr) {
            adjacentList.insert(current->right->val);
        }
        convert(current->left, current->val, map);
        convert(current->right, current->val, map);
    }
};

int main() {
 

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(5);

    Solution solution;

    // Call the amountOfTime function with root and starting node 1
    int minutesPassed = solution.amountOfTime(root, 1);

    std::cout << "Time taken to visit all nodes: " << minutesPassed << " minutes\n";

    // Don't forget to free the allocated memory
    delete root->left;
    delete root->right->left;
    delete root->right->right;
    delete root;

    return 0;
}

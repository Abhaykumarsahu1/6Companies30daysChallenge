#include <iostream>
#include <climits>

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    struct Result {
        int sum;
        int min_val;
        int max_val;
        bool isBST;
    };

    Result maxSumBSTUtil(TreeNode* root, int& maxSum) {
        if (!root) {
            return {0, INT_MAX, INT_MIN, true};
        }

        Result left = maxSumBSTUtil(root->left, maxSum);
        Result right = maxSumBSTUtil(root->right, maxSum);

        if (left.isBST && right.isBST && root->val > left.max_val && root->val < right.min_val) {
            int totalSum = root->val + left.sum + right.sum;
            maxSum = std::max(maxSum, totalSum);
            return {totalSum, std::min(root->val, left.min_val), std::max(root->val, right.max_val), true};
        }

        return {0, INT_MIN, INT_MAX, false};
    }

public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        maxSumBSTUtil(root, maxSum);
        return maxSum;
    }
};

int main() {
    // Example tree creation
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);

    Solution solution;
    int maxSum = solution.maxSumBST(root);
    
    std::cout << "Maximum sum of a BST contained within the given binary tree: " << maxSum << std::endl;

    return 0;
}

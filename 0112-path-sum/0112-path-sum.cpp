/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    bool dfs(TreeNode* node, int total, int targetSum){
        if (!node) return false;
        
        if (!node -> left && !node -> right) return total + node -> val == targetSum;
        bool left = dfs(node -> left, total + node -> val, targetSum);
        bool right = dfs(node -> right, total + node -> val, targetSum);
        return left || right;
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, 0, targetSum);
    }
};
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
    int dfs(TreeNode* root, int total){
        if (!root) return 0;
        
        total = total * 10 + root -> val;
        
        if (!root -> left && !root -> right) return total;
        
        return dfs(root -> left, total) + dfs(root -> right, total);
    }
    
public:
    int sumNumbers(TreeNode* root) {
        return dfs(root, 0);
    }
};
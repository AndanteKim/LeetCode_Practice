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
    bool dfs(TreeNode* node, long long small, long long large){
        if (!node) return true;
        if (!(small < node -> val && node -> val < large)) return false;
        
        bool left = dfs(node -> left, small, node -> val);
        bool right = dfs(node -> right, node -> val, large);
        return left && right;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        return dfs(root, LONG_LONG_MIN, LONG_LONG_MAX);
    }
};
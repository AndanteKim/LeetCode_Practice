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
    int countNodes(TreeNode* root){
        if (!root) return 0;
        
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
    
    bool dfs(TreeNode* root, int index, int n){
        if (!root) return true;
        if (index >= n) return false;
        
        return dfs(root -> left, 2 * index + 1, n) && dfs(root -> right, 2 * index + 2, n);
    }
    
public:
    bool isCompleteTree(TreeNode* root) {
        return dfs(root, 0, countNodes(root));
    }
};
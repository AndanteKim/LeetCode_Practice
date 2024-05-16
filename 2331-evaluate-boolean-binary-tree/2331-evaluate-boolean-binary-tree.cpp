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
private:
    bool dfs(TreeNode* curr){
        // If it's leaf node
        if (!(curr -> left && curr -> right)) return (curr -> val)? true : false;
        
        return (curr -> val == 2)? dfs(curr -> left) | dfs(curr -> right) : dfs(curr -> left) & dfs(curr -> right);
    }
    
public:
    bool evaluateTree(TreeNode* root) {
        return dfs(root);
    }
};
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
    int count = 0;
    long dfs(TreeNode* curr){
        if (!curr) return 0;
        
        long left = dfs(curr -> left), right = dfs(curr -> right);
        
        if (curr -> val == left + right) ++count;
        
        return left + right + curr -> val;
    }
    
public:
    int equalToDescendants(TreeNode* root) {
        dfs(root);
        
        return count;
    }
};
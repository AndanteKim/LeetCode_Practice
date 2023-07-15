/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    bool dfs(TreeNode* node, TreeNode* target){
        if (node == target) return true;
        if (!node) return false;
        return dfs(node -> left, target) || dfs(node -> right, target);
    }
    
    TreeNode* LCA(TreeNode* node, TreeNode* p, TreeNode* q){
        if (!node || node == p || node == q) return node;
        TreeNode* left = LCA(node -> left, p, q);
        TreeNode* right = LCA(node -> right, p, q);
        if (left && right) return node;
        else if (left) return left;
        return right;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = LCA(root, p, q);
        
        if (ans == p) return dfs(p, q)? p : nullptr;
        else if (ans == q) return dfs(q, p)? q: nullptr;
        return ans;
    }
};
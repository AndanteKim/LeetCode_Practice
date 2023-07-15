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
    bool nodesFound = false;
    TreeNode* dfs(TreeNode* node, TreeNode* p, TreeNode* q){
        if (!node) return node;
        TreeNode* left = dfs(node -> left, p, q), * right = dfs(node -> right, p, q);
        int conditions = 0;
        if (node == p || node == q) ++conditions;
        if (left) ++conditions;
        if (right) ++conditions;
        if (conditions == 2) nodesFound = true;
        if ((left && right) || node == p || node == q) return node;
        return left? left : right;
    }
    
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = dfs(root, p, q);
        return nodesFound? ans : nullptr; 
    }
};
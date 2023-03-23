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
    int ans = 0, depth = 0;
    void dfs(TreeNode* node, int level){
        if (!node) return;
        if (level == depth) ans += node -> val;
        else if (level > depth) {
            ans = node -> val;
            depth = level;
        }
        
        dfs(node -> left, level + 1);
        dfs(node -> right, level + 1);
    }
    
public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};
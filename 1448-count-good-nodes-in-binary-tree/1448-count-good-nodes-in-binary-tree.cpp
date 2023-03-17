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
    int dfs(TreeNode* node, int max_so_far){
        if (!node) return 0;
        
        int left = dfs(node -> left, max(max_so_far, node -> val));
        int right = dfs(node -> right, max(max_so_far, node -> val));
        int ans = left + right;
        
        if (node -> val >= max_so_far) ++ans;
        
        return ans;
    }
    
public:
    int goodNodes(TreeNode* root) {
        return dfs(root, INT_MIN);
    }
};
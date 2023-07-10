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
    int dfs(TreeNode* node, int height){
        if (!node -> left && !node -> right) return height;
        int ans = INT_MAX;
        
        if (node -> left) ans = min(ans, dfs(node -> left, height + 1));
        if (node -> right) ans = min(ans, dfs(node -> right, height + 1));
        return ans;
    }
    
public:
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        return dfs(root, 1);
    }
};
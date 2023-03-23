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
    void dfs(TreeNode* node, int level, vector<int>& ans){
        if (!node) return;
        if (level == ans.size()) ans.push_back(node -> val);
        ans[level] = max(ans[level], node -> val);
        
        if (node -> left) dfs(node -> left, level + 1, ans);
        if (node -> right) dfs(node -> right, level + 1, ans);
    }
    
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> ans;
        dfs(root, 0, ans);
        
        return ans;
    }
};
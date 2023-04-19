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
    vector<vector<int>> ans;
    
    void dfs(TreeNode* node, int level){
        if (ans.size() == level) ans.push_back({});
        
        ans[level].push_back(node -> val);
        if (node -> left) dfs(node -> left, level + 1);
        if (node -> right) dfs(node -> right, level + 1);
    }
    
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return ans;
        dfs(root, 0);
        return ans;
    }
};
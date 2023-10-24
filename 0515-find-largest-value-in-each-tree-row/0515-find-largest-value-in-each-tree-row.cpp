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
    void dfs(vector<int>& ans, TreeNode* node, int level){
        if (!node) return;
        
        if (ans.size() == level)
            ans.push_back(node -> val);
        else
            ans[level] = max(ans[level], node -> val);
        
        dfs(ans, node -> left, level + 1);
        dfs(ans, node -> right, level + 1);
    }
    
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return vector<int>{};
        vector<int> ans;
        dfs(ans, root, 0);
        return ans;
    }
};
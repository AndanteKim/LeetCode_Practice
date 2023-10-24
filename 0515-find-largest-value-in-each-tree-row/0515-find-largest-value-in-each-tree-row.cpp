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
public:
    vector<int> largestValues(TreeNode* root) {
        if (!root) return {};
        
        vector<int> ans;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        
        while (!q.empty()){
            auto [node, level] = q.front();
            q.pop();
            
            if (ans.size() == level)
                ans.push_back(INT_MIN);
            
            ans[level] = max(ans[level], node -> val);
            
            if (node -> left)
                q.push({node -> left, level + 1});
            
            if (node -> right)
                q.push({node -> right, level + 1});
        }
        
        return ans;
    }
};
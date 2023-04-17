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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (!root) return {};
        
        stack<pair<TreeNode*, pair<vector<int>, int>>> stack;
        stack.push({root, {{root -> val}, root -> val}});
        vector<vector<int>> ans;
        
        while (!stack.empty()){
            auto [node, values] = stack.top();
            
            auto[paths, total] = values;
            stack.pop();
            
            if ((!node -> left && !node -> right) && total == targetSum) ans.push_back(paths);
            
            if (node -> left){
                paths.push_back(node -> left -> val);
                stack.push({node -> left, {paths, total + node -> left -> val}});
                paths.pop_back();
            }
            
            if (node -> right){
                paths.push_back(node -> right -> val);
                stack.push({node -> right, {paths, total + node -> right -> val}});
            }
            
        }
        
        return ans;
    }
};
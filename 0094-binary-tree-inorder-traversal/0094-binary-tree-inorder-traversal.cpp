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
    vector<int> dfs(TreeNode* node){
        if (!node)
            return {};
        vector<int> ans{dfs(node -> left)};
        ans.push_back(node -> val);
        vector<int> right{dfs(node -> right)};
        ans.insert(ans.end(), right.begin(), right.end());
        
        return ans;
    }
    
public:
    vector<int> inorderTraversal(TreeNode* root) {
        return dfs(root);
    }
};
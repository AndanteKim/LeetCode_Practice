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
    void dfs(TreeNode* curr, bool isLonely, vector<int>& ans){
        if (!curr) return;
        
        if (isLonely) ans.push_back(curr -> val);
        
        dfs(curr -> left, curr -> right == nullptr, ans);
        dfs(curr -> right, curr -> left == nullptr, ans);
    }
    
    
public:
    vector<int> getLonelyNodes(TreeNode* root) {
        vector<int> ans;
        dfs(root, false, ans);
        
        return ans;
    }
};
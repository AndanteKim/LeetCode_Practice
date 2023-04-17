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
    void path(TreeNode* root, int target, vector<int> &&pth, vector<vector<int>>& ans){
        if (!root) return;
        
        if (root -> val == target && !root -> left && !root -> right){
            pth.push_back(root -> val);
            ans.push_back(pth);
            pth.pop_back();
            return;
        }
        pth.push_back(root -> val);
        path(root -> left, target - root -> val, move(pth), ans);
        path(root -> right, target - root -> val, move(pth), ans);
        pth.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        path(root, targetSum, {}, ans);
        return ans;
    }
};
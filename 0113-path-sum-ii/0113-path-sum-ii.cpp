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
    void recurseTree(TreeNode* node, int remainingSum, vector<int> pathNodes, \
                    vector<vector<int>>& ans){
        if (!node) return;
        
        pathNodes.push_back(node -> val);
        
        if (remainingSum == node -> val && !node -> left && !node -> right)
            ans.push_back(pathNodes);
        else{
            recurseTree(node -> left, remainingSum - node -> val, pathNodes, ans);
            recurseTree(node -> right, remainingSum - node -> val, pathNodes, ans);
        }
        
        pathNodes.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        recurseTree(root, targetSum, {}, ans);
        return ans;
    }
};
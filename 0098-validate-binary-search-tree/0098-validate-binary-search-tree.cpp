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
    void dfs(TreeNode* node, vector<int>& values){
        if (!node) return;
        dfs(node -> left, values);
        values.push_back(node -> val);
        dfs(node -> right, values);
    }
    
public:
    bool isValidBST(TreeNode* root) {
        vector<int> InorderTraversal;
        dfs(root, InorderTraversal);
        for (int i = 1; i < InorderTraversal.size(); ++i){
            if ((long long)InorderTraversal[i] - (long long)InorderTraversal[i - 1] <= 0) return false;
        }
        return true;
    }
};
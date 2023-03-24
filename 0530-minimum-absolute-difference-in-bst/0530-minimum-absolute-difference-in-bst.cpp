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
    void dfs(TreeNode* node, vector<int>& flatten){
        if (!node) return;
        dfs(node -> left, flatten);
        flatten.push_back(node -> val);
        dfs(node -> right, flatten);
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        vector<int> flatten;
        dfs(root, flatten);
        
        int ans = INT_MAX;
        for (int i = 0; i < flatten.size() - 1; ++i){
            ans = min(ans, flatten[i + 1] - flatten[i]);
        }
        
        return ans;
    }
};
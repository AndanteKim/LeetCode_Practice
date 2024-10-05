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
    TreeNode* clone(TreeNode* node, int offset){
        // Base case
        if (!node) return nullptr; 
        
        TreeNode* clonedNode = new TreeNode(node -> val + offset);
        clonedNode -> left = clone(node -> left, offset);
        clonedNode -> right = clone(node -> right, offset);
        
        return clonedNode;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector dp(n + 1, vector<TreeNode*>{});
        dp[0].push_back(nullptr);
        
        for (int numberOfNodes = 1; numberOfNodes <= n; ++numberOfNodes){
            for (int i = 1; i <= numberOfNodes; ++i){
                int j = numberOfNodes - i;
                
                for (TreeNode* left : dp[i - 1]){
                    for (TreeNode* right : dp[j]){
                        TreeNode* root = new TreeNode(i, left, clone(right, i));
                        dp[numberOfNodes].push_back(root);
                    }
                }
            }
        }
        
        return dp[n];
    }
};
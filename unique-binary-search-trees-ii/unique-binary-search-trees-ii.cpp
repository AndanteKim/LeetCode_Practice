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
    vector<TreeNode*> generateTrees(int n) {
        vector dp(n + 1, vector<vector<TreeNode*>>(n + 1, vector<TreeNode*>{}));
        
        for (int i = 1; i <= n; ++i) dp[i][i] = {new TreeNode(i)};
        
        for (int numberOfNodes = 2; numberOfNodes <= n; ++numberOfNodes){
            for (int start = 1; start < n - numberOfNodes + 2; ++start){
                int end = start + numberOfNodes - 1;
                
                for (int i = start; i <= end; ++i){
                    vector<TreeNode*> leftSubtrees = (i != start)? dp[start][i - 1] : vector<TreeNode*>{nullptr};
                    vector<TreeNode*> rightSubtrees = (i != end)? dp[i + 1][end] : vector<TreeNode*>{nullptr};
                    
                    for (TreeNode* left : leftSubtrees){
                        for (TreeNode* right : rightSubtrees){
                            TreeNode* root = new TreeNode(i, left, right);
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }
        
        return dp[1][n];
    }
};
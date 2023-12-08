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
    void dfs(TreeNode* node, unordered_map<TreeNode*, double>& descendantSum, unordered_map<TreeNode*, double>& descendantLength){
        if (!node)
            return;
        
        dfs(node -> left, descendantSum, descendantLength);
        dfs(node -> right, descendantSum, descendantLength);
        descendantSum[node] = descendantSum[node -> left] + descendantSum[node -> right] + node -> val;
        descendantLength[node] = descendantLength[node -> left] + descendantLength[node -> right] + 1;
    }
    
public:
    double maximumAverageSubtree(TreeNode* root) {
        unordered_map<TreeNode*, double> descendantSum, descendantLength;
        dfs(root, descendantSum, descendantLength);
        double ans = 0.0;
        
        for (auto& [key, _] : descendantSum)
            ans = max(ans, descendantSum[key] / descendantLength[key]);
            
        return ans;
    }
};
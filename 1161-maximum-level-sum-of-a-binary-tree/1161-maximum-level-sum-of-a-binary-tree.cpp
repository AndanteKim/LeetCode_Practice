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
    void dfs(TreeNode* node, int level, vector<int>& sumLevel){
        if (!node)
            return;
        
        if (sumLevel.size() == level)
            sumLevel.push_back(node -> val);
        else
            sumLevel[level] += node -> val;
        
        dfs(node -> left, level + 1, sumLevel);
        dfs(node -> right, level + 1, sumLevel);
    }
    
public:
    int maxLevelSum(TreeNode* root) {
        vector<int> sumLevel;
        dfs(root, 0, sumLevel);
        int ans = 1, idx = 0, maxSum = INT_MIN;
        
        for (int i = 0; i < sumLevel.size(); ++i){
            if (maxSum < sumLevel[i]){
                idx = i;
                maxSum = sumLevel[i];
            }
        }
        
        return ans + idx;
    }
};
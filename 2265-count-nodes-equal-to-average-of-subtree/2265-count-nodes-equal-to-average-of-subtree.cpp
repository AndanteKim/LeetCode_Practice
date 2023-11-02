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
    int count = 0;
    pair<int, int> dfs(TreeNode* node){
        if (!node) return {0, 0};
        
        pair<int, int> left = dfs(node -> left);
        pair<int, int> right = dfs(node -> right);
        
        int nodeSum = left.first + right.first + node -> val, nodeCount = left.second + right.second + 1;
        if (nodeSum / nodeCount == node -> val)
            ++count;
        return {nodeSum, nodeCount};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return count;
    }
};
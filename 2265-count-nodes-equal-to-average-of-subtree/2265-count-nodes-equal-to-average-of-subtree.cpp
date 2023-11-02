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
    tuple<int, int, int> dfs(TreeNode* node){
        if (!node)
            return {0, 0, 0};
        if (!node -> left && !node -> right)
            return {node -> val, 1, 1};
        
        auto [leftSum, leftCount, leftCorrect] = dfs(node -> left);
        auto [rightSum, rightCount, rightCorrect] = dfs(node -> right);
        if ((leftSum + rightSum + node -> val) / (leftCount + rightCount + 1) == node -> val)
            return {leftSum + rightSum + node -> val, leftCount + rightCount + 1, leftCorrect + rightCorrect + 1};
        return {leftSum + rightSum + node -> val, leftCount + rightCount + 1, leftCorrect + rightCorrect};
    }
    
public:
    int averageOfSubtree(TreeNode* root) {
        auto [total, count, ans] = dfs(root);
        return ans;
    }
};
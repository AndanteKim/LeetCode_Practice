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
    pair<bool, int> dfs(TreeNode* node){
        if (!node) return {true, 0};
        
        pair<bool, int> left = dfs(node -> left);
        pair<bool, int> right = dfs(node -> right);
        
        bool isLeftUniValue = left.first;
        bool isRightUniValue = right.first;
        int count = left.second + right.second;
        if (isLeftUniValue && isRightUniValue){
            if (node -> left && node -> left -> val != node -> val) return {false, count};
            if (node -> right && node -> right -> val != node -> val) return {false, count};
            return {true, count + 1};
        }
        return {false, count};
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        return dfs(root).second;
    }
};
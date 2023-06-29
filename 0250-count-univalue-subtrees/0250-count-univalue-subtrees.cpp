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
    bool dfs(TreeNode* node){
        if (!node) return true;
        
        bool isLeftUniValue = dfs(node -> left);
        bool isRightUniValue = dfs(node -> right);
        
        if (isLeftUniValue && isRightUniValue){
            if (node -> left && node -> val != node -> left -> val) return false;
            if (node -> right && node -> val != node -> right -> val) return false;
            ++count;
            return true;
        }
        
        return false;
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        dfs(root);
        return count;
    }
};
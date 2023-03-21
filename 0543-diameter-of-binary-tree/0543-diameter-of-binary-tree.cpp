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
    int diameter = 0;
    int longest_path(TreeNode* node){
        if (!node) return 0;
        int left_path = longest_path(node -> left);
        int right_path = longest_path(node -> right);
        
        diameter = max(diameter, left_path + right_path);
        
        return max(left_path, right_path) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        longest_path(root);
        return diameter;
    }
};
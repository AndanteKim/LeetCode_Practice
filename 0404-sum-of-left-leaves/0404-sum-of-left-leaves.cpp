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
    int process_subtree(TreeNode* sub_tree, bool is_left){
        if (!(sub_tree -> left || sub_tree -> right)) return is_left == true? sub_tree->val: 0;
        int total = 0;
        if (sub_tree-> left != NULL) total += process_subtree(sub_tree -> left, true);
        if (sub_tree-> right != NULL) total += process_subtree(sub_tree -> right, false);
        
        return total;
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        return process_subtree(root, false);
        
    }
};
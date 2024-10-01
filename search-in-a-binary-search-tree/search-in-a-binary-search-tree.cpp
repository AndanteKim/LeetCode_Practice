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
    TreeNode* searchBST(TreeNode* root, int val) {
        // Base case
        if (!root || root -> val == val)
            return root;
        
        // Find the target and its subtree from the BST
        TreeNode* target;
        if (root -> val < val)
            target = searchBST(root -> right, val);
        else if (root -> val > val)
            target = searchBST(root -> left, val);

        return target;
    }
};
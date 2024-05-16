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
    bool evaluateTree(TreeNode* root) {
        // Handle the case for leaf nodes.
        if (!(root -> left || root -> right)) return root -> val != 0;
        
        // Store evaluations for the left and right subtree.
        bool evaluateRoot;
        bool evaluateLeftSubtree = evaluateTree(root -> left), evaluateRightSubtree = evaluateTree(root -> right);
        if (root -> val == 2)
            evaluateRoot = evaluateLeftSubtree | evaluateRightSubtree;
        else
            evaluateRoot = evaluateLeftSubtree & evaluateRightSubtree;
        return evaluateRoot;
    }
};
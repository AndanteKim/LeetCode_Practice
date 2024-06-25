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
    void helper(TreeNode* node, int& nodeSum){
        // If the node is null, make no changes 
        if (!node) return;
        
        helper(node -> right, nodeSum);
        nodeSum += node -> val;
        // Update the value of root.
        node -> val = nodeSum;
        helper(node -> left, nodeSum);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        // Initialize a local variable nodeSum.
        int nodeSum = 0;
        helper(root, nodeSum);
        return root;
    }
};
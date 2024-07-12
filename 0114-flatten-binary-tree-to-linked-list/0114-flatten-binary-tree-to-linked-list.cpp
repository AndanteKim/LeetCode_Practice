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
    TreeNode* flattenTree(TreeNode* node){
        // Handle the null scenario
        if (!node) return nullptr;
        
        // For a leaf node, we simply return the node as is.
        if (!(node -> left || node -> right))
            return node;
        
        // Recursively flatten the left subtree
        TreeNode* leftTail = flattenTree(node -> left);
        
        // Recursively flatten the right subtree
        TreeNode* rightTail = flattenTree(node -> right);
        
        // If there was a left subtree, we shuffle the connections
        // around, so that there is nothing on the left side
        // anymore.
        if (leftTail){
            leftTail -> right = node -> right;
            node -> right = node -> left;
            node -> left = nullptr;
        }
        
        // We need to return the "rightmost" node after we are
        // done wiring the new connections.
        return (rightTail)? rightTail : leftTail;
    }
    
    
public:
    void flatten(TreeNode* root) {
        this -> flattenTree(root);
    }
};
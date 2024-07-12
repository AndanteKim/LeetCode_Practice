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
    void flatten(TreeNode* root) {
        // base case: if the root is nullptr
        if (!root) return;
        
        TreeNode* node = root;
        
        // Morris traversal
        while (node){
            
            if (node -> left){
                // Find the rightmost node
                TreeNode* rightmost = node -> left;
                while (rightmost -> right) rightmost = rightmost -> right;
                
                // Rewire the connections
                rightmost -> right = node -> right;
                node -> right = node -> left;
                node -> left = nullptr;
            }
            
            // Move on to the right side of the tree
            node = node -> right;
        }
    }
};
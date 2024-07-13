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
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        
        int ans = 0;
        
        // Morris traversal for optimized space
        while (root){
            if (root -> left){
                TreeNode* predecessor = root -> left;
                
                while (predecessor -> right && predecessor -> right != root)
                    predecessor = predecessor -> right;
                
                // Link the root to the predecessor's next
                if (!predecessor -> right){
                    predecessor -> right = root;
                    root = root -> left;
                    ++ans;
                }
                else{
                    // Unlink the root to the predecessor's next
                    predecessor -> right = nullptr;
                    root = root -> right;
                }
            }
            else{
                root = root -> right;
                ++ans;
            }
        }
        
        return ans;
    }
};
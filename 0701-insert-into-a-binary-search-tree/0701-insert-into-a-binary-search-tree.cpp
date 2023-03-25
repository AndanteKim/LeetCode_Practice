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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* node = root;
        
        while(node){
            if (val > node -> val){
                if (!node -> right) {
                    node -> right = new TreeNode(val);
                    return root;
                }
                else node = node -> right;
            }
            else{
                if (!node -> left){
                    node -> left = new TreeNode(val);
                    return root;
                }
                else node = node -> left;
            }
        }
        
        return new TreeNode(val);
    }
};
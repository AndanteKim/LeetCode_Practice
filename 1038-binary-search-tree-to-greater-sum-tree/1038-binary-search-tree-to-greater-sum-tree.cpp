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
    TreeNode* getSuccessor(TreeNode* node){
        TreeNode* succ = node -> right;
        
        // Get the node with the smallest value greater than this one.
        while (succ -> left && succ -> left != node)
            succ = succ -> left;
        
        return succ;
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        int total = 0;
        TreeNode* node = root;
        
        while (node){
            // If there is no right subtree, then we visit this node and
            // continue traversing left
            if (!node -> right){
                total += node -> val;
                node -> val = total;
                node = node -> left;
            }
            else{
                TreeNode* succ = getSuccessor(node);
                // If there is no left subtree (or right subtree, because we're in
                // this branch of control flow), make a temporary connection.
                if (!succ -> left){
                    succ -> left = node;
                    node = node -> right;
                }
                // If there is a left subtree, it's a link that we created on a
                // previous pass, so we should unlink it and visit this node.
                else{
                    succ -> left = nullptr;
                    total += node -> val;
                    node -> val = total;
                    node = node -> left;
                }
            }
        }
        
        return root;
    }
};
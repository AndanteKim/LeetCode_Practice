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
    // Store the inorder traversal in an array
    vector<int> inorderTraversal;
    void inorder(TreeNode* root){
        if (!root) return;
        
        inorder(root -> left);
        inorderTraversal.push_back(root -> val);
        inorder(root -> right);
    }
    
    // Function to modify the values in the tree.
    void replaceValues(TreeNode* root){
        if (!root) return;
        
        replaceValues(root -> left);
        replaceValues(root -> right);
        
        // Replace the node with values greater than the current value
        int nodeSum = 0;
        for (int i : inorderTraversal){
            if (i > root -> val)
                nodeSum += i;
            else
                break;
        }
        
        root -> val += nodeSum;
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        inorder(root);
        // Reverse the array to get descending order
        reverse(inorderTraversal.begin(), inorderTraversal.end());
        // Modify the values in the tree
        replaceValues(root);
        
        return root;
    }
};
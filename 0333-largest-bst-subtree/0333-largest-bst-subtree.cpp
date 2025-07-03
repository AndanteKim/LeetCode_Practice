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
    TreeNode* prev;
    bool isValidBST(TreeNode* node){
        /*
        Check if given tree is a valid BST using in-order traversal.
        
        An empty tree is a valid Binary Search Tree.
        */
        if (!node) return true;

        // If left subtree isn't a valid BST return false.
        if (!isValidBST(node -> left)) return false;

        // If current node's value isn't greater than the previous node's value
        // in the in-order traversal return false.
        if (prev && prev -> val >= node -> val) return false;

        // Update previous node to current node.
        prev = node;

        // If the right subtree isn't a valid BST return false
        return isValidBST(node -> right);
    }

    // Count nodes in current tree.
    int countNodes(TreeNode* node){
        if (!node) return 0;

        // Add nodes in left and right subtree.
        // Add 1 and return total size.
        return 1 + countNodes(node -> left) + countNodes(node -> right);
    } 

public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;

        // Previous node is initially null.
        prev = nullptr;

        // If the current subtree is a valid BST, its children will have smaller size BST.
        if (isValidBST(root)) return countNodes(root);

        // Find BST in left and right subtrees of current nodes.
        return max(largestBSTSubtree(root -> left), largestBSTSubtree(root -> right));
    }
};
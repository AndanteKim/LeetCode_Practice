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
    bool isValidBST(TreeNode* node){
        // Check if given tree is a valid Binary Search Tree.
        // An empty tree is a valid Binary Search Tree.
        if (!node) return true;

        // Find the max node in the left subtree of current node.
        int leftMax = findMax(node -> left);

        // If the left subtree has a node greater than or equal to the current node,
        // then it's not a valid Binary Search Tree.
        if (leftMax >= node -> val) return false;

        // Find the min node in the right subtree of current node.
        int rightMin = findMin(node -> right);
        
        // If the right subtree has a value less than or equal to the current node,
        // then it's not a valid Binary Search Tree.
        if (rightMin <= node -> val) return false;

        // If the left and right subtrees of current tree are also valid BST.
        // then the whole tree is a BST.
        return isValidBST(node -> left) && isValidBST(node -> right);
    }

    int findMax(TreeNode* node){
        // Max node in a empty tree should smaller than parent.
        if (!node) return std::numeric_limits<int>::min();

        // Check the maximum node from the current node, left and right subtree of the current tree.
        return max(node -> val, max(findMax(node -> left), findMax(node -> right)));
    }

    int findMin(TreeNode* node){
        // Min node in a empty tree should be larger than parent.
        if (!node) return std::numeric_limits<int>::max();
        
        // Check the minimum node from the current node, left and right subtree of the current tree
        return min(node -> val, min(findMin(node -> left), findMin(node -> right)));
    }
    

    int countNodes(TreeNode* node){
        if (!node) return 0;

        // Add nodes in left and right subtree.
        // Add 1 and return total size.
        return 1 + countNodes(node -> left) + countNodes(node -> right);
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        if (!root) return 0;

        // If current subtree is a validBST, its children will have smaller size BST.
        if (isValidBST(root)) return countNodes(root);

        // Find BST in left and right subtrees of current nodes.
        return max(largestBSTSubtree(root -> left), largestBSTSubtree(root -> right));    
    }
};
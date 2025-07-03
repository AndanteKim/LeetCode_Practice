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
    struct NodeValue{
        int minNode, maxNode, maxSize;
        NodeValue(int minNode, int maxNode, int maxSize): minNode(minNode), maxNode(maxNode), maxSize(maxSize){}
    };

    NodeValue* helper(TreeNode* node){
        // An empty tree is a BST of size 0.
        if (!node) return new NodeValue(std::numeric_limits<int>::max(), std::numeric_limits<int>::min(), 0);

        // Get values from left and right subtree of current tree.
        NodeValue *left = helper(node -> left), *right = helper(node -> right);

        // Current node is greater than max in left and smaller than min in right, it's a BST.
        if (left -> maxNode < node -> val && node -> val < right -> minNode)
            // It's a BST.
            return new NodeValue(min(left -> minNode, node -> val), max(right -> maxNode, node -> val), left -> maxSize + right -> maxSize + 1);

        // Otherwise, return [-inf, inf], so that parent can't be valid BST
        return new NodeValue(std::numeric_limits<int>::min(), std::numeric_limits<int>::max(), max(left -> maxSize, right -> maxSize));
    }

public:
    int largestBSTSubtree(TreeNode* root) {
        return helper(root) -> maxSize;
    }
};
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
    // Function to find the LCA of the given node.
    TreeNode* find_LCA(TreeNode* node, int p, int q){
        if (!node || node -> val == p || node -> val == q)
            return node;
        
        TreeNode* left = find_LCA(node -> left, p, q);
        TreeNode* right = find_LCA(node -> right, p, q);
        
        if (left && right)
            return node;
        
        return left? left : right;
    }
    
    // Function to find the depth of the node with respect to LCA
    int findDepth(TreeNode* node, int target, int currDepth = 0){
        // Node not found
        if (!node)
            return -1;
        
        if (node -> val == target)
            return currDepth;
        
        // Check left subtree
        int leftDepth = findDepth(node -> left, target, currDepth + 1);
        if (leftDepth != -1)
            return leftDepth;
        
        // If not in the left subtree, it's guaranteed to be in the right subtree.
        return findDepth(node -> right, target, currDepth + 1);
    }
    
public:
    int findDistance(TreeNode* root, int p, int q) {
        // Find the lowest common ancestor of p and q
        TreeNode* lca = find_LCA(root, p, q);
        return findDepth(lca, p, 0) + findDepth(lca, q, 0);
    }
};
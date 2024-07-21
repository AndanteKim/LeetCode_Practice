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
    // Private helper function
    int distance(TreeNode* root, int p, int q, int depth){
        if (!root || p == q)
            return 0;
        
        // If either p or q is found, calculate the retDistance the maximum
        // of depth and retDistance for left and right subtrees.
        if (root -> val == p || root -> val == q){
            int left = distance(root -> left, p, q, 1);
            int right = distance(root -> right, p, q, 1);
            
            return (left > 0 || right > 0)? max(left, right) : depth;
        }
        
        // Otherwise, calculate the retDistance as sum of retDistance of left
        // and right subtree.
        int left = distance(root -> left, p, q, depth + 1);
        int right = distance(root -> right, p, q, depth + 1);
        
        int retDistance = left + right;
        
        // If the current node is the LCA, subtract twice of depth.
        if (left != 0 && right != 0) retDistance -= 2 * depth;
        
        return retDistance;
    }
    
public:
    int findDistance(TreeNode* root, int p, int q) {
        return distance(root, p, q, 0);
    }
};
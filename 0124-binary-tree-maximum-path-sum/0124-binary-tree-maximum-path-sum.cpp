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
    int maxSum;
    // Post order traversal of subtree rooted at 'root'
    int gainFromSubtree(const TreeNode* node){
        if (!node) return 0;
        
        // Add the path sum from the left subtree. Note that if the path
        // sum is negative, we can ignore it, or count it as 0.
        int gainFromLeft = max(gainFromSubtree(node -> left), 0);
        
        // Add the path sum from the right subtree. 0 if negative
        int gainFromRight = max(gainFromSubtree(node -> right), 0);
        
        // If left or right path sum are negative, they're counted
        // as 0, so this statement takes care of all 4 scenarios
        maxSum = max(maxSum, gainFromLeft + gainFromRight + node -> val);
        
        // Return the max sum for a path starting at the root of subtree
        return max(gainFromLeft + node -> val, gainFromRight + node -> val);
    }
    
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        gainFromSubtree(root);
        return maxSum;
    }
};
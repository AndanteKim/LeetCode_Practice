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
    int helper(TreeNode* node, int cur_max, int cur_min){
        if (!node) return abs(cur_max - cur_min);
        cur_max = max(cur_max, node -> val);
        cur_min = min(cur_min, node -> val);
        
        int left = helper(node -> left, cur_max, cur_min);
        int right = helper(node -> right, cur_max, cur_min);
        return max(left, right);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return helper(root, root -> val, root -> val);
    }
};
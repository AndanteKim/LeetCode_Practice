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
    int dfs(TreeNode* child, TreeNode* parent, int length) {
        if (!child) return length;

        length = (parent && parent -> val + 1 == child -> val)? length + 1 : 1;
        
        return max(length, max(dfs(child -> left, child, length), dfs(child -> right, child, length)));
    }

public:
    int longestConsecutive(TreeNode* root) {
        return dfs(root, NULL, 0);
    }
};
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
    int maxLength = 0;

    int dfs(TreeNode* node) {
        if (!node) return 0;

        int left = 1 + dfs(node -> left), right = 1 + dfs(node -> right);

        if (node -> left && node -> val + 1 != node -> left -> val) left = 1;
        if (node -> right && node -> val + 1 != node -> right -> val) right = 1;

        int length = max(left, right);
        maxLength = max(maxLength, length);

        return length;
    }

public:
    int longestConsecutive(TreeNode* root) {
        dfs(root);

        return maxLength;
    }
};
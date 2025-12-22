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
    int maxVal = 0;
    pair<int, int> longestPath(TreeNode* node) {
        if (!node) return {0, 0};

        int inc = 1, dec = 1;

        if (node -> left) {
            auto left = longestPath(node -> left);
            if (node -> val == node -> left -> val + 1)
                dec = left.second + 1;
            else if (node -> val == node -> left -> val - 1)
                inc = left.first + 1;
        }

        if (node -> right) {
            auto right = longestPath(node -> right);
            if (node -> val == node -> right -> val + 1)
                dec = max(dec, right.second + 1);
            else if (node -> val == node -> right -> val - 1)
                inc = max(inc, right.first + 1);
        }

        maxVal = max(maxVal, inc + dec - 1);
        return {inc, dec};
    }

public:
    int longestConsecutive(TreeNode* root) {
        longestPath(root);
        return maxVal;
    }
};
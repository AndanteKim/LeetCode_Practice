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
    int ans = 0;

    void dfs(TreeNode* node, int curr) {
        if (!node) return;

        if (!(node -> left || node -> right)) {
            ans += (curr << 1) + node -> val;
        }

        dfs(node -> left, (curr << 1) + node -> val);
        dfs(node -> right, (curr << 1) + node -> val);
    }

public:
    int sumRootToLeaf(TreeNode* root) {
        dfs(root, 0);

        return ans;
    }
};
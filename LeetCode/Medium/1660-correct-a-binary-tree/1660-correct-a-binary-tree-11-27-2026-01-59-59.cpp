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
    TreeNode* dfs(TreeNode* node, unordered_set<int>& visited) {
        if (!node) return nullptr;

        if (node -> right && visited.count(node -> right -> val)) return nullptr;

        visited.insert(node -> val);
        if (node -> right) node -> right = dfs(node -> right, visited);
        if (node -> left) node -> left = dfs(node -> left, visited);

        return node;
    }

public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<int> visited;
        return dfs(root, visited);
    }
};
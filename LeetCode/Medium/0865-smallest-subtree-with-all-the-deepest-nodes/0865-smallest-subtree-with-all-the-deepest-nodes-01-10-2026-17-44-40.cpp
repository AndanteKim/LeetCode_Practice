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
    int maxLevel = 0;
    void dfs(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, int>& depths) {
        if (!node) return;
        
        depths[node] = depths[parent] + 1;
        maxLevel = max(maxLevel, depths[node]);
        dfs(node -> left, node, depths);
        dfs(node -> right, node, depths);
    }

    TreeNode* findAnswer(TreeNode* node, TreeNode* parent, unordered_map<TreeNode*, int> depths) {
        if (!node || (depths.find(node) != depths.end() && depths[node] == maxLevel)) return node;
        TreeNode* left = findAnswer(node -> left, node, depths);
        TreeNode* right = findAnswer(node -> right, node, depths);
        return (left && right)? node : left? left : right;
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        unordered_map<TreeNode*, int> depths{{NULL, -1}};
        dfs(root, NULL, depths);

        return findAnswer(root, NULL, depths);
    }
};
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
    int dfs(TreeNode* node, vector<int>& seen){
        if (!node) return 0;
        seen.push_back(dfs(node -> left, seen) + dfs(node -> right, seen) + node -> val);
        return seen.back();
    }

public:
    bool checkEqualTree(TreeNode* root) {
        vector<int> seen;
        int total = dfs(root, seen);
        seen.pop_back();
        return find(seen.begin(), seen.end(), total / 2.0) != seen.end();
    }
};
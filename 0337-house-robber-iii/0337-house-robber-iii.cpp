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
    pair<int, int> dfs(TreeNode* node){
        if (!node) return make_pair(0, 0);
        pair<int, int> left = dfs(node -> left), right = dfs(node -> right);
        int rob = node -> val + left.second + right.second, notRob = max(left.first, left.second) + max(right.first, right.second);
        return make_pair(rob, notRob);
    }
    
public:
    int rob(TreeNode* root) {
        pair<int, int> p = dfs(root);
        return max(p.first, p.second);
    }
};
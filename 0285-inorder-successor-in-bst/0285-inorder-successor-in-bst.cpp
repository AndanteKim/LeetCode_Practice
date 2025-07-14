/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    TreeNode* ans = nullptr;
    void dfs(TreeNode* curr, TreeNode* p){
        if (!curr) return;

        if (curr -> val > p -> val && (!ans || ans -> val > curr -> val)){
            ans = curr;
        }

        dfs(curr -> left, p);
        dfs(curr -> right, p);
    }

public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        dfs(root, p);

        if (ans){
            ans -> left = nullptr;
            ans -> right = nullptr;
        }

        return ans;
    }
};
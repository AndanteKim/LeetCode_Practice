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
    TreeNode* dfs(TreeNode* root, unordered_set<int>& seen){
        if (!root || (root -> right && seen.find(root -> right -> val) != seen.end()))
            return nullptr;
        seen.insert(root -> val);
        root -> right = dfs(root -> right, seen);
        root -> left = dfs(root -> left, seen);
        
        return root;
    }
    
public:
    TreeNode* correctBinaryTree(TreeNode* root) {
        unordered_set<int> seen;
        return dfs(root, seen);
    }
};
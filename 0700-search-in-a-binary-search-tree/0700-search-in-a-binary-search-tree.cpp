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
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (!root) return nullptr;
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        while (!stack.empty()){
            TreeNode* node = stack.top();
            stack.pop();
            
            if (node -> val == val) return node;
        
            if (node -> right) stack.push(node -> right);
            if (node -> left) stack.push(node -> left);
        }
        return nullptr;
    }
};
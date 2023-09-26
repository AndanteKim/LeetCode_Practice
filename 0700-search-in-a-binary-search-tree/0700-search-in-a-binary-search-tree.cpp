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
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            
            if (node -> val == val)
                return node;
            
            if (node -> left)
                queue.push(node -> left);
            
            if (node -> right)
                queue.push(node -> right);
        }
        
        return nullptr;
    }
};
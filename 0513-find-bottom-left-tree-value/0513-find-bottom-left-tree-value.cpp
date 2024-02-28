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
    int findBottomLeftValue(TreeNode* root) {
        TreeNode* curr = root;
        queue<TreeNode*> queue{{root}};
        
        while (!queue.empty()){
            curr = queue.front();
            queue.pop();
            
            if (curr -> right) queue.push(curr -> right);
            if (curr -> left) queue.push(curr -> left);
        }
        
        return curr -> val;
    }
};
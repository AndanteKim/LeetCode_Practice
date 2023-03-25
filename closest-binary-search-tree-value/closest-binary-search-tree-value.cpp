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
    int closestValue(TreeNode* root, double target) {
        stack<TreeNode*> *st = new stack<TreeNode*>;
        int ans = INT_MAX;
        st -> push(root);
        while (!st -> empty()){
            TreeNode* node = st -> top();
            st -> pop();
            if (abs(node -> val - target) < abs(ans - target)) ans = node -> val;
            
            if (node -> left) st -> push(node -> left);
            if (node -> right) st -> push(node -> right);
        }
        
        return ans;
    }
};
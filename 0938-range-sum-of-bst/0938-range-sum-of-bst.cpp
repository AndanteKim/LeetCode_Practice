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
    int rangeSumBST(TreeNode* root, int low, int high) {
        stack<TreeNode*> *st = new stack<TreeNode*>;
        int sum = 0;
        st -> push(root);
        while (!st -> empty()){
            TreeNode* node = st -> top();
            st -> pop();
            if (node -> val >= low && node -> val <= high) sum += node -> val;
            
            if (node -> left) st -> push(node -> left);
            if (node -> right) st -> push(node -> right);
        }
        
        return sum;
    }
};
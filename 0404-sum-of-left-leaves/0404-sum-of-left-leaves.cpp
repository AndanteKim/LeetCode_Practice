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
    bool is_leaf(TreeNode* node){
        return (node != NULL) && (node -> left == NULL) && (node -> right == NULL);
    }
    
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL) return 0;
        stack<TreeNode*> st({root});
        int total = 0;
        TreeNode* sub_root;
        while (!st.empty()){
            sub_root = st.top();
            st.pop();
            if (is_leaf(sub_root->left)) total += sub_root->left->val;
            
            if (sub_root->right != NULL) st.push(sub_root -> right);
            if (sub_root -> left != NULL) st.push(sub_root -> left);
        }
        
        return total;
        
    }
};
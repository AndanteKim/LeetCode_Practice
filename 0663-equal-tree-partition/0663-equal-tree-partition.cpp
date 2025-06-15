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
    int sum(TreeNode* node){
        int s = 0;
        stack<TreeNode*> st;
        st.push(node);
        
        while (!st.empty()){
            TreeNode* curr = st.top();
            s += curr -> val; st.pop();
            
            if (curr -> left) st.push(curr -> left);
            if (curr -> right) st.push(curr -> right);
        }

        return s;
    }

public:
    bool checkEqualTree(TreeNode* root) {
        int total = sum(root);

        if (total % 2) return false;

        stack<TreeNode*> st;
        if (root -> left) st.push(root -> left);
        if (root -> right) st.push(root -> right);

        while (!st.empty()){
            TreeNode* curr = st.top(); st.pop();
            int s = sum(curr);
            if (s * 2 == total) return true;
            else{
                if (curr -> left) st.push(curr -> left);
                if (curr -> right) st.push(curr -> right);
            }
        }

        return false;
    }
};
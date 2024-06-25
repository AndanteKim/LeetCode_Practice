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
    TreeNode* bstToGst(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode* node = root;
        int nodeSum = 0;
        
        
        while (!st.empty() || node){
            while (node){
                st.push(node);
                node = node -> right;
            }
            
            // Store the top value of stack in node and pop it.
            node = st.top();
            st.pop();
            
            // Update value of node.
            nodeSum += node -> val;
            node -> val = nodeSum;
            
            // Move to the left child of node.
            node = node -> left;
        }
        
        return root;
    }
};
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
    vector<int> dfs(TreeNode* root){
        stack<TreeNode*> stack;
        stack.push(root);
        vector<int> leaves;
        
        while(!stack.empty()){
            TreeNode* node= stack.top();
            stack.pop();
            
            if (!node -> left && !node -> right) leaves.push_back(node -> val);
            
            if (node -> left) stack.push(node -> left);
            if (node -> right) stack.push(node -> right);
        }
        return leaves;
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        return dfs(root1) == dfs(root2);
    }
};
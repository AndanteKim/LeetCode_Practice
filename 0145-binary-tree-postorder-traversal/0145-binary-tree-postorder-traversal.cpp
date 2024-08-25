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
    vector<int> postorderTraversal(TreeNode* root) {
        // If the root is null, return an empty list
        if (!root)
            return {};
        
        vector<int> ans;
        
        // Stack to manage the traversal, path
        stack<TreeNode*> path, main;
        
        // Start with the root node
        main.push(root);
        
        // Process nodes until the main stack is empty
        while (!main.empty()){
            TreeNode* curr = main.top();
            
            // If the node is in the path stack and it's the top, add its value.
            if (!path.empty() && path.top() == curr){
                ans.push_back(curr -> val);
                path.pop();
                main.pop();
            }
            else{
                // Push the current node to the path stack
                path.push(curr);
                
                // Push right child if it exists
                if (curr -> right)
                    main.push(curr -> right);
                
                // Push left child if it exists
                if (curr -> left)
                    main.push(curr -> left);
            }
        }
        
        return ans;
    }
};
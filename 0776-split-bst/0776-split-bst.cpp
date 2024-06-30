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
    vector<TreeNode*> splitBST(TreeNode* root, int target) {
        // Initialize an array to store the two split trees
        vector<TreeNode*> ans{nullptr, nullptr};
        
        // If the root is null, return the empty array
        if (!root) return ans;
        
        // Stack to traverse the tree and find the split point
        stack<TreeNode*> stk;
        
        
        // Find the node with the closest value to the taarget.
        while (root){
            stk.push(root);
            if (root -> val > target)
                root = root -> left;
            else
                root = root -> right;
        }
        
        // Process nodes in reverse order from the stack to perform the split
        while (!stk.empty()){
            TreeNode* curr = stk.top(); stk.pop();
            
            if (curr -> val > target){
                // Assign current node's left child to the subtree
                // containing nodes greater than the target
                curr -> left = ans[1];
                
                // Current node becomes the new root of this subtree
                ans[1] = curr;
            }
            else{
                // Assign current node's right child to the subtree
                // containing nodes smaller than the target
                curr -> right = ans[0];
                // current node becomes the new root of this subtree
                ans[0] = curr;
            }
        }
        
        return ans;
    }
};
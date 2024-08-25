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
            return vector<int>{};
        
        vector<int> ans;
        // Stack to manage the traversal
        stack<TreeNode*> traversal;
        
        // To keep track of the previously processed node
        TreeNode* prevNode = nullptr;
        
        // Process nodes until both the root is null and the stack is empty
        while (root || !traversal.empty()){
            // Traverse to the leftmost node
            if (root){
                traversal.push(root);
                root = root -> left;
            }
            else{
                // Peek at the top node of the stack
                root = traversal.top();
                
                // If there is no right child or the right child was already processed
                if (!root -> right || root -> right == prevNode){
                    ans.push_back(root -> val);
                    prevNode = root;
                    traversal.pop();
                    
                    // Ensure we don't traverse again from this node.
                    root = nullptr;
                }
                else
                    // Move to the right child
                    root = root -> right;
            }
            
        }
        
        return ans;
    }
};
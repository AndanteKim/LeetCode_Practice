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
        // List to store the result of postorder traversal
        vector<int> ans;
        
        // Stack to facilitate the traversal of nodes
        TreeNode* currNode = root;
        stack<TreeNode*> traversal;
        
        // Traverse the tree while there are nodes to process
        while (currNode || !traversal.empty()){
            if (currNode){
                // Add current node's value to ans list before going to its children
                ans.push_back(currNode -> val);
                
                // Push current node onto the stack
                traversal.push(currNode);
                
                // Move to the right child
                currNode = currNode -> right;
            }
            else{
                // Pop the node from the stack and move to its left child
                currNode = traversal.top();
                traversal.pop();
                currNode = currNode -> left;
            }
        }
        
        // Reverse the ans list to get the correct postorder sequence
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
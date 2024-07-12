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
    void flatten(TreeNode* root) {
        // Iterative
        if (!root) return;
        
        stack<pair<TreeNode*, int>> stk;
        int START = 1, END = 2;
        stk.push({root, START});
        TreeNode* tailNode = nullptr;
        
        while (!stk.empty()){
            auto [currNode, recursionState] = stk.top(); stk.pop();
            
            // We reached a leaf node. Record this as a tail node
            // and move on.
            if (!(currNode -> left || currNode -> right)){
                tailNode = currNode;
                continue;
            }
            
            // If the node is in the START state, it means we still
            // haven't processed it's left child yet.
            if (recursionState == START){
                // If the current node has a left child, we add it
                // to the stack AFTER adding the current node again
                // to the stack with the END recursion state.
                if (currNode -> left){
                    stk.push({currNode, END});
                    stk.push({currNode -> left, START});
                }
                else if (currNode -> right)
                    // In case the current node didn't have a left child
                    // we will add it's right child.
                    stk.push({currNode -> right, START});
            }
            else{
                // If the current node is in the END recursion state,
                // that means we did process one of it's children. Left
                // if it existed, else right.
                TreeNode* rightNode = currNode -> right;
                
                // If there was a left child, there must have been a leaf
                // node and so, we would have set the tailNode
                if (tailNode){
                    tailNode -> right = currNode -> right;
                    currNode -> right = currNode -> left;
                    currNode -> left = nullptr;
                    rightNode = tailNode -> right;
                }
                
                if (rightNode) stk.push({rightNode, START});
            }
            
        }
    }
};
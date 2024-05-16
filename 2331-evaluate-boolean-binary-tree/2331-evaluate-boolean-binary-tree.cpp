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
    bool evaluateTree(TreeNode* root) {
        stack<TreeNode*> stack;
        unordered_map<TreeNode*, bool> evaluated;
        stack.push(root);
        
        while(!stack.empty()){
            TreeNode* topNode = stack.top();
            
            // If the node is a leaf node, store its value in the evaluated, 
            if (!(topNode -> left || topNode -> right)){
                stack.pop();
                evaluated[topNode] = topNode -> val == 1;
                continue;
            }
            
            // If both the children have already been evaluated, use their
            // values to evaluate the current node.
            if (evaluated.find(topNode -> left) != evaluated.end() && evaluated.find(topNode -> right) != evaluated.end()){
                stack.pop();
                if (topNode -> val == 2)
                    evaluated[topNode] = evaluated[topNode -> left] | evaluated[topNode -> right];
                else
                    evaluated[topNode] = evaluated[topNode -> left] & evaluated[topNode -> right];
            }
            else{
                // If both the children are not leaf nodes, push the current
                // node along with its left and right child back into the stack.
                if (topNode -> left)
                    stack.push(topNode -> left);
                if (topNode -> right)
                    stack.push(topNode -> right);
            }
        }
        
        return evaluated[root];
    }
};
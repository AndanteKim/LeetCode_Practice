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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        stack<pair<TreeNode*, int>> stack;
        stack.push(pair(root, 0));
        
        while(!stack.empty()){
            auto [node, curr] = stack.top();
            stack.pop();
            
            if (!node -> left && !node -> right){
                if (curr + node -> val == targetSum) return true;
            }
            
            curr += node -> val;
            
            if (node -> left) stack.push({node -> left, curr});
            if (node -> right) stack.push({node -> right, curr});
        }
        
        return false;
    }
};
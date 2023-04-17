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
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if (!root) return nullptr;
        stack<pair<TreeNode*, pair<TreeNode*, bool>>> stack;
        stack.push({root, {nullptr, false}});
        
        while(!stack.empty()){
            auto [child, others] = stack.top();
            auto [parent, visited] = others;
            stack.pop();
            
            if (visited){
                if (!child -> left && !child -> right && child -> val == target){
                    if (!parent) return nullptr;
                    else if (parent -> left == child) parent -> left = nullptr;
                    else parent -> right = nullptr;
                }
            }
            else{
                stack.push({child, {parent, true}});
                if (child -> right) stack.push({child -> right, {child, false}});
                if (child -> left) stack.push({child -> left, {child, false}});
            }
        }
        
        return root;
    }
};
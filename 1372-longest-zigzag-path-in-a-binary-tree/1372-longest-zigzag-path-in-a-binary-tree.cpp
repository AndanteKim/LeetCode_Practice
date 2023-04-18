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
    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        
        int ans = 0;
        stack<pair<TreeNode*, pair<int, char>>> stack;
        stack.push({root, {0, NULL}});
        
        while(!stack.empty()){
            auto [node, others] = stack.top();
            auto [zigzag, direction] = others;
            stack.pop();
            
            ans = max(ans, zigzag);
            if (node -> left){
                if (direction == 'l') stack.push({node -> left, {1, 'l'}});
                else stack.push({node -> left, {zigzag + 1, 'l'}});
            }
            
            if (node -> right){
                if (direction == 'r') stack.push({node -> right, {1, 'r'}});
                else stack.push({node -> right, {zigzag + 1, 'r'}});
            }
        }
        
        return ans;
    }
};
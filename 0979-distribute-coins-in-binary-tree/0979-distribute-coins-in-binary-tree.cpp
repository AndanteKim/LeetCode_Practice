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
    int distributeCoins(TreeNode* root) {
        stack<TreeNode*> stack{{root}}, visited;
        
        while (!stack.empty()){
            TreeNode* node = stack.top(); stack.pop();
            
            visited.push(node);
            if (node -> left) stack.push(node -> left);
            if (node -> right) stack.push(node -> right);
        }
        
        int ans = 0;
        while (!visited.empty()){
            TreeNode* curr = visited.top(); visited.pop();
            
            if (curr -> left){
                ans += abs(curr -> left -> val - 1);
                curr -> val += curr -> left -> val - 1;
            }
            
            if (curr -> right){
                ans += abs(curr -> right -> val - 1);
                curr -> val += curr -> right -> val - 1;
            }
        }
        
        return ans;
    }
};
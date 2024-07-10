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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // Iterative
        // base case
        if (preorder.empty()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        int pre = 1, ino = 0;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while (pre < preorder.size()){
            TreeNode* curr = new TreeNode(preorder[pre++]), *prev = nullptr;
            
            while (!stk.empty() && stk.top() -> val == inorder[ino]){
                prev = stk.top();
                stk.pop();
                ++ino;
            }
            
            if (prev)
                prev -> right = curr;
            else
                stk.top() -> left = curr;
            stk.push(curr);
        }
        
        return root;
    }
};
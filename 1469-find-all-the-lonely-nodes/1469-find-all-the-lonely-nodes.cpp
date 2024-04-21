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
    vector<int> getLonelyNodes(TreeNode* root) {
        queue<TreeNode*> queue{{root}};
        vector<int> ans;
        
        while (!queue.empty()){
            TreeNode* curr = queue.front(); queue.pop();
            
            
            if (curr -> left != nullptr ^ curr -> right != nullptr){
                // If curr's child is leaf
                if (curr -> left) ans.push_back(curr -> left -> val);
                
                if (curr -> right) ans.push_back(curr -> right -> val);
            }
            
            if (curr -> left) queue.push(curr -> left);
            if (curr -> right) queue.push(curr -> right);
        }
        
        return ans;
    }
};
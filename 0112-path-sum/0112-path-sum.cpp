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
        TreeNode* curr = root;
        int m = 0;
        bool result = false;
        
        while (curr){
            if (!curr -> left){
                m += curr -> val;
                curr = curr -> right;
                if (!curr && m == targetSum) result = true;
            }
            else{
                TreeNode* pred = curr -> left;
                int n = pred -> val;
                
                while (pred -> right && pred -> right != curr){
                    pred = pred -> right;
                    n += pred -> val;
                }
                
                if (!pred -> right){
                    pred -> right = curr;
                    m += curr -> val;
                    if (!pred -> left && m + n == targetSum) result = true;
                    curr = curr -> left;
                }
                else{
                    pred -> right = nullptr;
                    m -= n;
                    curr = curr -> right;
                }
            }
        }
        
        return result;
    }
};
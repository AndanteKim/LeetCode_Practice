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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        TreeNode *curr = root, *pre;
        
        while(curr){
            // If there no exists the leftmost side of subtree
            if (!curr -> left){
                ans.push_back(curr -> val);
                curr = curr -> right;
            }
            else{
                pre = curr -> left;
                while (pre -> right){
                    pre = pre -> right;
                }
                // connect curr from the rightmost side of subtree to return to the origin curr
                pre -> right = curr;
                TreeNode* temp = curr;
                curr = curr -> left;
                temp -> left = nullptr;
            }
        }
        
        return ans;
    }
};
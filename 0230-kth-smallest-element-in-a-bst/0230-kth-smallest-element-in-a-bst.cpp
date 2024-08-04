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
private:
    int ans = -1, k = 1;
    void inorder(TreeNode* node, int target){
        if (!node) return;
        
        inorder(node -> left, target);
        if (k == target){
            ans = node -> val;
            ++k;
            return;
        }
        ++k;
        inorder(node -> right, target);
    }
    
    
public:
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        
        return ans;
    }
};
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
    vector<TreeNode*> inorder(TreeNode* curr){
        if (!curr) return {};
        
        vector<TreeNode*> traversal = inorder(curr -> left);
        traversal.push_back(curr);
        vector<TreeNode*> right = inorder(curr -> right);
        traversal.insert(traversal.end(), right.begin(), right.end());
        
        return traversal;
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> inorderTraversal = inorder(root);
        
        for (int i = inorderTraversal.size() - 2; i >= 0; --i){
            inorderTraversal[i] -> val += inorderTraversal[i + 1] -> val;
        }
        
        return root;
    }
};
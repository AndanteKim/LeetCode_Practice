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
    void inorder(TreeNode* curr, vector<TreeNode*>& traversal){
        if (!curr) return;
        
        inorder(curr -> left, traversal);
        traversal.push_back(curr);
        inorder(curr -> right, traversal);
    }
    
public:
    TreeNode* bstToGst(TreeNode* root) {
        vector<TreeNode*> traversal;
        inorder(root, traversal);
        
        for (int i = traversal.size() - 2; i >= 0; --i){
            traversal[i] -> val += traversal[i + 1] -> val;
        }
        
        return root;
    }
};
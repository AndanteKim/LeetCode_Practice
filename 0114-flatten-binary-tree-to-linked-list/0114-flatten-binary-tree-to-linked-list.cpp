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
    void preorder(TreeNode* root, vector<int>& flatten){
        if (!root) return;
        
        flatten.push_back(root -> val);
        preorder(root -> left, flatten);
        preorder(root -> right, flatten);
    }
    
public:
    void flatten(TreeNode* root) {
        if (!root) return;

        vector<int> flatten;
        preorder(root, flatten);
        root -> left = nullptr;
        root -> right = nullptr;
        TreeNode* curr = root;
        
        for (int i = 1; i < flatten.size(); ++i){
            curr -> right = new TreeNode(flatten[i]);
            curr = curr -> right;
        }
        
    }
};
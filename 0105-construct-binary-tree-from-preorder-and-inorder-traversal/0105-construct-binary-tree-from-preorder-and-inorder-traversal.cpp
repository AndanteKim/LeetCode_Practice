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
    TreeNode* build(int stop, vector<int>& preorder, vector<int>& inorder){
        if (!inorder.empty() && inorder.back() != stop){
            TreeNode* root = new TreeNode(preorder.back());
            preorder.pop_back();
            root -> left = build(root -> val, preorder, inorder);
            
            inorder.pop_back();
            root -> right = build(stop, preorder, inorder);
            
            return root;
        }
        
        return nullptr;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        // recursion without map
        reverse(preorder.begin(), preorder.end());
        reverse(inorder.begin(), inorder.end());
        
        return build(-3001, preorder, inorder);
    }
};
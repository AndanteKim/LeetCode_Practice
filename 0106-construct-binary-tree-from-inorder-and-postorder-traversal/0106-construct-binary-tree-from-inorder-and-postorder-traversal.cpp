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
    vector<int> postorder;
    unordered_map<int, int> idx_map;
    
    TreeNode* helper(int in_left, int in_right){
        if (in_left > in_right) return nullptr;
        int val = this -> postorder.back();
        this -> postorder.pop_back();
        TreeNode* root = new TreeNode(val);
        int index = idx_map[val];
        root -> right = helper(index + 1, in_right);
        root -> left = helper(in_left, index - 1);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        this -> postorder = postorder;
        
        for (int i = 0; i < inorder.size(); ++i) idx_map[inorder[i]] = i;
        
        return helper(0, inorder.size() - 1);
    }
};
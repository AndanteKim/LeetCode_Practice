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
    void inorder(TreeNode* node, vector<int>& arr){
        if (!node) return;
        inorder(node -> left, arr);
        arr.push_back(node -> val);
        inorder(node -> right, arr);
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> r1, r2;
        inorder(root1, r1);
        inorder(root2, r2);
        vector<int> ans = r1;
        ans.insert(ans.end(), r2.begin(), r2.end());
        sort(ans.begin(), ans.end());
        return ans;
    }
};
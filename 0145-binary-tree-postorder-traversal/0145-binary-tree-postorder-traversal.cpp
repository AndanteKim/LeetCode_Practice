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
    vector<int> postOrder(TreeNode* curr){
        if (!curr) return vector<int>{};
        
        vector<int> left = postOrder(curr -> left), right = postOrder(curr -> right);
        vector<int> ans{left};
        ans.insert(ans.end(), right.begin(), right.end());
        ans.push_back(curr -> val);
        return ans;
    }
    
public:
    vector<int> postorderTraversal(TreeNode* root) {
        return postOrder(root);
    }
};
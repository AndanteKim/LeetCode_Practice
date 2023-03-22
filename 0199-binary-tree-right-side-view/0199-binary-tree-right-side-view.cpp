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
    vector<int> rightside;
    void helper(TreeNode* node, int level){
        if (level == rightside.size()) rightside.push_back(node -> val);
        for (TreeNode* child : {node -> right, node -> left}){
            if (child) helper(child, level + 1);
        }
    }
    
public:
    vector<int> rightSideView(TreeNode* root) {
        if (!root) return {};
        
        helper(root, 0);
        return rightside;
    }
};
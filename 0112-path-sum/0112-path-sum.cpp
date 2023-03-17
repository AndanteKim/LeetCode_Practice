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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        
        queue<pair<TreeNode*, int>> *q = new queue<pair<TreeNode*, int>>;
        q -> push({root, 0});
        while (!q -> empty()){
            TreeNode* node = q -> front().first;
            int total = q -> front().second;
            q -> pop();
            
            if (!node -> left && !node -> right){
                if (total + node -> val == targetSum) return true;
            }
            
            if (node -> left) q -> push({node -> left, total + node -> val});
            if (node -> right) q -> push({node -> right, total + node -> val});
        }
        
        return false;
    }
};
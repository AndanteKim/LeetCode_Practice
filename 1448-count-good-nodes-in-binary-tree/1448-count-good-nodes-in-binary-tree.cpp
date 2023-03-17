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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> *q = new queue<pair<TreeNode*, int>>;
        q -> push({root, INT_MIN});
        int ans = 0;
        
        while(!q -> empty()){
            auto[node, prev_max_val] = q -> front();
            q -> pop();
            if (node -> val >= prev_max_val) ++ans;
            
            if (node -> left) q -> push({node -> left, max(prev_max_val, node -> val)});
            
            if (node -> right) q -> push({node -> right, max(prev_max_val, node -> val)});
        }
        
        return ans;
    }
};
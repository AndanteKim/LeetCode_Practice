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
        stack<pair<TreeNode*, int>> *st = new stack<pair<TreeNode*, int>>;
        st -> push({root, INT_MIN});
        int ans = 0;
        
        while (!st -> empty()){
            auto[node, max_so_far] = st -> top();
            st -> pop();
            if (node -> val >= max_so_far) ++ans;
            
            if (node -> left) st -> push({node -> left, max(max_so_far, node -> val)});
            if (node -> right) st -> push({node -> right, max(max_so_far, node -> val)});
        }
        
        return ans;
    }
};
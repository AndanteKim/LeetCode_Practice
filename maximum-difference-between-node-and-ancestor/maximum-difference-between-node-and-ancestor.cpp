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
    int maxAncestorDiff(TreeNode* root) {
        int ans = 0;
        stack<pair<TreeNode*, pair<int ,int>>> *st = new stack<pair<TreeNode*, pair<int, int>>>;
        st -> push({root, {INT_MIN, INT_MAX}});
        while (!st -> empty()){
            auto it = st -> top();
            TreeNode* node = it.first;
            int mx = it.second.first, mn = it.second.second;
            st -> pop();
            mx = max(mx, node -> val);
            mn = min(mn, node -> val);
            ans = max(abs(mx - mn), ans);
            
            if (node -> left) st -> push({node -> left, {mx, mn}});
            if (node -> right) st -> push({node -> right, {mx, mn}});
        }
        
        return ans;
    }
};
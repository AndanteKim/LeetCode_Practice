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
#define ll long long

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<pair<TreeNode*, pair<ll, ll>>> *st = new stack<pair<TreeNode*, pair<ll, ll>>>;
        st -> push({root, {LONG_LONG_MIN, LONG_LONG_MAX}});
        
        while(!st -> empty()){
            auto [node, range] = st -> top();
            ll small = range.first;
            ll large = range.second;
            st -> pop();
            
            if (!(small < (ll)node -> val && (ll)node -> val < large)) return false;
            
            if (node -> left) st -> push({node -> left, {small, (ll)node -> val}});
            if (node -> right) st -> push({node -> right, {(ll)node -> val, large}});
            
        }
        
        return true;
    }
};
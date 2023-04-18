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
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        int ans = 0;
        unordered_map<ll, int> h;
        stack<pair<TreeNode*, pair<ll, bool>>> stack;
        stack.push({root, {0, false}});
        while(!stack.empty()){
            auto [node, others] = stack.top();
            auto [curr_sum, visited] = others;
            stack.pop();
            
            if (visited){
                --h[curr_sum];
                continue;
            }
            
            curr_sum += node -> val;
            if (curr_sum == targetSum) ++ans;
            ans += h[curr_sum - targetSum];
            ++h[curr_sum];
            stack.push({node, {curr_sum, true}});
            
            if (node -> right) stack.push({node -> right, {curr_sum, false}});
            if (node -> left) stack.push({node -> left, {curr_sum, false}});
        }
        
        return ans;
    }
};
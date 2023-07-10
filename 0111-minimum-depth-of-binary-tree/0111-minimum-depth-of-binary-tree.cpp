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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 1});
        int ans = INT_MAX;
        
        while (!queue.empty()){
            auto [node, height] = queue.front();
            queue.pop();
            
            if (!node -> left && !node -> right) ans = min(ans, height);
            
            if (node -> left) queue.push({node -> left, height + 1});
            if (node -> right) queue.push({node -> right, height + 1});
        }
        
        return ans;
    }
};
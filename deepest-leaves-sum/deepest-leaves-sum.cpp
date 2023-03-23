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
    int deepestLeavesSum(TreeNode* root) {
        unordered_map<int, int> level_sum;
        int max_level = 0;
        queue<pair<TreeNode*, int>> *q = new queue<pair<TreeNode*, int>>;
        q -> push({root, 0});
        
        while(!q -> empty()){
            auto [node, level] = q -> front();
            q -> pop();
            
            max_level = max(max_level, level);
            level_sum[level] += node -> val;
            if (node -> left) q -> push({node -> left, level + 1});
            if (node -> right) q -> push({node -> right, level + 1});
        }
        return level_sum[max_level];
    }
};
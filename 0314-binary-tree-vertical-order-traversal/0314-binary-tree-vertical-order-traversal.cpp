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
    vector<vector<int>> verticalOrder(TreeNode* root) {
        // Base case
        if (!root) return vector<vector<int>>{};

        vector<vector<int>> ans;
        map<int, vector<int>> seen;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});


        while (!q.empty()){
            auto [node, axis] = q.front(); q.pop();

            seen[axis].push_back(node -> val);
            if (node -> left) q.push({node -> left, axis - 1});
            if (node -> right) q.push({node -> right, axis + 1});
        }
        
        for (auto& [_, v] : seen) ans.push_back(v);

        return ans;
    }
};
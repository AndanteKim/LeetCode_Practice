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
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> frequencies;
        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root);
        
        while (!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            
            ++frequencies[node -> val];
            
            if (node -> left)
                queue.push(node -> left);
            if (node -> right)
                queue.push(node -> right);
        }
        
        int mx = INT_MIN;
        for (auto& [val, cnt] : frequencies)
            mx = max(mx, cnt);
        
        for (auto& [val, cnt] : frequencies){
            if (cnt == mx)
                ans.push_back(val);
        }
        
        return ans;
    }
};
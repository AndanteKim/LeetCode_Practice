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
    void dfs(TreeNode* root, int level, vector<deque<int>>& tmp){
        if (tmp.size() == level){
            tmp.push_back(deque<int>());
        }
        
        if (level % 2 == 0) tmp[level].push_back(root -> val);
        else tmp[level].push_front(root -> val);
        
        
        if (root -> left != nullptr) dfs(root -> left, level + 1, tmp); 
        if (root -> right != nullptr) dfs(root -> right, level + 1, tmp);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (not root) return {};
        vector<deque<int>> tmp;
        dfs(root, 0, tmp);
        vector<vector<int>> ans(tmp.size());
        for (int i = 0; i < tmp.size(); ++i){
            ans[i] = vector<int>(tmp[i].begin(), tmp[i].end());
        }
        
        return ans;
    }
};
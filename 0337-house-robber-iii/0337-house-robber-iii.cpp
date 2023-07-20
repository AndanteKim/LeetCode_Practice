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
private:
    int dfs(TreeNode* node, bool parentRobbed, unordered_map<TreeNode*, int>& memo, unordered_map<TreeNode*, int>& notMemo){
        if(!node) return 0;
        int result = 0;
        if (parentRobbed){
            if (memo.find(node) != memo.end()) return memo[node];
            result = dfs(node -> left, false, memo, notMemo) + dfs(node -> right, false, memo, notMemo);
            memo[node] = result;
        }
        else{
            if (notMemo.find(node) != notMemo.end()) return notMemo[node];
            int rob = node -> val + dfs(node -> left, true, memo, notMemo) + dfs(node -> right, true, memo, notMemo);
            int notRob = dfs(node -> left, false, memo, notMemo) + dfs(node -> right, false, memo, notMemo);
            result = max(rob, notRob);
            notMemo[node] = result;
        }
        
        return result;
    }
    
public:
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> memo, notMemo;
        return dfs(root, false, memo, notMemo);
    }
};
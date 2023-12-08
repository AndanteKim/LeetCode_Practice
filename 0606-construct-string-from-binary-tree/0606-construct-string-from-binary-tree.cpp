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
    string dfs(TreeNode* node){
        if (!node)
            return "";
        string ans = to_string(node -> val);
        
        if (node -> left){
            ans.push_back('(');
            ans += dfs(node -> left);
            ans.push_back(')');
        }
        
        if (node -> right){
            if (!node -> left)
                ans += "()";
            ans.push_back('(');
            ans += dfs(node -> right);
            ans.push_back(')');
        }
        
        return ans;
    }
    
public:
    string tree2str(TreeNode* root) {
        return dfs(root);
    }
};
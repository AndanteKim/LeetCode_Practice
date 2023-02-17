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
    int minDistance = INT_MAX;
    TreeNode* prevValue = nullptr;
    
public:
    void dfs(TreeNode* root){
        if (root == nullptr) return;
        
        dfs(root -> left);
        if (prevValue != nullptr){
            minDistance = min(minDistance, root -> val - prevValue -> val);
        }
        prevValue = root;
        dfs(root -> right);
    }
    
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        return minDistance;
    }
};
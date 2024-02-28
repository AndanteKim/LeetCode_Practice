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
    int maxDepth = -1, bottomLeftValue = 0;
    void dfs(TreeNode* current, int depth){
        if (!current) return;
        
        // If true, we discovered a new level
        if (depth > maxDepth){
            maxDepth = depth;
            bottomLeftValue = current -> val;
        }
        
        dfs(current -> left, depth + 1);
        dfs(current -> right, depth + 1);
    }
    
public:
    int findBottomLeftValue(TreeNode* root) {
        dfs(root, 0);
        
        return bottomLeftValue;
    }
};
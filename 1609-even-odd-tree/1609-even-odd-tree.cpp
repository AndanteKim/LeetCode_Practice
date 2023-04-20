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
    unordered_map<int, int> lastVal;
    
    bool dfs(TreeNode* node, int level){
        if (!node) return true;
        
        if (level % 2 == 0){
            if (node -> val % 2 == 0 || (lastVal[level] && lastVal[level] >= node -> val))
                return false;
            lastVal[level] = node -> val;
        }
        else{
            if (node -> val % 2 == 1 || (lastVal[level] && lastVal[level] <= node -> val))
                return false;
            lastVal[level] = node -> val;
        }
        return dfs(node -> left, level + 1) && dfs(node -> right, level + 1);
    }
    
public:
    bool isEvenOddTree(TreeNode* root) {
        return dfs(root, 0);
    }
};
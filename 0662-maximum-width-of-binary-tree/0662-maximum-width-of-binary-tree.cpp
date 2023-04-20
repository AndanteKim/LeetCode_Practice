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
#define ull unsigned long long

class Solution {
    ull ans = 0;
    unordered_map<ull, ull> firstColIndexTable;
    
    void dfs(TreeNode* node, ull depth, ull colIndex){
        if (!node) return;
        if (firstColIndexTable.find(depth) == firstColIndexTable.end())
            firstColIndexTable[depth] = colIndex;
        ans = max(ans, colIndex - firstColIndexTable[depth] + 1);
        dfs(node -> left, depth + 1, 2 * colIndex);
        dfs(node -> right, depth + 1, 2 * colIndex + 1);
    }
    
public:
    int widthOfBinaryTree(TreeNode* root) {
        dfs(root, 0, 0);
        return ans;
    }
};
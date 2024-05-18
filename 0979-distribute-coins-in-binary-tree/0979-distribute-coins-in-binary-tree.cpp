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
    int ans = 0;
    int dfs(TreeNode* curr){
        // base case
        if (!curr) return 0;
        
        // Calculate the number of coins each subtree has available to exchange
        int leftCoins = dfs(curr -> left), rightCoins = dfs(curr -> right);
        
        
        // Add the total number of exchanges to move
        ans += abs(leftCoins) + abs(rightCoins);
        
        // The number of coins current has available to exchange
        return curr -> val - 1 + leftCoins + rightCoins;
    }
    
public:
    int distributeCoins(TreeNode* root) {
        
        dfs(root);
        return ans;
    }
};
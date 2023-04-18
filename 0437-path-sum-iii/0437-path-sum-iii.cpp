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
#define ll long long

class Solution {
    int count = 0, k;
    unordered_map<ll, int> h;
    void preOrder(TreeNode* node, ll currSum){
        if (!node) return;
        
        currSum += node -> val;
        if (currSum == k) ++count;
        count += h[currSum - k];
        ++h[currSum];
        preOrder(node -> left, currSum);
        preOrder(node -> right, currSum);
        --h[currSum];
    }
    
public:
    int pathSum(TreeNode* root, int targetSum) {
        k = targetSum;
        preOrder(root, 0);
        
        return count;
    }
};
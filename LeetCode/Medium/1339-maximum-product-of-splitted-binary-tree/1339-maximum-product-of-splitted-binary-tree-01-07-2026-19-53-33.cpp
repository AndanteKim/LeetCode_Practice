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
    vector<int> allSums;
    int treeSum(TreeNode* node) {
        if (!node) return 0;

        int leftSum = treeSum(node -> left);
        int rightSum = treeSum(node -> right);
        int totalSum = leftSum + rightSum + node -> val;

        allSums.push_back(totalSum);
        return totalSum;
    }

public:
    int maxProduct(TreeNode* root) {
        int total = treeSum(root), mod = 1'000'000'007;
        long long ans = 0;

        for (const int sum : allSums) {
            ans = max(ans, (long long)sum * (total - sum));
        }

        return ans % mod;
    }
};
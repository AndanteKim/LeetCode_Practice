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
public:
    unordered_map<int, vector<TreeNode*>> memo;
    vector<TreeNode*> allPossibleFBT(int n) {
        if (n % 2 == 0) return {};
        if (n == 1) return {new TreeNode()};
        
        if (memo.find(n) != memo.end()) return memo[n];
        
        vector<TreeNode*> ans;
        for (int i = 1; i < n; i += 2){
            vector<TreeNode*> left = allPossibleFBT(i);
            vector<TreeNode*> right = allPossibleFBT(n - 1 - i);
            for (TreeNode *l : left){
                for (TreeNode *r : right){
                    TreeNode *root = new TreeNode(0, l, r);
                    ans.push_back(root);
                }
            }
        }
        
        return ans;
    }
};
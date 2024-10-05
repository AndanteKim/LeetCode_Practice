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
    vector<TreeNode*> allPossibleBSTs(int start, int end, map<pair<int, int>, vector<TreeNode*>>& memo){
        // Base case
        vector<TreeNode*> ans;
        if (start > end){
            ans.push_back(nullptr);
            return ans;
        }
        
        if (memo.count(make_pair(start, end)))
            return memo[make_pair(start, end)];
        
        // Iterate through all values from start to end to construct left and right subtrees recursively.
        for (int i = start; i <= end; ++i){
            vector<TreeNode*> leftSubtrees = allPossibleBSTs(start, i - 1, memo);
            vector<TreeNode*> rightSubtrees = allPossibleBSTs(i + 1, end, memo);
            
            // Loop through all left and right subtrees and connect them to ith root.
            for (TreeNode* left : leftSubtrees){
                for (TreeNode* right : rightSubtrees){
                    ans.push_back(new TreeNode(i, left, right));
                }
            }
        }
        
        return memo[make_pair(start, end)] = ans;
    }
        

public:
    vector<TreeNode*> generateTrees(int n) {
        map<pair<int, int>, vector<TreeNode*>> memo;
        return allPossibleBSTs(1, n, memo);
    }
};
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
    int maxLevelSum(TreeNode* root) {
        int ans = 1, maxSum = INT_MIN;
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 1});
        
        while (!queue.empty()){
            int currSum = 0, currLevel = -1;
            int sz = queue.size();
            for (int i = 0; i < sz; ++i){
                auto[node, level] = queue.front();
                queue.pop();
                currSum += node -> val;
                
                if (node -> left) queue.push({node -> left, level + 1});
                if (node -> right) queue.push({node -> right, level + 1});
                currLevel = level;
            }
            
            
            if (maxSum < currSum){
                maxSum = currSum;
                ans = currLevel;
            }
        }
        
        return ans;
    }
};
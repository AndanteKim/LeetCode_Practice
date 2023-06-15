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
typedef long long ll;

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 1});
        int ans = 1;
        ll maxSum = INT_MIN;
        
        while (!queue.empty()){
            int qLength = queue.size(), currLevel = queue.front().second;
            ll currSum = 0;
            for (int i = 0; i < qLength; ++i){
                auto [node, level] = queue.front();
                queue.pop();
                currSum += node -> val;
                if (node -> left) queue.push({node -> left, level + 1});
                if (node -> right) queue.push({node -> right, level + 1});
            }
            
            if (maxSum < currSum){
                maxSum = currSum;
                ans = currLevel;
            }
        }
        
        return ans;
    }
};
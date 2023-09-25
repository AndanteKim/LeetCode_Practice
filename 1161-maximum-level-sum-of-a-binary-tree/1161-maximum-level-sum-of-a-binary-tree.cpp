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
        queue<pair<TreeNode*, int>> queue;
        queue.push({root, 1});
        int ans = 1, maxSum = INT_MIN;
        
        while(!queue.empty()){
            int n = queue.size(), sum = 0, lv;
            
            for (int i = 0; i < n; ++i){
                auto [node, level] = queue.front();
                queue.pop();
                lv = level;
                sum += node -> val;
                
                if (node -> left) queue.push({node -> left, level + 1});
                if (node -> right) queue.push({node -> right, level + 1});
            }
            
            if (sum > maxSum){
                maxSum = sum;
                ans = lv;
            }
        }
        
        return ans;
    }
};
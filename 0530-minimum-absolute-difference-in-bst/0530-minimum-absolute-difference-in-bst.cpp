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
    int getMinimumDifference(TreeNode* root) {
        queue<TreeNode*> queue;
        vector<int> arr;
        queue.push(root);
        int ans = INT_MAX;
        while (!queue.empty()){
            TreeNode* curr = queue.front();
            queue.pop();
            
            arr.push_back(curr -> val);
            if (curr -> left) queue.push(curr -> left);
            if (curr -> right) queue.push(curr -> right);
        }
        
        sort(arr.begin(), arr.end());
        for (int i = 0; i < arr.size() - 1; ++i) ans = min(ans, arr[i + 1] - arr[i]);
        
        return ans;
    }
};
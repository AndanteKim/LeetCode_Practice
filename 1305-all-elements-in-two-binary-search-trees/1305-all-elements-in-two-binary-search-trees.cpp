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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        queue<TreeNode*> queue;
        queue.push(root1);
        queue.push(root2);
        
        while (!queue.empty()){
            TreeNode* node = queue.front();
            queue.pop();
            if (!node) continue;
            ans.push_back(node -> val);
            if (node -> left) queue.push(node -> left);
            if (node -> right) queue.push(node -> right);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
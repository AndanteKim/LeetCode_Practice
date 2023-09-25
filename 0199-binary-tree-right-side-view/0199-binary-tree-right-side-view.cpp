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
    vector<int> rightSideView(TreeNode* root) {
        if (!root)
            return {};
        
        queue<TreeNode*> queue;
        queue.push(root);
        vector<int> ans;
        
        while (!queue.empty()){
            int n = queue.size();
            
            for (int i = 0; i < n; ++i){
                TreeNode* node = queue.front();
                queue.pop();
                
                if (i == n - 1)
                    ans.push_back(node -> val);
                
                if (node -> left)
                    queue.push(node -> left);
                if (node -> right)
                    queue.push(node -> right);
            }
        }
        
        return ans;
    }
};
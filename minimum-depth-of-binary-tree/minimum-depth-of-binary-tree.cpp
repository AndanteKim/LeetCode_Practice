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
    int minDepth(TreeNode* root) {
        if (!root) return 0;
        queue<pair<TreeNode*, int>> *q = new queue<pair<TreeNode*, int>>;
        q -> push({root, 1});
        int ans = INT_MAX;
        
        while (!q -> empty()){
            auto[node, height] = q -> front();
            q -> pop();
            if (node -> left == nullptr && node -> right == nullptr){
                ans = min(ans, height);
            }
            
            if (node -> left){
                q -> push({node -> left, height + 1});
            }
            
            if (node -> right) q -> push({node -> right, height + 1});
        }
        
        return ans;
    }
};
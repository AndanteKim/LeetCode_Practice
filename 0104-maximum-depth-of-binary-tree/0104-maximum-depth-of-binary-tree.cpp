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
    int maxDepth(TreeNode* root) {
        if (root == NULL) return 0;
        int depth = 0;
        queue<pair<int, TreeNode*>> dq({{depth+1, root}});
        TreeNode *q;
        while (!dq.empty()){
            
            depth = max(depth, dq.front().first);
            q = dq.front().second;
            if (q -> left != NULL) dq.push({depth+1, q -> left});
            if (q -> right != NULL) dq.push({depth+1, q -> right});
            dq.pop();
            
        }
        
        return depth;
    }
};
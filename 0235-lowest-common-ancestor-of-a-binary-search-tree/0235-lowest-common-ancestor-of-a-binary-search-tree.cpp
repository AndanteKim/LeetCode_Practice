/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_map<TreeNode*, TreeNode*> ancestors;
        
        queue<pair<TreeNode*, TreeNode*>> queue;
        queue.push({root, nullptr});
        
        while (!queue.empty()){
            auto [child, parent] = queue.front();
            queue.pop();
            
            ancestors[child] = parent;
            
            if (child -> left)
                queue.push({child -> left, child});
            if (child -> right)
                queue.push({child -> right, child});
        }
        
        unordered_set<TreeNode*> seen;
        while (p){
            seen.insert(p);
            p = ancestors[p];
        }
        
        while (seen.find(q) == seen.end()){
            q = ancestors[q];
        }
        return q;
    }
};
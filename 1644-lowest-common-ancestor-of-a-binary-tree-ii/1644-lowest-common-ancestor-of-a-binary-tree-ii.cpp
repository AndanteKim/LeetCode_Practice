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
        unordered_map<TreeNode*, TreeNode*> parents;
        
        queue<pair<TreeNode*, TreeNode*>> queue;
        queue.push({root, nullptr});
        
        while (!queue.empty()){
            auto [child, parent] = queue.front();
            queue.pop();
            parents[child] = parent;
            
            if (child -> left) queue.push({child -> left, child});
            if (child -> right) queue.push({child -> right, child});
        }
        
        stack<TreeNode*> stack;
        stack.push(q);
        while (!stack.empty()){
            TreeNode* descendant = stack.top();
            stack.pop();
            if (descendant == p) return q;
            if (descendant -> left) stack.push(descendant -> left);
            if (descendant -> right) stack.push(descendant -> right);
        }
        stack.push(p);
        while (!stack.empty()){
            TreeNode* descendant = stack.top();
            stack.pop();
            if (descendant == q) return p;
            if (descendant -> left) stack.push(descendant -> left);
            if (descendant -> right) stack.push(descendant -> right);
        }
        
        TreeNode *pCopy = parents[p];
        
        while (pCopy){
            TreeNode *qCopy = parents[q];
            
            while (qCopy && pCopy != qCopy){
                qCopy = parents[qCopy];
            }
            if (pCopy == qCopy) return pCopy;
            pCopy = parents[pCopy];
        }
        
        return nullptr;
    }
};
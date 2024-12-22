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
        queue.push({nullptr, root});

        while (!queue.empty()){
            auto [parent, child] = queue.front(); queue.pop();

            parents[child] = parent;
            if (child -> left)
                queue.push({child, child -> left});
            
            if (child -> right)
                queue.push({child, child -> right});
        }

        // Base case
        if (!(parents.count(p) && parents.count(q)))
            return nullptr;

        TreeNode* pAncestor = p;
        while (pAncestor){
            TreeNode* qAncestor = q;
            while (qAncestor){
                if (pAncestor == qAncestor)
                    return pAncestor;
                qAncestor = parents[qAncestor];
            }
            pAncestor = parents[pAncestor];
        }

        return nullptr;
    }
};